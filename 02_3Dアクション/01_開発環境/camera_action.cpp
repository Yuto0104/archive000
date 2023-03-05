//=============================================================================
//
// �J�����}�l�[�W���[�N���X(camera_action.cpp)
// Author : �������l
// �T�v : �J�����}�l�[�W���[�̔h�����s��
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include <assert.h>
#include <stdio.h>
#include "camera_action.h"
#include "calculation.h"
#include "object.h"
#include "model_obj.h"
#include "camera.h"

//--------------------------------------------------------------------
// �萔��`
//--------------------------------------------------------------------
const unsigned int CCameraAction::nACTION_BLEND_FRAM = 5;

//=============================================================================
// �C���X�^���X����
// Author : �������l
// �T�v : ���[�V�����L�����N�^�[3D�𐶐�����
//=============================================================================
CCameraAction *CCameraAction::Create()
{// �I�u�W�F�N�g�C���X�^���X
	CCameraAction *pCameraAction = nullptr;

	// �������̉��
	pCameraAction = new CCameraAction;

	// �������̊m�ۂ��ł��Ȃ�����
	assert(pCameraAction != nullptr);

	// ���l�̏�����
	pCameraAction->Init();

	// �C���X�^���X��Ԃ�
	return pCameraAction;
}

//=============================================================================
// �R���X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�������ɍs������
//=============================================================================
CCameraAction::CCameraAction() : m_pPivot(nullptr),
m_pCamera(nullptr),
m_posDest(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),
m_posVDest(D3DXVECTOR3(0.0f,0.0f,0.0f)),
m_posRDest(D3DXVECTOR3(0.0f,0.0f,0.0f)),
m_rotDest(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),
m_nMaxAction(0),
m_nNumAction(0),
m_bAction(false),
m_bActionBlend(false)
{
	// �A�N�V�����̏�����
	m_action.clear();
}

//=============================================================================
// �f�X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�I�����ɍs������
//=============================================================================
CCameraAction::~CCameraAction()
{

}

//=============================================================================
// ������
// Author : �������l
// �T�v : ���_�o�b�t�@�𐶐����A�����o�ϐ��̏����l��ݒ�
//=============================================================================
HRESULT CCameraAction::Init()
{
	m_pPivot = CModelObj::Create();

	return S_OK;
}

//=============================================================================
// �I��
// Author : �������l
// �T�v : �e�N�X�`���̃|�C���^�ƒ��_�o�b�t�@�̉��
//=============================================================================
void CCameraAction::Uninit()
{
	m_action.clear();

	if (m_pPivot != nullptr)
	{// �I������
		m_pPivot->Uninit();
		m_pPivot = nullptr;
	}

	// �X�R�A�̉��
	Release();
}

//=============================================================================
// �X�V
// Author : �������l
// �T�v : �X�V���s��
//=============================================================================
void CCameraAction::Update()
{
	if (m_bActionBlend)
	{
		ActionBlend();
	}
	else if (m_bAction
		&& !m_bActionBlend)
	{
		PlayAction();
	}
}

//=============================================================================
// �`��
// Author : �������l
// �T�v : �`����s��
//=============================================================================
void CCameraAction::Draw()
{

}

//=============================================================================
// �A�N�V�����̓ǂݍ���
// Author : �������l
// �T�v : �A�N�V�����̓ǂݍ���
//=============================================================================
void CCameraAction::LoadAction(char * pFileName)
{
	// �ϐ��錾
	char aStr[128];

	// �t�@�C���̓ǂݍ���
	FILE *pFile = fopen(pFileName, "r");

	if (pFile != nullptr)
	{
		while (fscanf(pFile, "%s", &aStr[0]) != EOF)
		{// "EOF"��ǂݍ��ނ܂� 
			if (strncmp(&aStr[0], "#", 1) == 0)
			{// ���ǂݍ���
				fgets(&aStr[0], sizeof(aStr), pFile);
			}

			if (strstr(&aStr[0], "ACTIONSET") != NULL)
			{
				m_nMaxAction++;

				// �ϐ��錾
				int nCntKeySet = 0;
				int nNumKey = 0;			// �L�[��
				bool bLoop = false;			// ���[�v�g�p��
				bool bParent = false;		// �e�����邩�ۂ�

				while (strstr(&aStr[0], "END_FIELDSET") == NULL)
				{
					fscanf(pFile, "%s", &aStr[0]);

					if (strncmp(&aStr[0], "#", 1) == 0)
					{// ���ǂݍ���
						fgets(&aStr[0], sizeof(aStr), pFile);
					}

					if (strcmp(&aStr[0], "NUMKEY") == 0)
					{// ���f���̃t�@�C�����̐ݒ�
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%d", &nNumKey);

						// �������̊m��
						m_action.at(m_nMaxAction - 1).nNumKey = nNumKey;
						m_action.at(m_nMaxAction - 1).pKeySet.resize(m_action.at(m_nMaxAction - 1).nNumKey);
					}

					if (strcmp(&aStr[0], "LOOP") == 0)
					{// ���f���̃t�@�C�����̐ݒ�
						int nLoop = 0;
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%d", &nLoop);

						if (nLoop == 0)
						{
							bLoop = false;
						}
						else
						{
							bLoop = true;
						}
					}

					if (strcmp(&aStr[0], "PARENT") == 0)
					{// ���f���̃t�@�C�����̐ݒ�
						int nParent = 0;
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%d", &nParent);

						if (nParent == 0)
						{
							bParent = false;
						}
						else
						{
							bParent = true;
						}
					}

					if (strcmp(&aStr[0], "KEYSET") == 0)
					{
						// ���i�[�p�ϐ�
						D3DXVECTOR3	pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	// ���݈ʒu
						D3DXVECTOR3	posV = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	// ���_
						D3DXVECTOR3	posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	// �����_
						D3DXVECTOR3	rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	// ���݂̌���
						int nFrame = 0;										// �t���[����

						while (strstr(&aStr[0], "END_KEYSET") == NULL)
						{
							fscanf(pFile, "%s", &aStr[0]);

							if (strncmp(&aStr[0], "#", 1) == 0)
							{// ���ǂݍ���
								fgets(&aStr[0], sizeof(aStr), pFile);
							}

							if (strcmp(&aStr[0], "POS") == 0)
							{// �ʒu�̓ǂݍ���
								fscanf(pFile, "%s", &aStr[0]);
								fscanf(pFile, "%f", &pos.x);
								fscanf(pFile, "%f", &pos.y);
								fscanf(pFile, "%f", &pos.z);
							}
							if (strcmp(&aStr[0], "ROT") == 0)
							{// �����̓ǂݍ���
								fscanf(pFile, "%s", &aStr[0]);
								fscanf(pFile, "%f", &rot.x);
								fscanf(pFile, "%f", &rot.y);
								fscanf(pFile, "%f", &rot.z);
							}
							if (strcmp(&aStr[0], "POSV") == 0)
							{// �����̓ǂݍ���
								fscanf(pFile, "%s", &aStr[0]);
								fscanf(pFile, "%f", &rot.x);
								fscanf(pFile, "%f", &rot.y);
								fscanf(pFile, "%f", &rot.z);
							}
							if (strcmp(&aStr[0], "POSR") == 0)
							{// �����̓ǂݍ���
								fscanf(pFile, "%s", &aStr[0]);
								fscanf(pFile, "%f", &rot.x);
								fscanf(pFile, "%f", &rot.y);
								fscanf(pFile, "%f", &rot.z);
							}
							if (strcmp(&aStr[0], "FRAME") == 0)
							{// �����̓ǂݍ���
								fscanf(pFile, "%s", &aStr[0]);
								fscanf(pFile, "%d", &nFrame);
							}
						}

						// ���l�̐ݒ�
						m_action.at(m_nMaxAction - 1).pKeySet.at(nCntKeySet).nFrame = nFrame;
						m_action.at(m_nMaxAction - 1).pKeySet.at(nCntKeySet).pos = pos;
						m_action.at(m_nMaxAction - 1).pKeySet.at(nCntKeySet).rot = rot;
						m_action.at(m_nMaxAction - 1).pKeySet.at(nCntKeySet).posV = posV;
						m_action.at(m_nMaxAction - 1).pKeySet.at(nCntKeySet).posR = posR;
					}
				}

				// ���l�̐ݒ�
				m_action.at(m_nMaxAction - 1).bLoop = bLoop;
				m_action.at(m_nMaxAction - 1).bParent = bParent;
			}
		}
	}
	else
	{
		assert(false);
	}
}

//=============================================================================
// �A�N�V�����̐ݒ�
// Author : �������l
// �T�v : �A�N�V�����ݒ������
//=============================================================================
void CCameraAction::SetAction(const int nCntMotionSet)
{
	if (m_pCamera == nullptr)
	{
		return;
	}

	CCameraAction::Action& action = m_action.at(m_nNumAction);
	CObject *pParent = m_pCamera->GetTarget();

	// �ϐ��錾
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// �ʒu
	D3DXVECTOR3 posV = m_pCamera->GetPosV();					// ���_
	D3DXVECTOR3 posR = m_pCamera->GetPosR();					// �����_
	D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// ����

	if (pParent != nullptr)
	{
		pos = pParent->GetPos();
	}
	else
	{
		pos = m_pPivot->GetPos();
	}

	// �ʒu�̐ݒ�
	pos = action.pKeySet[action.nCntKeySet].pos;

	// ���_�̐ݒ�
	posV = action.pKeySet[action.nCntKeySet].posV;

	// �����_�̐ݒ�
	posR = action.pKeySet[action.nCntKeySet].posR;

	//	�����̐ݒ�
	rot = action.pKeySet[action.nCntKeySet].rot;

	// �p�x�̐��K��
	rot.x = CCalculation::RotNormalization(rot.x);
	rot.y = CCalculation::RotNormalization(rot.y);
	rot.z = CCalculation::RotNormalization(rot.z);

	if (pParent != nullptr)
	{
		pParent->SetPos(pos);
	}

	m_pCamera->SetPosVOffset(posV);
	m_pCamera->SetPosROffset(posR);
	m_pCamera->SetRot(rot);
}

//=============================================================================
// �A�N�V�����̐ݒ�
// Author : �������l
// �T�v : �A�N�V�����ݒ������
//=============================================================================
void CCameraAction::SetAction(const int nCntMotionSet, const int nNumKeySet)
{
	if (m_pCamera == nullptr)
	{
		return;
	}

	CCameraAction::Action& action = m_action.at(m_nNumAction);
	CObject *pParent = m_pCamera->GetTarget();

	// �ϐ��錾
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// �ʒu
	D3DXVECTOR3 posV = m_pCamera->GetPosV();					// ���_
	D3DXVECTOR3 posR = m_pCamera->GetPosR();					// �����_
	D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// ����

	if (pParent != nullptr)
	{
		pos = pParent->GetPos();
	}
	else
	{
		pos = m_pPivot->GetPos();
	}

	// �ʒu�̐ݒ�
	pos = action.pKeySet[nNumKeySet].pos;

	// ���_�̐ݒ�
	posV = action.pKeySet[nNumKeySet].posV;

	// �����_�̐ݒ�
	posR = action.pKeySet[nNumKeySet].posR;

	//	�����̐ݒ�
	rot = action.pKeySet[nNumKeySet].rot;

	// �p�x�̐��K��
	rot.x = CCalculation::RotNormalization(rot.x);
	rot.y = CCalculation::RotNormalization(rot.y);
	rot.z = CCalculation::RotNormalization(rot.z);

	if (pParent != nullptr)
	{
		pParent->SetPos(pos);
	}

	m_pCamera->SetPosVOffset(posV);
	m_pCamera->SetPosROffset(posR);
	m_pCamera->SetRot(rot);
}

//=============================================================================
// �A�N�V�����̍Đ�
// Author : �������l
// �T�v : �A�N�V�������Đ�����
//=============================================================================
void CCameraAction::PlayAction()
{
	if (m_pCamera == nullptr)
	{
		return;
	}

	CCameraAction::Action& action = m_action.at(m_nNumAction);
	CObject *pParent = m_pCamera->GetTarget();

	// �ϐ��錾
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// �ʒu
	D3DXVECTOR3 posV = m_pCamera->GetPosV();					// ���_
	D3DXVECTOR3 posR = m_pCamera->GetPosR();					// �����_
	D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// ����

	if (pParent != nullptr)
	{
		pos = pParent->GetPos();
	}
	else
	{
		pos = m_pPivot->GetPos();
	}

	if (action.nCntFrame == 0)
	{// �t���[���J�E���g��0�̎�
		// �ړI�̈ʒu�ƌ����̎Z�o
		m_posDest = action.pKeySet[action.nCntKeySet].pos - pos;
		m_posVDest = action.pKeySet[action.nCntKeySet].posV - posV;
		m_posRDest = action.pKeySet[action.nCntKeySet].posR - posR;
		m_rotDest = action.pKeySet[action.nCntKeySet].rot - rot;

		// �p�x�̐��K��
		m_rotDest.x = CCalculation::RotNormalization(m_rotDest.x);
		m_rotDest.y = CCalculation::RotNormalization(m_rotDest.y);
		m_rotDest.z = CCalculation::RotNormalization(m_rotDest.z);
	}

	// �ϐ��錾
	D3DXVECTOR3 addPos = D3DXVECTOR3(m_posDest / (float)(action.pKeySet[action.nCntKeySet].nFrame));
	D3DXVECTOR3 addPosV = D3DXVECTOR3(m_posVDest / (float)(action.pKeySet[action.nCntKeySet].nFrame));
	D3DXVECTOR3 addPosR = D3DXVECTOR3(m_posRDest / (float)(action.pKeySet[action.nCntKeySet].nFrame));
	D3DXVECTOR3 addRot = D3DXVECTOR3(m_rotDest / (float)(action.pKeySet[action.nCntKeySet].nFrame));

	if (pParent != nullptr)
	{
		// �ʒu�̉��Z
		pos += addPos;
	}

	// ���_�̉��Z
	posV += addPosV;

	// �����_�̉��Z
	posR += addPosR;

	//	�����̉��Z
	rot += addRot;

	// �p�x�̐��K��
	rot.x = CCalculation::RotNormalization(rot.x);
	rot.y = CCalculation::RotNormalization(rot.y);
	rot.z = CCalculation::RotNormalization(rot.z);

	if (pParent != nullptr)
	{
		pParent->SetPos(pos);
	}

	m_pCamera->SetPosVOffset(posV);
	m_pCamera->SetPosROffset(posR);
	m_pCamera->SetRot(rot);

	// �t���[���J�E���g�̉��Z
	action.nCntFrame++;

	if (action.nCntFrame >= action.pKeySet[action.nCntKeySet].nFrame)
	{// �t���[���J�E���g���w��̃t���[�����𒴂����ꍇ
		// �t���[�����̏�����
		action.nCntFrame = 0;

		// �Đ����̃L�[�ԍ����̉��Z
		action.nCntKeySet++;

		if (action.nCntKeySet >= action.nNumKey && action.bLoop)
		{// �Đ����̃L�[���J�E���g���L�[���̍ő�l�𒴂����Ƃ��A���̃��[�V���������[�v���g�p���Ă���
			// �Đ����̃L�[���J�E���g��������
			action.nCntKeySet = 0;

		}
		else if (action.nCntKeySet >= action.nNumKey)
		{
			action.nCntKeySet = 0;
			m_bAction = false;
		}
	}
}

//=============================================================================
// �A�N�V�����u�����h
// Author : �������l
// �T�v : �A�N�V�����u�����h���Đ�����
//=============================================================================
void CCameraAction::ActionBlend()
{
	if (m_pCamera == nullptr)
	{
		return;
	}

	CCameraAction::Action& action = m_action.at(m_nNumAction);
	CObject *pParent = m_pCamera->GetTarget();

	// �ϐ��錾
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// �ʒu
	D3DXVECTOR3 posV = m_pCamera->GetPosV();					// ���_
	D3DXVECTOR3 posR = m_pCamera->GetPosR();					// �����_
	D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// ����

	if (action.nCntFrame == 0)
	{// �t���[���J�E���g��0�̎�
		// �ړI�̈ʒu�ƌ����̎Z�o
		m_posDest = action.pKeySet[action.nCntKeySet].pos - pos;
		m_posVDest = action.pKeySet[action.nCntKeySet].posV - posV;
		m_posRDest = action.pKeySet[action.nCntKeySet].posR - posR;
		m_rotDest = action.pKeySet[action.nCntKeySet].rot - rot;

		// �p�x�̐��K��
		m_rotDest.x = CCalculation::RotNormalization(m_rotDest.x);
		m_rotDest.y = CCalculation::RotNormalization(m_rotDest.y);
		m_rotDest.z = CCalculation::RotNormalization(m_rotDest.z);
	}

	// �ϐ��錾
	D3DXVECTOR3 addPos = D3DXVECTOR3(m_posDest / (float)(nACTION_BLEND_FRAM));
	D3DXVECTOR3 addPosV = D3DXVECTOR3(m_posVDest / (float)(nACTION_BLEND_FRAM));
	D3DXVECTOR3 addPosR = D3DXVECTOR3(m_posRDest / (float)(nACTION_BLEND_FRAM));
	D3DXVECTOR3 addRot = D3DXVECTOR3(m_rotDest / (float)(nACTION_BLEND_FRAM));

	if (pParent != nullptr)
	{
		// �ʒu�̉��Z
		pos += addPos;
	}

	// ���_�̉��Z
	posV += addPosV;

	// �����_�̉��Z
	posR += addPosR;

	//	�����̉��Z
	rot += addRot;

	// �p�x�̐��K��
	rot.x = CCalculation::RotNormalization(rot.x);
	rot.y = CCalculation::RotNormalization(rot.y);
	rot.z = CCalculation::RotNormalization(rot.z);

	if (pParent != nullptr)
	{
		pParent->SetPos(pos);
	}

	m_pCamera->SetPosVOffset(posV);
	m_pCamera->SetPosROffset(posR);
	m_pCamera->SetRot(rot);

	// �t���[���J�E���g�̉��Z
	action.nCntFrame++;

	if (action.nCntFrame >= nACTION_BLEND_FRAM)
	{// �t���[���J�E���g���w��̃t���[�����𒴂����ꍇ
		action.nCntFrame = 0;	// �t���[�����̏�����
		action.nCntKeySet++;	// �Đ����̃L�[�ԍ����̉��Z

		m_bActionBlend = false;
	}
}

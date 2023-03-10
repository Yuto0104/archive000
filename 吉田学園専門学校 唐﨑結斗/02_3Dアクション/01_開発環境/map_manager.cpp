//=============================================================================
//
// �}�b�v�}�l�[�W���[�N���X(map_manager.cpp)
// Author : �������l
// �T�v : �}�b�v�}�l�[�W���[�̔h�����s��
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include <assert.h>
#include <stdio.h>
#include "map_manager.h"
#include "model_obj.h"
#include "mesh.h"
#include "sphere.h"
#include "keyboard.h"
#include "player.h"
#include "game.h"
#include "application.h"
#include "collision_rectangle3D.h"
#include "debug_proc.h"
#include "model3D.h"
#include "mesh.h"
#include "calculation.h"
#include "texture.h"
#include "super.h"
#include "score_item.h"

//=============================================================================
// �C���X�^���X����
// Author : �������l
// �T�v : ���[�V�����L�����N�^�[3D�𐶐�����
//=============================================================================
CMapManager *CMapManager::Create()
{// �I�u�W�F�N�g�C���X�^���X
	CMapManager *pMapManager = nullptr;

	// �������̉��
	pMapManager = new CMapManager;

	// �������̊m�ۂ��ł��Ȃ�����
	assert(pMapManager != nullptr);

	// ���l�̏�����
	pMapManager->Init();

	// �C���X�^���X��Ԃ�
	return pMapManager;
}

//=============================================================================
// �R���X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�������ɍs������
//=============================================================================
CMapManager::CMapManager()
{

}

//=============================================================================
// �f�X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�I�����ɍs������
//=============================================================================
CMapManager::~CMapManager()
{

}

//=============================================================================
// ������
// Author : �������l
// �T�v : ���_�o�b�t�@�𐶐����A�����o�ϐ��̏����l��ݒ�
//=============================================================================
HRESULT CMapManager::Init()
{
	return S_OK;
}

//=============================================================================
// �I��
// Author : �������l
// �T�v : �e�N�X�`���̃|�C���^�ƒ��_�o�b�t�@�̉��
//=============================================================================
void CMapManager::Uninit()
{
	// �X�R�A�̉��
	Release();
}

//=============================================================================
// �X�V
// Author : �������l
// �T�v : �X�V���s��
//=============================================================================
void CMapManager::Update()
{
	
}

//=============================================================================
// �`��
// Author : �������l
// �T�v : �`����s��
//=============================================================================
void CMapManager::Draw()
{

}

//=============================================================================
// �}�b�v�̓ǂݍ���
// Author : �������l
// �T�v : �}�b�v�̓ǂݍ���
//=============================================================================
void CMapManager::SetMap(char * pFileName)
{
	// ���b�V���t�B�[���h�̓ǂݍ���
	LoadFieldMesh(pFileName);

	// �X�J�C�{�b�N�X�̓ǂݍ���
	LoadSkayBox(pFileName);

	// ���f���̓ǂݍ���
	CModelObj::LoadFile(pFileName);

	// �A�C�e���̓ǂݍ���
	LoadScoreItem(pFileName);
}

//=============================================================================
// �t�B�[���h�̓ǂݍ���
// Author : �������l
// �T�v : �t�B�[���h�̓ǂݍ���
//=============================================================================
void CMapManager::LoadFieldMesh(char * pFileName)
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

			if (strstr(&aStr[0], "FIELDSET") != NULL)
			{
				// ���b�V���̐ݒu
				CMesh3D *pMesh = CMesh3D::Create();
				assert(pMesh != nullptr);
				D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				D3DXVECTOR3 size = D3DXVECTOR3(100.0f, 0.0f, 100.0f);
				CMesh3D::DOUBLE_INT block = CMesh3D::DOUBLE_INT(1, 1);
				D3DXVECTOR2 move = D3DXVECTOR2(0.0f, 0.0f);
				int nType = -1;
				bool bSplitTex = true;
				bool bScrollTex = false;
				bool bCollison = false;

				while (strstr(&aStr[0], "END_FIELDSET") == NULL)
				{
					fscanf(pFile, "%s", &aStr[0]);

					if (strncmp(&aStr[0], "#", 1) == 0)
					{// ���ǂݍ���
						fgets(&aStr[0], sizeof(aStr), pFile);
					}
					
					if (strcmp(&aStr[0], "POS") == 0)
					{// ���f���̃t�@�C�����̐ݒ�
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%f", &pos.x);
						fscanf(pFile, "%f", &pos.y);
						fscanf(pFile, "%f", &pos.z);
					}

					if (strcmp(&aStr[0], "ROT") == 0)
					{// ���f���̃t�@�C�����̐ݒ�
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%f", &rot.x);
						fscanf(pFile, "%f", &rot.y);
						fscanf(pFile, "%f", &rot.z);
					}

					if (strcmp(&aStr[0], "SIZE") == 0)
					{// �L�[���̓ǂݍ���
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%f", &size.x);
						fscanf(pFile, "%f", &size.y);
						fscanf(pFile, "%f", &size.z);
					}

					if (strstr(&aStr[0], "TEXTYPE") != NULL)
					{// �ǂݍ��ރe�N�X�`��
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%d", &nType);
					}

					if (strcmp(&aStr[0], "BLOCK") == 0)
					{// �L�[���̓ǂݍ���
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%d", &block.x);
						fscanf(pFile, "%d", &block.y);
					}

					if (strcmp(&aStr[0], "SPLITTEX") == 0)
					{// �L�[���̓ǂݍ���
						int nSplitTex = 0;
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%d", &nSplitTex);

						if (nSplitTex == 1)
						{
							bSplitTex = true;
						}
						else
						{
							bSplitTex = false;
						}
					}

					if (strcmp(&aStr[0], "COLLISON") == 0)
					{// �L�[���̓ǂݍ���
						int nCollison = 0;
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%d", &nCollison);

						if (nCollison == 1)
						{
							bCollison = true;
						}
						else
						{
							bCollison = false;
						}
					}

					if (strcmp(&aStr[0], "MOVE") == 0)
					{// �ړ����
						bScrollTex = true;
						fscanf(pFile, "%f", &move.x);
						fscanf(pFile, "%f", &move.y);
					}
				}

				// ���l�̐ݒ�
				pMesh->SetPos(pos);
				pMesh->SetRot(rot);
				pMesh->SetSize(size);
				pMesh->LoadTex(nType);
				pMesh->SetBlock(block);
				pMesh->SetSplitTex(bSplitTex);
				pMesh->SetScrollTex(move, bScrollTex);
				pMesh->SetUseCollison(bCollison);
			}
		}
	}
	else
	{
		assert(false);
	}
}

//=============================================================================
// �X�J�C�{�b�N�X�̓ǂݍ���
// Author : �������l
// �T�v : �X�J�C�{�b�N�X�̓ǂݍ���
//=============================================================================
void CMapManager::LoadSkayBox(char * pFileName)
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

			if (strstr(&aStr[0], "SKYSET") != NULL)
			{
				// �X�J�C�{�b�N�X�̐ݒ�
				CSphere *pSphere = CSphere::Create();
				assert(pSphere != nullptr);
				D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				D3DXVECTOR3 rot = D3DXVECTOR3(D3DX_PI, 0.0f, 0.0f);
				D3DXVECTOR3 size = D3DXVECTOR3(100.0f, 0.0f, 100.0f);
				CMesh3D::DOUBLE_INT block = CMesh3D::DOUBLE_INT(1, 1);
				D3DXVECTOR2 move = D3DXVECTOR2(0.0f, 0.0f);
				D3DXVECTOR2 sphereRange = D3DXVECTOR2(D3DX_PI * 2.0f, D3DX_PI * -0.5f);
				int nType = -1;
				float fRadius = 100.0f;
				bool bSplitTex = false;
				bool bScrollTex = false;

				while (strstr(&aStr[0], "END_SKYSET") == NULL)
				{
					fscanf(pFile, "%s", &aStr[0]);

					if (strncmp(&aStr[0], "#", 1) == 0)
					{// ���ǂݍ���
						fgets(&aStr[0], sizeof(aStr), pFile);
					}

					if (strstr(&aStr[0], "POS") != NULL)
					{// ���f���̃t�@�C�����̐ݒ�
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%f", &pos.x);
						fscanf(pFile, "%f", &pos.y);
						fscanf(pFile, "%f", &pos.z);
					}

					if (strstr(&aStr[0], "ROT") != NULL)
					{// ���f���̃t�@�C�����̐ݒ�
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%f", &rot.x);
						fscanf(pFile, "%f", &rot.y);
						fscanf(pFile, "%f", &rot.z);
					}

					if (strcmp(&aStr[0], "SIZE") == 0)
					{// �L�[���̓ǂݍ���
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%f", &size.x);
						fscanf(pFile, "%f", &size.z);
						fscanf(pFile, "%f", &size.y);
					}

					if (strstr(&aStr[0], "TEXTYPE") != NULL)
					{// �ǂݍ��ރe�N�X�`��
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%d", &nType);
					}

					if (strcmp(&aStr[0], "BLOCK") == 0)
					{// �L�[���̓ǂݍ���
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%d", &block.x);
						fscanf(pFile, "%d", &block.y);
					}

					if (strcmp(&aStr[0], "SPLITTEX") == 0)
					{// �L�[���̓ǂݍ���
						int nSplitTex = 0;
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%d", &nSplitTex);

						if (nSplitTex == 0)
						{
							bSplitTex = true;
						}
						else
						{
							bSplitTex = false;
						}
					}

					if (strcmp(&aStr[0], "MOVE") == 0)
					{// �ړ����
						bScrollTex = true;
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%f", &move.x);
						fscanf(pFile, "%f", &move.y);
					}

					if (strcmp(&aStr[0], "RADIUS") == 0)
					{// �ړ����
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%f", &fRadius);
					}

					if (strcmp(&aStr[0], "SPHERERANGE") == 0)
					{// �ړ����
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%f", &sphereRange.x);
						fscanf(pFile, "%f", &sphereRange.y);
					}
				}

				// �X�J�C�{�b�N�X�̐ݒ�
				pSphere->SetPos(pos);
				pSphere->SetRot(rot);
				pSphere->SetSize(size);
				pSphere->LoadTex(nType);
				pSphere->SetBlock(block);
				pSphere->SetSplitTex(bSplitTex);
				pSphere->SetScrollTex(move, bScrollTex);
				pSphere->SetRadius(fRadius);
				pSphere->SetSphereRange(sphereRange);
			}
		}
	}
	else
	{
		assert(false);
	}
}

//=============================================================================
// �X�R�A�A�C�e���̓ǂݍ���
// Author : �������l
// �T�v : �X�R�A�A�C�e���̓ǂݍ���
//=============================================================================
void CMapManager::LoadScoreItem(char * pFileName)
{
	// �ϐ��錾
	char aStr[128];
	int nCntSetModel = 0;

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

			if (strstr(&aStr[0], "SCOREITEMSET") != NULL)
			{
				// ���f���̐ݒu
				CScoreItem *pScoreItem = CScoreItem::Create();
				assert(pScoreItem != nullptr);
				CCollision_Rectangle3D *pCollision = pScoreItem->GetCollision();
				CModel3D *pModel = pScoreItem->GetModel();

				while (strstr(&aStr[0], "END_SCOREITEMSET") == NULL)
				{
					fscanf(pFile, "%s", &aStr[0]);

					if (strncmp(&aStr[0], "#", 1) == 0)
					{// ���ǂݍ���
						fgets(&aStr[0], sizeof(aStr), pFile);
					}
					else if (strcmp(&aStr[0], "POS") == 0)
					{// ���f���̃t�@�C�����̐ݒ�
						D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%f", &pos.x);
						fscanf(pFile, "%f", &pos.y);
						fscanf(pFile, "%f", &pos.z);
						pScoreItem->SetPos(pos);
					}

					if (strstr(&aStr[0], "ROT") != NULL)
					{// ���f���̃t�@�C�����̐ݒ�
						D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%f", &rot.x);
						fscanf(pFile, "%f", &rot.y);
						fscanf(pFile, "%f", &rot.z);
						pScoreItem->SetRot(rot);
					}

					if (strcmp(&aStr[0], "TYPE") == 0)
					{// �L�[���̓ǂݍ���
						int nID = 0;
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%d", &nID);
						pScoreItem->SetType(nID);
					}

					if (strcmp(&aStr[0], "SHADOW") == 0)
					{// �L�[���̓ǂݍ���
						int nUse = 0;
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%d", &nUse);
						pModel->SetShadow(nUse);
					}

					if (strcmp(&aStr[0], "SCORE") == 0)
					{// �L�[���̓ǂݍ���
						int nScore = 0;
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%d", &nScore);
						pScoreItem->SetScore(nScore);
					}

					if (strcmp(&aStr[0], "COLLISION_POS") == 0)
					{// �L�[���̓ǂݍ���
						D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%f", &pos.x);
						fscanf(pFile, "%f", &pos.y);
						fscanf(pFile, "%f", &pos.z);
						pCollision->SetPos(pos);
					}

					if (strcmp(&aStr[0], "COLLISION_SIZE") == 0)
					{// �L�[���̓ǂݍ���
						D3DXVECTOR3 size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						fscanf(pFile, "%s", &aStr[0]);
						fscanf(pFile, "%f", &size.x);
						fscanf(pFile, "%f", &size.y);
						fscanf(pFile, "%f", &size.z);
						pCollision->SetSize(size);
					}
				}

				nCntSetModel++;
			}
		}
	}
	else
	{
		assert(false);
	}
}

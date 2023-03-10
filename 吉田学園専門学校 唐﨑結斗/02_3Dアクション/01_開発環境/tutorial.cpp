//=============================================================================
//
// �`���[�g���A���N���X(tutorial.cpp)
// Author : �������l
// �T�v : �`���[�g���A���N���X�̊Ǘ����s��
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include <assert.h>

#include "tutorial.h"
#include "calculation.h"
#include "keyboard.h"
#include "mouse.h"
#include "application.h"
#include "camera.h"
#include "renderer.h"
#include "object.h"
#include "object3D.h"
#include "player.h"
#include "motion_model3D.h"
#include "motion_enemy.h"
#include "model3D.h"
#include "mesh.h"
#include "sphere.h"
#include "bg.h"
#include "model_obj.h"
#include "weapon_obj.h"
#include "collision_rectangle3D.h"
#include "debug_proc.h"
#include "map_manager.h"
#include "score_item.h"
#include "score.h"
#include "time.h"
#include "sound.h"
#include "object2D.h"

//*****************************************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************************************
CPlayer *CTutorial::m_pPlayer = nullptr;					// �v���C���[�N���X
CScore *CTutorial::m_pScore = nullptr;						// �X�R�A�C���X�^���X
D3DXCOLOR CTutorial::fogColor;								// �t�H�O�J���[
float CTutorial::fFogStartPos;								// �t�H�O�̊J�n�_
float CTutorial::fFogEndPos;								// �t�H�O�̏I���_
float CTutorial::fFogDensity;								// �t�H�O�̖��x

//=============================================================================
// �R���X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�������ɍs������
//=============================================================================
CTutorial::CTutorial() : m_pTutorial(nullptr),
m_nCntFrame(0)
{

}

//=============================================================================
// �f�X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�I�����ɍs������
//=============================================================================
CTutorial::~CTutorial()
{

}

//=============================================================================
// ������
// Author : �������l
// �T�v : ���_�o�b�t�@�𐶐����A�����o�ϐ��̏����l��ݒ�
//=============================================================================
HRESULT CTutorial::Init()
{// �}�E�X�̎擾
	CMouse *pMouse = CApplication::GetMouse();

	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	// �T�E���h���̎擾
	CSound *pSound = CApplication::GetSound();
	pSound->PlaySound(CSound::SOUND_LABEL_BGM003);

	// �d�͂̒l��ݒ�
	CCalculation::SetGravity(0.2f);

	// �}�b�v�̐ݒ�
	CMapManager *pMap = CMapManager::Create();
	pMap->SetMap("data/FILE/map000.txt");

	// �X�J�C�{�b�N�X�̐ݒ�
	CSphere *pSphere = CSphere::Create();
	pSphere->SetRot(D3DXVECTOR3(D3DX_PI, 0.0f, 0.0f));
	pSphere->SetSize(D3DXVECTOR3(100.0f, 0, 100.0f));
	pSphere->SetBlock(CMesh3D::DOUBLE_INT(100, 100));
	pSphere->SetRadius(10000.0f);
	pSphere->SetSphereRange(D3DXVECTOR2(D3DX_PI * 2.0f, D3DX_PI * -0.5f));
	pSphere->LoadTex(1);

	// �v���C���[�̐ݒ�
	m_pPlayer = CPlayer::Create();
	m_pPlayer->SetMotion("data/MOTION/motion001.txt");
	m_pPlayer->SetPos(D3DXVECTOR3(724.0f, 0.0f, 2700.0f));

	// �X�R�A
	m_pScore = CScore::Create(10, false);
	m_pScore->SetScore(0);
	m_pScore->SetPos(D3DXVECTOR3(1280.0f, m_pScore->GetSize().y / 2.0f, 0.0f));

	// �J�����̒Ǐ]�ݒ�(�ڕW : �v���C���[)
	CCamera *pCamera = CApplication::GetCamera();
	pCamera->SetFollowTarget(m_pPlayer, 1.0);
	pCamera->SetPosVOffset(D3DXVECTOR3(0.0f, 50.0f, -200.0f));
	pCamera->SetPosROffset(D3DXVECTOR3(0.0f, 0.0f, 100.0f));
	pCamera->SetRot(D3DXVECTOR3(0.0f, D3DX_PI, 0.0f));
	pCamera->SetUseRoll(true, true);

	// �}�E�X�J�[�\��������
	pMouse->SetShowCursor(false);

	// �t�H�O�̐��l�ݒ�
	fogColor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);		// �t�H�O�J���[
	fFogStartPos = 1.0f;								// �t�H�O�̊J�n�_
	fFogEndPos = 100000.0f;								// �t�H�O�̏I���_
	fFogDensity = 0.00001f;								// �t�H�O�̖��x

	// �t�H�O�̗L���ݒ�
	pDevice->SetRenderState(D3DRS_FOGENABLE, TRUE);

	// �t�H�O�J���[�̐ݒ�
	pDevice->SetRenderState(D3DRS_FOGCOLOR, fogColor);

	// �t�H�O�͈̔͐ݒ�
	pDevice->SetRenderState(D3DRS_FOGTABLEMODE, D3DFOG_LINEAR);
	pDevice->SetRenderState(D3DRS_FOGSTART, *(DWORD*)(&fFogStartPos));
	pDevice->SetRenderState(D3DRS_FOGEND, *(DWORD*)(&fFogEndPos));

	// �t�H�O�̖��x�̐ݒ�
	pDevice->SetRenderState(D3DRS_FOGDENSITY, *(DWORD*)(&fFogDensity));

	m_pTutorial = CObject2D::Create();
	m_pTutorial->SetPos(D3DXVECTOR3(1050.0f, 320.0f, 0.0f));
	m_pTutorial->SetSize(D3DXVECTOR3(500.0f, 500.0f, 0.0f));
	m_pTutorial->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	m_pTutorial->LoadTex(22);

	m_pTutorialEnd = CObject2D::Create();
	m_pTutorialEnd->SetPos(D3DXVECTOR3(1050.0f, 600.0f, 0.0f));
	m_pTutorialEnd->SetSize(D3DXVECTOR3(500.0f, 50.0f, 0.0f));
	m_pTutorialEnd->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	m_pTutorialEnd->LoadTex(24);

	m_bTutoItem = false;

	return S_OK;
}

//=============================================================================
// �I��
// Author : �������l
// �T�v : �e�N�X�`���̃|�C���^�ƒ��_�o�b�t�@�̉��
//=============================================================================
void CTutorial::Uninit()
{// �}�E�X�̎擾
	CMouse *pMouse = CApplication::GetMouse();

	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	// �T�E���h���̎擾
	CSound *pSound = CApplication::GetSound();

	// �T�E���h�I��
	pSound->StopSound();

	// �t�H�O�̗L���ݒ�
	pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);

	// �}�E�X�J�[�\�����o��
	pMouse->SetShowCursor(true);

	// �J�����̒Ǐ]�ݒ�
	CCamera *pCamera = CApplication::GetCamera();
	pCamera->SetFollowTarget(false);
	pCamera->SetTargetPosR(false);

	// �J�����̒Ǐ]�ݒ�
	pCamera = CApplication::GetMapCamera();
	pCamera->SetFollowTarget(false);
	pCamera->SetTargetPosR(false);

	// �ÓI�ϐ��̏�����
	if (m_pPlayer != nullptr)
	{
		m_pPlayer = nullptr;
	}

	// �X�R�A�̉��
	Release();
}

//=============================================================================
// �X�V
// Author : �������l
// �T�v : �X�V���s��
//=============================================================================
void CTutorial::Update()
{
	// �J�����̒Ǐ]�ݒ�
	CCamera *pCamera = nullptr;

	// �L�[�{�[�h�̎擾
	CKeyboard *pKeyboard = CApplication::GetKeyboard();

#ifdef _DEBUG

	// �J�����̒Ǐ]�ݒ�
	pCamera = CApplication::GetCamera();

	if (pKeyboard->GetTrigger(DIK_F10))
	{
		pCamera->Shake(60, 50.0f);
	}

	if (pKeyboard->GetPress(DIK_LSHIFT))
	{
		pCamera->Zoom();
	}

#endif // _DEBUG

	if (m_bTutoItem)
	{
		m_nCntFrame--;
		m_pTutorial->SetSize(D3DXVECTOR3(500.0f, 300.0f, 0.0f));
		m_pTutorial->LoadTex(23);

		if (m_nCntFrame <= 0)
		{
			m_nCntFrame = 0;
			m_bTutoItem = false;
		}
	}
	else
	{
		m_pTutorial->SetSize(D3DXVECTOR3(500.0f, 500.0f, 0.0f));
		m_pTutorial->LoadTex(22);
	}

	if (pKeyboard->GetTrigger(DIK_F3))
	{
		CApplication::SetNextMode(CApplication::MODE_TITLE);
	}
}

//=============================================================================
// �`��
// Author : �������l
// �T�v : �`����s��
//=============================================================================
void CTutorial::Draw()
{

}

//=============================================================================
// �A�C�e���̃`���[�g���A��
// Author : �������l
// �T�v : �A�C�e���̃`���[�g���A�����g�p����
//=============================================================================
void CTutorial::SetTutoItem(bool bTutoItem)
{
	m_bTutoItem = bTutoItem;
	m_nCntFrame = 300;
}

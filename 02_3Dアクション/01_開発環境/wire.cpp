//=============================================================================
//
// ���C���[�N���X(wire.cpp)
// Author : �������l
// �T�v : ���C���[�������s��
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include <assert.h>
#include <stdio.h>

#include "wire.h"
#include "application.h"
#include "renderer.h"
#include "move.h"
#include "line.h"
#include "collision_rectangle3D.h"
#include "motion_enemy.h"
#include "calculation.h"
#include "camera.h"
#include "debug_proc.h"
#include "game.h"
#include "player.h"
#include "model3D.h"
#include "player.h"
#include "game.h"
#include "tutorial.h"

//--------------------------------------------------------------------
// �萔��`
//--------------------------------------------------------------------
const float CWire::fDECISION = 500.0f;

//=============================================================================
// �C���X�^���X����
// Author : �������l
// �T�v : �C���X�^���X�𐶐�����
//=============================================================================
CWire *CWire::Create()
{
	// �I�u�W�F�N�g�C���X�^���X
	CWire *pWire = nullptr;

	// �������̉��
	pWire = new CWire;

	// �������̊m�ۂ��ł��Ȃ�����
	assert(pWire != nullptr);

	// ���l�̏�����
	pWire->Init();

	// �C���X�^���X��Ԃ�
	return pWire;
}

//=============================================================================
// �R���X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�������ɍs������
//=============================================================================
CWire::CWire() : m_pStart(nullptr),			// �X�^�[�g�n�_
m_pGoal(nullptr),							// �S�[���n�_
m_pDecision(nullptr),						// ����p�I�u�W�F�N�g
m_pWireModel(nullptr),						// ���f�����
m_pMove(nullptr),							// �ړ����
m_pRoll(nullptr),							// ��]���
m_EMode(MODE_STOP),							// ���C���[���[�h
m_ENextMode(MODE_STOP),						// ���̃��C���[���[�h
m_quat(),									// �N�H�[�^�j�I��
m_move(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),		// �ړ�
m_moveVec(D3DXVECTOR3(0.0f,0.0f,0.0f)),		// �ړ��x�N�g��
m_rot(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),		// ����
m_rotDest(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),	// �ړI�̌���
m_rotVec(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),	// �����x�N�g��
m_fLength(0.0f),							// ����
m_fAddRot(0.0f),							// ���Z
m_fAccele(0.0f)								// �p�����x
{// ���[���h�}�g���b�N�X
	D3DXMatrixIdentity(&m_mtxWorld);

	// ��]�}�g���b�N�X
	D3DXMatrixIdentity(&m_mtxRot);							
}

//=============================================================================
// �f�X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�I�����ɍs������
//=============================================================================
CWire::~CWire()
{

}

//=============================================================================
// ������
// Author : �������l
// �T�v : ���_�o�b�t�@�𐶐����A�����o�ϐ��̏����l��ݒ�
//=============================================================================
HRESULT CWire::Init()
{
	// ���C���[�̏�����
	CModelObj::Init();

	// �I�u�W�F�N�g�̃^�C�v�ݒ�
	SetObjType(CObject::OBJETYPE_WIRE);

	// �����蔻��
	CCollision_Rectangle3D *m_pCollision = nullptr;

	// �X�^�[�g�n�_
	m_pStart = CModelObj::Create();
	m_pStart->SetObjType(CObject::OBJETYPE_WIRE);
	m_pCollision = m_pStart->GetCollision();
	m_pCollision->SetSize(D3DXVECTOR3(10.0f, 10.0f, 10.0f));

	// �S�[���n�_
	m_pGoal = CModelObj::Create();
	m_pGoal->SetObjType(CObject::OBJETYPE_WIRE);
	m_pCollision = m_pGoal->GetCollision();
	m_pCollision->SetSize(D3DXVECTOR3(10.0f, 10.0f, 10.0f));

	// ����p�I�u�W�F�N�g
	m_pDecision = CModelObj::Create();
	m_pDecision->SetObjType(CObject::OBJETYPE_WIRE);
	m_pCollision = m_pDecision->GetCollision();
	m_pCollision->SetSize(D3DXVECTOR3(600.0f, 10.0f, 600.0f));

	// �ړ��N���X�̃������m��
	m_pMove = new CMove;
	assert(m_pMove != nullptr);
	m_pMove->SetMoving(60.0f, 1000.0f, 0.0f, 0.01f);

	// ��]�N���X�̃������m��
	m_pRoll = new CMove;
	assert(m_pRoll != nullptr);
	m_pRoll->SetMoving(10.0f, 1000.0f, 0.0f, 0.01f);

	// ���C���[���f��
	m_pWireModel = CModel3D::Create();
	m_pWireModel->SetModelID(38);
	m_pWireModel->SetLighting(false);
	m_pWireModel->SetShadow(false);

	return E_NOTIMPL;
}

//=============================================================================
// �I��
// Author : �������l
// �T�v : �e�N�X�`���̃|�C���^�ƒ��_�o�b�t�@�̉��
//=============================================================================
void CWire::Uninit()
{
	if (m_pStart != nullptr)
	{// �I��
		m_pStart->Uninit();
		m_pStart = nullptr;
	}

	if (m_pGoal != nullptr)
	{// �I��
		m_pGoal->Uninit();
		m_pGoal = nullptr;
	}

	if (m_pDecision != nullptr)
	{// �I��
		m_pDecision->Uninit();
		m_pDecision = nullptr;
	}

	if (m_pWireModel != nullptr)
	{// �I��
		m_pWireModel->Uninit();
		m_pWireModel = nullptr;
	}

	if (m_pMove != nullptr)
	{// �������̉��
		delete m_pMove;
		m_pMove = nullptr;
	}

	if (m_pRoll != nullptr)
	{// �������̉��
		delete m_pRoll;
		m_pRoll = nullptr;
	}

	// ���C���[�̏I��
	CModelObj::Uninit();

	// �I�u�W�F�N�g�̉��
	Release();
}

//=============================================================================
// �X�V
// Author : �������l
// �T�v : �X�V���s��
//=============================================================================
void CWire::Update()
{
	if (m_EMode == MODE_HANGING)
	{
		Hanging();
	}
	else
	{// �ړ�
		Move();
	}

	// �����蔻��
	CCollision_Rectangle3D *pCollision = nullptr;
	m_ETargetObjType = CObject::OBJTYPE_NONE;

	switch (m_EMode)
	{
	case CWire::MODE_STOP:
		break;

	case CWire::MODE_FIRING:
		pCollision = m_pGoal->GetCollision();

		if (pCollision->Collision(CObject::OBJETYPE_ENEMY, false))
		{
			m_EMode = MODE_PULL;
			m_pMove->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			D3DXVECTOR3 vec = GetStart()->GetPos() - GetGoal()->GetPos();
			D3DXVec3Normalize(&vec, &vec);
			SetMoveVec(vec);

			// �ړ�
			Move();

			CMotionEnemy *pEnemy = (CMotionEnemy*)pCollision->GetCollidedObj();
			CMove *pMoveEnemy = pEnemy->GetMove();
			pMoveEnemy->SetMove(m_pMove->GetMove());
		}
		if (pCollision->Collision(CObject::OBJTYPE_3DMODEL, false))
		{
			m_EMode = MODE_STOP;
			m_ETargetObjType = OBJTYPE_3DMODEL;
		}

		break;

	case CWire::MODE_ATTRACT:
	case CWire::MODE_PULL:
		pCollision = m_pGoal->GetCollision();

		if (pCollision->Collision(CObject::OBJETYPE_WIRE, false))
		{
			m_EMode = MODE_STOP;
			SetPos(m_pStart->GetPos());
		}

		break;

	case CWire::MODE_HANGING:
		break;

	default:
		assert(false);
		break;
	}

	CDebugProc::Print("���C���[�̌��� : %.3f\n", m_rot.x / D3DX_PI);

	// ���C���[�̍X�V
	CModelObj::Update();

	// �����̐ݒ�
	D3DXVECTOR3 vec = m_pGoal->GetPos() - m_pStart->GetPos();
	D3DXVECTOR3 rotWire = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	rotWire.x = atan2f(sqrtf((vec.x * vec.x) + (vec.z * vec.z)) , vec.y);
	rotWire.y = atan2f(vec.x, vec.z);
	m_pWireModel->SetRot(rotWire);

	// �T�C�Y�̐ݒ�
	m_pWireModel->SetSize(D3DXVECTOR3(1.0f, m_fLength, 1.0f));

	// ���f���̍X�V
	m_pWireModel->Update();
}

//=============================================================================
// �`��
// Author : �������l
// �T�v : �`����s��
//=============================================================================
void CWire::Draw()
{
	// ���C���[�̕`��
	CModelObj::Draw();

	if (m_EMode == MODE_HANGING)
	{
		// �ʒu�̎擾
		D3DXVECTOR3 pos = m_pGoal->GetPos();

		// �f�o�C�X�̎擾
		LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

		// �v�Z�p�}�g���b�N�X
		D3DXMATRIX mtxRot, mtxTrans;

		// ���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&m_mtxWorld);									// �s�񏉊����֐�

		// �N�H�[�^�j�I���̍쐬
		D3DXQuaternionRotationAxis(&m_quat, &m_vecAxis, m_fValueRot);

		// �����̔��f
		D3DXMatrixRotationQuaternion(&mtxRot, &m_quat);
		D3DXMatrixMultiply(&m_mtxRot, &m_mtxRot, &mtxRot);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &m_mtxRot);

		// �ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, pos.x, pos.y, pos.z);				// �s��ړ��֐�
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);			// �s��|���Z�֐�

		// ���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
	}
	else
	{
		// ���[���h�}�g���b�N�X
		D3DXMatrixIdentity(&m_mtxWorld);

		// ��]�}�g���b�N�X
		D3DXMatrixIdentity(&m_mtxRot);
	}

	// ���f���̕`��
	m_pWireModel->Draw(m_pStart->GetMtxWorld());
}

//=============================================================================
// �ʒu�̐ݒ�
// Author : �������l
// �T�v : �ʒu��ݒ肷��
//=============================================================================
void CWire::SetPos(const D3DXVECTOR3 & pos)
{
	m_pStart->SetPos(pos);
	m_pDecision->SetPos(D3DXVECTOR3(pos.x, pos.y + fDECISION, pos.z));
	m_pGoal->SetPos(pos);
	CModelObj::SetPos(pos);
}

//=============================================================================
// �ړ�
// Author : �������l
// �T�v : �ړ����������肵
//=============================================================================
void CWire::Move()
{
	// �ʒu
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	switch (m_EMode)
	{
	case CWire::MODE_STOP:
		break;

	case CWire::MODE_FIRING:
	case CWire::MODE_PULL:
		pos = m_pGoal->GetPos();
		break;

	case CWire::MODE_ATTRACT:
		pos = m_pStart->GetPos();
		break;

	default:
		assert(false);
		break;
	}

	// �ړ����
	m_pMove->Moving(m_moveVec);
	pos += m_pMove->GetMove();

	// �����x�N�g��
	D3DXVECTOR3 vec = GetGoal()->GetPos() - GetStart()->GetPos();

	switch (m_EMode)
	{
	case CWire::MODE_STOP:
		m_fLength = 0.0f;
		m_pWireModel->SetSize(D3DXVECTOR3(0.0f,0.0f,0.0f));
		m_pMove->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		break;

	case CWire::MODE_FIRING:
	case CWire::MODE_PULL:
		m_pGoal->SetPos(pos);

		// �����̐ݒ�
		m_fLength = sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));

		if (m_fLength >= 1000.0f)
		{
			m_EMode = MODE_STOP;
		}

		break;

	case CWire::MODE_ATTRACT:
		m_pStart->SetPos(pos);
		m_pDecision->SetPos(D3DXVECTOR3(pos.x, pos.y + fDECISION, pos.z));
		break;

	default:
		break;
	}

	// �ړ��x�N�g���̃��Z�b�g
	m_moveVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//=============================================================================
// �Ԃ牺���菈��
// Author : �������l
// �T�v : 
//=============================================================================
void CWire::Hanging()
{
	// �ʒu
	D3DXVECTOR3 pos = m_pStart->GetPos();
	D3DXVECTOR3 posGoal = m_pGoal->GetPos();
	D3DXVECTOR3 move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//�p�����x
	m_fAccele = (-1 * 0.6f / m_fLength) * sinf(m_rot.x);

	CApplication::SCENE_MODE mode = CApplication::GetMode();
	CPlayer *pPlayer = nullptr;

	if (mode == CApplication::MODE_GAME)
	{
		pPlayer = CGame::GetPlayer();
	}
	else if (mode == CApplication::MODE_TUTORIAL)
	{
		pPlayer = CTutorial::GetPlayer();
	}

	// �p�x�̉��Z
	m_fAddRot += m_fAccele;
	m_fAddRot *= 0.9995f;
	m_rot.x += m_fAddRot;
	//m_rot.y += m_fAddRot;
	m_rot.x = CCalculation::RotNormalization(m_rot.x);
	m_rot.y = pPlayer->GetRot().y;

	// �ʒu�̐ݒ�
	pos.z = posGoal.z - sinf(m_rot.x) * cosf(m_rot.y) * m_fLength;
	pos.x = posGoal.x - sinf(m_rot.x) * sinf(m_rot.y) * m_fLength;
	pos.y = posGoal.y - cosf(m_rot.x) * m_fLength;

	m_pStart->SetPos(pos);

	float fLimit = 0.5f;

	if ((m_rot.x >= D3DX_PI * fLimit  && m_rot.x >= D3DX_PI * 0.0f))
	{
		m_EMode = MODE_STOP;
		pPlayer->Dash();
	}
}

//=============================================================================
// ���[�h�̐ݒ�
// Author : �������l
// �T�v : 
//=============================================================================
void CWire::SetWireMode(WIRE_MODE EWireMode)
{
	m_EMode = EWireMode;
	m_pMove->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
}

//=============================================================================
// �����̐ݒ�
// Author : �������l
// �T�v : 
//=============================================================================
void CWire::SetHanging()
{
	// �J�������̎擾
	CCamera *pCamera = CApplication::GetCamera();

	//// �ړ������̎Z�o
	//m_rotDest.y = pCamera->GetRot().y + D3DX_PI;

	//// �ړ������̐��K��
	//m_rotDest.y = CCalculation::RotNormalization(m_rotDest.y - m_rot.y);

	//// �����̍X�V
	//m_rot.y += (m_rotDest.y - m_rot.y) * 0.01f;

	//// �����̐��K��
	//m_rot.y = CCalculation::RotNormalization(m_rot.y);

	//// �ړ������̐ݒ�
	//m_rotVec = D3DXVECTOR3(sinf(m_rot.y), 0.0f, cosf(m_rot.y));

	CApplication::SCENE_MODE mode = CApplication::GetMode();

	float fRot = 0.0f;

	if (mode == CApplication::MODE_GAME)
	{
		fRot = CGame::GetPlayer()->GetRot().y;
	}
	else if (mode == CApplication::MODE_TUTORIAL)
	{
		fRot = CTutorial::GetPlayer()->GetRot().y;
	}

	// �����x�N�g��
	D3DXVECTOR3 vec = GetGoal()->GetPos() - GetStart()->GetPos();

	m_rot.x = -atan2f(sqrtf((vec.x * vec.x) + (vec.z * vec.z)), vec.y);
	m_rot.y = fRot;
	m_rot.x = CCalculation::RotNormalization(m_rot.x);
	m_rot.y = CCalculation::RotNormalization(m_rot.y);

	// �����̐ݒ�
	m_fLength = sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	m_fAddRot = 0.0f;
}

//=============================================================================
// �����x�N�g���̐ݒ�
// Author : �������l
// �T�v : 
//=============================================================================
void CWire::SetRotVec(D3DXVECTOR3 rotVec)
{
	m_rotVec = rotVec;
	m_pRoll->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
}

//=============================================================================
// �Ԃ牺����ꏊ�̐ݒ�
// Author : �������l
// �T�v : 
//=============================================================================
D3DXVECTOR3 CWire::HangingSearch()
{
	// �Ԃ�l�̒�`
	D3DXVECTOR3 vec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// �����蔻��
	CCollision_Rectangle3D *pCollision = m_pDecision->GetCollision();

	if (pCollision->Collision(CObject::OBJTYPE_3DMODEL, false))
	{
		CModelObj *pModel = (CModelObj*)pCollision->GetCollidedObj();

		// ���̎擾
		D3DXVECTOR3 posTarget = pModel->GetPos();
		posTarget.y = m_pDecision->GetPos().y;
		D3DXVECTOR3 pos = m_pStart->GetPos();

		// �����x�N�g���̎Z�o
		vec = posTarget - pos;
	}

	// ���K��
	D3DXVec3Normalize(&vec, &vec);

	return vec;
}

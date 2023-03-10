//=============================================================================
//
// ���f���I�u�W�F�N�g�N���X(model_obj.cpp)
// Author : �������l
// �T�v : ���f���I�u�W�F�N�g�������s��
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include <assert.h>
#include <stdio.h>

#include "weapon_obj.h"
#include "application.h"
#include "renderer.h"
#include "model3D.h"
#include "collision_rectangle3D.h"

//=============================================================================
// �C���X�^���X����
// Author : �������l
// �T�v : �C���X�^���X�𐶐�����
//=============================================================================
CWeaponObj * CWeaponObj::Create()
{
	// �I�u�W�F�N�g�C���X�^���X
	CWeaponObj *pWeaponObj = nullptr;

	// �������̉��
	pWeaponObj = new CWeaponObj;

	// �������̊m�ۂ��ł��Ȃ�����
	assert(pWeaponObj != nullptr);

	// ���l�̏�����
	pWeaponObj->Init();

	// �C���X�^���X��Ԃ�
	return pWeaponObj;
}

//=============================================================================
// �R���X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�������ɍs������
//=============================================================================
CWeaponObj::CWeaponObj() : m_pParent(nullptr),		// �e�I�u�W�F�N�g�̏��
m_weaponType(WEAPONTYPE_NONE),						// ����̎��
m_posOffset(D3DXVECTOR3(0.0f,0.0f,0.0f)),			// �ʒu�̍���
m_rotOffset(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),			// �����̍���
m_colliSize(D3DXVECTOR3(0.0f, 0.0f, 0.0f)),			// �����蔻��̑傫��
m_nAttack(0)										// �U����
{

}

//=============================================================================
// �f�X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�I�����ɍs������
//=============================================================================
CWeaponObj::~CWeaponObj()
{

}

//=============================================================================
// ������
// Author : �������l
// �T�v : ���_�o�b�t�@�𐶐����A�����o�ϐ��̏����l��ݒ�
//=============================================================================
HRESULT CWeaponObj::Init()
{
	// ���f���I�u�W�F�N�g�̏�����
	CModelObj::Init();

	// �I�u�W�F�N�g�̃^�C�v�ݒ�
	SetObjType(OBJETYPE_WEAPON);

	return E_NOTIMPL;
}

//=============================================================================
// �I��
// Author : �������l
// �T�v : �e�N�X�`���̃|�C���^�ƒ��_�o�b�t�@�̉��
//=============================================================================
void CWeaponObj::Uninit()
{
	// ���f���I�u�W�F�N�g�̏I��
	CModelObj::Uninit();

	// �I�u�W�F�N�g�̉��
	Release();
}

//=============================================================================
// �X�V
// Author : �������l
// �T�v : �X�V���s��
//=============================================================================
void CWeaponObj::Update()
{
	// ���f���I�u�W�F�N�g�̍X�V
	CModelObj::Update();
}

//=============================================================================
// �`��
// Author : �������l
// �T�v : �`����s��
//=============================================================================
void CWeaponObj::Draw()
{
	// ���̎擾
	D3DXMATRIX mtxWorld = GetMtxWorld();
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 rot = GetRot();
	CModel3D *pModel = GetModel();

	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	// �v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;

	// ���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&mtxWorld);											// �s�񏉊����֐�

	if (m_pParent != nullptr)
	{// �����̔��f
		D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rotOffset.y, m_rotOffset.x, m_rotOffset.z);			// �s���]�֐�
		D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxRot);												// �s��|���Z�֐� 

		// �ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, m_posOffset.x, m_posOffset.y, m_posOffset.z);					// �s��ړ��֐�
		D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxTrans);											// �s��|���Z�֐�

		// �e�̃��[���h�}�b�g���b�N�X
		D3DXMATRIX mtxParent = m_pParent->GetMtxWorld();

		// �s��|���Z�֐�
		D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxParent);

		// �ʒu�̐ݒ�
		D3DXVec3TransformCoord(&pos, &D3DXVECTOR3(0.0f, 0.0f, 0.0f), &mtxWorld);
		SetPos(pos);
	}
	else
	{// �����̔��f
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rot.y, rot.x, rot.z);			// �s���]�֐�
		D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxRot);						// �s��|���Z�֐� 

		// �ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, pos.x, pos.y, pos.z);					// �s��ړ��֐�
		D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxTrans);					// �s��|���Z�֐�
	}

	// ���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);

	// ���f���̕`��
	pModel->Draw(mtxWorld);
	SetMtxWorld(mtxWorld);
}

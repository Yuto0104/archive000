//=============================================================================
//
// �X�t�B�A�N���X(sphere.cpp)
// Author : �������l
// �T�v : �X�t�B�A�������s��
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include <assert.h>

#include "wave_mesh.h"
#include "calculation.h"
#include "renderer.h"
#include "application.h"

//=============================================================================
// �C���X�^���X����
// Author : �������l
// �T�v : �X�t�B�A�𐶐�����
//=============================================================================
CWaveMesh * CWaveMesh::Create(void)
{
	// �X�t�B�A�C���X�^���X
	CWaveMesh *pWaveMesh = nullptr;

	// �������̉��
	pWaveMesh = new CWaveMesh;

	// �������̊m�ۂ��ł��Ȃ�����
	assert(pWaveMesh != nullptr);

	// ���l�̏�����
	pWaveMesh->Init();

	// �C���X�^���X��Ԃ�
	return pWaveMesh;
}

//=============================================================================
// �R���X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�������ɍs������
//=============================================================================
CWaveMesh::CWaveMesh()
{

}

//=============================================================================
// �f�X�g���N�^
// Author : �������l
// �T�v : �C���X�^���X�I�����ɍs������
//=============================================================================
CWaveMesh::~CWaveMesh()
{

}

//=============================================================================
// �X�V
// Author : �������l
// �T�v : 2D�X�V���s��
//=============================================================================
void CWaveMesh::Update()
{// �g
	Wave();

	// �X�V
	CMesh3D::Update();
}

//=============================================================================
// �g
// Author : �������l
// �T�v : �g�̓���������
//=============================================================================
void CWaveMesh::Wave()
{
	// ���̎擾
	DOUBLE_INT line = GetLine();

	// ���_���̎擾
	VERTEX_3D *pVtx = NULL;

	// ���_�o�b�t�@�����b�N
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntZ = 0; nCntZ < line.y; nCntZ++)
	{
		for (int nCntX = 0; nCntX < line.x; nCntX++)
		{// �ϐ��錾
			int nCntVtx = nCntX + (nCntZ *  line.x);

			m_fVtxHeight[nCntVtx] += m_fAddWave;

			// ���_���W�̐ݒ�
			pVtx[nCntVtx].pos.y = sinf(m_fVtxHeight[nCntVtx]) * m_fAmplitude;
		}
	}

	Normal();

	// ���_�o�b�t�@�̃A�����b�N
	m_pVtxBuff->Unlock();
}

//=============================================================================
// ���_���W�Ȃǂ̐ݒ�
// Author : �������l
// �T�v : 3D���_���W�Arhw�A���_�J���[��ݒ肷��
//=============================================================================
void CWaveMesh::SetVtx()
{
	// ���̎擾
	DOUBLE_INT line = GetLine();
	D3DXVECTOR3 size = GetSize();
	D3DXVECTOR3 blockSize = GetBlockSize();

	// ���_���̎擾
	VERTEX_3D *pVtx = NULL;

	// ���_�o�b�t�@�����b�N
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntZ = 0; nCntZ < line.y; nCntZ++)
	{
		for (int nCntX = 0; nCntX < line.x; nCntX++)
		{// �ϐ��錾
			int nCntVtx = nCntX + (nCntZ * line.x);

			// ���_���W�̐ݒ�
			pVtx[nCntVtx].pos.x = (nCntVtx % line.x * blockSize.x) - size.x / 2.0f;
			pVtx[nCntVtx].pos.y = sinf((m_fVtxHeight[nCntVtx]) * D3DX_PI / 180) * 50.0f;
			pVtx[nCntVtx].pos.z = (nCntVtx / line.x * -blockSize.z) + size.z / 2.0f;
		}
	}

	// ���_�o�b�t�@�̃A�����b�N
	m_pVtxBuff->Unlock();
}

//=============================================================================
// �g�̐ݒ�
// Author : �������l
// �T�v : �g�̐ݒ�
//=============================================================================
void CWaveMesh::SetWave(const float fAddWave, const float fAmplitude)
{
	// ���̎擾
	DOUBLE_INT line = GetLine();

	// �ǉ�����g�̑傫���̐ݒ�
	m_fAddWave = fAddWave * D3DX_PI / 180.0f;

	// �U���̐ݒ�
	m_fAmplitude = fAmplitude;

	for (int nCntZ = 0; nCntZ < line.y; nCntZ++)
	{
		for (int nCntX = 0; nCntX < line.x; nCntX++)
		{// �ϐ��錾
			int nCntVtx = nCntX + (nCntZ *  line.x);

			m_fVtxHeight[nCntVtx] = nCntZ * m_fAddWave + m_fAddWave;
		}
	}

	// ���_���W�Ȃǂ̐ݒ�
	SetVtx();

	// �C���f�b�N�X�̐ݒ�
	SetIndexBuff();

	// �@���̌v�Z
	Normal();
}


//=============================================================================
//
// ���C���[����(wire.h)
// Author : �������l
// �T�v : ���C���[�������s��
//
//=============================================================================
#ifndef _WIRE_H_		// ���̃}�N����`������ĂȂ�������
#define _WIRE_H_		// ��d�C���N���[�h�h�~�̃}�N����`

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "model_obj.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CMove;

//=============================================================================
// ���C���[�N���X
// Author : �������l
// �T�v : ���C���[�������s���N���X
//=============================================================================
class CWire : public CModelObj
{
public:
	//--------------------------------------------------------------------
	// �萔��`
	//--------------------------------------------------------------------
	static const float fDECISION;

	//--------------------------------------------------------------------
	// ���C���[���[�h�̗񋓌^
	//--------------------------------------------------------------------
	enum WIRE_MODE
	{
		MODE_STOP = 0,		// ��~
		MODE_FIRING,		// �ˏo
		MODE_ATTRACT,		// ������
		MODE_HANGING,		// �Ԃ牺����
		MODE_PULL,			// ��������
	};

	//--------------------------------------------------------------------
	// �ÓI�����o�֐�
	//--------------------------------------------------------------------
	static CWire *Create(void);				// �I�u�W�F�N�g�̐���

	//--------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//--------------------------------------------------------------------
	explicit CWire();
	~CWire();

	//--------------------------------------------------------------------
	// �����o�֐�
	//--------------------------------------------------------------------
	HRESULT Init() override;												// ������
	void Uninit() override;													// �I��
	void Update() override;													// �X�V
	void Draw() override;													// �`��
	void SetPos(const D3DXVECTOR3 &pos) override;							// �ʒu�̐ݒ�
	CMove *GetMove() { return m_pMove; }									// �ړ����̎擾
	void SetMoveVec(D3DXVECTOR3 moveVec) { m_moveVec = moveVec; }			// �ړ������̐ݒ�
	void SetWireMode(WIRE_MODE EWireMode);									// ���C���[���[�h�̐ݒ�
	CModelObj *GetStart() { return m_pStart; }								// �X�^�[�g�n�_
	CModelObj *GetGoal() { return m_pGoal; }								// �S�[���n�_
	WIRE_MODE GetWireMode() { return m_EMode; }								// ���C���[���[�h�̎擾
	CObject::EObjectType GetTargetObjType() { return m_ETargetObjType; }	// ���������I�u�W�F�N�g�^�C�v�̎擾
	void SetHanging();
	void SetRotVec(D3DXVECTOR3 rotVec);
	D3DXVECTOR3 GetMoveing() { return m_move; }
	D3DXVECTOR3 HangingSearch();

private:
	//--------------------------------------------------------------------
	// �����o�֐�
	//--------------------------------------------------------------------
	void Move();		// �ړ�
	void Hanging();

	//--------------------------------------------------------------------
	// �����o�ϐ�
	//--------------------------------------------------------------------
	CModelObj *m_pStart;						// �X�^�[�g�n�_
	CModelObj *m_pGoal;							// �S�[���n�_
	CModelObj *m_pDecision;						// ����p�I�u�W�F�N�g
	CModel3D *m_pWireModel;						// ���f�����
	CMove *m_pMove;								// �ړ����
	CMove *m_pRoll;								// ��]���
	WIRE_MODE m_EMode;							// ���C���[���[�h
	WIRE_MODE m_ENextMode;						// ���̃��C���[���[�h
	CObject::EObjectType m_ETargetObjType;		// �^�[�Q�b�g�̃I�u�W�F�N�g�^�C�v
	D3DXMATRIX m_mtxWorld;						// ���[���h�}�g���b�N�X
	D3DXMATRIX m_mtxRot;						// ��]�}�g���b�N�X
	D3DXQUATERNION m_quat;						// �N�H�[�^�j�I��
	D3DXVECTOR3 m_move;							// �ړ�
	D3DXVECTOR3 m_moveVec;						// �ړ��x�N�g��
	D3DXVECTOR3 m_rot;							// ����
	D3DXVECTOR3 m_rotDest;						// �ړI�̌���
	D3DXVECTOR3 m_rotVec;						// �����x�N�g��
	D3DXVECTOR3 m_vecAxis;						// ��]��
	float m_fValueRot;							// ��]�p
	float m_fLength;							// ����
	float m_fAddRot;							// ���Z
	float m_fAccele;							// �p�����x
};

#endif






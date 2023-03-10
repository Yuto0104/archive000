//=============================================================================
//
// ����N���X(weapon_obj.h)
// Author : �������l
// �T�v : ���퐶�����s��
//
//=============================================================================
#ifndef _WEAPON_OBJ_H_			// ���̃}�N����`������ĂȂ�������
#define _WEAPON_OBJ_H_			// ��d�C���N���[�h�h�~�̃}�N����`

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "model_obj.h"

//=============================================================================
// ���f���I�u�W�F�N�g�N���X
// Author : �������l
// �T�v : ���f���I�u�W�F�N�g�������s���N���X
//=============================================================================
class CWeaponObj : public CModelObj
{
public:
	//--------------------------------------------------------------------
	// ����̎�ʂ̗񋓌^
	// Author : �������l
	// �T�v : ����̎�ʏ����i�[
	//--------------------------------------------------------------------
	enum EWeaponType
	{
		WEAPONTYPE_NONE = 0,		// �^�C�v����
		WEAPONTYPE_KNIFE,			// �i�C�t
		MAX_WEAPONTYPE,				// ��ʂ̍ő吔
	};

	//--------------------------------------------------------------------
	// �ÓI�����o�֐�
	//--------------------------------------------------------------------
	static CWeaponObj *Create();							// ���f���I�u�W�F�N�g�̐���

	//--------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//--------------------------------------------------------------------
	CWeaponObj();
	~CWeaponObj();

	//--------------------------------------------------------------------
	// �����o�֐�
	//--------------------------------------------------------------------
	HRESULT Init() override;														// ������
	void Uninit() override;															// �I��
	void Update() override;															// �X�V
	void Draw() override;															// �`��
	void SetParent(CModel3D *pParent) { m_pParent = pParent; }						// �e�̐ݒ�
	void SetParent() { m_pParent = nullptr; }										// �e�̐ݒ����
	void SetWeaponType(EWeaponType weaponType) { m_weaponType = weaponType; }		// ����̃^�C�v�̐ݒ�
	void SetPosOffset(D3DXVECTOR3 posOffset) { m_posOffset = posOffset; }			// �ʒu�̍����̐ݒ�
	void SetRotOffset(D3DXVECTOR3 rotOffset) { m_rotOffset = rotOffset; }			// �����̍����̐ݒ�
	void SetAttack(const int nAttack) { m_nAttack = nAttack; }						// �U���͂̐ݒ�
	EWeaponType GetWeaponType() { return m_weaponType; }							// ����̃^�C�v�̎擾
	int GetAttack() { return m_nAttack; }											// �U���͂̎擾

private:
	//--------------------------------------------------------------------
	// �����o�ϐ�
	//--------------------------------------------------------------------
	CModel3D *m_pParent;			// �e���f���̏��
	EWeaponType m_weaponType;		// ����̎��
	D3DXVECTOR3 m_posOffset;		// �ʒu�̍���
	D3DXVECTOR3 m_rotOffset;		// �����̍���
	D3DXVECTOR3 m_colliSize;		// �����蔻��̑傫��
	int m_nAttack;					// �U����
};

#endif


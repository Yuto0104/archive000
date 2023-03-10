//=============================================================================
//
// 2D?G?l?~?[(enemy2D.cpp)
// Author : ???????l
// ?T?v : 2D?G?l?~?[???????s??
//
//=============================================================================

//*****************************************************************************
// ?C???N???[?h
//*****************************************************************************
#include <assert.h>

#include "enemy2D.h"
#include "renderer.h"
#include "application.h"

#include "bullet2D.h"

//=============================================================================
// ?C???X?^???X????
// Author : ???????l
// ?T?v : 2D?o???b?g?𐶐?????
//=============================================================================
CEnemy2D * CEnemy2D::Create(const D3DXVECTOR3 &pos, const D3DXVECTOR3 &rot, const float fSpeed)
{
	// ?I?u?W?F?N?g?C???X?^???X
	CEnemy2D *pEnemy2D = nullptr;

	pEnemy2D = new CEnemy2D;

	if (pEnemy2D != nullptr)
	{// ???l?̏?????
		pEnemy2D->Init();
		pEnemy2D->SetPos(pos);
		pEnemy2D->SetRot(rot);
		pEnemy2D->m_fSpeed = fSpeed;
	}
	else
	{// ???????̊m?ۂ??ł??Ȃ?????
		assert(false);
	}

	// ?C???X?^???X???Ԃ?
	return pEnemy2D;
}

//=============================================================================
// ?R???X?g???N?^
// Author : ???????l
// ?T?v : ?C???X?^???X???????ɍs??????
//=============================================================================
CEnemy2D::CEnemy2D()
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fSpeed = 0.0f;
	m_nCntShot = 0;
	SetObjType(CObject::OBJTYPE_2DENEMY);				// ?I?u?W?F?N?g?̎??ʐݒ?
}

//=============================================================================
// ?f?X?g???N?^
// Author : ???????l
// ?T?v : ?C???X?^???X?I?????ɍs??????
//=============================================================================
CEnemy2D::~CEnemy2D()
{

}

//=============================================================================
// ??????
// Author : ???????l
// ?T?v : 
//=============================================================================
HRESULT CEnemy2D::Init()
{
	// ?I?u?W?F?N?g2D?̏?????
	CObject2D::Init();

	// ?e?N?X?`???̐ݒ?
	LoadTex(4);

	// ?T?C?Y
	D3DXVECTOR3 size = GetSize();
	size = D3DXVECTOR3(100.0f, 100.0f, 0.0f);
	SetSize(size);

	// ?e?N?X?`?????W?̐ݒ?
	SetTex(D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(1.0f, 1.0f));

	return S_OK;
}

//=============================================================================
// ?I??
// Author : ???????l
// ?T?v : ?e?N?X?`???̃|?C???^?ƒ??_?o?b?t?@?̉???
//=============================================================================
void CEnemy2D::Uninit()
{
	// ?I?u?W?F?N?g2D?̏I??
	CObject2D::Uninit();
}

//=============================================================================
// ?X?V
// Author : ???????l
// ?T?v : 2D?|???S???̍X?V???s??
//=============================================================================
void CEnemy2D::Update()
{
	// ?I?u?W?F?N?g2D?̍X?V
	CObject2D::Update();

	// ?ړ?
	D3DXVECTOR3 pos = GetPos();
	SetPosOld(pos);
	pos -= Move();
	SetPos(pos);

	m_nCntShot++;

	if (m_nCntShot % 180 == 0)
	{
		CBullet2D::Create(pos, D3DXVECTOR3(0.0f,0.0f,D3DX_PI * 0.5f), 5.0f);
	}

	// ?e?N?X?`?????W?̐ݒ?
	SetTex(D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(1.0f, 1.0f));
}

//=============================================================================
// ?`??
// Author : ???????l
// ?T?v : 2D?|???S???̕`?????s??
//=============================================================================
void CEnemy2D::Draw()
{// ?v???C???[2D?̕`??
	CObject2D::Draw();
}

//=============================================================================
// ?ړ?
// Author : ???????l
// ?T?v : ???x?ƕ????????????ړ??ʂ??Z?o???Ԃ?
//=============================================================================
D3DXVECTOR3 CEnemy2D::Move(void)
{
	// ?ړ??ʂ̎Z?o
	D3DXVECTOR3 rot = GetRot();
	m_move.x = sinf(rot.z) * m_fSpeed;
	m_move.y = cosf(rot.z) * m_fSpeed;

	return m_move;
}

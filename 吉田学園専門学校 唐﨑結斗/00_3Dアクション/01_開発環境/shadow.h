//**************************************************************************************************
//
// e`ζ(shadow.h)
// AutherFϊ±l
//
//**************************************************************************************************
#ifndef _SHADOW_H_			// ±Μ}Nθ`ͺ³κΔΘ©Α½η
#define _SHADOW_H_			// ρdCN[hh~Μ}Nθ`

//***************************************************************************
// CN[h
//***************************************************************************
#include "main.h"

//***************************************************************
// |S\’Μπθ`
//***************************************************************
typedef struct
{
	D3DXVECTOR3		pos;			// Κu
	D3DXVECTOR3		rot;			// ό«
	D3DXMATRIX		mtxWorld;		// [h}gbNX
	D3DXVECTOR3		size;			// ε«³
	bool			bUse;			// gpσ΅
}Shadow;

//***************************************************************
// vg^CvιΎ
//***************************************************************
// §δΦ
void	InitShadow		(void);
void	UninitShadow	(void);
void	UpdateShadow	(void);
void	DrawShadow		(void);

// §δΦ
int		SetShadow				(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size);
void	SetPositionShadow		(int nIdxShadow, D3DXVECTOR3 pos, D3DXVECTOR3 rot,D3DXVECTOR3 size);
void	DeleteShadow			(int nIdxShadow);

#endif

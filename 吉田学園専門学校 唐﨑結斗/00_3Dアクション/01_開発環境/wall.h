//**************************************************************************************************
//
// Η`ζ(wall.h)
// AutherFϊ±l
//
//**************************************************************************************************
#ifndef _WALL_H_			// ±Μ}Nθ`ͺ³κΔΘ©Α½η
#define _WALL_H_			// ρdCN[hh~Μ}Nθ`

//***************************************************************************
// CN[h
//***************************************************************************
#include "main.h"

//***************************************************************
// Η\’Μπθ`
//***************************************************************
typedef struct
{
	D3DXVECTOR3		pos;			// Κu
	D3DXVECTOR3		rot;			// ό«
	D3DXVECTOR3		aVecLine;		// ΗΜxNg
	D3DXMATRIX		mtxWorld;		// [h}gbNX
	D3DXCOLOR		col;			// J[
	bool			bUse;			// gpσ΅
}Wall;

//***************************************************************
// vg^CvιΎ
//***************************************************************
// §δΦ
void	InitWall		(void);
void	UninitWall		(void);
void	UpdateWall		(void);
void	DrawWall		(void);

// §δΦ
void	SetWall					(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXCOLOR col);
bool	CollisionWallBillBoard	(D3DXVECTOR3 *pos, D3DXVECTOR3 *posOld,int nIdx);

#endif


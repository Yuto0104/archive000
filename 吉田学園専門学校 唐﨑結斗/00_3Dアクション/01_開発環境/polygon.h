//**************************************************************************************************
//
// |S`ζ(polygon.h)
// AutherFϊ±l
//
//**************************************************************************************************
#ifndef _POLYGON_H_			// ±Μ}Nθ`ͺ³κΔΘ©Α½η
#define _POLYGON_H_			// ρdCN[hh~Μ}Nθ`

//***************************************************************
// |S\’Μπθ`
//***************************************************************
typedef struct
{
	D3DXVECTOR3		pos;			// Κu
	D3DXVECTOR3		rot;			// ό«
	D3DXMATRIX		mtxWorld;		// [h}gbNX
}POLYGON;
						
//***************************************************************
// vg^CvιΎ
//***************************************************************
// §δΦ
void	InitPolygon		(void);
void	UninitPolygon	(void);
void	UpdatePolygon	(void);
void	DrawPolygon		(void);

#endif
//**************************************************************************************************
//
//_fQ[WΜέθ
//AutherFϊ±l
//
//**************************************************************************************************
#ifndef _OXYGEN_GAUGE_H_		//±Μ}Nθ`ͺ³κΔΘ©Α½η
#define _OXYGEN_GAUGE_H_		//ρdCN\[hh~Μ}Nθ`

#include"main.h"

//**********************************************************
// [V[hΜρ^
//**********************************************************
typedef enum
{
	TYPE_GAUGE = 0,					// Q[W
	TYPE_BG,						// wi
	MAX_STAMINA_GAUGE_TYPE			// X^~iQ[W^CvΜΕε
}STAMINA_GAUGE_TYPE;

//*************************************************************
//}Nθ`
//*************************************************************
#define MAX_OFFSET_OXYGEN_GAUGE_X0		(40.0f)									// ε«³()[0]
#define MAX_OFFSET_OXYGEN_GAUGE_Y0		(370.0f)								// ε«³(³)[0]
#define MAX_OFFSET_OXYGEN_GAUGE_X1		(40.0f)									// ε«³()[1]
#define MAX_OFFSET_OXYGEN_GAUGE_Y1		(0.0f)									// ε«³(³)[1]
#define MAX_STAMINA_GAUGE				(1 * MAX_STAMINA_GAUGE_TYPE)			// έuΜΕε

//************************************************************
//_fQ[WΜ\’Μπθ`
//************************************************************
typedef struct
{
	D3DXVECTOR3				pos;							// S_
	D3DXVECTOR3				size;							// ε«³
	D3DXVECTOR3				maxSize;						// ε«³ΜΕεl
	D3DXVECTOR3				rot;							// ό«
	D3DXCOLOR				col;							// J[
	STAMINA_GAUGE_TYPE		type;							// ^Cv
	float					fLength;						// ΞpόΜ·³
	float					fAngele;						// ΞpόΜpx
	bool					bUse;							// gp΅Δι©Η€©
}StaminaGauge;

//****************************************
//vg^CvιΎ
//****************************************
void InitStaminaGauge(void);
void UninitStaminaGauge(void);
void UpdateStaminaGauge(void);
void DrawStaminaGauge(void);
void SetStaminaGauge(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size, int nType);
void SubStaminaGauge(int nCnt);
StaminaGauge *GetStaminaGauge(void);

#endif

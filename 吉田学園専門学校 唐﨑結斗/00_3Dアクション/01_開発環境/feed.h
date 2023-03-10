//**************************************************************************************************
//
// a(feed.h)
// AutherFú±l
//
//**************************************************************************************************
#ifndef _FEED_H_			// ±Ì}Nè`ª³êÄÈ©Á½ç
#define _FEED_H_			// ñdCN[hh~Ì}Nè`

//***************************************************************************
// CN[h
//***************************************************************************
#include"main.h"

//***************************************************************************
// }Nè`
//***************************************************************************
#define	MAX_FEED			(1280)		// aÌÅå
#define	MAX_FEED_NAME		(128)		// aÌÅå

//***************************************************************
// at@C\¢Ìðè`
//***************************************************************
typedef struct
{
	char	aName[MAX_FEED_NAME];		// ¼O
}FeedFile;

//***************************************************************
// a\¢Ìðè`
//***************************************************************
typedef struct
{
	LPD3DXMESH		pMesh;			// bVîñÖÌ|C^
	LPD3DXBUFFER	pBuffer;		// }eAîñÖÌ|C^
	DWORD			nNumMat;		// }eAîñÌ
	D3DXMATRIX		mtxWorld;		// [h}gbNX
	D3DXVECTOR3		pos;			// Êu
	D3DXVECTOR3		posOld;			// ßÊu
	D3DXVECTOR3		rot;			// »ÝÌü«
	D3DXVECTOR3		rotDest;		// ÚIÌü«
	D3DXVECTOR3		move;			// Ú®Ê
	D3DXVECTOR3		joinVec;		// xNg
	D3DXVECTOR3		leaveVec;		// £êéxNg
	D3DXVECTOR3		averageVec;		// ½ÏxNg
	D3DXVECTOR3		vtxMin;			// ¸_ÀWÌÅ¬l
	D3DXVECTOR3		vtxMax;			// ¸_ÀWÌÅål
	int				nIdx;			// CfbNX
	int				nGroup;			// O[vÔ
	int				nIdxLeader;		// [_[ÌÔ([_ª¢È¢ê-1)
	int				nCntJoinTime;	// [_[{õÜÅÌÔ
	int				nCntMoveTime;	// Ú®ÊZoÜÅÌÔ
	float			fJoinRot;		// ûü
	float			fLeaveRot;		// ûü
	float			fSpeed;			// Ú®¬x
	bool			bUse;			// gpóµ
	bool			bSearchIn;		// ìpàÉ¢é©Ç¤©
	bool			bEscape;		// ¦°Ä¢é©Ç¤©
}Feed;

//***************************************************************
// vg^Cvé¾
//***************************************************************
// §äÖ
void InitFeed(void);
void UninitFeed(void);
void UpdateFeed(void);
void DrawFeed(void);

// üÍÖ
void MoveFeed(int nCnt);
void RotateFeed(int nCnt);
void CollisionFeed(D3DXVECTOR3 *pos, D3DXVECTOR3 *posOld, D3DXVECTOR3 *vtx, D3DXVECTOR3 *vtxOld);
void SearchLeader(int nCnt);
void LeaveFeed(int nCnt);
void AverageFeed(int nCnt);
void SetFeed(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
void RandSetFeed(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fSetRot, float fSetLength, int nNumSet);
void LeavePlayer(int nCnt);
void SetControllerFeed(void);

// oÍÖ
Feed *GetFeed(void);
FeedFile *GetFeedFile(void);
int GetCntFeed(void);

#endif


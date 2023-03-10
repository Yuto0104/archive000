//**************************************************************************************************
//
// a`æ(feed.cpp)
// AutherFú±l
//
//**************************************************************************************************

//***************************************************************************
// CN[h
//***************************************************************************
#include "main.h"
#include "feed.h"
#include"file.h"
#include"input.h"
#include"camera.h"
#include"shadow.h"
#include"billboard.h"
#include"effect.h"
#include"line.h"
#include"calculation.h"
#include<time.h>
#include"player.h"
#include"score.h"
#include"particle.h"
#include"model.h"
#include"sound.h"

//***************************************************************************
// }Nè`
//***************************************************************************
#define INIT_NUM_FEED			(10000)							// ¸_ÀWÌÅåÅ¬Ìúl
#define FEED_MOVE_SPEED			(0.5f)							// Ú®¬x
#define FEED_ROTATE_SPEED		(0.1f)							// ñ]¬x
#define SEARCH_RANGE_LENGTH		(100.0f)						// {õÍÍÌ£
#define LEAVE_RANGE_LENGTH		(25.0f)							// ª£ÍÍÌ£
#define SEARCH_PLAYER_LENGTH	(150.0f)						// õGÍÍÌ£
#define SEARCH_RANGE_ROT		(0.5f)							// {õÍÍÌpx
#define LEAVE_RANGE_ROT			(SEARCH_RANGE_ROT * 1.5f)		// {õÍÍÌpx
#define SEARCH_PLAYER_SPEED		(0.8f)							// õGÍÍÌ¬x
#define JOINT_TIME				(30)							// ðs¤ÜÅÌÔ
#define MOVE_TIME				(600)							// Ú®ÊZoÜÅÌÔ
#define MAX_SPEED				(0.5f)							// Ú®¬xÌÅå
#define MAX_MOVE_ROT			(0.15f)							// Ú®ûüÌÅå
#define MAX_COMBO_TIME_FEED		(120)							// R{ÁZÔ
#define MIN_SET_FEED			(30)							// Å¬Ýu
#define MAX_SET_FEED			(60)							// ÅåÝu
#define MAX_SET_POS_FEED		(400 * 2)						// ÝuÍÍ

//***************************************************************************
// O[oÏ
//***************************************************************************
static Feed			g_Feed[MAX_FEED];				// aîñ
static FeedFile		g_FeedFile;						// at@C¼îñ
static int			g_nCntFeed = 0;					// gp³êÄéaÌ

//---------------------------------------------------------------------------
// aú»
//---------------------------------------------------------------------------
void InitFeed(void)
{
	// foCXÌæ¾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	g_nCntFeed = 0;

	//Ìú»
	srand((unsigned int)time(0));

	// at@C¼îñÌú»
	memset(&g_FeedFile, 0, sizeof(g_FeedFile));

	// aîñÌú»
	memset(&g_Feed[0], 0, sizeof(g_Feed));
}

//---------------------------------------------------------------------------
// aI¹
//---------------------------------------------------------------------------
void UninitFeed(void)
{
	for (int i = 0; i < MAX_FEED; i++)
	{
		// bVÌjü
		if (g_Feed[i].pMesh != NULL)
		{
			g_Feed[i].pMesh->Release();
			g_Feed[i].pMesh = NULL;
		}

		// }eAÌjü
		if (g_Feed[i].pBuffer != NULL)
		{
			g_Feed[i].pBuffer->Release();
			g_Feed[i].pBuffer = NULL;
		}
	}
}

//---------------------------------------------------------------------------
// aXV
//---------------------------------------------------------------------------
void UpdateFeed(void)
{
	for (int nCnt = 0; nCnt < MAX_FEED; nCnt++)
	{
		if (g_Feed[nCnt].bUse == true)
		{// gpµÄ¢é
			// ßÊuÌXV
			g_Feed[nCnt].posOld = g_Feed[nCnt].pos;

			// »èpÌÏ
			g_Feed[nCnt].bSearchIn = false;
			bool bOnCollisionPlayer = false;

			// vC[ÌìpàÉ¢é©
			g_Feed[nCnt].bSearchIn = SearchPlayer(&g_Feed[nCnt].pos);

			// vC[Ì½è»è
			D3DXVECTOR3 aVtxA = WorldCastVtx(D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMax.z), g_Feed[nCnt].pos, g_Feed[nCnt].rot);
			D3DXVECTOR3 aVtxB = WorldCastVtx(D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMax.z), g_Feed[nCnt].pos, g_Feed[nCnt].rot);
			D3DXVECTOR3 aVtxC = WorldCastVtx(D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMin.z), g_Feed[nCnt].pos, g_Feed[nCnt].rot);
			D3DXVECTOR3 aVtxD = WorldCastVtx(D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMin.z), g_Feed[nCnt].pos, g_Feed[nCnt].rot);

			if (g_Feed[nCnt].bSearchIn == false)
			{// ìOÌ
				CollisionPlayer(&aVtxA);
				CollisionPlayer(&aVtxB);
				CollisionPlayer(&aVtxC);
				CollisionPlayer(&aVtxD);
			}

			bOnCollisionPlayer = EatPlayer(&g_Feed[nCnt].pos, g_Feed[nCnt].vtxMax - g_Feed[nCnt].vtxMin);

			MODE mode = GetMode();

			if (mode == MODE_GAME)
			{// Q[Ì
				if (g_Feed[nCnt].bSearchIn == true && bOnCollisionPlayer == true)
				{// ìpàÉ¢ÄvC[É½ÁÄ¢é
					g_Feed[nCnt].bUse = false;
					DeleteShadow(g_Feed[nCnt].nIdx);
					g_nCntFeed--;

					// vC[îñÌæ¾
					Player *pPlayer = GetPlayer();

					// R{ÁZ
					pPlayer->nCntCombo++;

					// R{ÁZÔÌXV
					pPlayer->nCntComboTime = MAX_COMBO_TIME_FEED;

					// X^~iðCNg
					pPlayer->nStamina += 3;

					if (pPlayer->nStamina >= pPlayer->nMaxStamina)
					{// X^~iðÅålÉÅè
						pPlayer->nStamina = pPlayer->nMaxStamina;
					}

					//XRAÌÁZ
					AddScore(200 + 100 * pPlayer->nCntCombo);

					// p[eBNÌÝu
					SetParticle(g_Feed[nCnt].pos,
						D3DXVECTOR3(0.0f, 0.0f, 0.0f),
						D3DXVECTOR3(1.0f, 1.0f, 0.0f),
						D3DXCOLOR(0.01f, 1.0f, 1.0f, 1.0f),
						5.0f,
						2.0f,
						0.0f,
						60,
						0,
						1,
						30,
						20,
						false);

					//TEhÌÄ¶
					PlaySound(SOUND_LABEL_SE_DAMAGE001);
				}

				// vC[©ç¦°é
				LeavePlayer(nCnt);
			}

			if (g_Feed[nCnt].bEscape == false)
			{// ¦°Ä¢È¢Æ«
				// [_[Ì{õ
				SearchLeader(nCnt);

				// ª£
				LeaveFeed(nCnt);
			}

			// ®
			AverageFeed(nCnt);

			// aÌÚ®
			MoveFeed(nCnt);

			//aÌñ]
			RotateFeed(nCnt);

			if (CollisionModel(&g_Feed[nCnt].pos, &g_Feed[nCnt].posOld, &aVtxA, &aVtxA) == true
				|| CollisionModel(&g_Feed[nCnt].pos, &g_Feed[nCnt].posOld, &aVtxB, &aVtxB) == true
				|| CollisionModel(&g_Feed[nCnt].pos, &g_Feed[nCnt].posOld, &aVtxC, &aVtxC) == true
				|| CollisionModel(&g_Feed[nCnt].pos, &g_Feed[nCnt].posOld, &aVtxD, &aVtxD) == true)
			{
				g_Feed[nCnt].bUse = false;
				DeleteShadow(g_Feed[nCnt].nIdx);
			}

			// eÌÚ®
			SetPositionShadow(g_Feed[nCnt].nIdx, g_Feed[nCnt].pos, g_Feed[nCnt].rot, D3DXVECTOR3(g_Feed[nCnt].vtxMax.x - g_Feed[nCnt].vtxMin.x, 0.0f, g_Feed[nCnt].vtxMax.z - g_Feed[nCnt].vtxMin.z));
		}
	}
}

//---------------------------------------------------------------------------
// a`æ
//---------------------------------------------------------------------------
void DrawFeed(void)
{
	// foCXÌæ¾
	LPDIRECT3DDEVICE9	pDevice = GetDevice();
	D3DXMATRIX			mtxRot, mtxTrans;			// vZp}gbNX
	D3DMATERIAL9		matDef;						// »ÝÌ}eAÛ¶p
	D3DXMATERIAL		*pMat;						// }eAf[^ÖÌ|C^

	for (int nCnt = 0; nCnt < MAX_FEED; nCnt++)
	{
		if (g_Feed[nCnt].bUse == true)
		{// gpµÄ¢é
			// [h}gbNXÌú»
			D3DXMatrixIdentity(&g_Feed[nCnt].mtxWorld);			// sñú»Ö

			// ü«Ì½f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Feed[nCnt].rot.y, g_Feed[nCnt].rot.x, g_Feed[nCnt].rot.z);		// sññ]Ö
			D3DXMatrixMultiply(&g_Feed[nCnt].mtxWorld, &g_Feed[nCnt].mtxWorld, &mtxRot);								// sñ|¯ZÖ 

			// Êuð½f
			D3DXMatrixTranslation(&mtxTrans, g_Feed[nCnt].pos.x, g_Feed[nCnt].pos.y, g_Feed[nCnt].pos.z);				// sñÚ®Ö
			D3DXMatrixMultiply(&g_Feed[nCnt].mtxWorld, &g_Feed[nCnt].mtxWorld, &mtxTrans);								// sñ|¯ZÖ

			//// TCYÌ½f
			//D3DXMatrixScaling()

			// [h}gbNXÌÝè
			pDevice->SetTransform(D3DTS_WORLD, &g_Feed[nCnt].mtxWorld);

			// »ÝÌ}eAðÛ
			pDevice->GetMaterial(&matDef);

			// }eAf[^ÖÌ|C^ðæ¾
			pMat = (D3DXMATERIAL*)g_Feed[nCnt].pBuffer->GetBufferPointer();

			for (int nCntMat = 0; nCntMat < (int)g_Feed[nCnt].nNumMat; nCntMat++)
			{
				// }eAÌÝè
				pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

				/*if (g_Feed[nCnt].bSearchIn == true)
				{
					D3DMATERIAL9  matD3D = pMat[nCntMat].MatD3D;
					matD3D.Diffuse = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
					pDevice->SetMaterial(&matD3D);
				}
				else
				{
					pDevice->SetMaterial(&pMat[nCntMat].MatD3D);
				}*/

				// ap[cÌ`æ
				g_Feed[nCnt].pMesh->DrawSubset(nCntMat);
			}

			// ÛµÄ¢½}eAðß·
			pDevice->SetMaterial(&matDef);
		}
	}
}

//---------------------------------------------------------------------------
// aÚ®
//---------------------------------------------------------------------------
void MoveFeed(int nCnt)
{
	// Ú®ÊÌZo
	if (g_Feed[nCnt].bEscape == false)
	{// ¦°Ä¢È¢
		g_Feed[nCnt].nCntMoveTime++;
		if (g_Feed[nCnt].nCntMoveTime >= MOVE_TIME)
		{// Ú®ÊÆ¬xÌZo
			// Ú®ûü
			if (g_Feed[nCnt].nIdxLeader == -1)
			{
				float fRotMove = ((D3DX_PI * MAX_MOVE_ROT)) - (float)(rand() % (int)(((D3DX_PI * MAX_MOVE_ROT) * 2.0f) * 100.0f) / 100.0f);

				// Ú®ÊÌZo
				g_Feed[nCnt].move.x = sinf(g_Feed[nCnt].rot.y + fRotMove);
				g_Feed[nCnt].move.z = cosf(g_Feed[nCnt].rot.y + fRotMove);
				D3DXVec3Normalize(&g_Feed[nCnt].move, &g_Feed[nCnt].move);
			}

			// Ú®¬x
			g_Feed[nCnt].fSpeed = (float)(rand() % (int)(MAX_SPEED * 100.0f) / 100.0f);

			// JEgÌú»
			g_Feed[nCnt].nCntMoveTime = 0;
		}
	}

	g_Feed[nCnt].move += g_Feed[nCnt].joinVec + g_Feed[nCnt].leaveVec + g_Feed[nCnt].averageVec;
	D3DXVec3Normalize(&g_Feed[nCnt].move, &g_Feed[nCnt].move);		// xNgðå«³1

	// Ú®ûüÌZo
	float fDestRot = atan2f((g_Feed[nCnt].move.x + g_Feed[nCnt].pos.x) - g_Feed[nCnt].pos.x,
		(g_Feed[nCnt].move.z + g_Feed[nCnt].pos.z) - g_Feed[nCnt].pos.z);

	// Ú®ûüÌ³K»
	g_Feed[nCnt].rotDest.y = RotNormalization(fDestRot - D3DX_PI);

	// ÊuÌXV
	g_Feed[nCnt].pos += (g_Feed[nCnt].move * g_Feed[nCnt].fSpeed);
}

//---------------------------------------------------------------------------
// añ]
//---------------------------------------------------------------------------
void RotateFeed(int nCnt)
{
	// ü«ÌXV
	g_Feed[nCnt].rot.y += (g_Feed[nCnt].rotDest.y - g_Feed[nCnt].rot.y) * FEED_ROTATE_SPEED;

	// ³K»
	g_Feed[nCnt].rot.y = RotNormalization(g_Feed[nCnt].rot.y);
}

//---------------------------------------------------------------------------
// aÌ½è»è	
//---------------------------------------------------------------------------
void CollisionFeed(D3DXVECTOR3 *pos, D3DXVECTOR3 *posOld, D3DXVECTOR3 *vtx, D3DXVECTOR3 *vtxOld)
{
	for (int nCnt = 0; nCnt < MAX_FEED; nCnt++)
	{
		if (g_Feed[nCnt].bUse == true && g_Feed[nCnt].bSearchIn != true)
		{// gpµÄ¢é
			// ¸_ÌZo
			D3DXVECTOR3 aVecA = D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMax.z);
			D3DXVECTOR3 aVecB = D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMax.z);
			D3DXVECTOR3 aVecC = D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMin.z);
			D3DXVECTOR3 aVecD = D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMin.z);

			// ¸_ð[hÀWÖLXg
			aVecA = WorldCastVtx(aVecA, g_Feed[nCnt].pos, g_Feed[nCnt].rot);
			aVecB = WorldCastVtx(aVecB, g_Feed[nCnt].pos, g_Feed[nCnt].rot);
			aVecC = WorldCastVtx(aVecC, g_Feed[nCnt].pos, g_Feed[nCnt].rot);
			aVecD = WorldCastVtx(aVecD, g_Feed[nCnt].pos, g_Feed[nCnt].rot);

			// xNgÌZo
			D3DXVECTOR3 aVecLineA = aVecB - aVecA;
			D3DXVECTOR3 aVecLineB = aVecC - aVecB;
			D3DXVECTOR3 aVecLineC = aVecD - aVecC;
			D3DXVECTOR3 aVecLineD = aVecA - aVecD;
			D3DXVECTOR3 aVecPosA = *vtx - aVecA;
			D3DXVECTOR3 aVecPosB = *vtx - aVecB;
			D3DXVECTOR3 aVecPosC = *vtx - aVecC;
			D3DXVECTOR3 aVecPosD = *vtx - aVecD;

			// ärZpÌÏÌè`Æãü
			float fA = (aVecLineA.z * aVecPosA.x) - (aVecLineA.x * aVecPosA.z);
			float fB = (aVecLineB.z * aVecPosB.x) - (aVecLineB.x * aVecPosB.z);
			float fC = (aVecLineC.z * aVecPosC.x) - (aVecLineC.x * aVecPosC.z);
			float fD = (aVecLineD.z * aVecPosD.x) - (aVecLineD.x * aVecPosD.z);

			if (0.0f < fA
				&& 0.0f < fB
				&& 0.0f < fC
				&& 0.0f < fD)
			{// fÌ¤¿É¢é
			 /*g_Feed[nCnt].bUse = false;
			 DeleteShadow(g_Feed[nCnt].nIdx);*/

			 // xNgÌZo
				aVecPosA = *vtxOld - aVecA;
				aVecPosB = *vtxOld - aVecB;
				aVecPosC = *vtxOld - aVecC;
				aVecPosD = *vtxOld - aVecD;

				// ärZpÌÏÉãü
				fA = (aVecLineA.z * aVecPosA.x) - (aVecLineA.x * aVecPosA.z);
				fB = (aVecLineB.z * aVecPosB.x) - (aVecLineB.x * aVecPosB.z);
				fC = (aVecLineC.z * aVecPosC.x) - (aVecLineC.x * aVecPosC.z);
				fD = (aVecLineD.z * aVecPosD.x) - (aVecLineD.x * aVecPosD.z);

				// »èpÌÏ
				D3DXVECTOR3 aJudgeVec;
				D3DXVECTOR3 aJudgeVecLine;

				if (0.0f >= fA)
				{
					aJudgeVec = aVecA;
					aJudgeVecLine = aVecLineA;
				}
				else if (0.0f >= fB)
				{
					aJudgeVec = aVecB;
					aJudgeVecLine = aVecLineB;
				}
				else if (0.0f >= fC)
				{
					aJudgeVec = aVecC;
					aJudgeVecLine = aVecLineC;
				}
				else if (0.0f >= fD)
				{
					aJudgeVec = aVecD;
					aJudgeVecLine = aVecLineD;
				}

				//D3DXVECTOR3 aVecPosOld = aJudgeVec - *posOld;
				//D3DXVECTOR3 aVecMove = *pos - *posOld;

				//// ð_ÌÊuÌ
				//float fIntersection = ((aVecPosOld.z * aVecMove.x) - (aVecPosOld.x * aVecMove.z))
				//	/ ((aVecMove.z * aJudgeVecLine.x) - (aVecMove.x * aJudgeVecLine.z));

				//// ð_ÌZo
				//pos->x = aJudgeVec.x + fIntersection * aJudgeVecLine.x;
				//pos->z = aJudgeVec.z + fIntersection * aJudgeVecLine.z;

				// ð_ÌZo
				pos->x = posOld->x;
				pos->z = posOld->z;
			}
		}
	}
}

//---------------------------------------------------------------------------
// [_[Ì{õ
//---------------------------------------------------------------------------
void SearchLeader(int nCnt)
{
	// pxÌZo
	float fSearchRot = (D3DX_PI * SEARCH_RANGE_ROT);
	float fDistanceMin = (float)(INIT_NUM_FEED);
	float fJoinRot = 0.0f;
	int nCntSearchIn = 0;

	// ÜÅÌJEgÌCNg
	g_Feed[nCnt].nCntJoinTime++;

	for (int nCntFeed = 0; nCntFeed < MAX_FEED; nCntFeed++)
	{
		if (nCntFeed != nCnt && g_Feed[nCntFeed].bUse == true)
		{// ©ªÈOÌ
			bool bSearch = false;

			// ÔÌ¢éü«
			float fFellowRot = atan2f(g_Feed[nCnt].pos.x - g_Feed[nCntFeed].pos.x, g_Feed[nCnt].pos.z - g_Feed[nCntFeed].pos.z);

			// ärpÌü«ÌZo
			float fSearchRotRight = g_Feed[nCnt].rot.y - fSearchRot;
			float fSRROld = fSearchRotRight;
			fSearchRotRight = RotNormalization(fSearchRotRight);
	
			float fSearchRotLeft = g_Feed[nCnt].rot.y + fSearchRot;
			float fSRLOld = fSearchRotLeft;
			fSearchRotLeft = RotNormalization(fSearchRotLeft);

			if (fSRROld == fSearchRotRight && fSRLOld == fSearchRotLeft)
			{// ³K»OÌlª¯¶ê
				if (fSearchRotRight <= fFellowRot
					&& fSearchRotLeft >= fFellowRot)
				{// ¡ûðo
					bSearch = true;
				}
			}
			else
			{// ³K»OÌlªá¤
				if (fSearchRotRight <= fFellowRot
					|| fSearchRotLeft >= fFellowRot)
				{// ¡ûðo
					bSearch = true;
				}
			}

			// ÚWÜÅÌ£
			D3DXVECTOR3 distance = g_Feed[nCntFeed].pos - g_Feed[nCnt].pos;
			float fDistance = sqrtf((distance.x * distance.x) + (distance.z * distance.z));

			if (bSearch == true
				&& fDistance <= SEARCH_RANGE_LENGTH)
			{// {õÍÍà¡ûª¢é
				// ¡ûÌûü
				fFellowRot = atan2f(g_Feed[nCntFeed].pos.x - g_Feed[nCnt].pos.x, g_Feed[nCntFeed].pos.z - g_Feed[nCnt].pos.z);

				// ¡ûÜÅÌ£
				float fFeedDistance = sqrtf((g_Feed[nCntFeed].pos.x - g_Feed[nCnt].pos.x) * (g_Feed[nCntFeed].pos.x - g_Feed[nCnt].pos.x)
					+ (g_Feed[nCntFeed].pos.z - g_Feed[nCnt].pos.z) * (g_Feed[nCntFeed].pos.z - g_Feed[nCnt].pos.z));

				// ¡ûÖÌü«ðÁZ
				fJoinRot += fFellowRot;

				// ÍÍàÌ¡ûÌðÁZ
				nCntSearchIn++;

				if (fDistanceMin > fFeedDistance)
				{// £ªZ¯êÎ
					g_Feed[nCnt].nGroup = g_Feed[nCntFeed].nGroup;						// O[v
					g_Feed[nCnt].nIdxLeader = g_Feed[nCntFeed].nGroup;					// [_[
					fDistanceMin = fFeedDistance;										// êÔß¢ÚW
				}
			}
		}
	}

	if (nCntSearchIn > 0)
	{// ÍÍàÉ¡ûª¢éÆ«
		// ¡ûûüÌ½ÏðZo
		g_Feed[nCnt].fJoinRot = fJoinRot / nCntSearchIn;
		g_Feed[nCnt].fJoinRot = RotNormalization(g_Feed[nCnt].fJoinRot - D3DX_PI);

		// xNgÌZo
		g_Feed[nCnt].joinVec.x = sinf(g_Feed[nCnt].fJoinRot - D3DX_PI);
		g_Feed[nCnt].joinVec.z = cosf(g_Feed[nCnt].fJoinRot - D3DX_PI);

		// 
		if (g_Feed[nCnt].nCntJoinTime >= JOINT_TIME)
		{// êèÌÔoßµ½
			// xNgÌZo
			g_Feed[nCnt].joinVec.x = sinf(g_Feed[nCnt].fJoinRot - D3DX_PI);
			g_Feed[nCnt].joinVec.z = cosf(g_Feed[nCnt].fJoinRot - D3DX_PI);
			g_Feed[nCnt].nCntJoinTime = 0;		// ÜÅÌJEgðú»
			D3DXVec3Normalize(&g_Feed[nCnt].joinVec, &g_Feed[nCnt].joinVec);
		}
	}
	else
	{// ÍÍàÉ¡ûª¢È¢
		g_Feed[nCnt].nIdxLeader = -1;										// [_[
		g_Feed[nCnt].nGroup = nCnt;											// O[v
		g_Feed[nCnt].fJoinRot = 0.0f;										// ûü

		// xNgÌZo
		g_Feed[nCnt].joinVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		D3DXVec3Normalize(&g_Feed[nCnt].joinVec, &g_Feed[nCnt].joinVec);
	}
}

//---------------------------------------------------------------------------
// ª£
//---------------------------------------------------------------------------
void LeaveFeed(int nCnt)
{
	// pxÌZo
	float fSearchRot = (D3DX_PI * LEAVE_RANGE_ROT);
	float fDistanceMin = (float)(INIT_NUM_FEED);
	int nCntSearchIn = 0;

	for (int nCntFeed = 0; nCntFeed < MAX_FEED; nCntFeed++)
	{
		if (nCntFeed != nCnt && g_Feed[nCntFeed].bUse == true)
		{// ©ªÈOÌ
			bool bSearch = false;

			// ÔÌ¢éü«
			float fFellowRot = atan2f(g_Feed[nCnt].pos.x - g_Feed[nCntFeed].pos.x, g_Feed[nCnt].pos.z - g_Feed[nCntFeed].pos.z);

			// ärpÌü«ÌZo
			float fSearchRotRight = g_Feed[nCnt].rot.y - fSearchRot;
			float fSRROld = fSearchRotRight;
			fSearchRotRight = RotNormalization(fSearchRotRight);

			float fSearchRotLeft = g_Feed[nCnt].rot.y + fSearchRot;
			float fSRLOld = fSearchRotLeft;
			fSearchRotLeft = RotNormalization(fSearchRotLeft);

			if (fSRROld == fSearchRotRight && fSRLOld == fSearchRotLeft)
			{// ³K»OÌlª¯¶ê
				if (fSearchRotRight <= fFellowRot
					&& fSearchRotLeft >= fFellowRot)
				{// ¡ûðo
					bSearch = true;
				}
			}
			else
			{// ³K»OÌlªá¤
				if (fSearchRotRight <= fFellowRot
					|| fSearchRotLeft >= fFellowRot)
				{// ¡ûðo
					bSearch = true;
				}
			}

			// ÚWÜÅÌ£
			D3DXVECTOR3 distance = g_Feed[nCntFeed].pos - g_Feed[nCnt].pos;
			float fDistance = sqrtf((distance.x * distance.x) + (distance.z * distance.z));

			if (bSearch == true
				&& fDistance <= LEAVE_RANGE_LENGTH)
			{// {õÍÍà¡ûª¢é
				float fFeedDistance = sqrtf((g_Feed[nCntFeed].pos.x - g_Feed[nCnt].pos.x) * (g_Feed[nCntFeed].pos.x - g_Feed[nCnt].pos.x)
					+ (g_Feed[nCntFeed].pos.z - g_Feed[nCnt].pos.z) * (g_Feed[nCntFeed].pos.z - g_Feed[nCnt].pos.z));

				// ÍÍàÉ©ûª¢éê
				nCntSearchIn++;

				if (fDistanceMin > fFeedDistance)
				{// £ªZ¯êÎ
					fDistanceMin = fFeedDistance;
					g_Feed[nCnt].fLeaveRot = fFellowRot;
					g_Feed[nCnt].fLeaveRot = RotNormalization(g_Feed[nCnt].fLeaveRot - D3DX_PI);
					g_Feed[nCnt].leaveVec.x = sinf(g_Feed[nCnt].fLeaveRot - D3DX_PI);
					g_Feed[nCnt].leaveVec.z = cosf(g_Feed[nCnt].fLeaveRot - D3DX_PI);
					D3DXVec3Normalize(&g_Feed[nCnt].leaveVec, &g_Feed[nCnt].leaveVec);
				}
			}
		}
	}

	if(nCntSearchIn == 0)
	{// {õÍÍÉ¡ûª¢È¢
		g_Feed[nCnt].leaveVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Feed[nCnt].fLeaveRot = 0.0f;
	}
}

//---------------------------------------------------------------------------
// ®
//---------------------------------------------------------------------------
void AverageFeed(int nCnt)
{
	float fSearchRot = (D3DX_PI * SEARCH_RANGE_ROT);
	D3DXVECTOR3 average = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	int nCntSearchIn = 0;

	for (int nCntFeed = 0; nCntFeed < MAX_FEED; nCntFeed++)
	{
		if (nCntFeed != nCnt && g_Feed[nCntFeed].bUse == true)
		{// ©ªÈOÌ
			bool bSearch = false;

			// ÔÌ¢éü«
			float fFellowRot = atan2f(g_Feed[nCnt].pos.x - g_Feed[nCntFeed].pos.x, g_Feed[nCnt].pos.z - g_Feed[nCntFeed].pos.z);

			// ärpÌü«ÌZo
			float fSearchRotRight = g_Feed[nCnt].rot.y - fSearchRot;
			float fSRROld = fSearchRotRight;
			fSearchRotRight = RotNormalization(fSearchRotRight);
			float fSearchRotLeft = g_Feed[nCnt].rot.y + fSearchRot;
			float fSRLOld = fSearchRotLeft;
			fSearchRotLeft = RotNormalization(fSearchRotLeft);

			if (fSRROld == fSearchRotRight && fSRLOld == fSearchRotLeft)
			{// ³K»OÌlª¯¶ê
				if (fSearchRotRight <= fFellowRot
					&& fSearchRotLeft >= fFellowRot)
				{// ¡ûðo
					bSearch = true;
				}
			}
			else
			{// ³K»OÌlªá¤
				if (fSearchRotRight <= fFellowRot
					|| fSearchRotLeft >= fFellowRot)
				{// ¡ûðo
					bSearch = true;
				}
			}

			// ÚWÜÅÌ£
			D3DXVECTOR3 distance = g_Feed[nCntFeed].pos - g_Feed[nCnt].pos;
			float fDistance = sqrtf((distance.x * distance.x) + (distance.z * distance.z));

			if (bSearch == true
				&& fDistance <= LEAVE_RANGE_LENGTH)
			{// {õÍÍà¡ûª¢é
				float fFeedDistance = sqrtf((g_Feed[nCntFeed].pos.x - g_Feed[nCnt].pos.x) * (g_Feed[nCntFeed].pos.x - g_Feed[nCnt].pos.x)
					+ (g_Feed[nCntFeed].pos.z - g_Feed[nCnt].pos.z) * (g_Feed[nCntFeed].pos.z - g_Feed[nCnt].pos.z));

				// ÍÍàÉ©ûª¢éê
				nCntSearchIn++;

				// ½ÏÉÁZ
				average += g_Feed[nCntFeed].move + g_Feed[nCntFeed].joinVec + g_Feed[nCntFeed].leaveVec;
			}
		}
	}

	if (nCntSearchIn > 0 && g_Feed[nCnt].nIdxLeader != -1)
	{// ÍÍàÉ¡ûª¢½
		// ½ÏûüÌZo
		g_Feed[nCnt].averageVec = average / (float)(nCntSearchIn);
		D3DXVec3Normalize(&g_Feed[nCnt].averageVec, &g_Feed[nCnt].averageVec);
	}
	else
	{// ÍÍàÉ¡ûª¢È¢
		// ½Ïûüðú»
		g_Feed[nCnt].averageVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}
}

//---------------------------------------------------------------------------
// vC[©ç¦°é
//---------------------------------------------------------------------------
void LeavePlayer(int nCnt)
{
	// vC[îñÌæ¾
	Player *pPlayer = GetPlayer();

	// ÚWÜÅÌ£
	D3DXVECTOR3 distance = pPlayer->pos - g_Feed[nCnt].pos;
	float fDistance = sqrtf((distance.x * distance.x) + (distance.z * distance.z));

	if (fDistance <= SEARCH_PLAYER_LENGTH)
	{// õGÍÍÉGª¢½
		// ÔÌ¢éü«
		D3DXVECTOR3 distance = g_Feed[nCnt].pos - pPlayer->pos;
		float fFellowRot = atan2f(distance.x, distance.z);

		// Ú®ûüÌZo
		g_Feed[nCnt].move.x = sinf(fFellowRot);
		g_Feed[nCnt].move.z = cosf(fFellowRot);

		// Æª£ðú»
		g_Feed[nCnt].joinVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Feed[nCnt].leaveVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		// Ú®ÊÌÁZ
		g_Feed[nCnt].pos += g_Feed[nCnt].move * SEARCH_PLAYER_SPEED;

		// ¦°é
		g_Feed[nCnt].bEscape = true;
	}
	else
	{
		g_Feed[nCnt].bEscape = false;
	}
}

//---------------------------------------------------------------------------
// aÝè
//---------------------------------------------------------------------------
void SetFeed(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// foCXÌæ¾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	for (int nCnt = 0; nCnt < MAX_FEED; nCnt++)
	{
		if (g_Feed[nCnt].bUse == false)
		{
			// t@CÏÌé¾Æãü
			char aFile[128] = FILE_MODEL_DATA;
			strcat(aFile, ".x");

			// aîñÌú»
			g_Feed[nCnt].pos = pos;																// ÊuÌú»
			g_Feed[nCnt].posOld = g_Feed[nCnt].pos;												// ßÊuÌú»
			g_Feed[nCnt].rot = rot;																// ü«Ìú»
			g_Feed[nCnt].rotDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);								// ÚIÌü«Ìú»
			g_Feed[nCnt].joinVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);								// ÌxNgÌú»
			g_Feed[nCnt].leaveVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);								// £êéxNgÌú»
			g_Feed[nCnt].averageVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);							// ½ÏxNgÌú»
			g_Feed[nCnt].nGroup = -1;															// O[vÔ
			g_Feed[nCnt].nIdxLeader = -1;														// [_[Ô
			g_Feed[nCnt].vtxMin = D3DXVECTOR3(INIT_NUM_FEED, INIT_NUM_FEED, INIT_NUM_FEED);		// ¸_ÀWÌÅ¬lÌú»
			g_Feed[nCnt].vtxMax = D3DXVECTOR3(-INIT_NUM_FEED, -INIT_NUM_FEED, -INIT_NUM_FEED);	// ¸_ÀWÌÅålÌú»
			g_Feed[nCnt].mtxWorld = {};															// [h}gbNX	
			g_Feed[nCnt].fSpeed = 0.5f;															// Ú®¬x
			g_Feed[nCnt].fJoinRot = 0.0f;														// ûü
			g_Feed[nCnt].fLeaveRot = 0.0f;														// ª£ûü
			g_Feed[nCnt].nCntJoinTime = 0;														// ÜÅÌÔ
			g_Feed[nCnt].nCntMoveTime = 0;														// Ú®ÊZoÜÅÌJEg
			g_Feed[nCnt].bUse = true;															// gpóµ
			g_Feed[nCnt].bEscape = false;														// ¦°Ä¢È¢

			// Ú®ÊÌZo
			g_Feed[nCnt].move.x = sinf(g_Feed[nCnt].rot.y);
			g_Feed[nCnt].move.z = cosf(g_Feed[nCnt].rot.y);
			D3DXVec3Normalize(&g_Feed[nCnt].move, &g_Feed[nCnt].move);

			// Xt@CÌÇÝÝ
			D3DXLoadMeshFromX(&aFile[0],
				D3DXMESH_SYSTEMMEM,
				pDevice,
				NULL,
				&g_Feed[nCnt].pBuffer,
				NULL,
				&g_Feed[nCnt].nNumMat,
				&g_Feed[nCnt].pMesh);

			// ¸_ÀWÌÅ¬lEÅålÌZo
			int		nNumVtx;	// ¸_
			DWORD	sizeFVF;	// ¸_tH[}bgÌTCY
			BYTE	*pVtxBuff;	// ¸_obt@ÖÌ|C^

			// ¸_Ìæ¾
			nNumVtx = g_Feed[nCnt].pMesh->GetNumVertices();

			// ¸_tH[}bgÌTCYÌæ¾
			sizeFVF = D3DXGetFVFVertexSize(g_Feed[nCnt].pMesh->GetFVF());

			// ¸_obt@ÌbN
			g_Feed[nCnt].pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBuff);

			for (int nCntVtx = 0; nCntVtx < nNumVtx; nCntVtx++)
			{
				// ¸_ÀWÌãü
				D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBuff;

				if (vtx.x < g_Feed[nCnt].vtxMin.x)
				{// ärÎÛª»ÝÌ¸_ÀW(X)ÌÅ¬læè¬³¢
					g_Feed[nCnt].vtxMin.x = vtx.x;
				}
				if (vtx.y < g_Feed[nCnt].vtxMin.y)
				{// ärÎÛª»ÝÌ¸_ÀW(Y)ÌÅ¬læè¬³¢
					g_Feed[nCnt].vtxMin.y = vtx.y;
				}
				if (vtx.z < g_Feed[nCnt].vtxMin.z)
				{// ärÎÛª»ÝÌ¸_ÀW(Z)ÌÅ¬læè¬³¢
					g_Feed[nCnt].vtxMin.z = vtx.z;
				}

				if (vtx.x > g_Feed[nCnt].vtxMax.x)
				{// ärÎÛª»ÝÌ¸_ÀW(X)ÌÅålæèå«¢
					g_Feed[nCnt].vtxMax.x = vtx.x;
				}
				if (vtx.y > g_Feed[nCnt].vtxMax.y)
				{// ärÎÛª»ÝÌ¸_ÀW(Y)ÌÅålæèå«¢
					g_Feed[nCnt].vtxMax.y = vtx.y;
				}
				if (vtx.z > g_Feed[nCnt].vtxMax.z)
				{// ärÎÛª»ÝÌ¸_ÀW(Z)ÌÅålæèå«¢
					g_Feed[nCnt].vtxMax.z = vtx.z;
				}

				// ¸_tH[}bgÌTCYª|C^ðißé
				pVtxBuff += sizeFVF;
			}

			// ¸_obt@ÌAbN
			g_Feed[nCnt].pMesh->UnlockVertexBuffer();

			// CÌÝè
			//SetLine(g_Feed[nCnt].pos, g_Feed[nCnt].rot, D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMax.z), D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMax.z), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
			//SetLine(g_Feed[nCnt].pos, g_Feed[nCnt].rot, D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMin.z), D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMax.z), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
			//SetLine(g_Feed[nCnt].pos, g_Feed[nCnt].rot, D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMin.z), D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMin.z), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
			//SetLine(g_Feed[nCnt].pos, g_Feed[nCnt].rot, D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMin.z), D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMax.z), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
			//SetLine(g_Feed[nCnt].pos, g_Feed[nCnt].rot, D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMax.y, g_Feed[nCnt].vtxMax.z), D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMax.y, g_Feed[nCnt].vtxMax.z), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
			//SetLine(g_Feed[nCnt].pos, g_Feed[nCnt].rot, D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMax.y, g_Feed[nCnt].vtxMin.z), D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMax.y, g_Feed[nCnt].vtxMax.z), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
			//SetLine(g_Feed[nCnt].pos, g_Feed[nCnt].rot, D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMax.y, g_Feed[nCnt].vtxMin.z), D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMax.y, g_Feed[nCnt].vtxMin.z), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
			//SetLine(g_Feed[nCnt].pos, g_Feed[nCnt].rot, D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMax.y, g_Feed[nCnt].vtxMin.z), D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMax.y, g_Feed[nCnt].vtxMax.z), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
			//SetLine(g_Feed[nCnt].pos, g_Feed[nCnt].rot, D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMax.z), D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMax.y, g_Feed[nCnt].vtxMax.z), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
			//SetLine(g_Feed[nCnt].pos, g_Feed[nCnt].rot, D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMin.z), D3DXVECTOR3(g_Feed[nCnt].vtxMin.x, g_Feed[nCnt].vtxMax.y, g_Feed[nCnt].vtxMin.z), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
			//SetLine(g_Feed[nCnt].pos, g_Feed[nCnt].rot, D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMin.z), D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMax.y, g_Feed[nCnt].vtxMin.z), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
			//SetLine(g_Feed[nCnt].pos, g_Feed[nCnt].rot, D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMin.y, g_Feed[nCnt].vtxMax.z), D3DXVECTOR3(g_Feed[nCnt].vtxMax.x, g_Feed[nCnt].vtxMax.y, g_Feed[nCnt].vtxMax.z), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));

			// eÌÝè
			g_Feed[nCnt].nIdx = SetShadow(g_Feed[nCnt].pos, g_Feed[nCnt].rot, D3DXVECTOR3(g_Feed[nCnt].vtxMax.x - g_Feed[nCnt].vtxMin.x, 0.0f, g_Feed[nCnt].vtxMax.z - g_Feed[nCnt].vtxMin.z));

			g_nCntFeed++;

			break;
		}
	}
}

//---------------------------------------------------------------------------
// aÌÍÍÝu
//---------------------------------------------------------------------------
void RandSetFeed(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fSetRot, float fSetLength, int nNumSet)
{
	// æªÌzu
	SetFeed(pos, rot);

	for (int nCntFeed = 0; nCntFeed < nNumSet - 1; nCntFeed++)
	{
		// Ïé¾
		float fSetRandRot = ((D3DX_PI * fSetRot) / 2.0f) - (float)(rand() % (int)(((D3DX_PI * fSetRot)) * 100.0f) / 100.0f);		// QêÌS©çÌpx
		float fSetRandLength = (float)(rand() % (int)(fSetLength * 100.0f) / 100.0f);												// QêÌS©çÌ£
		
		// ÊuÌZo
		D3DXVECTOR3 setPos = D3DXVECTOR3(pos.x + sinf(rot.y + fSetRandRot) * fSetRandLength,
			0.0f,
			pos.z + cosf(rot.y + fSetRandRot) * fSetRandLength);

		// zu
		SetFeed(setPos, rot);
	}
}

//---------------------------------------------------------------------------
// aÌ©®ÍÍÝu
//---------------------------------------------------------------------------
void SetControllerFeed(void)
{
	if (g_nCntFeed <= MIN_SET_FEED)
	{// ÝuªÅ¬ðºñÁ½ê
		while (g_nCntFeed < MAX_SET_FEED)
		{
			// ÊuÌZo
			D3DXVECTOR3 pos = D3DXVECTOR3((float)(-(int)(MAX_SET_POS_FEED / 2.0f) + rand() % ((int)(MAX_SET_POS_FEED)+1)),
				0.0f,
				(float)(-(int)(MAX_SET_POS_FEED / 2.0f) + rand() % ((int)(MAX_SET_POS_FEED)+1)));

			// ü«ÌZo
			D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, (D3DX_PI * 2 / 2.0f) - (float)(rand() % (int)((D3DX_PI * 2) * 100.0f) / 100.0f), 0.0f);

			// ÝuÍÍ(ü«)ÌZo
			float fRot = (D3DX_PI * 2 / 2.0f) - (float)(rand() % (int)((D3DX_PI * 2 + 1) * 100.0f) / 100.0f);

			// ÝuÍÍ(£)ÌZo
			float fLength = (float)(rand() % (int)((200.0f) * 100.0f) / 100.0f);

			// ÝuÌZo
			int nNumSet = rand() % (MAX_SET_FEED - g_nCntFeed);

			// Ýu
			RandSetFeed(pos, rot, fRot, fLength, nNumSet);
		}
	}
}

//---------------------------------------------------------------------------
// aæ¾
//---------------------------------------------------------------------------
Feed *GetFeed(void)
{
	return &g_Feed[0];
}

//---------------------------------------------------------------------------
// at@Cæ¾
//---------------------------------------------------------------------------
FeedFile *GetFeedFile(void)
{
	return &g_FeedFile;
}
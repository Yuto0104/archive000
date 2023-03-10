//**************************************************************************************************
//
// vC[`æ(player.cpp)
// AutherFú±l
//
//**************************************************************************************************

//***************************************************************************
// CN[h
//***************************************************************************
#include "main.h"
#include "player.h"
#include"file.h"
#include"input.h"
#include"camera.h"
#include"shadow.h"
#include"billboard.h"
#include"effect.h"
#include"line.h"
#include"model.h"
#include"camera.h"
#include"feed.h"
#include"calculation.h"
#include"combo.h"
#include"mouse.h"
#include"fade.h"
#include"sound.h"

//***************************************************************************
// }Nè`
//***************************************************************************
#define INIT_NUM_PLAYER				(10000)				// ¸_ÀWÌÅåÅ¬Ìúl
#define PLAYER_MOVE_SPEED			(2.0f)				// Ú®¬x
#define PLAYER_MAX_SPEED			(5.0f)				// Ú®¬x
#define PLAYER_ROTATE_SPEED			(0.1f)				// ñ]¬x
#define CAMERA_ROTATE_INTERVAL		(60)				// JÌ©®ñ]ÜÅÌ^C~O
#define	MAX_MOTION					(64)				// [VÅå
#define MAX_VIEW_ROT				(0.25f)				// ìp
#define MAX_COUNT_STATE				(60)				// óÔJE^ÌÅål
#define MAX_STAMINA					(200)				// X^~iÌÅål

//***************************************************************************
// O[oÏ
//***************************************************************************
static int				nCntFrame = 0;					// »ÝÌt[
static int				nCntNumKeySet;					// Ä¶ÌL[ÝèÔ
static int				nNumMotionCnt;					// Ä¶·é[VÔ
static int				nNumMotionCntOld;				// ÐÆÂOÌÄ¶·é[VÔ
static Player			g_Player;						// vC[îñ
static MotionSet		g_MotionSet[MAX_MOTION];		// [VÝèîñ
static PlayerFile		g_PlayerFile[MAX_MOTION];		// vC[t@Cîñ

//---------------------------------------------------------------------------
// vC[ú»
//---------------------------------------------------------------------------
void InitPlayer(void)
{
	// vC[t@CîñÌú»
	memset(&g_PlayerFile[0], 0, sizeof(g_PlayerFile));

	// vC[îñÌú»
	memset(&g_Player, 0, sizeof(g_Player));

	// fp[cÌú»
	memset(&g_Player.modeParts[0], 0, sizeof(g_Player.modeParts));

	// [VÝèÌú»
	memset(&g_MotionSet[0], 0, sizeof(g_MotionSet));
}

//---------------------------------------------------------------------------
// vC[I¹
//---------------------------------------------------------------------------
void UninitPlayer(void)
{
	for (int i = 0; i < g_Player.nMaxModelParts; i++)
	{
		// bVÌjü
		if (g_Player.modeParts[i].pMesh != NULL)
		{
			g_Player.modeParts[i].pMesh->Release();
			g_Player.modeParts[i].pMesh = NULL;
		}

		// }eAÌjü
		if (g_Player.modeParts[i].pBuffer != NULL)
		{
			g_Player.modeParts[i].pBuffer->Release();
			g_Player.modeParts[i].pBuffer = NULL;
		}
	}
}

//---------------------------------------------------------------------------
// vC[XV
//---------------------------------------------------------------------------
void UpdatePlayer(void)
{
	if (g_Player.bUse == true)
	{// gpµÄ¢é
		// JEgðCNg
		g_Player.nCntNotMove++;

		// ßÊuÌXV
		g_Player.posOld = g_Player.pos;

		nNumMotionCntOld = nNumMotionCnt;

		// j[g[V
		g_Player.MotionState = NEUTRAL_MOTION;

		// _bV
		DashPlayer();

		if (g_Player.PlayerState == NORMAL_STATE)
		{// vC[ÌÚ®
			MovePlayer();
		}
		// [V
		MotionPlayer((int)(g_Player.MotionState));

		//vC[Ìñ]
		RotatePlayer();

		// fÆÌ½è»è
		D3DXVECTOR3 aVtxA = WorldCastVtx(D3DXVECTOR3(-(g_Player.size.x / 2.0f), g_Player.pos.y, +(g_Player.size.z / 2.0f)), g_Player.pos, g_Player.rot);
		D3DXVECTOR3 aVtxB = WorldCastVtx(D3DXVECTOR3(+(g_Player.size.x / 2.0f), g_Player.pos.y, +(g_Player.size.z / 2.0f)), g_Player.pos, g_Player.rot);
		D3DXVECTOR3 aVtxC = WorldCastVtx(D3DXVECTOR3(+(g_Player.size.x / 2.0f), g_Player.pos.y, -(g_Player.size.z / 2.0f)), g_Player.pos, g_Player.rot);
		D3DXVECTOR3 aVtxD = WorldCastVtx(D3DXVECTOR3(-(g_Player.size.x / 2.0f), g_Player.pos.y, -(g_Player.size.z / 2.0f)), g_Player.pos, g_Player.rot);
		D3DXVECTOR3 aVtxAOld = WorldCastVtx(D3DXVECTOR3(g_Player.posOld.x - (g_Player.size.x / 2.0f), g_Player.posOld.y, g_Player.posOld.z + (g_Player.size.z / 2.0f)), g_Player.posOld, g_Player.rot);
		D3DXVECTOR3 aVtxBOld = WorldCastVtx(D3DXVECTOR3(g_Player.posOld.x + (g_Player.size.x / 2.0f), g_Player.posOld.y, g_Player.posOld.z + (g_Player.size.z / 2.0f)), g_Player.posOld, g_Player.rot);
		D3DXVECTOR3 aVtxCOld = WorldCastVtx(D3DXVECTOR3(g_Player.posOld.x + (g_Player.size.x / 2.0f), g_Player.posOld.y, g_Player.posOld.z - (g_Player.size.z / 2.0f)), g_Player.posOld, g_Player.rot);
		D3DXVECTOR3 aVtxDOld = WorldCastVtx(D3DXVECTOR3(g_Player.posOld.x - (g_Player.size.x / 2.0f), g_Player.posOld.y, g_Player.posOld.z - (g_Player.size.z / 2.0f)), g_Player.posOld, g_Player.rot);
		CollisionModel(&g_Player.pos, &g_Player.posOld, &aVtxA, &aVtxAOld);
		CollisionModel(&g_Player.pos, &g_Player.posOld, &aVtxB, &aVtxBOld);
		CollisionModel(&g_Player.pos, &g_Player.posOld, &aVtxC, &aVtxCOld);
		CollisionModel(&g_Player.pos, &g_Player.posOld, &aVtxD, &aVtxDOld);

		CollisionFeed(&g_Player.pos, &g_Player.posOld, &aVtxA, &aVtxAOld);
		CollisionFeed(&g_Player.pos, &g_Player.posOld, &aVtxB, &aVtxBOld);
		CollisionFeed(&g_Player.pos, &g_Player.posOld, &aVtxC, &aVtxCOld);
		CollisionFeed(&g_Player.pos, &g_Player.posOld, &aVtxD, &aVtxDOld);

		// JÌñèÝ
		if (g_Player.nCntNotMove >= CAMERA_ROTATE_INTERVAL)
		{
			//AutoRotateCamera();
		}

		// eÌÚ®
		SetPositionShadow(g_Player.nIdx, g_Player.pos, g_Player.rot, g_Player.size);

		//if (GetKeyboardTrigger(DIK_SPACE))
		//{// [SPACE]L[ª³ê½
		//	SetBillboard(g_Player.pos, g_Player.rot,1.0f);

		//	// GtFNgÌ¶¬
		//	SetEffect(g_Player.pos,
		//		D3DXVECTOR3(0.0f,0.0f,0.0f),
		//		D3DXCOLOR(1.0f, 0.5f, 0.5f, 1.0f),
		//		D3DCMP_ALWAYS,
		//		EFFECTTYPE_FIELD,
		//		10.0f,
		//		0.0f,
		//		0.0f,
		//		30,
		//		1,
		//		false);
		//}

		if (g_Player.PlayerState == NORMAL_STATE)
		{// R{ÔÌfNg
			g_Player.nCntComboTime--;
		}

		if (g_Player.nCntComboTime == 0)
		{// R{ÁZÔª0Ì
			if (g_Player.nMaxCombo < g_Player.nCntCombo)
			{
				g_Player.nMaxCombo = g_Player.nCntCombo;
			}
			g_Player.nCntCombo = 0;
		}

		// R{Zbg
		SetCombo(g_Player.nCntCombo, D3DXVECTOR3((30.0f * 2) * 3.0f + 1080.0f, 230.0f, 0.0f), D3DXVECTOR3(30.0f, 60.0f, 0.0f));

		// R{JE^[ÌXV
		AddCombo(g_Player.nCntCombo);

		// X^~iÌ¸­
		if ((int)(g_Player.fMoveDistance) % 20 == 0 
			&& (int)(g_Player.fMoveDistance) > 0
			&& g_Player.PlayerState == NORMAL_STATE)
		{// êèÈãÚ®µ½
			g_Player.nStamina--;

			if (g_Player.nStamina == 0)
			{// 0ÈºÌ
				//tF[hîñÌæ¾
				FADE fade;			//tF[hîñÖÌ|C^
				fade = GetFade();

				if (g_Player.nMaxCombo < g_Player.nCntCombo)
				{
					g_Player.nMaxCombo = g_Player.nCntCombo;
				}

				if (fade == FADE_NONE)
				{//tF[hªsíêÄÈ¢Æ«
					//UgæÊÖÚ®
					SetFade(MODE_RESULT);
				}
			}
		}
	}
}

//---------------------------------------------------------------------------
// vC[`æ
//---------------------------------------------------------------------------
void DrawPlayer(void)
{
	// foCXÌæ¾
	LPDIRECT3DDEVICE9	pDevice = GetDevice();

	D3DXMATRIX			mtxRot, mtxTrans;			// vZp}gbNX
	D3DMATERIAL9		matDef;						// »ÝÌ}eAÛ¶p
	D3DXMATERIAL		*pMat;						// }eAf[^ÖÌ|C^

	if (g_Player.bUse == true)
	{// gpµÄ¢é
		// [h}gbNXÌú»
		D3DXMatrixIdentity(&g_Player.mtxWorld);			// sñú»Ö

		// ü«Ì½f
		D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Player.rot.y, g_Player.rot.x, g_Player.rot.z);		// sññ]Ö
		D3DXMatrixMultiply(&g_Player.mtxWorld, &g_Player.mtxWorld, &mtxRot);							// sñ|¯ZÖ 

		// Êuð½f
		D3DXMatrixTranslation(&mtxTrans, g_Player.pos.x, g_Player.pos.y, g_Player.pos.z);				// sñÚ®Ö
		D3DXMatrixMultiply(&g_Player.mtxWorld, &g_Player.mtxWorld, &mtxTrans);							// sñ|¯ZÖ

		//// TCYÌ½f
		//D3DXMatrixScaling()

		for (int i = 0; i < g_Player.nMaxModelParts; i++)
		{
			// [h}gbNXÌú»
			D3DXMatrixIdentity(&g_Player.modeParts[i].mtxWorld);			// sñú»Ö

			// ü«Ì½f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, 
				g_Player.modeParts[i].rot.y, 
				g_Player.modeParts[i].rot.x, 
				g_Player.modeParts[i].rot.z);								// sññ]Ö
			D3DXMatrixMultiply(&g_Player.modeParts[i].mtxWorld, 
				&g_Player.modeParts[i].mtxWorld,
				&mtxRot);													// sñ|¯ZÖ 

			// Êuð½f
			D3DXMatrixTranslation(&mtxTrans, 
				g_Player.modeParts[i].pos.x, 
				g_Player.modeParts[i].pos.y,
				g_Player.modeParts[i].pos.z);								// sñÚ®Ö
			D3DXMatrixMultiply(&g_Player.modeParts[i].mtxWorld, 
				&g_Player.modeParts[i].mtxWorld,
				&mtxTrans);													// sñ|¯ZÖ

			// ep[cÌ[h}gbNXðÛ
			D3DXMATRIX mtxParent;

			if (g_Player.modeParts[i].nIdxModelParent == -1)
			{// efÌCfbNXª-1Ì
				mtxParent = g_Player.mtxWorld;
			}
			else
			{
				mtxParent = g_Player.modeParts[g_Player.modeParts[i].nIdxModelParent].mtxWorld;
			}

			// ©ªÌe}gbNXÆÌ|¯Z
			D3DXMatrixMultiply(&g_Player.modeParts[i].mtxWorld, &g_Player.modeParts[i].mtxWorld, &mtxParent);

			//// TCYÌ½f
			//D3DXMatrixScaling()

			// [h}gbNXÌÝè
			pDevice->SetTransform(D3DTS_WORLD, &g_Player.modeParts[i].mtxWorld);

			// »ÝÌ}eAðÛ
			pDevice->GetMaterial(&matDef);

			// }eAf[^ÖÌ|C^ðæ¾
			pMat = (D3DXMATERIAL*)g_Player.modeParts[i].pBuffer->GetBufferPointer();

			for (int nCntMat = 0; nCntMat < (int)g_Player.modeParts[i].nNumMat; nCntMat++)
			{
				// }eAÌÝè
				pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

				// vC[p[cÌ`æ
				g_Player.modeParts[i].pMesh->DrawSubset(nCntMat);
			}

			// ÛµÄ¢½}eAðß·
			pDevice->SetMaterial(&matDef);
		}
	}
}

//---------------------------------------------------------------------------
// vC[Ú®
//---------------------------------------------------------------------------
void MovePlayer(void)
{
	if (GetKeyboardPress(DIK_W)
		|| GetKeyboardPress(DIK_A)
		|| GetKeyboardPress(DIK_D)
		|| GetKeyboardPress(DIK_S))
	{// Ú®L[ª³ê½
		 // Ú®[V
		g_Player.MotionState = MOVE_MOTION;

		if (GetKeyboardPress(DIK_W))
		{// [ª]L[ª³ê½
			if (GetKeyboardPress(DIK_A))
			{// [¨]L[ª³ê½
				// Ú®ûüÌXV
				g_Player.rotDest.y = D3DX_PI * -0.25f;
			}
			else if (GetKeyboardPress(DIK_D))
			{// [©]L[ª³ê½
				// Ú®ûüÌXV
				g_Player.rotDest.y = D3DX_PI * 0.25f;
			}
			else
			{// Ú®ûüÌXV
				g_Player.rotDest.y = D3DX_PI * 0.0f;
			}
		}
		else if (GetKeyboardPress(DIK_S))
		{// [«]L[ª³ê½
			if (GetKeyboardPress(DIK_A))
			{// [¨]L[ª³ê½
				// Ú®ûüÌXV
				g_Player.rotDest.y = D3DX_PI * -0.75f;
			}
			else if (GetKeyboardPress(DIK_D))
			{// [©]L[ª³ê½
				// Ú®ûüÌXV
				g_Player.rotDest.y = D3DX_PI * 0.75f;
			}
			else
			{// Ú®ûüÌXVq
				g_Player.rotDest.y = D3DX_PI;
			}
		}
		else if (GetKeyboardPress(DIK_A))
		{// [¨]L[ª³ê½
			// Ú®ûüÌXV
			g_Player.rotDest.y = D3DX_PI * -0.5f;
		}
		else if (GetKeyboardPress(DIK_D))
		{// [©]L[ª³ê½
			// Ú®ûüÌXV
			g_Player.rotDest.y = D3DX_PI * 0.5f;
		}

		// JîñÌæ¾
		Camera *pCamera = GetCamera();

		// Ú®ûüÌZo
		g_Player.rotDest.y += pCamera->rot.y;

		if (g_Player.rotDest.y > D3DX_PI)
		{// Ú®ûüÌ³K»
			g_Player.rotDest.y -= D3DX_PI * 2;
		}
		else if (g_Player.rotDest.y < -D3DX_PI)
		{// Ú®ûüÌ³K»
			g_Player.rotDest.y += D3DX_PI * 2;
		}

		// _ÊuÆü«ÌXV
		g_Player.fSpeed = PLAYER_MOVE_SPEED + (0.1f * g_Player.nCntCombo);

		if (g_Player.fSpeed >= PLAYER_MAX_SPEED)
		{// ¬xªêèÈã¢Á½
			g_Player.fSpeed = PLAYER_MAX_SPEED;
		}

		// Ú®ÊÌvZ
		D3DXVECTOR3 move = D3DXVECTOR3(sinf(g_Player.rotDest.y), 0.0f, cosf(g_Player.rotDest.y));

		// Ú®
		g_Player.pos += move * g_Player.fSpeed;

		// Ú®£ÌÁZ
		g_Player.fMoveDistance += sqrtf((move.x * move.x) + (move.z * move.z));

		g_Player.rotDest.y -= D3DX_PI;

		// JEgð0É·é
		g_Player.nCntNotMove = 0;
	}

	//if (GetKeyboardPress(DIK_I) || GetKeyboardPress(DIK_K))
	//{
	//	if (GetKeyboardPress(DIK_I))
	//	{// [I]L[ª³ê½
	//	 // Ú®ûüÌXV
	//		g_Player.pos.y += PLAYER_MOVE_SPEED;
	//	}
	//	else if (GetKeyboardPress(DIK_K))
	//	{// [K]L[ª³ê½
	//	 // Ú®ûüÌXV
	//		g_Player.pos.y -= PLAYER_MOVE_SPEED;
	//	}

	//	// JEgð0É·é
	//	g_Player.nCntNotMove = 0;
	//}

	// ÚIÌü«Ìâ³
	if (g_Player.rotDest.y - g_Player.rot.y >= D3DX_PI)
	{// Ú®ûüÌ³K»
		g_Player.rotDest.y -= D3DX_PI * 2;
	}
	else if (g_Player.rotDest.y - g_Player.rot.y <= -D3DX_PI)
	{// Ú®ûüÌ³K»
		g_Player.rotDest.y += D3DX_PI * 2;
	}
}

//---------------------------------------------------------------------------
// vC[ñ]
//---------------------------------------------------------------------------
void RotatePlayer(void)
{
	// ü«ÌXV
	g_Player.rot.y += (g_Player.rotDest.y - g_Player.rot.y) * PLAYER_ROTATE_SPEED;

	if (g_Player.rot.y >= D3DX_PI)
	{// Ú®ûüÌ³K»
		g_Player.rot.y -= D3DX_PI * 2;
	}
	else if (g_Player.rot.y <= -D3DX_PI)
	{// Ú®ûüÌ³K»
		g_Player.rot.y += D3DX_PI * 2;
	}
}

//---------------------------------------------------------------------------
// vC[Ýè
//---------------------------------------------------------------------------
void SetPlayer(D3DXVECTOR3 pos,D3DXVECTOR3 rot,int	nMaxModelType,int	nMaxMotion)
{
	// vC[îñÌú»
	g_Player.pos = pos;																		// ÊuÌú»
	g_Player.posOld = g_Player.pos;															// ßÊuÌú»
	g_Player.rot = rot;																		// ü«Ìú»
	g_Player.vtxMin = D3DXVECTOR3(INIT_NUM_PLAYER, INIT_NUM_PLAYER, INIT_NUM_PLAYER);		// ¸_ÀWÌÅ¬l
	g_Player.vtxMax = D3DXVECTOR3(-INIT_NUM_PLAYER, -INIT_NUM_PLAYER, -INIT_NUM_PLAYER);	// ¸_ÀWÌÅål
	g_Player.size = D3DXVECTOR3(35.0f, 50.0f, 110.0f);										// å«³
	g_Player.PlayerState = NORMAL_STATE;													// ÊíóÔ
	g_Player.attackPos = D3DXVECTOR3(0.0f, 0.0f, -20.0f);									// ½è»èÌ[JÀW
	g_Player.fAttackRadius = 20.0f;															// ½è»èÌå«³
	g_Player.mtxWorld = {};																	// [h}gbNX
	g_Player.rotDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);										// ÚIÌü«
	g_Player.nMaxModelType = nMaxModelType;													// fÌ^Cv
	g_Player.nMaxMotion = nMaxMotion;														// [V
	g_Player.nCntCombo = 0;																	// R{
	g_Player.nMaxCombo = 0;																	// R{Åål
	g_Player.nMaxStamina = MAX_STAMINA;														// X^~iÌÅål
	g_Player.nStamina = g_Player.nMaxStamina;												// X^~i
	g_Player.nCntState = 0;																	// óÔJE^
	g_Player.fSpeed = PLAYER_MOVE_SPEED + (0.1f * g_Player.nCntCombo);						// Ú®¬x
	g_Player.fMoveDistance = 0.0f;															// Ú®£
	g_Player.bUse = true;																	// gpóµ
	g_Player.nCntNotMove = CAMERA_ROTATE_INTERVAL;

	// foCXÌæ¾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	for (int i = 0; i < g_Player.nMaxModelParts; i++)
	{
		// ÊuÆü«ÌúlðÛ¶
		g_Player.modeParts[i].posOrigin = g_Player.modeParts[i].pos;
		g_Player.modeParts[i].rotOrigin = g_Player.modeParts[i].rot;

		// p[cîñÌú»
		g_Player.modeParts[i].mtxWorld = {};																// [h}gbNX
		g_Player.modeParts[i].vtxMin = D3DXVECTOR3(INIT_NUM_PLAYER, INIT_NUM_PLAYER, INIT_NUM_PLAYER);		// ¸_ÀWÌÅ¬l
		g_Player.modeParts[i].vtxMax = D3DXVECTOR3(-INIT_NUM_PLAYER, -INIT_NUM_PLAYER, -INIT_NUM_PLAYER);	// ¸_ÀWÌÅål

		// Xt@CÌÇÝÝ
		D3DXLoadMeshFromX(&g_PlayerFile[g_Player.modeParts[i].nType].aName[0],
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_Player.modeParts[i].pBuffer,
			NULL,
			&g_Player.modeParts[i].nNumMat,
			&g_Player.modeParts[i].pMesh);

		// ¸_ÀWÌÅ¬lEÅålÌZo
		int			nNumVtx;		// ¸_
		DWORD		sizeFVF;		// ¸_tH[}bgÌTCY
		BYTE		*pVtxBuff;		// ¸_obt@ÖÌ|C^

		// ¸_Ìæ¾
		nNumVtx = g_Player.modeParts[i].pMesh->GetNumVertices();

		// ¸_tH[}bgÌTCYÌæ¾
		sizeFVF = D3DXGetFVFVertexSize(g_Player.modeParts[i].pMesh->GetFVF());

		// ¸_obt@ÌbN
		g_Player.modeParts[i].pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBuff);

		for (int nCntVtx = 0; nCntVtx < nNumVtx; nCntVtx++)
		{
			// ¸_ÀWÌãü
			D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBuff;

			if (vtx.x < g_Player.modeParts[i].vtxMin.x)
			{// ärÎÛª»ÝÌ¸_ÀW(X)ÌÅ¬læè¬³¢
				g_Player.modeParts[i].vtxMin.x = vtx.x;
			}
			if (vtx.y < g_Player.modeParts[i].vtxMin.y)
			{// ärÎÛª»ÝÌ¸_ÀW(Y)ÌÅ¬læè¬³¢
				g_Player.modeParts[i].vtxMin.y = vtx.y;
			}
			if (vtx.z < g_Player.modeParts[i].vtxMin.z)
			{// ärÎÛª»ÝÌ¸_ÀW(Z)ÌÅ¬læè¬³¢
				g_Player.modeParts[i].vtxMin.z = vtx.z;
			}

			if (vtx.x > g_Player.modeParts[i].vtxMax.x)
			{// ärÎÛª»ÝÌ¸_ÀW(X)ÌÅålæèå«¢
				g_Player.modeParts[i].vtxMax.x = vtx.x;
			}
			if (vtx.y > g_Player.modeParts[i].vtxMax.y)
			{// ärÎÛª»ÝÌ¸_ÀW(Y)ÌÅålæèå«¢
				g_Player.modeParts[i].vtxMax.y = vtx.y;
			}
			if (vtx.z > g_Player.modeParts[i].vtxMax.z)
			{// ärÎÛª»ÝÌ¸_ÀW(Z)ÌÅålæèå«¢
				g_Player.modeParts[i].vtxMax.z = vtx.z;
			}

			// ¸_tH[}bgÌTCYª|C^ðißé
			pVtxBuff += sizeFVF;
		}

		// ¸_ÌZo
		D3DXVECTOR3 aVtxMin = D3DXVECTOR3(g_Player.modeParts[i].vtxMin.x, g_Player.modeParts[i].vtxMin.y, g_Player.modeParts[i].vtxMin.z);
		D3DXVECTOR3 aVtxMax = D3DXVECTOR3(g_Player.modeParts[i].vtxMax.x, g_Player.modeParts[i].vtxMax.y, g_Player.modeParts[i].vtxMax.z);

		// ¸_ð[hÀWÖLXg
		aVtxMin = WorldCastVtx(aVtxMin, g_Player.modeParts[i].pos, g_Player.modeParts[i].rot);
		aVtxMax = WorldCastVtx(aVtxMax, g_Player.modeParts[i].pos, g_Player.modeParts[i].rot);

		if (aVtxMin.x < g_Player.vtxMin.x)
		{// ärÎÛª»ÝÌ¸_ÀW(X)ÌÅ¬læè¬³¢
			g_Player.vtxMin.x = aVtxMin.x;
		}
		if (aVtxMin.y < g_Player.vtxMin.y)
		{// ärÎÛª»ÝÌ¸_ÀW(Y)ÌÅ¬læè¬³¢
			g_Player.vtxMin.y = aVtxMin.y;
		}
		if (aVtxMin.z < g_Player.vtxMin.z)
		{// ärÎÛª»ÝÌ¸_ÀW(Z)ÌÅ¬læè¬³¢
			g_Player.vtxMin.z = aVtxMin.z;
		}

		if (aVtxMax.x > g_Player.vtxMax.x)
		{// ärÎÛª»ÝÌ¸_ÀW(X)ÌÅålæèå«¢
			g_Player.vtxMax.x = aVtxMax.x;
		}
		if (aVtxMax.y > g_Player.vtxMax.y)
		{// ärÎÛª»ÝÌ¸_ÀW(Y)ÌÅålæèå«¢
			g_Player.vtxMax.y = aVtxMax.y;
		}
		if (aVtxMax.z > g_Player.vtxMax.z)
		{// ärÎÛª»ÝÌ¸_ÀW(Z)ÌÅålæèå«¢
			g_Player.vtxMax.z = aVtxMax.z;
		}

		// ¸_obt@ÌAbN
		g_Player.modeParts[i].pMesh->UnlockVertexBuffer();
	}

	// CÌÝè
#ifndef _DEBUG
	SetLine(g_Player.pos, g_Player.rot, D3DXVECTOR3(-g_Player.size.x / 2.0f, -g_Player.size.y, g_Player.size.z / 2.0f), D3DXVECTOR3(g_Player.size.x / 2.0f, -g_Player.size.y, g_Player.size.z / 2.0f), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
	SetLine(g_Player.pos, g_Player.rot, D3DXVECTOR3(-g_Player.size.x / 2.0f, -g_Player.size.y, -g_Player.size.z / 2.0f), D3DXVECTOR3(-g_Player.size.x / 2.0f, -g_Player.size.y, g_Player.size.z / 2.0f), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
	SetLine(g_Player.pos, g_Player.rot, D3DXVECTOR3(-g_Player.size.x / 2.0f, -g_Player.size.y, -g_Player.size.z / 2.0f), D3DXVECTOR3(g_Player.size.x / 2.0f, -g_Player.size.y, -g_Player.size.z / 2.0f), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
	SetLine(g_Player.pos, g_Player.rot, D3DXVECTOR3(g_Player.size.x / 2.0f, -g_Player.size.y, -g_Player.size.z / 2.0f), D3DXVECTOR3(g_Player.size.x / 2.0f, -g_Player.size.y, g_Player.size.z / 2.0f), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));

	SetLine(g_Player.pos, g_Player.rot, D3DXVECTOR3(-g_Player.size.x / 2.0f, g_Player.size.y, g_Player.size.z / 2.0f), D3DXVECTOR3(g_Player.size.x / 2.0f, g_Player.size.y, g_Player.size.z / 2.0f), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
	SetLine(g_Player.pos, g_Player.rot, D3DXVECTOR3(-g_Player.size.x / 2.0f, g_Player.size.y, -g_Player.size.z / 2.0f), D3DXVECTOR3(-g_Player.size.x / 2.0f, g_Player.size.y, g_Player.size.z / 2.0f), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
	SetLine(g_Player.pos, g_Player.rot, D3DXVECTOR3(-g_Player.size.x / 2.0f, g_Player.size.y, -g_Player.size.z / 2.0f), D3DXVECTOR3(g_Player.size.x / 2.0f, g_Player.size.y, -g_Player.size.z / 2.0f), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
	SetLine(g_Player.pos, g_Player.rot, D3DXVECTOR3(g_Player.size.x / 2.0f, g_Player.size.y, -g_Player.size.z / 2.0f), D3DXVECTOR3(g_Player.size.x / 2.0f, g_Player.size.y, g_Player.size.z / 2.0f), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));

	SetLine(g_Player.pos, g_Player.rot, D3DXVECTOR3(-g_Player.size.x / 2.0f, -g_Player.size.y, g_Player.size.z / 2.0f), D3DXVECTOR3(-g_Player.size.x / 2.0f, g_Player.size.y, g_Player.size.z / 2.0f), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
	SetLine(g_Player.pos, g_Player.rot, D3DXVECTOR3(-g_Player.size.x / 2.0f, -g_Player.size.y, -g_Player.size.z / 2.0f), D3DXVECTOR3(-g_Player.size.x / 2.0f, g_Player.size.y, -g_Player.size.z / 2.0f), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
	SetLine(g_Player.pos, g_Player.rot, D3DXVECTOR3(g_Player.size.x / 2.0f, -g_Player.size.y, -g_Player.size.z / 2.0f), D3DXVECTOR3(g_Player.size.x / 2.0f, g_Player.size.y, -g_Player.size.z / 2.0f), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
	SetLine(g_Player.pos, g_Player.rot, D3DXVECTOR3(g_Player.size.x / 2.0f, -g_Player.size.y, g_Player.size.z / 2.0f), D3DXVECTOR3(g_Player.size.x / 2.0f, g_Player.size.y, g_Player.size.z / 2.0f), D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
#endif // _DEBUG

	// eÌÝè
	g_Player.nIdx = SetShadow(g_Player.pos, g_Player.rot, g_Player.size);

	AutoRotateCamera();
}

//---------------------------------------------------------------------------
// vC[Ì[V
//---------------------------------------------------------------------------
void MotionPlayer(int nCntMotionSet)
{
	KeySet* keyset = &g_MotionSet[nCntMotionSet].keySet[g_MotionSet[nCntMotionSet].nCntKeySet];
	MotionSet* motionSet = &g_MotionSet[nCntMotionSet];

	for (int nCntParts = 0; nCntParts < g_Player.nMaxModelParts; nCntParts++)
	{
		ModelParts* modelParts = &g_Player.modeParts[nCntParts];

		if (motionSet->nCntFrame == 0)
		{// t[JEgª0Ì
			// ÚIÌÊuÆü«ÌZo
			modelParts->posDest = (modelParts->posOrigin + keyset->key[nCntParts].pos) - modelParts->pos;
			modelParts->rotDest = (modelParts->rotOrigin + keyset->key[nCntParts].rot) - modelParts->rot;

			// Ú®ûüÌ³K»
			RotNormalization(modelParts->rotDest.x);
			RotNormalization(modelParts->rotDest.y);
			RotNormalization(modelParts->rotDest.z);
		}
				
		// Ïé¾
		D3DXVECTOR3 addPos = D3DXVECTOR3(modelParts->posDest / (float)(keyset->nFrame));
		D3DXVECTOR3 addRot = D3DXVECTOR3(modelParts->rotDest / (float)(keyset->nFrame));

		// ÊuÌÁZ
		modelParts->pos += addPos;

		//	ü«ÌÁZ
		modelParts->rot += addRot;

		// Ú®ûüÌ³K»
		RotNormalization(modelParts->rot.x);
		RotNormalization(modelParts->rot.y);
		RotNormalization(modelParts->rot.z);
	}

	// t[JEgÌÁZ
	motionSet->nCntFrame++;

	if (motionSet->nCntFrame >= keyset->nFrame)
	{// t[JEgªwèÌt[ð´¦½ê
		// t[Ìú»
		motionSet->nCntFrame = 0;

		// Ä¶ÌL[ÔÌÁZ
		motionSet->nCntKeySet++;

		if ((motionSet->nCntKeySet >= motionSet->nNumKey) && motionSet->bLoop)
		{// Ä¶ÌL[JEgªL[ÌÅålð´¦½Æ«A»Ì[Vª[vðgpµÄ¢é
			// Ä¶ÌL[JEgðú»
			motionSet->nCntKeySet = 0;
		}
	}
}

//---------------------------------------------------------------------------
// vC[Ì[Vuh
//---------------------------------------------------------------------------
void MotionBlend(int nCntMotionSet)
{
	for (int nCntParts = 0; nCntParts < g_Player.nMaxModelParts; nCntParts++)
	{
		if (g_MotionSet[nCntMotionSet].nCntFrame == 0)
		{// t[JEgª0Ì
		 // ÚIÌÊuÆü«ÌZo
			g_Player.modeParts[nCntParts].posDest = (g_Player.modeParts[nCntParts].posOrigin + g_MotionSet[nCntMotionSet].keySet[g_MotionSet[nCntMotionSet].nCntKeySet].key[nCntParts].pos) - g_Player.modeParts[nCntParts].pos;
			g_Player.modeParts[nCntParts].rotDest = (g_Player.modeParts[nCntParts].rotOrigin + g_MotionSet[nCntMotionSet].keySet[g_MotionSet[nCntMotionSet].nCntKeySet].key[nCntParts].rot) - g_Player.modeParts[nCntParts].rot;

			if (g_Player.modeParts[nCntParts].rotDest.x >= D3DX_PI)
			{// Ú®ûüÌ³K»
				g_Player.modeParts[nCntParts].rotDest.x -= D3DX_PI * 2;
			}
			else if (g_Player.modeParts[nCntParts].rotDest.x <= -D3DX_PI)
			{// Ú®ûüÌ³K»
				g_Player.modeParts[nCntParts].rotDest.x += D3DX_PI * 2;
			}
			if (g_Player.modeParts[nCntParts].rotDest.y >= D3DX_PI)
			{// Ú®ûüÌ³K»
				g_Player.modeParts[nCntParts].rotDest.y -= D3DX_PI * 2;
			}
			else if (g_Player.modeParts[nCntParts].rotDest.y <= -D3DX_PI)
			{// Ú®ûüÌ³K»
				g_Player.modeParts[nCntParts].rotDest.y += D3DX_PI * 2;
			}
			if (g_Player.modeParts[nCntParts].rotDest.z >= D3DX_PI)
			{// Ú®ûüÌ³K»
				g_Player.modeParts[nCntParts].rotDest.z -= D3DX_PI * 2;
			}
			else if (g_Player.modeParts[nCntParts].rotDest.z <= -D3DX_PI)
			{// Ú®ûüÌ³K»
				g_Player.modeParts[nCntParts].rotDest.z += D3DX_PI * 2;
			}
		}

		// Ïé¾
		D3DXVECTOR3 addPos = D3DXVECTOR3(g_Player.modeParts[nCntParts].posDest / (float)(g_MotionSet[nCntMotionSet].keySet[g_MotionSet[nCntMotionSet].nCntKeySet].nFrame));
		D3DXVECTOR3 addRot = D3DXVECTOR3(g_Player.modeParts[nCntParts].rotDest / (float)(g_MotionSet[nCntMotionSet].keySet[g_MotionSet[nCntMotionSet].nCntKeySet].nFrame));

		// ÊuÌÁZ
		g_Player.modeParts[nCntParts].pos += addPos;

		//	ü«ÌÁZ
		g_Player.modeParts[nCntParts].rot += addRot;

		if (g_Player.modeParts[nCntParts].rot.x >= D3DX_PI)
		{// Ú®ûüÌ³K»
			g_Player.modeParts[nCntParts].rot.x -= D3DX_PI * 2;
		}
		else if (g_Player.modeParts[nCntParts].rot.x <= -D3DX_PI)
		{// Ú®ûüÌ³K»
			g_Player.modeParts[nCntParts].rot.x += D3DX_PI * 2;
		}
		if (g_Player.modeParts[nCntParts].rot.y >= D3DX_PI)
		{// Ú®ûüÌ³K»
			g_Player.modeParts[nCntParts].rot.y -= D3DX_PI * 2;
		}
		else if (g_Player.modeParts[nCntParts].rot.y <= -D3DX_PI)
		{// Ú®ûüÌ³K»
			g_Player.modeParts[nCntParts].rot.y += D3DX_PI * 2;
		}
		if (g_Player.modeParts[nCntParts].rot.z >= D3DX_PI)
		{// Ú®ûüÌ³K»
			g_Player.modeParts[nCntParts].rot.z -= D3DX_PI * 2;
		}
		else if (g_Player.modeParts[nCntParts].rot.z <= -D3DX_PI)
		{// Ú®ûüÌ³K»
			g_Player.modeParts[nCntParts].rot.z += D3DX_PI * 2;
		}
	}

	// t[JEgÌÁZ
	g_MotionSet[nCntMotionSet].nCntFrame++;

	if (g_MotionSet[nCntMotionSet].nCntFrame >= g_MotionSet[nCntMotionSet].keySet[g_MotionSet[nCntMotionSet].nCntKeySet].nFrame)
	{// t[JEgªwèÌt[ð´¦½ê
		// t[Ìú»
		g_MotionSet[nCntMotionSet].nCntFrame = 0;

		// Ä¶ÌL[ÔÌÁZ
		g_MotionSet[nCntMotionSet].nCntKeySet++;

		if (g_MotionSet[nCntMotionSet].nCntKeySet >= g_MotionSet[nCntMotionSet].nNumKey && g_MotionSet[nCntMotionSet].bLoop == true)
		{// Ä¶ÌL[JEgªL[ÌÅålð´¦½Æ«A»Ì[Vª[vðgpµÄ¢é
			// Ä¶ÌL[JEgðú»
			g_MotionSet[nCntMotionSet].nCntKeySet = 0;
		}
	}
}

//---------------------------------------------------------------------------
// vC[ìp
//---------------------------------------------------------------------------
bool SearchPlayer(D3DXVECTOR3 *pos)
{
	// Ïé¾
	bool bSearchIn = false;

	// ìpÌ¼ªðZo
	float fSearchRot = (D3DX_PI * MAX_VIEW_ROT);

	// ÔÌ¢éü«
	D3DXVECTOR3 aVtxPos = g_Player.pos;
	float fFellowRot = atan2f(aVtxPos.x - pos->x, aVtxPos.z - pos->z);
	fFellowRot = RotNormalization(fFellowRot);

	// ärpÌü«ÌZo
	D3DXVECTOR3 sen = g_Player.pos;
	float fSearchRotRight = g_Player.rot.y - fSearchRot;
	float fSRROld = fSearchRotRight;
	fSearchRotRight = RotNormalization(fSearchRotRight);

	float fSearchRotLeft = g_Player.rot.y + fSearchRot;
	float fSRLOld = fSearchRotLeft;
	fSearchRotLeft = RotNormalization(fSearchRotLeft);

	if (fSRROld == fSearchRotRight && fSRLOld == fSearchRotLeft)
	{// ³K»OÌlª¯¶ê
		if (fSearchRotRight <= fFellowRot
			&& fSearchRotLeft >= fFellowRot)
		{// ìpàÉÚWª¢é
			bSearchIn = true;
		}
	}
	else
	{// ³K»OÌlªá¤ê
		if (fSearchRotRight <= fFellowRot
			|| fSearchRotLeft >= fFellowRot)
		{// ìpàÉÚWª¢é
			bSearchIn = true;
		}
	}

	return bSearchIn;
}

//---------------------------------------------------------------------------
// vC[U»è
//---------------------------------------------------------------------------
bool EatPlayer(D3DXVECTOR3 *pos, D3DXVECTOR3 size)
{
	// Ïé¾
	bool bOnCollison = false;
	D3DXVECTOR3 distance;

	// ¼aÌZo
	float fRadius = sqrtf((size.x * size.x) + (size.z * size.z)) / 2.0f;
	fRadius += g_Player.fAttackRadius / 2.0f;

	// ½è»èÌÊuð[hÀWÉLXg
	distance = WorldCastVtx(g_Player.attackPos, g_Player.pos, g_Player.rot);

	// ÚWÆ·ª
	distance = *pos - distance;
	float fDistance = sqrtf((distance.x * distance.x) + (distance.z * distance.z));
	
	if (fDistance <= fRadius)
	{// ½è»èI
		bOnCollison = true;
	}

	return bOnCollison;
}

//---------------------------------------------------------------------------
// vC[½è»è
//---------------------------------------------------------------------------
bool CollisionPlayer(D3DXVECTOR3 *vtx)
{
	// Ïé¾
	bool OnCollision = false;

	// ¸_ÌZo
	D3DXVECTOR3 aVecA = D3DXVECTOR3(-(g_Player.size.x / 2.0f), g_Player.pos.y, +(g_Player.size.z / 2.0f));
	D3DXVECTOR3 aVecB = D3DXVECTOR3(+(g_Player.size.x / 2.0f), g_Player.pos.y, +(g_Player.size.z / 2.0f));
	D3DXVECTOR3 aVecC = D3DXVECTOR3(+(g_Player.size.x / 2.0f), g_Player.pos.y, -(g_Player.size.z / 2.0f));
	D3DXVECTOR3 aVecD = D3DXVECTOR3(-(g_Player.size.x / 2.0f), g_Player.pos.y, -(g_Player.size.z / 2.0f));

	// ¸_ð[hÀWÖLXg
	aVecA = WorldCastVtx(aVecA, g_Player.pos, g_Player.rot);
	aVecB = WorldCastVtx(aVecB, g_Player.pos, g_Player.rot);
	aVecC = WorldCastVtx(aVecC, g_Player.pos, g_Player.rot);
	aVecD = WorldCastVtx(aVecD, g_Player.pos, g_Player.rot);

	if (g_Player.pos.x < g_Player.pos.x)g_Player.pos.x = g_Player.pos.x;

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
		// ð_ÌZo
		g_Player.pos.x = g_Player.posOld.x;
		g_Player.pos.z = g_Player.posOld.z;
		OnCollision = true;
	}

	return OnCollision;
}

//---------------------------------------------------------------------------
// vC[Ì_bV
//---------------------------------------------------------------------------
void DashPlayer(void)
{
	if(GetKeyboardTrigger(DIK_LSHIFT))
	{// ¶Vtg{^ð³ê½
		if (g_Player.nStamina > DASH_STAMINA)
		{// _bVÉg¤X^~iÈã é
			if (g_Player.PlayerState == NORMAL_STATE)
			{// ÊíóÔÌ
				g_Player.PlayerState = DASH_STATE;
				g_Player.nCntState = MAX_COUNT_STATE;
				g_Player.nStamina -= DASH_STAMINA;
				g_Player.fSpeed = PLAYER_MOVE_SPEED + (0.1f * g_Player.nCntCombo);

				if (g_Player.fSpeed >= PLAYER_MAX_SPEED)
				{// ¬xªêèÈã¢Á½
					g_Player.fSpeed = PLAYER_MAX_SPEED;
				}

				//TEhÌÄ¶
				PlaySound(SOUND_LABEL_SE_APPEAR);
			}
		}
	}

	if (g_Player.PlayerState == DASH_STATE)
	{// _bVóÔ
		// Ú®[V
		g_Player.MotionState = MOVE_MOTION;
		float fMaxSpeed = 3.0f;
		g_Player.fSpeed += fMaxSpeed / (float)(g_Player.nCntState);

		// Ú®
		g_Player.pos.x += sinf(g_Player.rot.y - D3DX_PI) * g_Player.fSpeed;
		g_Player.pos.z += cosf(g_Player.rot.y - D3DX_PI) * g_Player.fSpeed;

		g_Player.nCntState--;

		if (g_Player.nCntState <= 0)
		{
			g_Player.PlayerState = NORMAL_STATE;
		}
	}
}

//---------------------------------------------------------------------------
// vC[æ¾
//---------------------------------------------------------------------------
Player *GetPlayer(void)
{
	return &g_Player;
}

//---------------------------------------------------------------------------
// vC[t@Cæ¾
//---------------------------------------------------------------------------
PlayerFile	*GetPlayerFile(void)
{
	return &g_PlayerFile[0];
}

//---------------------------------------------------------------------------
// [Væ¾
//---------------------------------------------------------------------------
MotionSet	*GetMotionSet(void)
{
	return &g_MotionSet[0];
}
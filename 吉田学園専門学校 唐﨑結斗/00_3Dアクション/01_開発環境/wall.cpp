//**************************************************************************************************
//
// Η`ζ(wall.cpp)
// AutherFϊ±l
//
//**************************************************************************************************

//***************************************************************************
// CN[h
//***************************************************************************
#include "main.h"
#include "wall.h"
#include"file.h"
#include"model.h"
#include"billboard.h"
#include"shadow.h"
#include"effect.h"
#include "calculation.h"

//***************************************************************************
// }Nθ`
//***************************************************************************
#define MAX_WALL_VERTEX			(4)					// ΗΜΈ_
#define MAX_WALL				(128)				// ΗΜΕε
#define MAX_WALL_WIDH			(200.0f)			// ΗΜ
#define MAX_WALL_HEIGHT			(100.0f)			// ΗΜ³

//***************************************************************************
// O[oΟ
//***************************************************************************
static LPDIRECT3DVERTEXBUFFER9		g_pVtxBuffWall = NULL;		// Έ_obt@ΦΜ|C^
static LPDIRECT3DTEXTURE9			g_pTextureWall = NULL;		// eNX`ΦΜ|C^
static Wall							g_Wall[MAX_WALL];			// ΗξρΜζΎ

//---------------------------------------------------------------------------
// Ηϊ»
//---------------------------------------------------------------------------
void InitWall(void)
{
	// t@CΟΜιΎΖγό
	char aFile[128] = FILE_TEXTURE_DATA;
	strcat(aFile, "wall000.jpg");

	// foCXΜζΎ
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//Έ_obt@ΜΆ¬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * MAX_WALL_VERTEX * MAX_WALL,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffWall,
		NULL);

	// ΗΙ£θt―ιeNX`ΜΗέέ
	D3DXCreateTextureFromFile(pDevice, aFile, &g_pTextureWall);

	// Έ_ξρΜζΎ
	VERTEX_3D *pVtx = NULL;

	// Έ_obt@πbN
	g_pVtxBuffWall->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntWall = 0; nCntWall < MAX_WALL; nCntWall++)
	{
		// ΗξρΜϊ»
		g_Wall[nCntWall].pos = {};											// Κu
		g_Wall[nCntWall].rot = {};											// ό«
		g_Wall[nCntWall].mtxWorld = {};										// [h}gbNX
		g_Wall[nCntWall].col = {};											// J[
		g_Wall[nCntWall].bUse = false;										// gpσ΅

		// Έ_ΐW
		pVtx[0].pos = D3DXVECTOR3(-MAX_WALL_WIDH, MAX_WALL_HEIGHT,0.0f);
		pVtx[1].pos = D3DXVECTOR3(MAX_WALL_WIDH, MAX_WALL_HEIGHT, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-MAX_WALL_WIDH, -MAX_WALL_HEIGHT, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(MAX_WALL_WIDH, -MAX_WALL_HEIGHT, 0.0f);

		// eΈ_Μ@όΜέθ(*xNgΜε«³Ν1Ι·ιKvͺ ι)
		pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, 1.0f);

		// Έ_J[Μέθ
		pVtx[0].col = g_Wall[nCntWall].col;
		pVtx[1].col = g_Wall[nCntWall].col;
		pVtx[2].col = g_Wall[nCntWall].col;
		pVtx[3].col = g_Wall[nCntWall].col;

		// eNX`ΐW
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;		//Έ_f[^Μ|C^π4Βͺiίι
	}

	// Έ_obt@ΜAbN
	g_pVtxBuffWall->Unlock();
}

//---------------------------------------------------------------------------
// ΗIΉ
//---------------------------------------------------------------------------
void UninitWall(void)
{
	//eNX`Μjό	  
	if (g_pTextureWall != NULL)
	{
		g_pTextureWall->Release();

		g_pTextureWall = NULL;
	}

	// Έ_obt@Μjό
	if (g_pVtxBuffWall != NULL)
	{
		g_pVtxBuffWall->Release();
		g_pVtxBuffWall = NULL;
	}
}

//---------------------------------------------------------------------------
// ΗXV
//---------------------------------------------------------------------------
void UpdateWall(void)
{
	
}

//---------------------------------------------------------------------------
// Η`ζ
//---------------------------------------------------------------------------
void DrawWall(void)
{
	// foCXΜζΎ
	LPDIRECT3DDEVICE9	pDevice = GetDevice();
	D3DXMATRIX			mtxRot, mtxTrans;			// vZp}gbNX

	// eNX`Μέθ
	pDevice->SetTexture(0, g_pTextureWall);

	for (int nCntWall = 0; nCntWall < MAX_WALL; nCntWall++)
	{
		if (g_Wall[nCntWall].bUse == true)
		{// Ηͺgp³κΔ’ιΖ«
			// [h}gbNXΜϊ»
			// sρϊ»Φ(ζκψΜ[sρ]π[PΚsρ]Ιϊ»)
			D3DXMatrixIdentity(&g_Wall[nCntWall].mtxWorld);

			// ό«Μ½f
			// sρρ]Φ (ζκψΙ[[(y)sb`(x)[(z)]ϋόΜρ]sρπμ¬)
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Wall[nCntWall].rot.y, g_Wall[nCntWall].rot.x, g_Wall[nCntWall].rot.z);

			// sρ|―ZΦ (ζρψ * ζOψπζκψΙi[)
			D3DXMatrixMultiply(&g_Wall[nCntWall].mtxWorld, &g_Wall[nCntWall].mtxWorld, &mtxRot);

			// Κuπ½f
			// sρΪ?Φ (ζκψΙX,Y,ZϋόΜΪ?sρπμ¬)
			D3DXMatrixTranslation(&mtxTrans, g_Wall[nCntWall].pos.x, g_Wall[nCntWall].pos.y, g_Wall[nCntWall].pos.z);
			D3DXMatrixMultiply(&g_Wall[nCntWall].mtxWorld, &g_Wall[nCntWall].mtxWorld, &mtxTrans);		// sρ|―ZΦ

			// [h}gbNXΜέθ
			pDevice->SetTransform(D3DTS_WORLD, &g_Wall[nCntWall].mtxWorld);

			// Έ_obt@πfoCXΜf[^Xg[Ιέθ
			pDevice->SetStreamSource(0, g_pVtxBuffWall, 0, sizeof(VERTEX_3D));

			// Έ_tH[}bg
			pDevice->SetFVF(FVF_VERTEX_3D);

			// Η`ζ
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, MAX_WALL_VERTEX * nCntWall, 2);
		}
	}

	// eNX`Μπ
	pDevice->SetTexture(0, NULL);
}

//---------------------------------------------------------------------------
// Ηέθ
//---------------------------------------------------------------------------
void SetWall(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXCOLOR col)
{
	// ΟιΎ
	int nCntWall;

	// Έ_ξρΜζΎ
	VERTEX_3D *pVtx = NULL;

	// Έ_obt@πbN
	g_pVtxBuffWall->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntWall = 0; nCntWall < MAX_WALL; nCntWall++)
	{
		if (g_Wall[nCntWall].bUse == false)
		{
			// ΗξρΜέθ
			g_Wall[nCntWall].pos = pos;																		// Κu
			g_Wall[nCntWall].rot = D3DXVECTOR3((D3DX_PI * rot.x),(D3DX_PI * rot.y),(D3DX_PI * rot.z));		// ό«
			g_Wall[nCntWall].mtxWorld = {};																	// [h}gbNX
			g_Wall[nCntWall].col = col;																		// J[
			g_Wall[nCntWall].bUse = true;																	// gpσ΅

			// Έ_J[Μέθ
			pVtx[0].col = g_Wall[nCntWall].col;
			pVtx[1].col = g_Wall[nCntWall].col;
			pVtx[2].col = g_Wall[nCntWall].col;
			pVtx[3].col = g_Wall[nCntWall].col;
			break;
		}

		pVtx += 4;		//Έ_f[^Μ|C^π4Βͺiίι
	}

	// Έ_obt@ΜAbN
	g_pVtxBuffWall->Unlock();
}

//---------------------------------------------------------------------------
// ΗΖr{[hΜ½θ»θ
//---------------------------------------------------------------------------
bool	CollisionWallBillBoard(D3DXVECTOR3 *pos, D3DXVECTOR3 *posOld, int nIdx)
{
	// ΟιΎ
	int		nCntWall;
	bool	bIsLanding = false;

	// Έ_ξρΜζΎ
	VERTEX_3D *pVtx = NULL;

	// Έ_obt@πbN
	g_pVtxBuffWall->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntWall = 0; nCntWall < MAX_WALL; nCntWall++)
	{
		if (g_Wall[nCntWall].bUse == true)
		{
			// ΟιΎ
			D3DXVECTOR3 aVtx0 = WorldCastVtx(pVtx[0].pos, g_Wall[nCntWall].pos, g_Wall[nCntWall].rot);
			D3DXVECTOR3 aVtx1 = WorldCastVtx(pVtx[1].pos, g_Wall[nCntWall].pos, g_Wall[nCntWall].rot);
			D3DXVECTOR3 aVecLine = aVtx1 - aVtx0;															// ΗΜxNg
			D3DXVECTOR3 aVecPos = D3DXVECTOR3(pos->x - aVtx0.x, pos->y - aVtx0.y, pos->z - aVtx0.z);		// ΚuΜxNg
			// OΟπgp΅½½θ»θ
			if (0.0f > (aVecLine.z * aVecPos.x) - (aVecLine.x * aVecPos.z))
			{
				/*bIsLanding = true;*/
				Billboard *pBillboard = GetBillboard();
				pBillboard += nIdx;

				D3DXVECTOR3 VecC = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				D3DXVECTOR3 aVtx0 = WorldCastVtx(pVtx[0].pos, g_Wall[nCntWall].pos, g_Wall[nCntWall].rot);
				D3DXVECTOR3 aVtx1 = WorldCastVtx(pVtx[1].pos, g_Wall[nCntWall].pos, g_Wall[nCntWall].rot);
				D3DXVECTOR3 aVtx2 = WorldCastVtx(pVtx[2].pos, g_Wall[nCntWall].pos, g_Wall[nCntWall].rot);
				D3DXVECTOR3 aVecA = aVtx1 - aVtx0;		// ΗΜxNg
				D3DXVECTOR3 aVecB = aVtx2 - aVtx0;		// ΗΜxNg

				// OΟπgp΅Δ@όΜZo
				D3DXVec3Cross(&VecC, &aVecA, &aVecB);
				D3DXVec3Normalize(&VecC, &VecC);

				VecC *= (-pBillboard->move.x * VecC.x) + (-pBillboard->move.z * VecC.z);

				// ½Λ
				pBillboard->move += VecC * 2.0f;

				break;
			}
		}
	}

	return bIsLanding;

	// Έ_obt@ΜAbN
	g_pVtxBuffWall->Unlock();
}
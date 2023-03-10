//**************************************************************************************************
//
// ~`ζ(cylinder.cpp)
// AutherFϊ±l
//
//**************************************************************************************************

//***************************************************************************
// CN[h
//***************************************************************************
#include "main.h"
#include "cylinder.h"
#include"file.h"

//***************************************************************************
// }Nθ`
//***************************************************************************
#define CYLINDER_X_BLOCK2			(10)						// XϋόΜubN
#define CYLINDER_Z_BLOCK2			(3)						// ZϋόΜubN

// ubN + 1
#define MESHBLOCK_X_ADD_ONE		(CYLINDER_X_BLOCK2 + 1)
#define MESHBLOCK_Z_ADD_ONE		(CYLINDER_Z_BLOCK2 + 1)

// 1ρΈ_
#define CYLINDER_RHINE_VTX_ONE		(CYLINDER_X_BLOCK2 * 2 + 2)

// ~ΜΈ_
#define MAX_CYLINDER_VERTEX			(MESHBLOCK_X_ADD_ONE * MESHBLOCK_Z_ADD_ONE)		

// ~Μ|S
#define MAX_CYLINDER_POLYGON		((CYLINDER_X_BLOCK2 * CYLINDER_Z_BLOCK2 * 2) + (((CYLINDER_Z_BLOCK2 - 1) * 2) * 2))

// ~ΜCfbNX
#define MAX_CYLINDER_INDEX			((CYLINDER_RHINE_VTX_ONE * CYLINDER_Z_BLOCK2) + ((CYLINDER_Z_BLOCK2 - 1) * 2))	

// ~TCY
#define MAX_CYLINDER_SIZE			(10.0f)

// ~ΜΌaΜ·³
#define CYLINDER_RADIUS				(50.0f)

//***************************************************************************
// O[oΟ
//***************************************************************************
static LPDIRECT3DVERTEXBUFFER9		g_pVtxBuffCylinder = NULL;		// Έ_obt@ΦΜ|C^
static LPDIRECT3DTEXTURE9			g_pTextureCylinder = NULL;		// eNX`ΦΜ|C^
static LPDIRECT3DINDEXBUFFER9		g_pIdzBuffCylinder = NULL;		// CfbNXobt@ΦΜ|C^
static Cylinder						g_Cylinder;						// ~ξρΜζΎ

//---------------------------------------------------------------------------
// ~ϊ»
//---------------------------------------------------------------------------
void InitCylinder(void)
{
	g_Cylinder.pos = D3DXVECTOR3(0.0f, 0.0f, 100.0f);

	// t@CΟΜιΎΖγό
	char aFile[128] = FILE_TEXTURE_DATA;
	strcat(aFile, "sky001.jpg");

	// foCXΜζΎ
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	// ~Ι£θt―ιeNX`ΜΗέέ
	D3DXCreateTextureFromFile(pDevice, aFile, &g_pTextureCylinder);

	// Έ_obt@ΜΆ¬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * MAX_CYLINDER_VERTEX,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffCylinder,
		NULL);

	// CfbNXobt@ΜΆ¬
	pDevice->CreateIndexBuffer(sizeof(WORD) * MAX_CYLINDER_INDEX,
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&g_pIdzBuffCylinder,
		NULL);

	// Έ_ξρΜζΎ
	VERTEX_3D *pVtx = NULL;

	// Έ_obt@πbN
	g_pVtxBuffCylinder->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntV = 0; nCntV < CYLINDER_Z_BLOCK2 + 1; nCntV++)
	{
		for (int nCntH = 0; nCntH < CYLINDER_X_BLOCK2 + 1; nCntH++)
		{// ΟιΎ
			float fRot = ((D3DX_PI * 2.0f) / CYLINDER_X_BLOCK2) * nCntH;		// pxΜέθ

			// Έ_ΐWΜέθ
			pVtx[0].pos.x = sinf(fRot) * CYLINDER_RADIUS;
			pVtx[0].pos.z = cosf(fRot) * CYLINDER_RADIUS;
			pVtx[0].pos.y = MAX_CYLINDER_SIZE * nCntV;

			// eΈ_Μ@όΜέθ(*xNgΜε«³Ν1Ι·ιKvͺ ι)
			pVtx[0].nor.x = pVtx[0].pos.x;
			pVtx[0].nor.z = pVtx[0].pos.z;
			pVtx[0].nor.y = 0.0f;
			D3DXVec3Normalize(&pVtx[0].nor, &pVtx[0].nor);

			// Έ_J[Μέθ
			pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

			// eNX`ΐWΜέθ
			pVtx[0].tex = D3DXVECTOR2(1.0f / CYLINDER_X_BLOCK2 * nCntH, 1.0f / CYLINDER_X_BLOCK2 * nCntV);

			pVtx++;
		}
	}

	// CfbNXobt@πbN
	WORD *pIdx;
	g_pIdzBuffCylinder->Lock(0, 0, (void**)&pIdx, 0);

	// CfbNXΜέθ
	for (int nCntZ = 0; nCntZ < CYLINDER_Z_BLOCK2; nCntZ++)
	{
		for (int nCntX = 0; nCntX < MESHBLOCK_X_ADD_ONE; nCntX++)
		{// CfbNXΜέθ
			pIdx[0] = MESHBLOCK_X_ADD_ONE + nCntX + nCntZ * MESHBLOCK_X_ADD_ONE;
			pIdx[1] = MESHBLOCK_X_ADD_ONE + nCntX + nCntZ * MESHBLOCK_X_ADD_ONE - MESHBLOCK_X_ADD_ONE;

			pIdx += 2;
		}

		if (nCntZ != CYLINDER_Z_BLOCK2)
		{// ΕεΘΊΜ
		 // kή|SCfbNXΜέθ
			pIdx[0] = MESHBLOCK_X_ADD_ONE * nCntZ + CYLINDER_X_BLOCK2;
			pIdx[1] = MESHBLOCK_X_ADD_ONE * (nCntZ + 2);

			pIdx += 2;
		}
	}

	// Έ_obt@ΜAbN
	g_pVtxBuffCylinder->Unlock();

	// Έ_obt@ΜAbN
	g_pIdzBuffCylinder->Unlock();
}

//---------------------------------------------------------------------------
// ~IΉ
//---------------------------------------------------------------------------
void UninitCylinder(void)
{
	// eNX`Μjό	  
	if (g_pTextureCylinder != NULL)
	{
		g_pTextureCylinder->Release();
		g_pTextureCylinder = NULL;
	}

	// Έ_obt@Μjό
	if (g_pVtxBuffCylinder != NULL)
	{
		g_pVtxBuffCylinder->Release();
		g_pVtxBuffCylinder = NULL;
	}

	// CfbNXobt@Μjό	  
	if (g_pIdzBuffCylinder != NULL)
	{
		g_pIdzBuffCylinder->Release();
		g_pIdzBuffCylinder = NULL;
	}
}

//---------------------------------------------------------------------------
// ~XV
//---------------------------------------------------------------------------
void UpdateCylinder(void)
{

}

//---------------------------------------------------------------------------
// ~`ζ
//---------------------------------------------------------------------------
void DrawCylinder(void)
{
	// foCXΜζΎ
	LPDIRECT3DDEVICE9	pDevice = GetDevice();
	D3DXMATRIX			mtxRot, mtxTrans;			// vZp}gbNX

	// [h}gbNXΜϊ»
	// sρϊ»Φ(ζκψΜ[sρ]π[PΚsρ]Ιϊ»)
	D3DXMatrixIdentity(&g_Cylinder.mtxWorld);

	// ό«Μ½f
	// sρρ]Φ (ζκψΙ[[(y)sb`(x)[(z)]ϋόΜρ]sρπμ¬)
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Cylinder.rot.y, g_Cylinder.rot.x, g_Cylinder.rot.z);

	// sρ|―ZΦ (ζρψ * ζOψπζκψΙi[)
	D3DXMatrixMultiply(&g_Cylinder.mtxWorld, &g_Cylinder.mtxWorld, &mtxRot);

	// Κuπ½f
	// sρΪ?Φ (ζκψΙX,Y,ZϋόΜΪ?sρπμ¬)
	D3DXMatrixTranslation(&mtxTrans, g_Cylinder.pos.x, g_Cylinder.pos.y, g_Cylinder.pos.z);
	D3DXMatrixMultiply(&g_Cylinder.mtxWorld, &g_Cylinder.mtxWorld, &mtxTrans);						// sρ|―ZΦ

	// [h}gbNXΜέθ
	pDevice->SetTransform(D3DTS_WORLD, &g_Cylinder.mtxWorld);

	// Έ_obt@πfoCXΜf[^Xg[Ιέθ
	pDevice->SetStreamSource(0, g_pVtxBuffCylinder, 0, sizeof(VERTEX_3D));

	// CfbNXobt@πf[^Xg[Ιέθ
	pDevice->SetIndices(g_pIdzBuffCylinder);

	// Έ_tH[}bg
	pDevice->SetFVF(FVF_VERTEX_3D);

	//eNX`Μέθ
	pDevice->SetTexture(0, g_pTextureCylinder);

	// ~`ζ
	pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0, 0, MAX_CYLINDER_VERTEX, 0, MAX_CYLINDER_POLYGON);

	// eNX`Μπ
	pDevice->SetTexture(0, NULL);
}
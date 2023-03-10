//**************************************************************************************************
//
// `ζ(sphere.cpp)
// AutherFϊ±l
//
//**************************************************************************************************

//***************************************************************************
// CN[h
//***************************************************************************
#include "main.h"
#include "sphere.h"
#include"file.h"

//***************************************************************************
// }Nθ`
//***************************************************************************
#define SPHERE_X_BLOCK2				(100)						// XϋόΜubN
#define SPHERE_Z_BLOCK2				(10)						// ZϋόΜubN

// ubN + 1
#define MESHBLOCK_X_ADD_ONE			(SPHERE_X_BLOCK2 + 1)
#define MESHBLOCK_Z_ADD_ONE			(SPHERE_Z_BLOCK2 + 1)

// 1ρΈ_
#define SPHERE_RHINE_VTX_ONE		(SPHERE_X_BLOCK2 * 2 + 2)

// ΜΈ_
#define MAX_SPHERE_VERTEX			(MESHBLOCK_X_ADD_ONE * MESHBLOCK_Z_ADD_ONE)		

// Μ|S
#define MAX_SPHERE_POLYGON			((SPHERE_X_BLOCK2 * SPHERE_Z_BLOCK2 * 2) + (((SPHERE_Z_BLOCK2 - 1) * 2) * 2))

// ΜCfbNX
#define MAX_SPHERE_INDEX			((SPHERE_RHINE_VTX_ONE * SPHERE_Z_BLOCK2) + ((SPHERE_Z_BLOCK2 - 1) * 2))	

// TCY
#define MAX_SPHERE_SIZE				(10.0f)

// ΜΌaΜ·³
#define SPHERE_RADIUS				(50.0f)


//***************************************************************************
// O[oΟ
//***************************************************************************
LPDIRECT3DVERTEXBUFFER9		g_pVtxBuffSphere = NULL;		// Έ_obt@ΦΜ|C^
LPDIRECT3DTEXTURE9			g_pTextureSphere = NULL;		// eNX`ΦΜ|C^
LPDIRECT3DINDEXBUFFER9		g_pIdzBuffSphere = NULL;		// CfbNXobt@ΦΜ|C^
Sphere						g_Sphere;						// ξρΜζΎ

//---------------------------------------------------------------------------
// ϊ»
//---------------------------------------------------------------------------
void InitSphere(void)
{
	// t@CΟΜιΎΖγό
	char aFile[128] = FILE_TEXTURE_DATA;
	strcat(aFile, "sky001.jpg");

	// foCXΜζΎ
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	// Ι£θt―ιeNX`ΜΗέέ
	D3DXCreateTextureFromFile(pDevice, aFile, &g_pTextureSphere);

	// Έ_obt@ΜΆ¬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * MAX_SPHERE_VERTEX,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffSphere,
		NULL);

	// CfbNXobt@ΜΆ¬
	pDevice->CreateIndexBuffer(sizeof(WORD) * MAX_SPHERE_INDEX,
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&g_pIdzBuffSphere,
		NULL);

	// Έ_ξρΜζΎ
	VERTEX_3D *pVtx = NULL;

	// Έ_obt@πbN
	g_pVtxBuffSphere->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntV = 0; nCntV < SPHERE_Z_BLOCK2 + 1; nCntV++)
	{
		for (int nCntH = 0; nCntH < SPHERE_X_BLOCK2 + 1; nCntH++)
		{// ΟιΎ
			float fRot = ((-D3DX_PI * 2.0f) / SPHERE_X_BLOCK2) * nCntH;			// Y²ΜpxΜέθ
			float fHalfRot = (-D3DX_PI / SPHERE_Z_BLOCK2) * nCntV;				// ΌΜZ²ΜpxΜΌͺ

			// ³ΖΌaΜέθ
			D3DXVECTOR2 radius = D3DXVECTOR2(sinf(fHalfRot) * SPHERE_RADIUS, cosf(fHalfRot) * SPHERE_RADIUS);

			//// Έ_ΐWΜέθ
			//pVtx[0].pos.x = sinf(fRot) * radius.y;
			//pVtx[0].pos.z = cosf(fRot) * radius.y;
			//pVtx[0].pos.y = radius.x;

			// _ΜZo
			pVtx[0].pos.z = sinf(fHalfRot) * cosf(fRot) * SPHERE_RADIUS;
			pVtx[0].pos.x = sinf(fHalfRot) * sinf(fRot) * SPHERE_RADIUS;
			pVtx[0].pos.y = cosf(fHalfRot) * SPHERE_RADIUS;

			// eΈ_Μ@όΜέθ(*xNgΜε«³Ν1Ι·ιKvͺ ι)
			pVtx[0].nor.x = pVtx[0].pos.x;
			pVtx[0].nor.z = pVtx[0].pos.z;
			pVtx[0].nor.y = 0.0f;
			D3DXVec3Normalize(&pVtx[0].nor, &pVtx[0].nor);

			// Έ_J[Μέθ
			pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

			// eNX`ΐWΜέθ
			pVtx[0].tex = D3DXVECTOR2(1.0f / SPHERE_X_BLOCK2 * nCntH, 1.0f / SPHERE_Z_BLOCK2 * nCntV);

			pVtx++;
		}
	}

	// CfbNXobt@πbN
	WORD *pIdx;
	g_pIdzBuffSphere->Lock(0, 0, (void**)&pIdx, 0);

	// CfbNXΜέθ
	for (int nCntZ = 0; nCntZ < SPHERE_Z_BLOCK2; nCntZ++)
	{
		for (int nCntX = 0; nCntX < MESHBLOCK_X_ADD_ONE; nCntX++)
		{// CfbNXΜέθ
			pIdx[0] = MESHBLOCK_X_ADD_ONE + nCntX + nCntZ * MESHBLOCK_X_ADD_ONE;
			pIdx[1] = MESHBLOCK_X_ADD_ONE + nCntX + nCntZ * MESHBLOCK_X_ADD_ONE - MESHBLOCK_X_ADD_ONE;

			pIdx += 2;
		}

		if (nCntZ != SPHERE_Z_BLOCK2)
		{// ΕεΘΊΜ
		 // kή|SCfbNXΜέθ
			pIdx[0] = MESHBLOCK_X_ADD_ONE * nCntZ + SPHERE_X_BLOCK2;
			pIdx[1] = MESHBLOCK_X_ADD_ONE * (nCntZ + 2);

			pIdx += 2;
		}
	}

	// Έ_obt@ΜAbN
	g_pVtxBuffSphere->Unlock();

	// Έ_obt@ΜAbN
	g_pIdzBuffSphere->Unlock();
}

//---------------------------------------------------------------------------
// IΉ
//---------------------------------------------------------------------------
void UninitSphere(void)
{
	// eNX`Μjό	  
	if (g_pTextureSphere != NULL)
	{
		g_pTextureSphere->Release();
		g_pTextureSphere = NULL;
	}

	// Έ_obt@Μjό
	if (g_pVtxBuffSphere != NULL)
	{
		g_pVtxBuffSphere->Release();
		g_pVtxBuffSphere = NULL;
	}

	// CfbNXobt@Μjό	  
	if (g_pIdzBuffSphere != NULL)
	{
		g_pIdzBuffSphere->Release();
		g_pIdzBuffSphere = NULL;
	}
}

//---------------------------------------------------------------------------
// XV
//---------------------------------------------------------------------------
void UpdateSphere(void)
{

}

//---------------------------------------------------------------------------
// `ζ
//---------------------------------------------------------------------------
void DrawSphere(void)
{
	// foCXΜζΎ
	LPDIRECT3DDEVICE9	pDevice = GetDevice();
	D3DXMATRIX			mtxRot, mtxTrans;			// vZp}gbNX

	// [h}gbNXΜϊ»
	// sρϊ»Φ(ζκψΜ[sρ]π[PΚsρ]Ιϊ»)
	D3DXMatrixIdentity(&g_Sphere.mtxWorld);

	// ό«Μ½f
	// sρρ]Φ (ζκψΙ[[(y)sb`(x)[(z)]ϋόΜρ]sρπμ¬)
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Sphere.rot.y, g_Sphere.rot.x, g_Sphere.rot.z);

	// sρ|―ZΦ (ζρψ * ζOψπζκψΙi[)
	D3DXMatrixMultiply(&g_Sphere.mtxWorld, &g_Sphere.mtxWorld, &mtxRot);

	// Κuπ½f
	// sρΪ?Φ (ζκψΙX,Y,ZϋόΜΪ?sρπμ¬)
	D3DXMatrixTranslation(&mtxTrans, g_Sphere.pos.x, g_Sphere.pos.y, g_Sphere.pos.z);
	D3DXMatrixMultiply(&g_Sphere.mtxWorld, &g_Sphere.mtxWorld, &mtxTrans);						// sρ|―ZΦ

	// [h}gbNXΜέθ
	pDevice->SetTransform(D3DTS_WORLD, &g_Sphere.mtxWorld);

	// Έ_obt@πfoCXΜf[^Xg[Ιέθ
	pDevice->SetStreamSource(0, g_pVtxBuffSphere, 0, sizeof(VERTEX_3D));

	// CfbNXobt@πf[^Xg[Ιέθ
	pDevice->SetIndices(g_pIdzBuffSphere);

	// Έ_tH[}bg
	pDevice->SetFVF(FVF_VERTEX_3D);

	//eNX`Μέθ
	pDevice->SetTexture(0, g_pTextureSphere);

	// `ζ
	pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0, 0, MAX_SPHERE_VERTEX, 0, MAX_SPHERE_POLYGON);

	// eNX`Μπ
	pDevice->SetTexture(0, NULL);
}
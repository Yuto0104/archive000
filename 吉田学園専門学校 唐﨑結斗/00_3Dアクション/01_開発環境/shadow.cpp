//**************************************************************************************************
//
// e`ζ(shadow.cpp)
// AutherFϊ±l
//
//**************************************************************************************************

//***************************************************************************
// CN[h
//***************************************************************************
#include "main.h"
#include "shadow.h"
#include"file.h"
#include"model.h"

//***************************************************************************
// }Nθ`
//***************************************************************************
#define MAX_SHADOW_VERTEX		(4)				// eΜΈ_
#define MAX_SHADOW				(12800)			// eΜΕε
#define MAX_SHADOW_SIZE			(10.0f)			// eTCY
#define ATTENUATION_SHADOW		(0.01f)			// eΜΈW

//***************************************************************************
// O[oΟ
//***************************************************************************
static LPDIRECT3DVERTEXBUFFER9		g_pVtxBuffShadow = NULL;		// Έ_obt@ΦΜ|C^
static LPDIRECT3DTEXTURE9			g_pTextureShadow = NULL;		// eNX`ΦΜ|C^
static Shadow						g_Shadow[MAX_SHADOW];			// eξρΜζΎ

//---------------------------------------------------------------------------
// eϊ»
//---------------------------------------------------------------------------
void InitShadow(void)
{
	// t@CΟΜιΎΖγό
	char aFile[128] = FILE_TEXTURE_DATA;
	strcat(aFile, "shadow000.jpg");

	// foCXΜζΎ
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//Έ_obt@ΜΆ¬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * MAX_SHADOW_VERTEX * MAX_SHADOW,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffShadow,
		NULL);

	// eΙ£θt―ιeNX`ΜΗέέ
	D3DXCreateTextureFromFile(pDevice, aFile, &g_pTextureShadow);

	// Έ_ξρΜζΎ
	VERTEX_3D *pVtx = NULL;

	// Έ_obt@πbN
	g_pVtxBuffShadow->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntShadow = 0; nCntShadow < MAX_SHADOW; nCntShadow++)
	{
		// eξρΜϊ»
		g_Shadow[nCntShadow].pos = {};						// Κu
		g_Shadow[nCntShadow].rot = {};						// ό«
		g_Shadow[nCntShadow].size = {};						// Όa
		g_Shadow[nCntShadow].mtxWorld = {};					// [h}gbNX
		g_Shadow[nCntShadow].bUse = false;					// gpσ΅

		// Έ_ΐW
		pVtx[0].pos = D3DXVECTOR3(-g_Shadow[nCntShadow].size.x, 0.0f, g_Shadow[nCntShadow].size.z);
		pVtx[1].pos = D3DXVECTOR3(g_Shadow[nCntShadow].size.x, 0.0f, g_Shadow[nCntShadow].size.z);
		pVtx[2].pos = D3DXVECTOR3(-g_Shadow[nCntShadow].size.x, 0.0f, -g_Shadow[nCntShadow].size.z);
		pVtx[3].pos = D3DXVECTOR3(g_Shadow[nCntShadow].size.x, 0.0f, -g_Shadow[nCntShadow].size.z);

		// eΈ_Μ@όΜέθ(*xNgΜε«³Ν1Ι·ιKvͺ ι)
		pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		// Έ_J[Μέθ
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		// eNX`ΐW
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;		//Έ_f[^Μ|C^π4Βͺiίι
	}

	// Έ_obt@ΜAbN
	g_pVtxBuffShadow->Unlock();
}

//---------------------------------------------------------------------------
// eIΉ
//---------------------------------------------------------------------------
void UninitShadow(void)
{
	//eNX`Μjό	  
	if (g_pTextureShadow != NULL)
	{
		g_pTextureShadow->Release();

		g_pTextureShadow = NULL;
	}

	// Έ_obt@Μjό
	if (g_pVtxBuffShadow != NULL)
	{
		g_pVtxBuffShadow->Release();
		g_pVtxBuffShadow = NULL;
	}
}

//---------------------------------------------------------------------------
// eXV
//---------------------------------------------------------------------------
void UpdateShadow(void)
{

}

//---------------------------------------------------------------------------
// e`ζ
//---------------------------------------------------------------------------
void DrawShadow(void)
{
	// foCXΜζΎ
	LPDIRECT3DDEVICE9	pDevice = GetDevice();
	D3DXMATRIX			mtxRot, mtxTrans;			// vZp}gbNX

	// ΏufBOπΈZ¬Ιέθ
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_REVSUBTRACT);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	// eNX`Μέθ
	pDevice->SetTexture(0, g_pTextureShadow);

	for (int nCntShadow = 0; nCntShadow < MAX_SHADOW; nCntShadow++)
	{
		if (g_Shadow[nCntShadow].bUse == true)
		{// eͺgp³κΔ’ιΖ«
			// [h}gbNXΜϊ»
			// sρϊ»Φ(ζκψΜ[sρ]π[PΚsρ]Ιϊ»)
			D3DXMatrixIdentity(&g_Shadow[nCntShadow].mtxWorld);

			// ό«Μ½f
			// sρρ]Φ (ζκψΙ[[(y)sb`(x)[(z)]ϋόΜρ]sρπμ¬)
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Shadow[nCntShadow].rot.y, g_Shadow[nCntShadow].rot.x, g_Shadow[nCntShadow].rot.z);

			// sρ|―ZΦ (ζρψ * ζOψπζκψΙi[)
			D3DXMatrixMultiply(&g_Shadow[nCntShadow].mtxWorld, &g_Shadow[nCntShadow].mtxWorld, &mtxRot);

			// Κuπ½f
			// sρΪ?Φ (ζκψΙX,Y,ZϋόΜΪ?sρπμ¬)
			D3DXMatrixTranslation(&mtxTrans, g_Shadow[nCntShadow].pos.x, g_Shadow[nCntShadow].pos.y, g_Shadow[nCntShadow].pos.z);
			D3DXMatrixMultiply(&g_Shadow[nCntShadow].mtxWorld, &g_Shadow[nCntShadow].mtxWorld, &mtxTrans);		// sρ|―ZΦ

			// [h}gbNXΜέθ
			pDevice->SetTransform(D3DTS_WORLD, &g_Shadow[nCntShadow].mtxWorld);

			// Έ_obt@πfoCXΜf[^Xg[Ιέθ
			pDevice->SetStreamSource(0, g_pVtxBuffShadow, 0, sizeof(VERTEX_3D));

			// Έ_tH[}bg
			pDevice->SetFVF(FVF_VERTEX_3D);

			// e`ζ
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, MAX_SHADOW_VERTEX * nCntShadow, 2);
		}
	}

	// eNX`Μπ
	pDevice->SetTexture(0, NULL);

	// ΏufBOπ³Ιί·
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

//---------------------------------------------------------------------------
// eέθ
//---------------------------------------------------------------------------
int	SetShadow(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	// ΟιΎ
	int nCntShadow;

	for (nCntShadow = 0; nCntShadow < MAX_SHADOW; nCntShadow++)
	{
		if (g_Shadow[nCntShadow].bUse == false)
		{
			// ΟιΎ
			float fDiffPos = pos.y * 0.01f;

			// eξρΜέθ
			g_Shadow[nCntShadow].pos.x = pos.x;																			// Κu(x)
			g_Shadow[nCntShadow].pos.y = 0.1f;																			// Κu(y)
			g_Shadow[nCntShadow].pos.z = pos.z;																			// Κu(z)
			g_Shadow[nCntShadow].rot = rot;																				// ό«
			g_Shadow[nCntShadow].mtxWorld = {};																			// [h}gbNX
			g_Shadow[nCntShadow].size = D3DXVECTOR3(size.x + (size.x * fDiffPos),0.0f, size.z + (size.z * fDiffPos));	// ε«³						// Όa
			g_Shadow[nCntShadow].bUse = true;																			// gpσ΅

			break;
		}
	}

	return nCntShadow;		// eΜΤ(index)πΤ·
}

//---------------------------------------------------------------------------
// eΪ?
//---------------------------------------------------------------------------
void SetPositionShadow(int nIdxShadow, D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	// ΟιΎ
	float fDiffPos = pos.y * ATTENUATION_SHADOW;
	float fAlpha = pos.y * ATTENUATION_SHADOW;

	// eξρΜέθ
	g_Shadow[nIdxShadow].pos.x = pos.x;																			// Κu(x)
	g_Shadow[nIdxShadow].pos.y = 0.1f;																			// Κu(y)
	g_Shadow[nIdxShadow].pos.z = pos.z;																			// Κu(z)
	g_Shadow[nIdxShadow].rot.x = 0.0f;																			// ό«(x)
	g_Shadow[nIdxShadow].rot.y = rot.y;																			// ό«(y)
	g_Shadow[nIdxShadow].rot.z = 0.0f;																			// ό«(z)
	g_Shadow[nIdxShadow].size = D3DXVECTOR3(size.x + (size.x * fDiffPos), 0.0f, size.z + (size.z * fDiffPos));	// ε«³	

	// Έ_ξρΜζΎ
	VERTEX_3D *pVtx = NULL;

	// Έ_obt@πbN
	g_pVtxBuffShadow->Lock(0, 0, (void**)&pVtx, 0);

	pVtx += nIdxShadow * 4;		//Έ_f[^Μ|C^π4Βͺiίι

	// Έ_ΐW
	pVtx[0].pos = D3DXVECTOR3(-g_Shadow[nIdxShadow].size.x, 0.0f, g_Shadow[nIdxShadow].size.z);
	pVtx[1].pos = D3DXVECTOR3(g_Shadow[nIdxShadow].size.x, 0.0f, g_Shadow[nIdxShadow].size.z);
	pVtx[2].pos = D3DXVECTOR3(-g_Shadow[nIdxShadow].size.x, 0.0f, -g_Shadow[nIdxShadow].size.z);
	pVtx[3].pos = D3DXVECTOR3(g_Shadow[nIdxShadow].size.x, 0.0f, -g_Shadow[nIdxShadow].size.z);

	// eΈ_Μ@όΜέθ(*xNgΜε«³Ν1Ι·ιKvͺ ι)
	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	// Έ_J[Μέθ
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f - (1.0f * fAlpha));
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f - (1.0f * fAlpha));
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f - (1.0f * fAlpha));
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f - (1.0f * fAlpha));

	// eNX`ΐW
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	// Έ_obt@ΜAbN
	g_pVtxBuffShadow->Unlock();
}

//---------------------------------------------------------------------------
// eν
//---------------------------------------------------------------------------
void DeleteShadow(int nIdxShadow)
{
	// eξρΜϊ»
	g_Shadow[nIdxShadow].pos = {};						// Κu
	g_Shadow[nIdxShadow].rot = {};						// ό«
	g_Shadow[nIdxShadow].size = {};						// Όa
	g_Shadow[nIdxShadow].mtxWorld = {};					// [h}gbNX
	g_Shadow[nIdxShadow].bUse = false;					// gpσ΅
}
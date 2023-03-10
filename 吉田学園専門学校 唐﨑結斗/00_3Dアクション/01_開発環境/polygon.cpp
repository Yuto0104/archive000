//**************************************************************************************************
//
// |S`ζ(polygon.cpp)
// AutherFϊ±l
//
//**************************************************************************************************

//***************************************************************************
// CN[h
//***************************************************************************
#include "main.h"
#include "polygon.h"
#include"file.h"

//***************************************************************************
// }Nθ`
//***************************************************************************
#define MAX_POLYGON_VERTEX		(4)				// |SΜΈ_
#define MAX_POLYGON_SIZE		(200.0f)		// |STCY

//***************************************************************************
// O[oΟ
//***************************************************************************
LPDIRECT3DVERTEXBUFFER9		g_pVtxBuffPolygon = NULL;		// Έ_obt@ΦΜ|C^
LPDIRECT3DTEXTURE9			g_pTexturePolygon = NULL;		// eNX`ΦΜ|C^
POLYGON						g_polygon;						// |SξρΜζΎ

//---------------------------------------------------------------------------
// |Sϊ»
//---------------------------------------------------------------------------
void InitPolygon(void)
{
	// t@CΟΜιΎΖγό
	char aFile[128] = FILE_TEXTURE_DATA;
	strcat(aFile, "field000.jpg");

	// foCXΜζΎ
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//Έ_obt@ΜΆ¬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * MAX_POLYGON_VERTEX,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffPolygon,
		NULL);

	// Έ_ξρΜζΎ
	VERTEX_3D *pVtx = NULL;

	// Έ_obt@πbN
	g_pVtxBuffPolygon->Lock(0, 0, (void**)&pVtx, 0);

	// |SΙ£θt―ιeNX`ΜΗέέ
	D3DXCreateTextureFromFile(pDevice, aFile, &g_pTexturePolygon);

	// Έ_ΐW
	pVtx[0].pos = D3DXVECTOR3(-MAX_POLYGON_SIZE, 0.0f, MAX_POLYGON_SIZE);
	pVtx[1].pos = D3DXVECTOR3(MAX_POLYGON_SIZE, 0.0f, MAX_POLYGON_SIZE);
	pVtx[2].pos = D3DXVECTOR3(-MAX_POLYGON_SIZE, 0.0f, -MAX_POLYGON_SIZE);
	pVtx[3].pos = D3DXVECTOR3(MAX_POLYGON_SIZE, 0.0f, -MAX_POLYGON_SIZE);

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

	// Έ_obt@ΜAbN
	g_pVtxBuffPolygon->Unlock();
}

//---------------------------------------------------------------------------
// |SIΉ
//---------------------------------------------------------------------------
void UninitPolygon(void)
{
	//eNX`Μjό	  
	if (g_pTexturePolygon != NULL)
	{
		g_pTexturePolygon->Release();

		g_pTexturePolygon = NULL;
	}

	// Έ_obt@Μjό
	if (g_pVtxBuffPolygon != NULL)
	{
		g_pVtxBuffPolygon->Release();
		g_pVtxBuffPolygon = NULL;
	}
}

//---------------------------------------------------------------------------
// |SXV
//---------------------------------------------------------------------------
void UpdatePolygon(void)
{

}

//---------------------------------------------------------------------------
// |S`ζ
//---------------------------------------------------------------------------
void DrawPolygon(void)
{
	// foCXΜζΎ
	LPDIRECT3DDEVICE9	pDevice = GetDevice();
	D3DXMATRIX			mtxRot, mtxTrans;			// vZp}gbNX

	// [h}gbNXΜϊ»
	// sρϊ»Φ(ζκψΜ[sρ]π[PΚsρ]Ιϊ»)
	D3DXMatrixIdentity(&g_polygon.mtxWorld);

	// ό«Μ½f
	// sρρ]Φ (ζκψΙ[[(y)sb`(x)[(z)]ϋόΜρ]sρπμ¬)
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_polygon.rot.y, g_polygon.rot.x, g_polygon.rot.z);

	// sρ|―ZΦ (ζρψ * ζOψπζκψΙi[)
	D3DXMatrixMultiply(&g_polygon.mtxWorld, &g_polygon.mtxWorld, &mtxRot);

	// Κuπ½f
	// sρΪ?Φ (ζκψΙX,Y,ZϋόΜΪ?sρπμ¬)
	D3DXMatrixTranslation(&mtxTrans, g_polygon.pos.x, g_polygon.pos.y, g_polygon.pos.z);
	D3DXMatrixMultiply(&g_polygon.mtxWorld, &g_polygon.mtxWorld, &mtxTrans);						// sρ|―ZΦ

	// [h}gbNXΜέθ
	pDevice->SetTransform(D3DTS_WORLD, &g_polygon.mtxWorld);

	// Έ_obt@πfoCXΜf[^Xg[Ιέθ
	pDevice->SetStreamSource(0, g_pVtxBuffPolygon, 0, sizeof(VERTEX_3D));

	// Έ_tH[}bg
	pDevice->SetFVF(FVF_VERTEX_3D);

	//eNX`Μέθ
	pDevice->SetTexture(0, g_pTexturePolygon);

	// |S`ζ
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	// eNX`Μπ
	pDevice->SetTexture(0, NULL);
}
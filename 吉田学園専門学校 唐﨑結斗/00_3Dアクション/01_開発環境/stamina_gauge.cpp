//**************************************************************************************************
//
//_fQ[WΜέθ
//AutherFϊ±l
//
//**************************************************************************************************
#include"main.h"
#include"input.h"
#include"pause.h"
#include"fade.h"
#include"stamina_gauge.h"
#include"player.h"

//*******************************************************************************
// O[oΟ
//*******************************************************************************
//LPDIRECT3DTEXTURE9 g_pTextureStaminaGauge = NULL;			//eNX`ΦΜ|C^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffStaminaGauge = NULL;		//Έ_obt@ΦΜ|C^
StaminaGauge g_StaminaGauge[MAX_STAMINA_GAUGE];				// X^~iQ[W

//---------------------------------------------------------------------------
// X^~iQ[WΜϊ»
//---------------------------------------------------------------------------
void InitStaminaGauge(void)
{
	// foCXΦΜ|C^
	LPDIRECT3DDEVICE9 pDevice;

	// foCXΜζΎ
	pDevice = GetDevice();

	////|SΙ£θt―ιeNX`ΜΗέέ
	//D3DXCreateTextureFromFile(pDevice,
	//	"data/TEXTURE/_f{x.png",
	//	&g_pTextureStaminaGauge);

	// Έ_obt@ΜΆ¬
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_STAMINA_GAUGE,		// mΫ·ιobt@TCY
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,															// Έ_t@[}bg
		D3DPOOL_MANAGED,
		&g_pVtxBuffStaminaGauge,
		NULL);

	for (int nCnt = 0; nCnt < MAX_STAMINA_GAUGE; nCnt++)
	{
		// X^~iQ[WξρΜϊ»
		g_StaminaGauge[nCnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);												// S_
		g_StaminaGauge[nCnt].size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);												// ε«³
		g_StaminaGauge[nCnt].maxSize = g_StaminaGauge[nCnt].size;												// ε«³ΜΕεl
		D3DXVECTOR3 sizePos = D3DXVECTOR3(g_StaminaGauge[nCnt].size.x, 0.0f, 0.0f);								// Όͺ€Με«³
		g_StaminaGauge[nCnt].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);												// ό«
		g_StaminaGauge[nCnt].type = TYPE_GAUGE;																	// ^Cv
		g_StaminaGauge[nCnt].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);											// J[
		g_StaminaGauge[nCnt].bUse = false;																		// gp΅Δι

		// Έ_ξρΦΜ|C^πΆ¬						
		VERTEX_2D *pVtx;

		// Έ_obt@πbN΅AΈ_ξρΦΜ|C^πζΎ
		g_pVtxBuffStaminaGauge->Lock(0, 0, (void**)&pVtx, 0);

		// ΞpόΜ·³[0]πZo·ι
		g_StaminaGauge[nCnt].fLength = sqrtf(((g_StaminaGauge[nCnt].size.x * g_StaminaGauge[nCnt].size.x) + (g_StaminaGauge[nCnt].size.y * g_StaminaGauge[nCnt].size.y)) / 2.0f);
		float fLengthPos = sqrtf(((sizePos.x * sizePos.x) + (sizePos.y * sizePos.y)) / 2.0f);

		// ΞpόΜpx[0]πZo
		g_StaminaGauge[nCnt].fAngele = atan2f(g_StaminaGauge[nCnt].size.x, g_StaminaGauge[nCnt].size.y);
		float fAngelePos = atan2f(sizePos.x, sizePos.y);

		// Έ_ΐWΜέθ
		pVtx[0].pos.x = g_StaminaGauge[nCnt].pos.x + sinf(g_StaminaGauge[nCnt].rot.z + (D3DX_PI + g_StaminaGauge[nCnt].fAngele)) * g_StaminaGauge[nCnt].fLength;
		pVtx[0].pos.y = g_StaminaGauge[nCnt].pos.y + cosf(g_StaminaGauge[nCnt].rot.z + (D3DX_PI + g_StaminaGauge[nCnt].fAngele)) * g_StaminaGauge[nCnt].fLength;
		pVtx[0].pos.z = 0.0f;

		pVtx[1].pos.x = g_StaminaGauge[nCnt].pos.x + sinf(g_StaminaGauge[nCnt].rot.z + (D3DX_PI - g_StaminaGauge[nCnt].fAngele)) *  g_StaminaGauge[nCnt].fLength;
		pVtx[1].pos.y = g_StaminaGauge[nCnt].pos.y + cosf(g_StaminaGauge[nCnt].rot.z + (D3DX_PI - g_StaminaGauge[nCnt].fAngele)) *  g_StaminaGauge[nCnt].fLength;
		pVtx[1].pos.z = 0.0f;

		pVtx[2].pos.x = g_StaminaGauge[nCnt].pos.x + sinf(g_StaminaGauge[nCnt].rot.z - (0 + fAngelePos)) * fLengthPos;
		pVtx[2].pos.y = g_StaminaGauge[nCnt].pos.y + cosf(g_StaminaGauge[nCnt].rot.z - (0 + fAngelePos)) * fLengthPos;
		pVtx[2].pos.z = 0.0f;

		pVtx[3].pos.x = g_StaminaGauge[nCnt].pos.x + sinf(g_StaminaGauge[nCnt].rot.z - (0 - fAngelePos)) * fLengthPos;
		pVtx[3].pos.y = g_StaminaGauge[nCnt].pos.y + cosf(g_StaminaGauge[nCnt].rot.z - (0 - fAngelePos)) * fLengthPos;
		pVtx[3].pos.z = 0.0f;

		// rhwΜέθ
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		// Έ_J[Μέθ
		pVtx[0].col = g_StaminaGauge[nCnt].col;
		pVtx[1].col = g_StaminaGauge[nCnt].col;
		pVtx[2].col = g_StaminaGauge[nCnt].col;
		pVtx[3].col = g_StaminaGauge[nCnt].col;

		// eNX`ΐW
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
	}

	// Έ_obt@πAbN
	g_pVtxBuffStaminaGauge->Unlock();
}

//---------------------------------------------------------------------------
// X^~iQ[WΜIΉ
//---------------------------------------------------------------------------
void UninitStaminaGauge(void)
{
	//// eNX`Μjό	  
	//if (g_pTextureStaminaGauge != NULL)
	//{
	//	g_pTextureStaminaGauge->Release();

	//	g_pTextureStaminaGauge = NULL;
	//}

	// Έ_obt@πjό
	if (g_pVtxBuffStaminaGauge != NULL)
	{
		g_pVtxBuffStaminaGauge->Release();

		g_pVtxBuffStaminaGauge = NULL;
	}
}

//---------------------------------------------------------------------------
// X^~iQ[WΜXV
//---------------------------------------------------------------------------
void UpdateStaminaGauge(void)
{
	for (int nCnt = 0; nCnt < MAX_STAMINA_GAUGE; nCnt++)
	{
		if (g_StaminaGauge[nCnt].bUse)
		{
			SubStaminaGauge(nCnt);
		}
	}
}

//---------------------------------------------------------------------------
// X^~iQ[WΜ`ζ
//---------------------------------------------------------------------------
void DrawStaminaGauge(void)
{
	// foCXΦΜ|C^
	LPDIRECT3DDEVICE9 pDevice;

	// foCXΜζΎ
	pDevice = GetDevice();

	// Έ_obt@πf[^Xg[Ιέθ
	pDevice->SetStreamSource(0, g_pVtxBuffStaminaGauge, 0, sizeof(VERTEX_2D));

	// Έ_tH[}bgΜέθ
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int nCnt = 0; nCnt < MAX_STAMINA_GAUGE; nCnt++)
	{
		if (g_StaminaGauge[nCnt].bUse)
		{
			// eNX`Μέθ
			pDevice->SetTexture(0, NULL);

			// |S`ζ
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 
				nCnt * 4,
				2);
		}
	}
}

//---------------------------------------------------------------------------
// X^~iQ[WΜέθ
//---------------------------------------------------------------------------
void SetStaminaGauge(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size, int nType)
{
	for (int nCntType = 0; nCntType < MAX_STAMINA_GAUGE; nCntType++)
	{
		if (g_StaminaGauge[nCntType].bUse == false)
		{
			// X^~iQ[WξρΜϊ»
			g_StaminaGauge[nCntType].pos = pos;																			// S_
			g_StaminaGauge[nCntType].size = D3DXVECTOR3(size.x, size.y * 2.0f, size.z);									// ε«³
			g_StaminaGauge[nCntType].maxSize = g_StaminaGauge[nCntType].size;											// ε«³ΜΕεl
			g_StaminaGauge[nCntType].type = (STAMINA_GAUGE_TYPE)(nType);												// ^Cv
			D3DXVECTOR3 sizePos = D3DXVECTOR3(g_StaminaGauge[nCntType].size.x, 0.0f, 0.0f);								// Όͺ€Με«³
			g_StaminaGauge[nCntType].rot = rot;																			// ό«
			g_StaminaGauge[nCntType].bUse = true;																		// gp΅Δι

			switch (g_StaminaGauge[nCntType].type)
			{
			case TYPE_GAUGE:
				g_StaminaGauge[nCntType].col = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);					// J[
				break;

			case TYPE_BG:
				g_StaminaGauge[nCntType].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);					// J[
				break;
			}
			

			//Έ_ξρΦΜ|C^πΆ¬						
			VERTEX_2D *pVtx;

			// Έ_obt@πbN΅AΈ_ξρΦΜ|C^πζΎ
			g_pVtxBuffStaminaGauge->Lock(0, 0, (void**)&pVtx, 0);

			// ΞpόΜ·³πZo·ι
			g_StaminaGauge[nCntType].fLength = sqrtf(((g_StaminaGauge[nCntType].size.x * g_StaminaGauge[nCntType].size.x) + (g_StaminaGauge[nCntType].size.y * g_StaminaGauge[nCntType].size.y)) / 2.0f);
			float fLengthPos = sqrtf(((sizePos.x * sizePos.x) + (sizePos.y * sizePos.y)) / 2.0f);

			// ΞpόΜpxπZo
			g_StaminaGauge[nCntType].fAngele = atan2f(g_StaminaGauge[nCntType].size.x, g_StaminaGauge[nCntType].size.y);
			float fAngelePos = atan2f(sizePos.x, sizePos.y);

			// Έ_ΐWΜέθ
			pVtx[0].pos.x = g_StaminaGauge[nCntType].pos.x + sinf(g_StaminaGauge[nCntType].rot.z + (D3DX_PI + g_StaminaGauge[nCntType].fAngele)) * g_StaminaGauge[nCntType].fLength;
			pVtx[0].pos.y = g_StaminaGauge[nCntType].pos.y + cosf(g_StaminaGauge[nCntType].rot.z + (D3DX_PI + g_StaminaGauge[nCntType].fAngele)) * g_StaminaGauge[nCntType].fLength;
			pVtx[0].pos.z = 0.0f;

			pVtx[1].pos.x = g_StaminaGauge[nCntType].pos.x + sinf(g_StaminaGauge[nCntType].rot.z + (D3DX_PI - g_StaminaGauge[nCntType].fAngele)) *  g_StaminaGauge[nCntType].fLength;
			pVtx[1].pos.y = g_StaminaGauge[nCntType].pos.y + cosf(g_StaminaGauge[nCntType].rot.z + (D3DX_PI - g_StaminaGauge[nCntType].fAngele)) *  g_StaminaGauge[nCntType].fLength;
			pVtx[1].pos.z = 0.0f;

			pVtx[2].pos.x = g_StaminaGauge[nCntType].pos.x + sinf(g_StaminaGauge[nCntType].rot.z - (0 + fAngelePos)) * fLengthPos;
			pVtx[2].pos.y = g_StaminaGauge[nCntType].pos.y + cosf(g_StaminaGauge[nCntType].rot.z - (0 + fAngelePos)) * fLengthPos;
			pVtx[2].pos.z = 0.0f;

			pVtx[3].pos.x = g_StaminaGauge[nCntType].pos.x + sinf(g_StaminaGauge[nCntType].rot.z - (0 - fAngelePos)) * fLengthPos;
			pVtx[3].pos.y = g_StaminaGauge[nCntType].pos.y + cosf(g_StaminaGauge[nCntType].rot.z - (0 - fAngelePos)) * fLengthPos;
			pVtx[3].pos.z = 0.0f;

			// rhwΜέθ
			pVtx[0].rhw = 1.0f;
			pVtx[1].rhw = 1.0f;
			pVtx[2].rhw = 1.0f;
			pVtx[3].rhw = 1.0f;

			// Έ_J[Μέθ
			pVtx[0].col = g_StaminaGauge[nCntType].col;
			pVtx[1].col = g_StaminaGauge[nCntType].col;
			pVtx[2].col = g_StaminaGauge[nCntType].col;
			pVtx[3].col = g_StaminaGauge[nCntType].col;

			// eNX`ΐW
			pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
			pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
			pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
			pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

			// Έ_obt@πAbN
			g_pVtxBuffStaminaGauge->Unlock();

			break;
		}
	}
}

//---------------------------------------------------------------------------
// X^~iQ[WΜΈ­
//---------------------------------------------------------------------------
void SubStaminaGauge(int nCnt)
{
	if (g_StaminaGauge[nCnt].bUse)
	{
		//vC[ξρΜζΎ
		Player *pPlayer = GetPlayer();

		switch (g_StaminaGauge[nCnt].type)
		{
		case TYPE_GAUGE:
			// ε«³Ιlπγό
			g_StaminaGauge[nCnt].size.y = (g_StaminaGauge[nCnt].maxSize.y / (float)(pPlayer->nMaxStamina)) * (float)(pPlayer->nStamina);

			if (pPlayer->nStamina <= pPlayer->nMaxStamina)
			{// X^~iͺΌͺΘΊΜ
				g_StaminaGauge[nCnt].col = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);			// J[
				if (pPlayer->nStamina <= pPlayer->nMaxStamina / 2)
				{// X^~iͺΌͺΘΊΜ
					g_StaminaGauge[nCnt].col = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);			// J[

					if (pPlayer->nStamina <= DASH_STAMINA)
					{// X^~iͺ_bVΑοΚΘΊ
						g_StaminaGauge[nCnt].col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);			// J[
					}
				}
			}
			break;

		case TYPE_BG:
			break;
		}

		// Όͺ€Με«³
		D3DXVECTOR3 sizePos = D3DXVECTOR3(g_StaminaGauge[nCnt].size.x, 0.0f, 0.0f);

		//Έ_ξρΦΜ|C^πΆ¬						
		VERTEX_2D *pVtx;

		// Έ_obt@πbN΅AΈ_ξρΦΜ|C^πζΎ
		g_pVtxBuffStaminaGauge->Lock(0, 0, (void**)&pVtx, 0);

		// ΞpόΜ·³πZo·ι
		g_StaminaGauge[nCnt].fLength = sqrtf(((g_StaminaGauge[nCnt].size.x * g_StaminaGauge[nCnt].size.x) + (g_StaminaGauge[nCnt].size.y * g_StaminaGauge[nCnt].size.y)) / 2.0f);
		float fLengthPos = sqrtf(((sizePos.x * sizePos.x) + (sizePos.y * sizePos.y)) / 2.0f);

		// ΞpόΜpxπZo
		g_StaminaGauge[nCnt].fAngele = atan2f(g_StaminaGauge[nCnt].size.x, g_StaminaGauge[nCnt].size.y);
		float fAngelePos = atan2f(sizePos.x, sizePos.y);

		// Έ_ΐWΜέθ
		pVtx[0].pos.x = g_StaminaGauge[nCnt].pos.x + sinf(g_StaminaGauge[nCnt].rot.z + (D3DX_PI + g_StaminaGauge[nCnt].fAngele)) * g_StaminaGauge[nCnt].fLength;
		pVtx[0].pos.y = g_StaminaGauge[nCnt].pos.y + cosf(g_StaminaGauge[nCnt].rot.z + (D3DX_PI + g_StaminaGauge[nCnt].fAngele)) * g_StaminaGauge[nCnt].fLength;
		pVtx[0].pos.z = 0.0f;

		pVtx[1].pos.x = g_StaminaGauge[nCnt].pos.x + sinf(g_StaminaGauge[nCnt].rot.z + (D3DX_PI - g_StaminaGauge[nCnt].fAngele)) *  g_StaminaGauge[nCnt].fLength;
		pVtx[1].pos.y = g_StaminaGauge[nCnt].pos.y + cosf(g_StaminaGauge[nCnt].rot.z + (D3DX_PI - g_StaminaGauge[nCnt].fAngele)) *  g_StaminaGauge[nCnt].fLength;
		pVtx[1].pos.z = 0.0f;

		pVtx[2].pos.x = g_StaminaGauge[nCnt].pos.x + sinf(g_StaminaGauge[nCnt].rot.z - (0 + fAngelePos)) * fLengthPos;
		pVtx[2].pos.y = g_StaminaGauge[nCnt].pos.y + cosf(g_StaminaGauge[nCnt].rot.z - (0 + fAngelePos)) * fLengthPos;
		pVtx[2].pos.z = 0.0f;

		pVtx[3].pos.x = g_StaminaGauge[nCnt].pos.x + sinf(g_StaminaGauge[nCnt].rot.z - (0 - fAngelePos)) * fLengthPos;
		pVtx[3].pos.y = g_StaminaGauge[nCnt].pos.y + cosf(g_StaminaGauge[nCnt].rot.z - (0 - fAngelePos)) * fLengthPos;
		pVtx[3].pos.z = 0.0f;

		// Έ_J[Μέθ
		pVtx[0].col = g_StaminaGauge[nCnt].col;
		pVtx[1].col = g_StaminaGauge[nCnt].col;
		pVtx[2].col = g_StaminaGauge[nCnt].col;
		pVtx[3].col = g_StaminaGauge[nCnt].col;

		// Έ_obt@πAbN
		g_pVtxBuffStaminaGauge->Unlock();
	}
}

//---------------------------------------------------------------------------
// X^~iQ[WΜξρζΎ
//---------------------------------------------------------------------------
StaminaGauge *GetStaminaGauge(void)
{
	return &g_StaminaGauge[0];
}
//**************************************************************************************************
//
// vZ(calculation.cpp)
// AutherFú±l
//
//**************************************************************************************************

//***************************************************************************
// CN[h
//***************************************************************************
#include "main.h"
#include "calculation.h"

//---------------------------------------------------------------------------
// [hÀWÖÌLXg
//---------------------------------------------------------------------------
D3DXVECTOR3	WorldCastVtx(D3DXVECTOR3 vtx, D3DXVECTOR3 FormerPos, D3DXVECTOR3 FormerRot)
{
	// Ïé¾
	D3DXMATRIX		mtxWorldVtx;				// [h}gbNX
	D3DXMATRIX		mtxRot, mtxTrans;			// vZp}gbNX

	// [h}gbNXÌú»
	// sñú»Ö(æêøÌ[sñ]ð[PÊsñ]Éú»)
	D3DXMatrixIdentity(&mtxWorldVtx);

	// Êuð½f
	// sñÚ®Ö (æêøÉX,Y,ZûüÌÚ®sñðì¬)
	D3DXMatrixTranslation(&mtxTrans, vtx.x, vtx.y, vtx.z);
	D3DXMatrixMultiply(&mtxWorldVtx, &mtxWorldVtx, &mtxTrans);		// sñ|¯ZÖ

	// ü«Ì½f
	// sññ]Ö (æêøÉ[[(y)sb`(x)[(z)]ûüÌñ]sñðì¬)
	D3DXMatrixRotationYawPitchRoll(&mtxRot, FormerRot.y, FormerRot.x, FormerRot.z);

	// sñ|¯ZÖ (æñø * æOøðæêøÉi[)
	D3DXMatrixMultiply(&mtxWorldVtx, &mtxWorldVtx, &mtxRot);

	// Êuð½f
	// sñÚ®Ö (æêøÉX,Y,ZûüÌÚ®sñðì¬)
	D3DXMatrixTranslation(&mtxTrans, FormerPos.x, FormerPos.y, FormerPos.z);
	D3DXMatrixMultiply(&mtxWorldVtx, &mtxWorldVtx, &mtxTrans);		// sñ|¯ZÖ

	return D3DXVECTOR3(mtxWorldVtx._41, mtxWorldVtx._42, mtxWorldVtx._43);
}

//---------------------------------------------------------------------------
// pxÌ³K»
//---------------------------------------------------------------------------
float RotNormalization(float fRot)
{
	if (fRot >= D3DX_PI)
	{// Ú®ûüÌ³K»
		fRot -= D3DX_PI * 2;
	}
	else if (fRot <= -D3DX_PI)
	{// Ú®ûüÌ³K»
		fRot += D3DX_PI * 2;
	}

	return fRot;
}

//---------------------------------------------------------------------------
// ¸_ÀWÌÝè
//---------------------------------------------------------------------------
void SetVertex(VERTEX_2D *pVtx, D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fAngele, float fLength, float SizeX, int nType)
{
	if (nType == 0)
	{// ¸_ÀWÌÝè
		pVtx[0].pos.x = pos.x + sinf(rot.z + (D3DX_PI + fAngele)) * fLength;
		pVtx[0].pos.y = pos.y + cosf(rot.z + (D3DX_PI + fAngele)) * fLength;
		pVtx[0].pos.z = 0.0f;

		pVtx[1].pos.x = pos.x + sinf(rot.z + (D3DX_PI - fAngele)) * fLength;
		pVtx[1].pos.y = pos.y + cosf(rot.z + (D3DX_PI - fAngele)) * fLength;
		pVtx[1].pos.z = 0.0f;

		pVtx[2].pos.x = pos.x + sinf(rot.z - (D3DX_PI / 2)) * SizeX / 2;
		pVtx[2].pos.y = pos.y + cosf(rot.z - (D3DX_PI / 2)) * SizeX / 2;
		pVtx[2].pos.z = 0.0f;

		pVtx[3].pos.x = pos.x + sinf(rot.z - (-D3DX_PI / 2)) * SizeX / 2;
		pVtx[3].pos.y = pos.y + cosf(rot.z - (-D3DX_PI / 2)) * SizeX / 2;
		pVtx[3].pos.z = 0.0f;
	}
	else if (nType == 1)
	{// ¸_ÀWÌÝè
		pVtx[0].pos.x = pos.x + sinf(rot.z + (D3DX_PI + fAngele)) * fLength;
		pVtx[0].pos.y = pos.y + cosf(rot.z + (D3DX_PI + fAngele)) * fLength;
		pVtx[0].pos.z = 0.0f;

		pVtx[1].pos.x = pos.x + sinf(rot.z + (D3DX_PI - fAngele)) * fLength;
		pVtx[1].pos.y = pos.y + cosf(rot.z + (D3DX_PI - fAngele)) * fLength;
		pVtx[1].pos.z = 0.0f;

		pVtx[2].pos.x = pos.x + sinf(rot.z - (0 + fAngele)) * fLength;
		pVtx[2].pos.y = pos.y + cosf(rot.z - (0 + fAngele)) * fLength;
		pVtx[2].pos.z = 0.0f;

		pVtx[3].pos.x = pos.x + sinf(rot.z - (0 - fAngele)) * fLength;
		pVtx[3].pos.y = pos.y + cosf(rot.z - (0 - fAngele)) * fLength;
		pVtx[3].pos.z = 0.0f;
	}
}

//---------------------------------------------------------------------------
// rhwÌÝèÌÝè
//---------------------------------------------------------------------------
void SetRhw(VERTEX_2D *pVtx)
{
	// rhwÌÝè
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;
}

//---------------------------------------------------------------------------
// ¸_J[ÌÝè
//---------------------------------------------------------------------------
void SetVtxColor(VERTEX_2D *pVtx, float fRed, float fGreen, float fBlue, float fAlpha)
{
	// ¸_J[ÌÝè
	pVtx[0].col = D3DXCOLOR(fRed, fGreen, fBlue, fAlpha);
	pVtx[1].col = D3DXCOLOR(fRed, fGreen, fBlue, fAlpha);
	pVtx[2].col = D3DXCOLOR(fRed, fGreen, fBlue, fAlpha);
	pVtx[3].col = D3DXCOLOR(fRed, fGreen, fBlue, fAlpha);
}

//---------------------------------------------------------------------------
// eNX`ÀWÌÝè
//---------------------------------------------------------------------------
void SetVtxTexture(VERTEX_2D *pVtx, float fTexU, float fTexV)
{
	// eNX`ÀW
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(fTexU, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, fTexV);
	pVtx[3].tex = D3DXVECTOR2(fTexU, fTexV);
}
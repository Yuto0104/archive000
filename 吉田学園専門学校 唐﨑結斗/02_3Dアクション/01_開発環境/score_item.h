//=============================================================================
//
// アイテムクラス(score_item.h)
// Author : 唐�ｱ結斗
// 概要 : アイテム生成を行う
//
//=============================================================================
#ifndef _SCORE_ITEM_H_			// このマクロ定義がされてなかったら
#define _SCORE_ITEM_H_			// 二重インクルード防止のマクロ定義

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "model_obj.h"

//*****************************************************************************
// 前方宣言
//*****************************************************************************

//=============================================================================
// アイテムクラス
// Author : 唐�ｱ結斗
// 概要 : アイテム生成を行うクラス
//=============================================================================
class CScoreItem : public CModelObj
{
public:
	//--------------------------------------------------------------------
	// 静的メンバ関数
	//--------------------------------------------------------------------
	static CScoreItem *Create();							// アイテムの生成

	//--------------------------------------------------------------------
	// コンストラクタとデストラクタ
	//--------------------------------------------------------------------
	CScoreItem();
	~CScoreItem();

	//--------------------------------------------------------------------
	// メンバ関数
	//--------------------------------------------------------------------
	HRESULT Init() override;									// 初期化
	void Uninit() override;										// 終了
	void Update() override;										// 更新
	void Draw() override;										// 描画
	void SetScore(const int nScore) { m_nScore = nScore; }
	int Acquisition(const int nCntReCreate);			
	bool GetUse() { return m_bUse; }

private:
	//--------------------------------------------------------------------
	// メンバ変数
	//--------------------------------------------------------------------
	int m_nScore;			// スコア
	int m_nCntReCreate;		// 再出現までのカウント
	bool m_bUse;			// 使用状況
};

#endif


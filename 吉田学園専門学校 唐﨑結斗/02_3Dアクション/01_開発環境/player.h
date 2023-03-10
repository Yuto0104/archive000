//=============================================================================
//
// プレイヤークラス(player.h)
// Author : 唐?ｱ結斗
// 概要 : プレイヤー生成を行う
//
//=============================================================================
#ifndef _PLAYER_H_			// このマクロ定義がされてなかったら
#define _PLAYER_H_			// 二重インクルード防止のマクロ定義

//*****************************************************************************
// ライブラリーリンク
//*****************************************************************************
#pragma comment(lib,"d3d9.lib")			// 描画処理に必要
#pragma comment(lib,"d3dx9.lib")		// [d3d9.lib]の拡張ライブラリ

//*****************************************************************************
// インクルード
//*****************************************************************************
#include <Windows.h>
#include "d3dx9.h"							// 描画処理に必要
#include "motion_model3D.h"

//*****************************************************************************
// 前方宣言
//*****************************************************************************
class CMove;
class COrbit;
class CCollision_Rectangle3D;
class CModelObj;
class CWeaponObj;
class CWire;

//=============================================================================
// プレイヤークラス
// Author : 唐?ｱ結斗
// 概要 : プレイヤー生成を行うクラス
//=============================================================================
class CPlayer : public CMotionModel3D
{
public:
	//--------------------------------------------------------------------
	// 定数定義
	//--------------------------------------------------------------------
	static const unsigned int nFIST_ATTACK = 1;
	static const float fSPEED;
	static const float fJAMP;

	//--------------------------------------------------------------------
	// プレイヤーのアクションの列挙型
	//--------------------------------------------------------------------
	enum ACTION_TYPE
	{
		// 通常
		NEUTRAL_ACTION = 0,		// ニュートラル
		MOVE_ACTION,			// 移動
		ATTACK_ACTION,			// 攻撃
		ATTACK_JUMP,			// ジャンプ
		ATTACK_LANDING,			// 着地 
		ATTACK_HANGING,			// ぶら下がり
		MAX_ACTION,				// 最大数
	};

	//--------------------------------------------------------------------
	// 静的メンバ関数
	//--------------------------------------------------------------------
	static CPlayer *Create();			// プレイヤーの生成

	//--------------------------------------------------------------------
	// コンストラクタとデストラクタ
	//--------------------------------------------------------------------
	CPlayer();
	~CPlayer();

	//--------------------------------------------------------------------
	// メンバ関数
	//--------------------------------------------------------------------
	virtual HRESULT Init();											// 初期化
	void Uninit() override;											// 終了
	void Update() override;											// 更新
	void Draw() override;											// 描画
	void SetSpeed(const float fSpeed) { m_fSpeed = fSpeed; }		// 移動速度の設定
	void Dash();													// ダッシュ

private:
	//--------------------------------------------------------------------
	// メンバ関数
	//--------------------------------------------------------------------
	D3DXVECTOR3 Move();		// 移動
	void Rotate();			// 回転
	void Jump();			// ジャンプ
	void Attack();			// 攻撃
	void GetWeapon();		// 武器の取得
	void Landing();			// 着地
		
	//--------------------------------------------------------------------
	// メンバ変数
	//--------------------------------------------------------------------
	CMove						*m_pMove;						// 移動情報
	COrbit						*m_pOrbit;						// 軌跡
	CCollision_Rectangle3D		*m_pCollisionRectangle3D;		// 3D矩形の当たり判定
	CModelObj					*m_pAttack;						// 攻撃オブジェクト情報
	CCollision_Rectangle3D		*m_pColliAttack;				// 攻撃の当たり判定
	CWeaponObj					*m_pMyWeapon;					// 武器のポインタ
	CWire						*m_pWire;						// ワイヤー
	ACTION_TYPE					m_EAction;						// アクションタイプ
	D3DXVECTOR3					m_move;							// 移動ベクトル
	D3DXVECTOR3					m_rotDest;						// 目的の向き
	float						m_fSpeed;						// 移動速度
	float						m_fGravity;						// 重力
	int							m_nNumMotion;					// 現在のモーション番号
	int							m_nNumHandParts;				// 手のパーツ番号
};

#endif


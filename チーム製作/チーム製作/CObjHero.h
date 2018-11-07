#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : 主人公
class C0bjHero : public CObj
{
public:
	C0bjHero() {};
	~C0bjHero() {};
	void Init();   //イ二シャライズ
	void Action();	//アクション
	void Draw();    //ドロー

#define HEROX (64)
#define HEROY (64)

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }
	int GetBT() { return m_block_type; }

	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
	void SetBT(int t) { m_block_type = t; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }
private:
	float m_px;      //位置
	float m_py;
	float m_vx;      //移動ベクトル
	float m_vy;
	float m_posture; //姿勢

	int m_ani_time; //アニメーションフレーム動作間隔
	int m_ani_frame;  //描画フレーム

	float m_speed_power; //スピードパワー
	float m_speed_pow;   //しゃがむ速度
	float m_ani_max_time;//アニメーション動画間隔最大値

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//踏んでいるblockの種類を確認用
	int m_block_type;

	float m_x;     //主人公機のx方向移動用変数
	float m_y;     //主人公機のy方向移動用変数
};
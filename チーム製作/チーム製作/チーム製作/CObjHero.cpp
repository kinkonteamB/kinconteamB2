//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"CObjHero.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

float g_px = 64.0f;
float g_py = 450.0f;

//イニシャライズ
void C0bjHero::Init()
{

	m_vx = 0.0f;    //移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f; //右向き0.0f,左向き1,0f

	m_ani_time = 0;
	m_ani_frame = 0;  //静止フレームを初期化する

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0;	//踏んでいるブロックの種類


	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;  //アニメーション間隔幅

	m_time = 31;

//当たり判定用のHitBoxを作成
						
Hits::SetHitBox(this, g_px, g_py,32,64, ELEMENT_PLAYER, COBJ_HERO, 1);
}

//アクション
void C0bjHero::Action()
{


	if (Input::GetVKey(VK_TAB) == true) 
	{
		Scene::SetScene(new CSceneMenu());
	}

	//落下によるゲームオーバー＆リスタート
	if (g_py > 1000.0f)
	{
		//場外に出たらリスタート
		Scene::SetScene(new CSceneOver());
	}

	m_speed_power = 0.5f;

	//Shihtキー入力で速度アップ

	if (Input::GetVKey(VK_SHIFT) == true)
	{
		//ダッシュ時の速度
		m_speed_power = 0.6f;
		m_ani_max_time = 2;
	}
	//ジャンプ
	if (Input::GetVKey('W') == true)
	{
		if (m_hit_down == true &&m_time==0 )
		{
			m_vy = -9;
			g_py += m_vy;

			Audio::Start(1);

		}
	}
	if (m_time > 0) {
		m_time--;
		if (m_time <= 0) {
			m_time = 0;
		}
	}

	//しゃがむ
	if (Input::GetVKey('S') == true)
	{
		m_ani_frame = 5;
		m_ani_time = 0;
		m_speed_power = 0.2f;
		if (m_ani_frame != 5)//5のフレーム以外なら何もしない
		{
		}

		else if (Input::GetVKey('D') == true) //しゃがむ（右移動）
		{
			m_vx += m_speed_power;
			m_posture = 1.0f;
		}
		else if (Input::GetVKey('A') == true)//しゃがむ（左移動）
		{
			m_vx -= m_speed_power;
			m_posture = 0.0f;
		}
	}

	else if (m_ani_frame >= 4)
	{
		m_ani_frame = 0;
		m_ani_time = 0;
	}

	else if (Input::GetVKey('D') == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey('A') == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}

	else
	{
		m_ani_frame = 0;   //キー入力が無い場合静止フレームにする
		m_ani_time = 0;
	}
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//主人公機が領域外行かない処理
	if (g_px + 64.0f > 800.0f)
	{
		g_px = 800.0f - 64.0f;

	}

	CObjBlock*b = (CObjBlock*)Objs::GetObj(COBJ_HERO);
	//後方スクロールライン
	if (g_px < 80)
	{
		g_px = 80;
		b->SetScroll(b->GetScroll());
	}

	//前方スクロールライン
	if (g_px > 350)
	{
		g_px = 350;
		b->SetScroll(b->GetScroll());
	}
	
	//摩擦
	m_vx += -(m_vx*0.098);

	//自由落下運動
	m_vy += 9.8 / (16.0f);

	//位置の更新
	g_px += m_vx;
	g_py += m_vy;

	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&g_px, &g_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//自身のHitBoxを持ってくる
	CHitBox*hit = Hits::GetHitBox(this);

	//HitBoxの位置を変更	
	hit->SetPos(g_px+18, g_py);

	//罠に接触したらリスタート
	if (hit->CheckObjNameHit(OBJ_BLOCK) != nullptr)
	{
		//場外に出たらリスタート
		Scene::SetScene(new CSceneOver());
		g_px = 64.0f;
		g_py = 500.0f;
	}

}
//ドロー
void C0bjHero::Draw()
{
	int AniData[6] =
	{
		0,1,0,2,3,4
	};

	//描写カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//描写元切り取り位置
	RECT_F dst;//描写先表示位置
	
    //切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f + g_py;
	dst.m_left = (64.0f*m_posture) + g_px;
	dst.m_right = (64 - 64.0f*m_posture) + g_px;
	dst.m_bottom = 64.0f + g_py;

	//0番目に登録したグラフィックをsrc・dst・ｃの情報を元に描写
	Draw::Draw(0, &src, &dst, c, 0.0f);

}
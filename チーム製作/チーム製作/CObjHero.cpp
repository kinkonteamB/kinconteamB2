//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"CObjHero.h"



//使用するネームスペース
using namespace GameL;

//イニシャライズ
void C0bjHero::Init()
{
	m_px = 100.0f;
	m_py = 100.0f;    //位置

	m_vx = 0.0f;    //移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f; //右向き0.0f,左向き1,0f

	m_ani_time = 0;
	m_ani_frame = 0;  //静止フレームを初期化する

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;  //アニメーション間隔幅


//当たり判定用のHitBoxを作成
						
//Hits::SetHitBox(this, m_px, m_py, 64, 32, ELEMENT_PLAYER, COBJ_HERO, 1);
}

//アクション
void C0bjHero::Action()
{
	m_speed_power = 0.5f;

	//キーの入力方向
	//ジャンプ
	if (Input::GetVKey('W') == true)
	{
		m_vy = -15;
		m_py += m_vy;
	}
	//しゃがむ
	if (Input::GetVKey('S') == true)
	{
		m_ani_frame = 5;
		m_ani_time = 0;
		m_speed_power = 0.3f;
		if (m_ani_frame != 5)//5のフレーム以外なら何もしない
		{
		}
		else if (Input::GetVKey('D') == true) //しゃがむ（右移動）
		{
			m_vx += m_speed_power;
			m_posture = 1.0f;
		}
		else if (Input::GetVKey('A') == true)//しゃがむ（右移動）
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

	//摩擦
	m_vx += -(m_vx*0.098);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//主人公機が領域外行かない処理
	if (m_px + 64.0f > 800.0f)
	{
		m_px = 800.0f - 64.0f;
	}

	if (m_py + 64.0f > 600.0f)
	{
		m_py = 600.0f - 64.0f;
	}

	if (m_py < 0.0f)
	{
		m_py = 0.0f;
	}

	if (m_px < 0.0f)
	{
		m_px = 0.0f;
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
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f*m_posture) + m_px;
	dst.m_right = (64 - 64.0f*m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

	//0番目に登録したグラフィックをsrc・dst・ｃの情報を元に描写
	Draw::Draw(0, &src, &dst, c, 0.0f);


}
//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\UserData.h"

#include "GameHead.h"
#include "ObjTitle.h"

#include"GameL\DrawTexture.h"

#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = true;
	choose = 0;
	m_time = 10;

	//ゲーム実行して一回のみ
	static bool init_point = false;
	if (init_point == false)
	{
		for (int i = 0; i < 10; i++)
		{
			((UserData*)Save::GetData())->m_ranking[i] = ALL_RANKING_SIZE;
		}

		//ロード
		Save::Open();//同フォルダ「UserData」からデータ取得

		//点数を0にする
		((UserData*)Save::GetData())->minute = ALL_RANKING_SIZE;

		init_point = true;
	}
	//得点情報ランキング最下位（描画圏外）に登録
	((UserData*)Save::GetData())->m_ranking[9] = ((UserData*)Save::GetData())->minute;

	Save::Seve();//UserDataの情報フォルダ「UserData」を作成
}

//アクション
void CObjTitle::Action()
{
	if (Input::GetVKey(VK_UP) == true && choose > 0 && m_time == 0)
	{
		--choose;
		m_time = 10;
	}
	if (Input::GetVKey(VK_DOWN) == true && choose < 2 && m_time == 0)
	{
		++choose;
		m_time = 10;
	}

	if (m_time > 0) {
		m_time--;
		if (m_time <= 0) {
			m_time = 0;
		}
	}
	if (choose == 0)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				Scene::SetScene(new CSceneMain());
				g_px = 64.0f;
				g_py = 450.0f;
				m_time = 20;

				//得点の初期化
				((UserData*)Save::GetData())->minute = ALL_RANKING_SIZE;
			}
		}
		else
		{
			m_key_flag = true;
		}
	}
	if (choose == 1)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				Scene::SetScene(new CSceneRanking());
			}
		}
		else
		{
			m_key_flag = true;
		}
	}
	if (choose == 2)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			exit(1);
		}
	}
	//得点の初期化
	((UserData*)Save::GetData())->minute = ALL_RANKING_SIZE;
}

//ドロー
void CObjTitle::Draw()
{
	//描写カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//描写元切り取り位置
	RECT_F dst;//描写先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1600.0f;
	src.m_bottom = 909.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//0番目に登録したグラフィックをsrc・dst・ｃの情報を元に描写
	Draw::Draw(3, &src, &dst, c, 0.0f);

	float b[4] = { 1,1,1,1 };

	//タイトル
	Font::StrDraw(L"異世界の塔", 148, 120, 100, b);

		if(choose==0)
			Font::StrDraw(L"◇START", GAME_START_POS_X - 55, GAME_START_POS_Y, GAME_START_FONT_SIZE, b);
		else
			Font::StrDraw(L"START", GAME_START_POS_X, GAME_START_POS_Y, GAME_START_FONT_SIZE, b);
		if(choose==1)
			Font::StrDraw(L"◇RANKING", GAME_RANKING_POS_X - 55, GAME_RANKING_POS_Y, GAME_RANKING_FONT_SIZE, b);
		else
			Font::StrDraw(L"RANKING", GAME_RANKING_POS_X, GAME_RANKING_POS_Y, GAME_RANKING_FONT_SIZE, b);
		if(choose==2)
			Font::StrDraw(L"◇EXIT", GAME_EXIT_POS_X - 55, GAME_EXIT_POS_Y, GAME_EXIT_FONT_SIZE, b);
		else
			Font::StrDraw(L"EXIT", GAME_EXIT_POS_X, GAME_EXIT_POS_Y, GAME_EXIT_FONT_SIZE, b);
}
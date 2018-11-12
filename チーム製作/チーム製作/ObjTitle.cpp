//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjTitle.h"

#include"GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = false;
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
}

//アクション
void CObjTitle::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスの位置とクリックする場所で当たり判定
	if (m_mou_x > MOU_START_HIT_X && m_mou_x<MOU_START_HIT_V &&
		m_mou_y>MOU_START_HIT_Y && m_mou_y < MOU_START_HIT_H)
	{
		//マウスのボタンが押されたらメインに遷移
		if (m_mou_r == true || m_mou_l == true)

		{
			Scene::SetScene(new CSceneMain());
		}
	}

	if (m_mou_x > GAME_RANKING_POS_X -3 && m_mou_x < GAME_RANKING_POS_X +209 &&
		m_mou_y > GAME_RANKING_POS_Y && m_mou_y < GAME_RANKING_POS_Y +40)
	{
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneRanking());
		}
	}

	if (m_mou_x > GAME_EXIT_POS_X && m_mou_x < GAME_EXIT_POS_X +112 &&
		m_mou_y > GAME_EXIT_POS_Y && m_mou_y < GAME_EXIT_POS_Y +25)
	{
		if (m_mou_r == true || m_mou_l == true)
		{
			exit(1);
		}
	}
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
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

	if (m_mou_x > 318 && m_mou_x < 464 && m_mou_y < 399 && m_mou_y >349)
		Font::StrDraw(L"◇START", GAME_START_POS_X - 55, GAME_START_POS_Y, GAME_START_FONT_SIZE, b);
	else
		Font::StrDraw(L"START", GAME_START_POS_X, GAME_START_POS_Y, GAME_START_FONT_SIZE, b);

	if (m_mou_x > 287 && m_mou_x < 496 && m_mou_y > 420 && m_mou_y < 460)
		Font::StrDraw(L"◇RANKING", GAME_RANKING_POS_X - 55, GAME_RANKING_POS_Y, GAME_RANKING_FONT_SIZE, b);
	else
		Font::StrDraw(L"RANKING", GAME_RANKING_POS_X, GAME_RANKING_POS_Y, GAME_RANKING_FONT_SIZE, b);

	if (m_mou_x > 326 && m_mou_x < 453 && m_mou_y > 487 && m_mou_y < 537)
		Font::StrDraw(L"◇EXIT", GAME_EXIT_POS_X - 55, GAME_EXIT_POS_Y, GAME_EXIT_FONT_SIZE, b);
	else
		Font::StrDraw(L"EXIT", GAME_EXIT_POS_X, GAME_EXIT_POS_Y, GAME_EXIT_FONT_SIZE, b);

}
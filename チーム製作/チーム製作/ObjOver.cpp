//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjOver.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjOver::Init()
{

}

//アクション
void CObjOver::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();


	//マウスの位置とクリックする場所で当たり判定
	if (m_mou_x > GAME_YES_X -4 && m_mou_x < GAME_YES_X +100 &&
		m_mou_y > GAME_YES_Y -4 && m_mou_y < GAME_YES_Y +38)
	{
		//マウスのボタンが押されたらメインに遷移
		if (m_mou_r == true || m_mou_l == true)

		{
			Scene::SetScene(new CSceneMain());
		}
	}
	if (m_mou_x > GAME_NO_X -4 && m_mou_x < GAME_NO_X + 144 &&
		m_mou_y > GAME_NO_Y -4 && m_mou_y < GAME_NO_Y + 35)
	{
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneTitle());
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
void CObjOver::Draw()

{
	//描写カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//描写元切り取り位置
	RECT_F dst;//描写先表示位置

    //切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 700.0f;
	src.m_bottom = 420.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//0番目に登録したグラフィックをsrc・dst・ｃの情報を元に描写
	Draw::Draw(4, &src, &dst, c, 0.0f);

	float p[4] = { 1,1,1,1 };

	Font::StrDraw(L"Game Over", GAME_OVER_X, GAME_OVER_Y, GAME_OVER_FONT_SIZE, p);

	Font::StrDraw(L"コンテニューしますか？", GAME_CON_X, GAME_CON_Y, GAME_CON_FONT_SIZE, p);

    if(m_mou_x > 330 && m_mou_x < 435 && m_mou_y > 395 && m_mou_y < 439)
	Font::StrDraw(L"◇はい", GAME_YES_X -30, GAME_YES_Y, GAME_YES_FONT_SIZE, p);
	else
	Font::StrDraw(L"はい", GAME_YES_X, GAME_YES_Y, GAME_YES_FONT_SIZE, p);

	if (m_mou_x > 310 && m_mou_x < 460 && m_mou_y > 475 && m_mou_y < 516)
	Font::StrDraw(L"◇いいえ", GAME_NO_X -30, GAME_NO_Y, GAME_NO_FONT_SIZE, p);
	else
	Font::StrDraw(L"いいえ", GAME_NO_X, GAME_NO_Y, GAME_NO_FONT_SIZE, p);

}

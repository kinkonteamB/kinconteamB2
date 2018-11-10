//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjMenu.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMenu::Init()
{

}

//アクション
void CObjMenu::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


	if (m_mou_x > GAME_BACK_X - 5 && m_mou_x < GAME_BACK_X + 292 &&
		m_mou_y > GAME_BACK_Y - 5 && m_mou_y < GAME_BACK_Y + 40)
	{
		//マウスのボタンが押されたらメインに遷移
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneMain());
		}
	}

	if (m_mou_x > TITLE_BACK_X - 3 && m_mou_x < TITLE_BACK_X + 339 &&
		m_mou_y > TITLE_BACK_Y - 6 && m_mou_y < TITLE_BACK_Y + 38)
	{
		//マウスのボタンが押されたらメインに遷移
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneTitle());
		}
	}


}
//ドロー
void CObjMenu::Draw()

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
	Draw::Draw(4, &src, &dst, c, 0.0f);

	float b[4] = { 1,1,1,1 };

	Font::StrDraw(L"メニュー", 230, 100, 90, c);

	if(m_mou_x > GAME_BACK_X -5 && m_mou_x < GAME_BACK_X +292 &&
		m_mou_y > GAME_BACK_Y -5 && m_mou_y < GAME_BACK_Y +40)
    	Font::StrDraw(L"◇ゲームに戻る", GAME_BACK_X -50, GAME_BACK_Y, GAME_DOBLE_FONT, c);
	else
		Font::StrDraw(L"ゲームに戻る", GAME_BACK_X, GAME_BACK_Y, GAME_DOBLE_FONT, c);

	if(m_mou_x > TITLE_BACK_X - 3 && m_mou_x < TITLE_BACK_X + 339 &&
		m_mou_y > TITLE_BACK_Y - 6 && m_mou_y < TITLE_BACK_Y + 38)
		Font::StrDraw(L"◇タイトルに戻る", TITLE_BACK_X -50, TITLE_BACK_Y, GAME_DOBLE_FONT, c);
	else
		Font::StrDraw(L"タイトルに戻る", TITLE_BACK_X, TITLE_BACK_Y, GAME_DOBLE_FONT, c);


}

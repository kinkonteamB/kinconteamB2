//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjClear.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjClear::Init()
{
	m_key_flag = false;
}

//アクション
void CObjClear::Action()
{
	//エンターキーを押してシーン:ゲームTitleに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}
//ドロー
void CObjClear::Draw()
{
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	Font::StrDraw(L"ｵﾒﾃﾞﾄｳ!ｷｮｳﾀﾞｲﾅﾃｷｦﾅｷﾞﾊﾗｲ､ｺﾉﾃﾞｽｹﾞｰﾑｦｸﾘｱｼﾏｼﾀ｡", 224, 250, 16, c);
	Font::StrDraw(L"ﾏﾀ､ｱﾗﾀﾅﾃｷｶﾞｱﾗﾜﾚﾙｿﾉﾋﾏﾃﾞ､ﾋﾄﾄｷﾉﾍｲﾜｦﾋﾀﾘﾅｻｲ｡", 230, 270, 16, c);

	Font::StrDraw(L"ｵﾜﾘ", 340, 300, 64, c);
}

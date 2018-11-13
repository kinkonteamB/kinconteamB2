//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjNeedle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjNeedle::Init()
{

}

//アクション
void CObjNeedle::Action()
{
	
}
//ドロー
void CObjNeedle::Draw()

{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画元表示位置

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;

	//表示位置の設定
	dst.m_top = 32.0f;
	dst.m_left =32.0f;
	dst.m_right = dst.m_left + 32.0f;
	dst.m_bottom = dst.m_top + 32.0f;

	Draw::Draw(4, &src, &dst, c, 0.0f);

}

//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjNeedle.h"
#include "ObjBlock.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjNeedle::Init()
{
	m_x = 600;
	m_y = 400;

	//当たり判定用hitbox作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_NEEDLE, 12);
}

//アクション
void CObjNeedle::Action()
{
	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
}
//ドロー
void CObjNeedle::Draw()
{

	//描写カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//描写元切り取り位置
	RECT_F dst;//描写先表示位置

			   //切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] == 2)
			{
				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				Draw::Draw(1, &src, &dst, c, 0.0f);
			}
		}
	}
}

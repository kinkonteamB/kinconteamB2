//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "CObjArrow.h"

//使用するネームスペース
using namespace GameL;

CObjArrow::CObjArrow()
{
}

//イニシャライズ
void CObjArrow::Init()
{
	//m_eff.m_top = 32;
	//m_eff.m_left = 0;
	//m_eff.m_right = 32;
	//m_eff.m_bottom = 64;
	//m_ani = 0;
	//m_ani_time = 0;

	m_vx = -1.0f;
	m_vy = 0.0f;
	
	////当たり判定用HitBoxを作成
	//Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ARROW, 1);

}

//アクション
void CObjArrow::Action()
{
	//Resourcesの描画物のRECT
	//m_eff = GetBulletEffec(&m_ani, &m_ani_time, m_del, 2);

	//弾丸消滅処理 -----
	//if (m_del == true)
	//{
	//	//着弾アニメーション終了で本当にオブジェクトの破壊
	//	if (m_ani == 4)
	//	{
	//		this->SetStatus(false);
	//		Hits::DeleteHitBox(this);
	//	}

	//	return;//消滅処理は、ここでアクションメゾットを終了させる
	//}

	////弾丸実行処理 -----
	////移動
	//m_x += m_vx*5.0f;
	//m_y += m_vy*5.0f;

	////敵機弾丸のHitBox更新用ポインター取得
	//CHitBox*hit = Hits::GetHitBox(this);
	//hit->SetPos(m_x, m_y);			//HitBoxの位置を敵機弾丸の位置に更新

									//敵機弾丸が完全に領域外に出たら敵機弾丸を破棄する
	//bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	/*if (check == false)
	{
		this->SetStatus(false);//自身に削除命令を出す。
		Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxに削除する。
	}*/

	////主人公オブジェクトと接触したら弓矢削除
	//if (hit->CheckObjNameHit(OBJ_ARROW) != nullptr)
	//{
	//	Audio::Start(3);

	//	m_del = true;				//消滅実行
	//	hit->SetInvincibility(true);//当たり判定無効
	//}
}

//ドロー
void CObjArrow::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F dst; //描画先表示位置
	RECT_F src; 

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom =8.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 32.0f;
	dst.m_bottom = 32.0f;

	//0番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(5, &src, &dst, c, 0.0f);
}
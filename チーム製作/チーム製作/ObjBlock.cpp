//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjBlock.h"

//使用するネームスペース
using namespace GameL;


C0bjBlock::C0bjBlock(int map[19][75])
{
	//マップデータコピー
	memcpy(m_map, map, sizeof(int)*(19 * 75));
}

//イニシャライズ
void C0bjBlock::Init()
{
	m_scroll = 0.0f;
	m_scroll_map = 0.0f;
	float m_x1 = 0.0f;
}



//アクション
void C0bjBlock::Action()
{
	//主人公の位置を取得
	C0bjHero*hero = (C0bjHero*)Objs::GetObj(COBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

}
//ドロー
void C0bjBlock::Draw()
{

	//描写カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//描写元切り取り位置
	RECT_F dst;//描写先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 34.0f;
	src.m_bottom = 34.0f;


	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 75; j++)
		{
			if (m_map[i][j] > 0)
			{
				//表示位置の設定
				dst.m_top    = i*32.0f;
				dst.m_left   = j*32.0f;
				dst.m_right  = dst.m_left + 32.0f;
				dst.m_bottom =  dst.m_top + 32.0f;

				Draw::Draw(1, &src, &dst, c, 0.0f);
			}
		}
	}
}
//BlockHit関数
//引数１    float * x           :判定を行うobjectのX位置
//引数２    float * y           :判定を行うobjectのY位置
//引数３    bool     scroll_on  :判定を行うobjectはスクロールの影響与えるかどうか（true=与える　false=与えない）
//引数４    bool *   up         :上下左右判定の上部分に当たっているかどうかを返す
//引数５    bool *   down       :上下左右判定の下部分に当たっているかどうかを返す
//引数６    bool *   left       :上下左右判定の左部分に当たっているかどうかを返す
//引数７    bool *   right      :上下左右判定の右部分に当たっているかどうかを返す
//引数８    float * vx          :左右判定時の反発による移動方向・力の値変えて返す
//引数９    float * vy          :上下判定時による自由落下運動の移動方向・力の値変えて返す
//引数１０  int * bt            :下部分判定時、特殊なブロックのタイプを返す
//判定を行うobjectとブロック64×64限定で、当たり判定と上下左右判定を行う
//その結果は引数4〜10に返す
void C0bjBlock::BlockHit(
	float *x, float *y, bool scroll_on,
	bool*up, bool*down, bool*left, bool*right,
	float *vx, float*vy, int *bt
)
{
	//衝突状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//踏んでいるblockの種類の初期化
	*bt = 0;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 75; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 4)
			{
				//要素番号を座標に変更
				float bx = j*32.0f;
				float by = i*32.0f;

				//スクロールの影響
				float scroll = scroll_on ? m_scroll : 0;

				//オブジェクトとブロックの当たり判定
				if ((*x + (-scroll) + 32.0f > bx) && 
					(*x + (-scroll) < bx + 32.0f) && 
					(*y + 32.0f > by) && 
					(*y < by + 32.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = (*x + (-scroll)) - bx;
					float rvy = *y - by;

					//長さを求める
					float len = sqrt(rvx*rvx + rvy*rvy);

					//角度を求める
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r < 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//角度で上下左右を判定
					if ((r < 45 && r>0) || r > 315)
					{
						//右
						*right = true;//オブジェクトの左の部分が衝突している
						*x = bx + 32.0f + (scroll);//ブロックの位置-オブジェクトの幅
						*vx = -(*vx)*0.1f;//-vx*反発係数
					}
					if (r > 45 && r < 135)
					{
						//上

						*down = true;//オブジェクトから見て、下の部分が衝突してるzx
						*y = by - 64.0f;//ブロックの位置-オブジェクトの幅
						*vy = 0.0f;
					}
					if (r > 135 && r < 225)
					{
						//左
						*left = true;//オブジェクの右の部分が衝突している
						*x = bx - 32.0f + (scroll);//ブロックの位置-オブジェクトの幅
						*vx = (*vx)*0.1f;//-vx*反発係数
					}
					if (r > 225 && r < 315)
					{
						//下
						*up = true;//オブジェクトの上の部分が衝突している
						*y = by + 32.0f;//ブロックの位置-オブジェクトの幅
						if (*vy < 0)
						{
							*vy = 0.0f;
						}
					}
				}
			}
		}
	}
}

void C0bjBlock::BlockDraw(float x, float y, RECT_F * dst, float c[])
{
}
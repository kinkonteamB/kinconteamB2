#include "GameL\SceneObjManager.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjBlock.h"

using namespace GameL;

CObjBlock::CObjBlock(int map[10][100])
{
	//マップデータをコピー
	memcpy(m_map, map, sizeof(int)*(10 * 100));
}

//イニシャライズ
void CObjBlock::Init()
{
	m_scroll = 0.0f;
}

//アクション
void CObjBlock::Action()
{
	//主人公の位置を取得
	//CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//float hx = hero->GetX();
	//float hy = hero->GetY();

	//後方スクロールライン
	//if (hx < 80)
	//{
	//	hero->SetX(80);
	//	m_scroll -= hero->GetVX();
	//}
	//前方スクロールライン
	//if (hx > 300)
	//{
	//	hero->SetX(300);
	//	m_scroll -= hero->GetVX();
	//}

	//敵出現ライン
	//主人公の位置+500を敵出現ラインにする
	/*float line = hx + (-m_scroll) + 500;*/

	//int ex = ((int)line) / 64;

	//敵出現ラインを要素番号化
	//for (int i = 0; i < 10; i++)
	//{
		//列の中から4を探しす
		//if (m_map[i][ex] == 4)
		//{
		//	//4があれば、敵を出現
		//	CObjEnemy* obje = new CObjEnemy(ex*64.0f, i*64.0f);
		//	Objs::InsertObj(obje, OBJ_ENEMY, 10);

		//	//敵出現場所の値を０にする
		//	m_map[i][ex] = 0;
		//}
	//}
}


void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//
	RECT_F dst;	//

	//背景表示
	src.m_top = 256.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);

	//マップチップによるblock設置
	//切り取り位置の設定

	//m_scroll -= 3.0f;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] > 0)
			{
				//表示位置の設定
				dst.m_top = i*64.0f;
				dst.m_left = j*64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				if (m_map[i][j] == 2)
				{
					//スタートブロック
					BlockDraw(320.0f + 64.0f, 0.0f, &dst, c);
				}
				else if (m_map[i][j] == 3)
				{
					//ゴールブロック
					BlockDraw(320.0f + 64.0f, 0.0f, &dst, c);
					;
				}
				else if (m_map[i][j] == 4)
				{
					;//敵配置用のため何もしない
				}
				else
				{
					//描画
					BlockDraw(320.0f, 0.0f, &dst, c);
				}
			}
		}
	}

}

//BlockDrawMethod関数
//引数1	float	x	:リソース切り取り位置
//引数2	float	x	:リソース切り取り位置
//引数3
//引数4
//ブロックを64*64限定描画用。リソース切り取りの位置のみx.yで
//設定できる
void CObjBlock::BlockDraw(float x, float y, RECT_F*dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//描画
	Draw::Draw(0, &src, dst, c, 0.0f);
}

//BlockHit関数
//引数1	float x
//引数2	float y
//引数3	bool scroll_on
//引数4	bool scroll_on
//引数5	bool scroll_on
//引数6	bool scroll_on
//引数7	bool scroll_on
//引数8	float*vx
//引数9	float*vy
//引数10  int*  bt

void CObjBlock::BlockHit(
	float *x, float *y, bool scroll_on,
	bool*up, bool* down, bool*left, bool* right,
	float* vx, float*vy, int*bt
)
{
	//主人公の衝突状態確認用フラグの初期化
	*up = (false);
	*down = (false);
	*left = (false);
	*right = (false);

	//踏んでいるblockの種類の初期化
	*bt = 0;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 4)
			{
				//要素番号を座標に変更
				float bx = j * 64.0f;
				float by = i * 64.0f;

				//エラー検出
				//スクロールの影響
				float scroll = scroll_on ? m_scroll : 0;

				if ((*x + (-scroll) + 64.0f > bx) && (*x + (-scroll) < bx + 64.0f) && (*y + 64.0f > by) && (*y < by + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = (*x + (-scroll)) - bx;
					float rvy = *y - by;

					//長さを求める
					float len = sqrt(rvx*rvx + rvy * rvy);

					//角度を求める
					float r = atan2(rvy, rvx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さより短い場合判定に入る
					if (len < 88.0f)
					{

						//角度で上下左右を判定
						if ((r < 45 && r > 0) || r > 315)
						{
							//右
							*right = true;	//主人公の左の部分が衝突している
							*x = bx + 64.0f + (scroll);	//ブロックの位置-主人公の幅
							*vx = -(*vx)*0.1f;
						}
						if (r > 45 && r < 135)
						{
							//上
							*down = true;	//主人公の下の部分が衝突している
							*y = by - 64.0f;//ブロックの位置ー主人公の幅
											//種類を渡すスタートとゴールのみ変更する
							if (m_map[i][j] >= 2)
								*bt = m_map[i][j];
							*vy = 0.0f;
						}
						if (r > 135 && r < 225)
						{
							//左
							*left = true;	//主人公の左の部分が衝突している
							*x = bx - 64.0f + (scroll);	//ブロックの位置-主人公の幅
							*vx = -(*vx)*0.1f;
						}
						if (r > 225 && r < 335)
						{
							//下
							*up = true;
							*y = by + 64.0f;
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
}

//内積関数
//引数1,2 float ax,ay :Aベクトル
//引数3,4 float bx,by :Bベクトル
//戻り値　float       :射影
//内容　AベクトルとBベクトルで内積を行い射影を求める
float CObjBlock::Dot(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax*bx + ay*by;
	return t;
}
//外積関数
//引数1,2 float ax,ay :Aベクトル
//引数3,4 float bx,by :Bベクトル
//戻り値　float       :射影
//内容　AベクトルとBベクトルで内積を行い射影を求める
float CObjBlock::Cross(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax*bx - ay*by;
	return t;
}
//符号を求めるマクロ
#define SGN(x) 1-(x <= 0) - (x < 0)

//線と線と交差判定
bool CObjBlock::LineCrossPoint(
	float a1x, float a1y, float a2x, float a2y,
	float b1x, float b1y, float b2x, float b2y,
	float *out_px, float *out_py
)
{
	//エラーコード
	*out_px = -99999.0f;

	//Aベクトル作成(a2<-a1)
	float ax = a2x - a1x; float ay = a2y - a1y;

	//Bベクトル作成
	float bx = b2x - b1x; float by = b2y - b1y;

	//Cベクトル作成
	float cx = b1x - a1x; float cy = b1y - a1y;

	//Dベクトル作成
	float dx = b2x - a1x; float dy = b2y - a1y;

	//A*Cの射影A*Bの射影を求める
	float t1 = Cross(ax, ay, cx, cy);
	float t2 = Cross(ax, ay, dx, dy);

	//符号が同じ方向になっているかどうかチェック
	if (SGN(t1) == SGN(t2))
		return false; //交点無し

					  //射影を絶対値化
	t1 = abs(t1); t2 = abs(t2);

	//交点を求める
	float px = bx*(t1 / (t1 + t2)) + b1x;
	float py = by*(t1 / (t1 + t2)) + b1y;

	//APベクトル
	float apx = px - a1x; float apy = py - a1y;

	//BPベクトル
	float bpx = px - a2x; float bpy = py - a2y;

	//A・APの射影とA・Bpの射影を求める
	float w1 = Dot(ax, ay, apx, apy);
	float w2 = Dot(ax, ay, bpx, bpy);

	//符号チェック
	if (SGN(w1) == SGN(w2))
		return false;//交点が外

					 //交点を返す
	*out_px = px; *out_py = py;

	return true;

}

//主人公と壁の交差判定関数
//引数1,2 float x, y			:主人公の位置
//引数3,4 float vx, vy			:主人公の移動ベクトル
//引数5,6 float out_px, out_y	:blockと交点
//引数7   float*out				:位置から交点までの距離
//主人公の位置+移動ベクトルと各ブロックの辺りで交差判定を行い
//最も近い交点の位置と距離を返す
bool CObjBlock::HeroBlockCrossPoint(
	float x, float y, float vx, float vy,
	float *out_px, float *out_py, float* out_len
)
{
	bool pb = false;
	float len = 99999.0f;
	//ブロック辺りのベクトル
	float edge[4][4] =
	{
		{ 0,  0, 64,  0 },//→
		{ 64,  0, 64, 64 },//↓
		{ 64, 64,  0, 64 },//←
		{ 0, 64,  0,  0 },//→
	};

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 4)
			{
				//ブロックの4辺から交点を探す
				for (int k = 0; k < 4; k++)
				{
					//交点を探す
					float px, py;
					bool b;
					float l = 0.0f;
					b = LineCrossPoint(x, y, x + vx, y + vy,
						j * 64 + edge[k][0], i * 64 + edge[k][1], j * 64 + +edge[k][2], i * 64 + edge[k][3],
						&px, &py);

					//交点チェック
					if (b == true)
					{
						l = sqrt((px - x)*(px - x) + (py - y)*(py - y));

						//みつけた交点の中で最も距離を求める
						if (len > l)
						{
							len = l;
							*out_px = px;
							*out_py = py;
							pb = true;
						}
					}
				}
			}
		}
	}

	*out_len = len;
	return pb;
}


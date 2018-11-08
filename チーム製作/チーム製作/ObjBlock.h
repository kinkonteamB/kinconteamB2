#pragma once
#pragma once
//使用するヘッダー
#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト : ブロック＆背景
class C0bjBlock : public CObj
{
public:
	C0bjBlock(int map[19][84]);
	~C0bjBlock() {};
	void Init();   //イ二シャライズ
	void Action();	//アクション
	void Draw();    //ドロー

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	//ブロックの当たり判定
	void BlockHit(
		float*x, float*y, bool scroll_on,
		bool*up, bool*down, bool*left, bool*right,
		float*vx, float*vy, int*bt
	);


private:
	void BlockDraw(float x, float y, RECT_F*dst, float c[]);
	int m_map[19][84]; //マップ情報

	float m_scroll;     //左右スクロール用

	float Dot(float ax, float ay, float bx, float by);  //内積
	float Cross(float ax, float ay, float bx, float by);  //外積
	float m_scroll_map;
};

#pragma once
//使用ヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック
class CObjBlock : public CObj
{
public:
	CObjBlock(int map[10][100]);
	~CObjBlock() {};
	void Init();
	void Action();
	void Draw();

	/*void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }*/

private:
	void BlockDraw(float x, float y, RECT_F*dst, float c[]);
	int m_map[10][100];//マップ情報仮




};


#pragma once

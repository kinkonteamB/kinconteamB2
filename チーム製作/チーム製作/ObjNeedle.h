#pragma once


#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：針
class CObjNeedle :public CObj
{
public:
	CObjNeedle() {};
	~CObjNeedle() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	int m_map[19][100]; //マップ情報
	float m_x;
	float m_y;


	float m_scroll;     //左右スクロール用
	float m_scroll_map;

};
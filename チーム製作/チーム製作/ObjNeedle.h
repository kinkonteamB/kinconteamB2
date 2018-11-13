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
	
};
#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//マウスクリックのメイン遷移（せんい）
#define MOU_MAIN_HIT_X (319)
#define MOU_MAIN_HIT_V (469)
#define MOU_MAIN_HIT_Y (349)
#define MOU_MAIN_HIT_H (399)

//描画関係の定数
#define TITLE_POS_X (200)
#define TITLE_POS_Y (250)
#define TITLE_FONT_SIZE (40)

#define CLICK_START_POS_X (230)
#define CLICK_START_POS_Y (400)
#define CLICK_START_FONT_SIZE (30)

#define CLICK_RESET_POS_X (680)
#define CLICK_RESET_POS_Y (380)
#define CLICK_RESET_FONT_SIZE (16)

//オブジェクト:タイトル
class CObjTitle :public CObj
{
public:
	CObjTitle() {};
	~CObjTitle() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー
private:
	bool m_key_flag; //キーフラグ
	float m_mou_x;  //マウスの位置X
	float m_mou_y;  //マウスの位置Y
	bool m_mou_r;   //マウスの右ボタン
	bool m_mou_l;   //マウスの左ボタン
};

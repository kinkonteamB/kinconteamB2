#pragma once

#define ALL_RANKING_SIZE (999);

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	COBJ_HERO,
	OBJ_TITLE,
	OBJ_BACKGROUND,
	OBJ_CLEAR,
	OBJ_BLOCK,
	OBJ_OVER,
	OBJ_RANKING,
	OBJ_MENU,
	OBJ_TIME,
	OBJ_GOAL_BLOCK,
	//OBJ_ARROW,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	int minute;
	int m_ranking[10];  //ランキング情報
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include"CObjHero.h"
#include"ObjBackground.h"
#include"ObjClear.h"
#include"ObjBlock.h"
#include"ObjOver.h"
#include"ObjRanking.h"
#include"ObjMenu.h"
#include"ObjTime.h"
//#include"ObjArrow.h"
#include"Objgoalblock.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include"SceneMain.h"
#include"SceneTitle.h"
#include"SceneRanking.h"
#include"SceneClear.h"
#include"SceneOver.h"
#include"SceneMenu.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START  CSceneMain
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------
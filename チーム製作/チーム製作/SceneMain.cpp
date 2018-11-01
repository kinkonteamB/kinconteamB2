//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\UserData.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain.h"
#include"GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//テストラクタ
CSceneMain::~CSceneMain()
{

}


//初期化メソッド
void CSceneMain::InitScene()
{

	//外部グラフィックファイルを読み込み0番に登録（576x384ピクセル）
	Draw::LoadImage(L"1133010303.png", 0, TEX_SIZE_576);

	//出力させる文字のグラフィックを作成
	Draw::LoadImage(L"647749.jpg", 3, TEX_SIZE_1600);

	//背景オブジェクト作成
	CObjTitle* back = new CObjTitle();
	Objs::InsertObj(back, OBJ_TITLE, 3);
	//主人公オブジェクト作成
	C0bjHero* obj = new C0bjHero();   //主人公オブジェクト作成
	Objs::InsertObj(obj, COBJ_HERO, 10);//作った主人公オブジェクトをオブジェクトマネージャーに登録

}


//実行中メソッド
void CSceneMain::Scene()
{

}
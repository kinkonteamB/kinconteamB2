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

	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p; //ステージ情報ポインター
	int size;              //ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"map.csv", &size);//外部データ読み込み

	int map[19][82];
	int count = 1;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 82; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}
	
	//外部グラフィックファイルを読み込み0番に登録（576x384ピクセル）
	Draw::LoadImage(L"1133010303.png", 0, TEX_SIZE_576);

	//背景画像読み込み
	Draw::LoadImage(L"map.jpg", 3, TEX_SIZE_1920);

	Draw::LoadImage(L"Brock3.jpg", 2, TEX_SIZE_768);

	Draw::LoadImage(L"kusa.png", 1, TEX_SIZE_32);

	//主人公オブジェクト作成
	C0bjHero* obj = new C0bjHero();   //主人公オブジェクト作成
	Objs::InsertObj(obj, COBJ_HERO, 10);//作った主人公オブジェクトをオブジェクトマネージャーに登録

	//背景オブジェクト作成
	C0bjBackground * back = new C0bjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 8);
	
	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	////タイムオブジェクト作成
	//C0bjTime* objt = new C0bjTime();
	//Objs::InsertObj(objt, OBJ_TIME, 11);
}


//実行中メソッド
void CSceneMain::Scene()
{

}
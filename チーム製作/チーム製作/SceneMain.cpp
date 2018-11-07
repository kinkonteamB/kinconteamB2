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
	p = Save::ExternalDataOpen(L"mapblock.csv", &size);//外部データ読み込み

	int map[19][75];
	int count = 1;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 75; j++)
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

	Draw::LoadImage(L"block1.png", 1, TEX_SIZE_768);

	//主人公オブジェクト作成
	C0bjHero* obj = new C0bjHero();   //主人公オブジェクト作成
	Objs::InsertObj(obj, COBJ_HERO, 10);//作った主人公オブジェクトをオブジェクトマネージャーに登録

	//背景オブジェクト作成
	C0bjBackground * back = new C0bjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 8);
	
	//blockオブジェクト作成
	C0bjBlock* objb = new C0bjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);
}


//実行中メソッド
void CSceneMain::Scene()
{

}
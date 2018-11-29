//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"
//使用するネームスペース
using namespace GameL;


//使用ヘッダー
#include"SceneMain.h"
#include"GameHead.h"
#include"ObjArrow.h"


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
	//Font作成
	Font::SetStrTex(L"0123456789分秒");

	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p; //ステージ情報ポインター
	int size;              //ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"map2-1.csv", &size);//外部データ読み込み

	int map[19][100];
	int count = 1;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;

			count += 2;
		}
	}

	//Font作成
	Font::SetStrTex(L"0123456789分秒");
	
	//外部グラフィックファイルを読み込み0番に登録（576x384ピクセル）
	Draw::LoadImage(L"1133010303.png", 0, TEX_SIZE_576);

	//背景画像読み込み
	Draw::LoadImage(L"map2haikei.png", 3, TEX_SIZE_1920);

	//ブロック画像読み込み
	Draw::LoadImage(L"brock5.png", 2, TEX_SIZE_768);

	//針罠読み込み
	Draw::LoadImage(L"blockobj2.png", 4, TEX_SIZE_768);

	//矢読み込み
	Draw::LoadImage(L"矢2.png", 5, TEX_SIZE_768);

	//ゴール
	Draw::LoadImage(L"efe.png", 5, TEX_SIZE_768);

	//主人公オブジェクト作成
	C0bjHero* obj = new C0bjHero();   //主人公オブジェクト作成
	Objs::InsertObj(obj, COBJ_HERO, 10);//作った主人公オブジェクトをオブジェクトマネージャーに登録

	//背景オブジェクト作成
	C0bjBackground * back = new C0bjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 8);
	
	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//タイムオブジェクト作成
	C0bjTime* objt = new C0bjTime();
	Objs::InsertObj(objt, OBJ_TIME, 12);

	//音楽読み込み
	Audio::LoadAudio(0, L"moristage.wav", BACK_MUSIC);
	Audio::LoadAudio(1, L"choice.wav", EFFECT);

	//ボリュームを1.5増やす
	float v = Audio::VolumeMaster(0);

	//音楽スタート
	Audio::Start(0);
	////テスト用矢のオブジェクト作成
	//CObjArrow* obja = new CObjArrow();
	//Objs::InsertObj(obja, OBJ_ARROW, 5);

	//弓矢オブジェクト作成
	//CObjArrow* objar = new CObjArrow();
	//Objs::InsertObj(objar, OBJ_ARROW, 12);

}


//実行中メソッド
void CSceneMain::Scene()
{

}
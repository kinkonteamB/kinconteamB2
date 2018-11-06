//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneClear.h"
#include "GameHead.h"

//コンストラクタ
CSceneClear::CSceneClear()
{

}

//デストラクタ
CSceneClear::~CSceneClear()
{

}

//初期化メソッド
void CSceneClear::InitScene()
{

	//出力させる文字のグラフィックを作成
	Draw::LoadImage(L"GameClear.jpg", 4, TEX_SIZE_1600);

	//背景オブジェクト作成
	CObjClear* nk= new CObjClear();
	Objs::InsertObj(nk, OBJ_CLEAR, 4);

	CObjClear* op = new CObjClear();
	Objs::InsertObj(op, OBJ_CLEAR, 1);
}
//実行中メソッド
void CSceneClear::Scene()
{

}
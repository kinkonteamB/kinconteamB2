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
#include"SceneRanking.h"
#include "GameHead.h"

//コンストラクタ
CSceneRanking::CSceneRanking()
{

}

//デストラクタ
CSceneRanking::~CSceneRanking()
{

}

//初期化メソッド
void CSceneRanking::InitScene()
{

	//出力させる文字のグラフィックを作成
	//Draw::LoadImage(L"Ranking.jpg", 4, TEX_SIZE_1600);

	//背景オブジェクト作成
	CObjRanking* or = new CObjRanking();
	Objs::InsertObj(or, OBJ_RANKING, 4);

	CObjRanking* or1 = new CObjRanking();
	Objs::InsertObj(or1, OBJ_RANKING, 1);

	CObjRanking* or2 = new CObjRanking();
	Objs::InsertObj(or2, OBJ_RANKING, 1);

	CObjRanking* or3 = new CObjRanking();
	Objs::InsertObj(or3, OBJ_RANKING, 1);

	CObjRanking* or4 = new CObjRanking();
	Objs::InsertObj(or4, OBJ_RANKING, 1);

	CObjRanking* or5 = new CObjRanking();
	Objs::InsertObj(or5, OBJ_RANKING, 1);

	CObjRanking* or6 = new CObjRanking();
	Objs::InsertObj(or6, OBJ_RANKING, 1);

	CObjRanking* or7 = new CObjRanking();
	Objs::InsertObj(or7, OBJ_RANKING, 1);

	CObjRanking* or8 = new CObjRanking();
	Objs::InsertObj(or8, OBJ_RANKING, 1);

	CObjRanking* or9 = new CObjRanking();
	Objs::InsertObj(or9, OBJ_RANKING, 1);

	CObjRanking* or10 = new CObjRanking();
	Objs::InsertObj(or10, OBJ_RANKING, 1);
}
//実行中メソッド
void CSceneRanking::Scene()
{

}
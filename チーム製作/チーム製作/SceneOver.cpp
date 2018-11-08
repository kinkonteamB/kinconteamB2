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
#include "GameHead.h"
#include "SceneOver.h"

//実行中メソッド
void CSceneOver::Scene()
{

}

//コンストラクタ
CSceneOver::CSceneOver()
{
}

//デストラクタ
CSceneOver::~CSceneOver()
{
}

//初期化メソッド
void CSceneOver::InitScene()
{
	//出力させる文字のグラフィックを作成
	Draw::LoadImage(L"Game Ober.jpg", 4, TEX_SIZE_700);

	//背景オブジェクト作成
	CObjOver* go1 = new CObjOver();
	Objs::InsertObj(go1, OBJ_OVER, 4);

	CObjOver* go2 = new CObjOver();
	Objs::InsertObj(go2, OBJ_OVER, 1);

	CObjOver* go3 = new CObjOver();
	Objs::InsertObj(go3, OBJ_OVER, 1);
}

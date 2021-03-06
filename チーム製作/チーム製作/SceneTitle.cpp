//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include"GameL\DrawTexture.h"
#include"GameL\Audio.h"
//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include "SceneMain.h"
#include "GameHead.h"
#include "SceneTitle.h"
#include "ObjTitle.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	//出力させる文字のグラフィックを作成
	Draw::LoadImage(L"647749.jpg", 3, TEX_SIZE_1600);

	//背景オブジェクト作成
	CObjTitle* back = new CObjTitle();
	Objs::InsertObj(back, OBJ_TITLE, 3);

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"title2.wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	float Volume = Audio::VolumeMaster(1.8);
	Audio::Start(0);    //音楽スタート
}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{

}
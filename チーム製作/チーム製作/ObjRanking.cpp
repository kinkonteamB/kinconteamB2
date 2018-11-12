//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"
#include"GameHead.h"

#include"ObjRanking.h"
#include"SceneMain.h"



//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjRanking::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;

	//ゲーム実行して一回のみ
	static bool init_point = false;
	if (init_point == false)
	{
		//	//ランキング初期化
		for (int i = 0; i < 10; i++)
		{
			((UserData*)Save::GetData())->m_ranking[i] = 0;
		}
	}

	//	//ロード
	//	Save::Open();//同フォルダ「UserData」からデータ取得

		//点数を0にする
//		((UserData*)Save::GetData())->m_time = 0;

	//	init_point = true;
	//}
	////得点情報ランキング最下位（描画圏外）に登録
	//((UserData*)Save::GetData())->m_ranking[9] = ((UserData*)Save::GetData())->m_point;

	////得点が高い順に並び替えをする
	//RankingSort(((UserData*)Save::GetData())->m_ranking);

	////ゲーム実行して一回のみ以外、ランキングを自動的にセーブする
	//if (init_point = true)
	//{
	//	Save::Seve();//UserDataの情報フォルダ「UserData」を作成する

	//}

}

//アクション
void CObjRanking::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	if (m_mou_x > CLICK_TITLE_GO_X && m_mou_x < CLICK_TITLE_GO_X + 140 &&
		m_mou_y > CLICK_TITLE_GO_Y && m_mou_y < CLICK_TITLE_GO_Y + 19)
	{
		//マウスのボタンが押されたらメインに遷移
		if (m_mou_r == true || m_mou_l == true)

		{
			Scene::SetScene(new CSceneTitle());
		}
	}
	//ランキングリセットの部分と当たり判定
	if (m_mou_x > CLICK_RESET_POS_X -12 && m_mou_x < CLICK_RESET_POS_X +103 &&
		m_mou_y>CLICK_RESET_POS_Y -15 && m_mou_y < CLICK_RESET_POS_Y +10)
	{
		if (m_mou_r == true || m_mou_l == true)
		{
			//ランキング初期化
			for (int i = 0; i < 11; i++)
			{
				((UserData*)Save::GetData())->m_ranking[i] = 0;
			}
			m_mou_r = false;
			m_mou_l = false;
		}
	}
}

//ドロー
void CObjRanking::Draw()
{
	float c[4] = { 1,1,1,1 };

	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);

	//ランキング
	Font::StrDraw(L"ランキング", RANKING_POS_X, RANKING_POS_Y, RANKING_FONT_SIZE, c);

	for (int i = 0; i <RANKING_CLASS_MAX; i++)
	{
		wchar_t str[STR_MAX2];
		swprintf_s(str, L"%d階層", i + CLASS_INIT);
		Font::StrDraw(str, CLASS_POS_X, CLASS_POS_Y + CLASS_INTERVAL *i + 1, CLASS_FONT_SIZE, c);
	}

	for (int i = 0; i <RANKING_SCORE_MAX; i++)
	{
		wchar_t str[STR_MAX];
		swprintf_s(str, L"%d 位 %d 秒", i + SCORE_INIT,((UserData*)Save::GetData())->m_ranking[i]);
		Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i+1, SCORE_FONT_SIZE, c);
	}
	//ランキングリセット場所
	if (m_mou_x > 658 && m_mou_x < 761 && m_mou_y > 555 && m_mou_y < 580)
		Font::StrDraw(L"◇ClickReset", CLICK_RESET_POS_X -20, CLICK_RESET_POS_Y, CLICK_RESET_FONT_SIZE, c);
	else
		Font::StrDraw(L"ClickReset", CLICK_RESET_POS_X, CLICK_RESET_POS_Y, CLICK_RESET_FONT_SIZE, c);

	//マウスがその位置に行った時の処理
	if (m_mou_x > CLASS_ALL_POS_X && m_mou_x < CLASS_ALL_POS_X2 && m_mou_y > CLASS_ALL_POS_Y && m_mou_y < CLASS_ALL_POS_Y2)
	    Font::StrDraw(L"◇", CLASS_POS_X - 35, CLASS_POS_Y, CLASS_FONT_SIZE,c);

	if (m_mou_x > CLASS_ALL_POS_X && m_mou_x < CLASS_ALL_POS_X2 && m_mou_y > CLASS_ALL_POS_Y +45 && m_mou_y < CLASS_ALL_POS_Y2 +45)
		Font::StrDraw(L"◇", CLASS_POS_X - 35, CLASS_POS_Y +45, CLASS_FONT_SIZE, c);

	if (m_mou_x > CLASS_ALL_POS_X && m_mou_x < CLASS_ALL_POS_X2 && m_mou_y > CLASS_ALL_POS_Y + 90 && m_mou_y < CLASS_ALL_POS_Y2 + 90)
		Font::StrDraw(L"◇", CLASS_POS_X - 35, CLASS_POS_Y + 90, CLASS_FONT_SIZE, c);

	if (m_mou_x > CLASS_ALL_POS_X && m_mou_x < CLASS_ALL_POS_X2 && m_mou_y > CLASS_ALL_POS_Y + 135 && m_mou_y < CLASS_ALL_POS_Y2 + 135)
		Font::StrDraw(L"◇", CLASS_POS_X - 35, CLASS_POS_Y + 135, CLASS_FONT_SIZE, c);

	if (m_mou_x > CLASS_ALL_POS_X && m_mou_x < CLASS_ALL_POS_X2 && m_mou_y > CLASS_ALL_POS_Y + 180 && m_mou_y < CLASS_ALL_POS_Y2 + 180)
		Font::StrDraw(L"◇", CLASS_POS_X - 35, CLASS_POS_Y + 180, CLASS_FONT_SIZE, c);

	if (m_mou_x > CLASS_ALL_POS_X && m_mou_x < CLASS_ALL_POS_X2 && m_mou_y > CLASS_ALL_POS_Y + 225 && m_mou_y < CLASS_ALL_POS_Y2 + 225)
		Font::StrDraw(L"◇", CLASS_POS_X - 35, CLASS_POS_Y + 225, CLASS_FONT_SIZE, c);

	if (m_mou_x > CLASS_ALL_POS_X && m_mou_x < CLASS_ALL_POS_X2 && m_mou_y > CLASS_ALL_POS_Y + 270 && m_mou_y < CLASS_ALL_POS_Y2 + 270)
		Font::StrDraw(L"◇", CLASS_POS_X - 35, CLASS_POS_Y + 270, CLASS_FONT_SIZE, c);

	if (m_mou_x > CLASS_ALL_POS_X && m_mou_x < CLASS_ALL_POS_X2 && m_mou_y > CLASS_ALL_POS_Y + 315 && m_mou_y < CLASS_ALL_POS_Y2 + 315)
		Font::StrDraw(L"◇", CLASS_POS_X - 35, CLASS_POS_Y + 315, CLASS_FONT_SIZE, c);

	if (m_mou_x > CLASS_ALL_POS_X && m_mou_x < CLASS_ALL_POS_X2 && m_mou_y > CLASS_ALL_POS_Y + 360 && m_mou_y < CLASS_ALL_POS_Y2 + 360)
		Font::StrDraw(L"◇", CLASS_POS_X - 35, CLASS_POS_Y + 360, CLASS_FONT_SIZE, c);

	if (m_mou_x > CLASS_ALL_POS_X && m_mou_x < CLASS_ALL_POS_X2 +21 && m_mou_y > CLASS_ALL_POS_Y + 405 && m_mou_y < CLASS_ALL_POS_Y2 + 405)
		Font::StrDraw(L"◇", CLASS_POS_X - 40, CLASS_POS_Y + 405, CLASS_FONT_SIZE, c);

	if(m_mou_x > CLICK_TITLE_GO_X && m_mou_x < CLICK_TITLE_GO_X +140 && m_mou_y > CLICK_TITLE_GO_Y && m_mou_y < CLICK_TITLE_GO_Y +19)
	Font::StrDraw(L"◇タイトルに戻る", CLICK_TITLE_GO_X -20, CLICK_TITLE_GO_Y, TITLE_FONT_SIZE, c);
	else
	Font::StrDraw(L"タイトルに戻る", CLICK_TITLE_GO_X, CLICK_TITLE_GO_Y, TITLE_FONT_SIZE, c);
}

//ランキングソートメゾット
//引数1　int[11] :ランキング用配列
//高順でバブルソートを行う
void CObjRanking::RankingSort(int rank[10])
{
	//値交換用変数
	int w;

	//バブルソート
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (rank[i] < rank[j])
			{
				//値の交換
				w = rank[i];
				rank[i] = rank[j];
				rank[j] = w;
			}
		}
	}
}


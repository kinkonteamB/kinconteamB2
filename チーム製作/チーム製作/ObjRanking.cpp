//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"
#include"GameHead.h"

#include"ObjRanking.h"
#include"SceneMain.h"



//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjRanking::Init()
{
	m_key_flag = false;
	choose = 1;
	m_time = 8;

		//�Q�[�����s���Ĉ��̂�
		static bool init_point = false;
		if (init_point == false)
		{
			//	//�����L���O������
			for (int i = 0; i < 10; i++)
			{
				((UserData*)Save::GetData())->m_ranking[i] = 0;
			}
		}
	
		//	//���[�h
		//	Save::Open();//���t�H���_�uUserData�v����f�[�^�擾
	
			//�_����0�ɂ���
	//		((UserData*)Save::GetData())->m_time = 0;
	
		//	init_point = true;
		//}
		////���_��񃉃��L���O�ŉ��ʁi�`�挗�O�j�ɓo�^
		//((UserData*)Save::GetData())->m_ranking[9] = ((UserData*)Save::GetData())->m_point;
	
		////���_���������ɕ��ёւ�������
		//RankingSort(((UserData*)Save::GetData())->m_ranking);
	
		////�Q�[�����s���Ĉ��݈̂ȊO�A�����L���O�������I�ɃZ�[�u����
		//if (init_point = true)
		//{
		//	Save::Seve();//UserData�̏��t�H���_�uUserData�v���쐬����
	
		//}
	
	}
	
	//�A�N�V����
	void CObjRanking::Action()
	{
		if (Input::GetVKey(VK_UP) == true && choose > 1 && m_time == 0)
		{
			--choose;
			m_time = 8;
		}
		if (Input::GetVKey(VK_DOWN) == true && choose < 11 && m_time == 0)
		{
			++choose;
			m_time = 8;
		}
	
		if (m_time > 0) {
			m_time--;
			if (m_time <= 0) {
				m_time = 0;
			}
		}
			//�{�^���������ꂽ�烁�C���ɑJ��
			if (Input::GetVKey(VK_BACK) == true)
			{
				if (m_key_flag == true)
				{
					Scene::SetScene(new CSceneTitle());
					m_key_flag = false;
				}
			}
			else
			{
				m_key_flag = true;
			}
		//�����L���O���Z�b�g�̕����Ɠ����蔻��
		if (choose==11)
		{
			if (Input::GetVKey(VK_RETURN) == true)
			{
				if (m_key_flag == true)
				{
					//�����L���O������
					for (int i = 0; i < 11; i++)
					{
						((UserData*)Save::GetData())->m_ranking[i] = 0;
					}
					m_key_flag = false;
				}
			}
		}
		else
		{
			m_key_flag = true;
		}
	}

//�h���[
void CObjRanking::Draw()
{
	float c[4] = { 1,1,1,1 };

	//�����L���O
	Font::StrDraw(L"�����L���O", RANKING_POS_X, RANKING_POS_Y, RANKING_FONT_SIZE, c);

	for (int i = 0; i <RANKING_CLASS_MAX; i++)
	{
		wchar_t str[STR_MAX2];
		swprintf_s(str, L"%d�K�w", i + CLASS_INIT);
		Font::StrDraw(str, CLASS_POS_X, CLASS_POS_Y + CLASS_INTERVAL *i + 1, CLASS_FONT_SIZE, c);
	}

	for (int i = 0; i <RANKING_SCORE_MAX; i++)
	{
		wchar_t str[STR_MAX];
		swprintf_s(str, L"%d �� %d �b", i + SCORE_INIT,((UserData*)Save::GetData())->m_ranking[i]);
		Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i+1, SCORE_FONT_SIZE, c);
	}

	Font::StrDraw(L"�o�b�N�X�y�[�X�Ń^�C�g����", CLICK_TITLE_GO_X, CLICK_TITLE_GO_Y, TITLE_FONT_SIZE, c);

	//�}�E�X�����̈ʒu�ɍs�������̏���
	if (choose == 1)
	    Font::StrDraw(L"��", CLASS_POS_X - 30, CLASS_POS_Y, CLASS_FONT_SIZE,c);

	if (choose == 2)
		Font::StrDraw(L"��", CLASS_POS_X - 30, CLASS_POS_Y +45, CLASS_FONT_SIZE, c);

	if (choose == 3)
		Font::StrDraw(L"��", CLASS_POS_X - 30, CLASS_POS_Y + 90, CLASS_FONT_SIZE, c);

	if (choose == 4)
		Font::StrDraw(L"��", CLASS_POS_X - 30, CLASS_POS_Y + 135, CLASS_FONT_SIZE, c);

	if (choose == 5)
		Font::StrDraw(L"��", CLASS_POS_X - 30, CLASS_POS_Y + 180, CLASS_FONT_SIZE, c);

	if (choose == 6)
		Font::StrDraw(L"��", CLASS_POS_X - 30, CLASS_POS_Y + 225, CLASS_FONT_SIZE, c);

	if (choose == 7)
		Font::StrDraw(L"��", CLASS_POS_X - 30, CLASS_POS_Y + 270, CLASS_FONT_SIZE, c);

	if (choose == 8)
		Font::StrDraw(L"��", CLASS_POS_X - 30, CLASS_POS_Y + 315, CLASS_FONT_SIZE, c);

	if (choose == 9)
		Font::StrDraw(L"��", CLASS_POS_X - 30, CLASS_POS_Y + 360, CLASS_FONT_SIZE, c);

	if (choose == 10)
		Font::StrDraw(L"��", CLASS_POS_X - 30, CLASS_POS_Y + 400, CLASS_FONT_SIZE, c);

	//�����L���O���Z�b�g�ꏊ
	if (choose == 11)
		Font::StrDraw(L"��ClickReset", CLICK_RESET_POS_X - 20, CLICK_RESET_POS_Y, CLICK_RESET_FONT_SIZE, c);
	else
		Font::StrDraw(L"ClickReset", CLICK_RESET_POS_X, CLICK_RESET_POS_Y, CLICK_RESET_FONT_SIZE, c);
}
//
////�����L���O�\�[�g���]�b�g
////����1�@int[11] :�����L���O�p�z��
////�����Ńo�u���\�[�g���s��
void CObjRanking::RankingSort(int rank[10])
{
	//�l�����p�ϐ�+
	int w;

	//�o�u���\�[�g
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (rank[i] < rank[j])
			{
				//�l�̌���
				w = rank[i];
				rank[i] = rank[j];
				rank[j] = w;
			}
		}
	}
}


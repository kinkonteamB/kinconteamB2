//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\UserData.h"

#include "GameHead.h"
#include "ObjTitle.h"

#include"GameL\DrawTexture.h"

#include"GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_key_flag = true;
	choose = 0;
	m_time = 10;

	//�Q�[�����s���Ĉ��̂�
	static bool init_point = false;
	if (init_point == false)
	{
		for (int i = 0; i < 10; i++)
		{
			((UserData*)Save::GetData())->m_ranking[i] = ALL_RANKING_SIZE;
		}

		//���[�h
		Save::Open();//���t�H���_�uUserData�v����f�[�^�擾

		//�_����0�ɂ���
		((UserData*)Save::GetData())->minute = ALL_RANKING_SIZE;

		init_point = true;
	}
	//���_��񃉃��L���O�ŉ��ʁi�`�挗�O�j�ɓo�^
	((UserData*)Save::GetData())->m_ranking[9] = ((UserData*)Save::GetData())->minute;

	Save::Seve();//UserData�̏��t�H���_�uUserData�v���쐬
}

//�A�N�V����
void CObjTitle::Action()
{
	if (Input::GetVKey(VK_UP) == true && choose > 0 && m_time == 0)
	{
		--choose;
		m_time = 10;
	}
	if (Input::GetVKey(VK_DOWN) == true && choose < 2 && m_time == 0)
	{
		++choose;
		m_time = 10;
	}

	if (m_time > 0) {
		m_time--;
		if (m_time <= 0) {
			m_time = 0;
		}
	}
	if (choose == 0)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				Scene::SetScene(new CSceneMain());
				g_px = 64.0f;
				g_py = 450.0f;
				m_time = 20;

				//���_�̏�����
				((UserData*)Save::GetData())->minute = ALL_RANKING_SIZE;
			}
		}
		else
		{
			m_key_flag = true;
		}
	}
	if (choose == 1)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				Scene::SetScene(new CSceneRanking());
			}
		}
		else
		{
			m_key_flag = true;
		}
	}
	if (choose == 2)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			exit(1);
		}
	}
	//���_�̏�����
	((UserData*)Save::GetData())->minute = ALL_RANKING_SIZE;
}

//�h���[
void CObjTitle::Draw()
{
	//�`�ʃJ���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//�`�ʌ��؂���ʒu
	RECT_F dst;//�`�ʐ�\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1600.0f;
	src.m_bottom = 909.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�E���̏������ɕ`��
	Draw::Draw(3, &src, &dst, c, 0.0f);

	float b[4] = { 1,1,1,1 };

	//�^�C�g��
	Font::StrDraw(L"�ِ��E�̓�", 148, 120, 100, b);

		if(choose==0)
			Font::StrDraw(L"��START", GAME_START_POS_X - 55, GAME_START_POS_Y, GAME_START_FONT_SIZE, b);
		else
			Font::StrDraw(L"START", GAME_START_POS_X, GAME_START_POS_Y, GAME_START_FONT_SIZE, b);
		if(choose==1)
			Font::StrDraw(L"��RANKING", GAME_RANKING_POS_X - 55, GAME_RANKING_POS_Y, GAME_RANKING_FONT_SIZE, b);
		else
			Font::StrDraw(L"RANKING", GAME_RANKING_POS_X, GAME_RANKING_POS_Y, GAME_RANKING_FONT_SIZE, b);
		if(choose==2)
			Font::StrDraw(L"��EXIT", GAME_EXIT_POS_X - 55, GAME_EXIT_POS_Y, GAME_EXIT_FONT_SIZE, b);
		else
			Font::StrDraw(L"EXIT", GAME_EXIT_POS_X, GAME_EXIT_POS_Y, GAME_EXIT_FONT_SIZE, b);
}
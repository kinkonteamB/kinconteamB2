//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjTitle.h"

#include"GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_key_flag = false;
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
}

//�A�N�V����
void CObjTitle::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	if (m_mou_x > MOU_START_HIT_X && m_mou_x<MOU_START_HIT_V &&
		m_mou_y>MOU_START_HIT_Y && m_mou_y < MOU_START_HIT_H)
	{
		//�}�E�X�̃{�^���������ꂽ�烁�C���ɑJ��
		if (m_mou_r == true || m_mou_l == true)

		{
			Scene::SetScene(new CSceneMain());
		}
	}

	if (m_mou_x > GAME_RANKING_POS_X -3 && m_mou_x < GAME_RANKING_POS_X +209 &&
		m_mou_y > GAME_RANKING_POS_Y && m_mou_y < GAME_RANKING_POS_Y +40)
	{
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneRanking());
		}
	}

	if (m_mou_x > GAME_EXIT_POS_X && m_mou_x < GAME_EXIT_POS_X +112 &&
		m_mou_y > GAME_EXIT_POS_Y && m_mou_y < GAME_EXIT_POS_Y +25)
	{
		if (m_mou_r == true || m_mou_l == true)
		{
			exit(1);
		}
	}
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
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

	if (m_mou_x > 318 && m_mou_x < 464 && m_mou_y < 399 && m_mou_y >349)
		Font::StrDraw(L"��START", GAME_START_POS_X - 55, GAME_START_POS_Y, GAME_START_FONT_SIZE, b);
	else
		Font::StrDraw(L"START", GAME_START_POS_X, GAME_START_POS_Y, GAME_START_FONT_SIZE, b);

	if (m_mou_x > 287 && m_mou_x < 496 && m_mou_y > 420 && m_mou_y < 460)
		Font::StrDraw(L"��RANKING", GAME_RANKING_POS_X - 55, GAME_RANKING_POS_Y, GAME_RANKING_FONT_SIZE, b);
	else
		Font::StrDraw(L"RANKING", GAME_RANKING_POS_X, GAME_RANKING_POS_Y, GAME_RANKING_FONT_SIZE, b);

	if (m_mou_x > 326 && m_mou_x < 453 && m_mou_y > 487 && m_mou_y < 537)
		Font::StrDraw(L"��EXIT", GAME_EXIT_POS_X - 55, GAME_EXIT_POS_Y, GAME_EXIT_FONT_SIZE, b);
	else
		Font::StrDraw(L"EXIT", GAME_EXIT_POS_X, GAME_EXIT_POS_Y, GAME_EXIT_FONT_SIZE, b);

}
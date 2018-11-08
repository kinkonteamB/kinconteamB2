//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjOver.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjOver::Init()
{

}

//�A�N�V����
void CObjOver::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();


	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	if (m_mou_x > GAME_YES_X -4 && m_mou_x < GAME_YES_X +100 &&
		m_mou_y > GAME_YES_Y -4 && m_mou_y < GAME_YES_Y +38)
	{
		//�}�E�X�̃{�^���������ꂽ�烁�C���ɑJ��
		if (m_mou_r == true || m_mou_l == true)

		{
			Scene::SetScene(new CSceneMain());
		}
	}
	if (m_mou_x > GAME_NO_X -4 && m_mou_x < GAME_NO_X + 144 &&
		m_mou_y > GAME_NO_Y -4 && m_mou_y < GAME_NO_Y + 35)
	{
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneTitle());
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
void CObjOver::Draw()

{
	//�`�ʃJ���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//�`�ʌ��؂���ʒu
	RECT_F dst;//�`�ʐ�\���ʒu

    //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 700.0f;
	src.m_bottom = 420.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�E���̏������ɕ`��
	Draw::Draw(4, &src, &dst, c, 0.0f);

	float p[4] = { 1,1,1,1 };

	Font::StrDraw(L"Game Over", GAME_OVER_X, GAME_OVER_Y, GAME_OVER_FONT_SIZE, p);

	Font::StrDraw(L"�R���e�j���[���܂����H", GAME_CON_X, GAME_CON_Y, GAME_CON_FONT_SIZE, p);

    if(m_mou_x > 330 && m_mou_x < 435 && m_mou_y > 395 && m_mou_y < 439)
	Font::StrDraw(L"���͂�", GAME_YES_X -30, GAME_YES_Y, GAME_YES_FONT_SIZE, p);
	else
	Font::StrDraw(L"�͂�", GAME_YES_X, GAME_YES_Y, GAME_YES_FONT_SIZE, p);

	if (m_mou_x > 310 && m_mou_x < 460 && m_mou_y > 475 && m_mou_y < 516)
	Font::StrDraw(L"��������", GAME_NO_X -30, GAME_NO_Y, GAME_NO_FONT_SIZE, p);
	else
	Font::StrDraw(L"������", GAME_NO_X, GAME_NO_Y, GAME_NO_FONT_SIZE, p);

}

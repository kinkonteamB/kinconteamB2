//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjMenu.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMenu::Init()
{

}

//�A�N�V����
void CObjMenu::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


	if (m_mou_x > GAME_BACK_X - 5 && m_mou_x < GAME_BACK_X + 292 &&
		m_mou_y > GAME_BACK_Y - 5 && m_mou_y < GAME_BACK_Y + 40)
	{
		//�}�E�X�̃{�^���������ꂽ�烁�C���ɑJ��
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneMain());
		}
	}

	if (m_mou_x > TITLE_BACK_X - 3 && m_mou_x < TITLE_BACK_X + 339 &&
		m_mou_y > TITLE_BACK_Y - 6 && m_mou_y < TITLE_BACK_Y + 38)
	{
		//�}�E�X�̃{�^���������ꂽ�烁�C���ɑJ��
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneTitle());
		}
	}


}
//�h���[
void CObjMenu::Draw()

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
	Draw::Draw(4, &src, &dst, c, 0.0f);

	float b[4] = { 1,1,1,1 };

	Font::StrDraw(L"���j���[", 230, 100, 90, c);

	if(m_mou_x > GAME_BACK_X -5 && m_mou_x < GAME_BACK_X +292 &&
		m_mou_y > GAME_BACK_Y -5 && m_mou_y < GAME_BACK_Y +40)
    	Font::StrDraw(L"���Q�[���ɖ߂�", GAME_BACK_X -50, GAME_BACK_Y, GAME_DOBLE_FONT, c);
	else
		Font::StrDraw(L"�Q�[���ɖ߂�", GAME_BACK_X, GAME_BACK_Y, GAME_DOBLE_FONT, c);

	if(m_mou_x > TITLE_BACK_X - 3 && m_mou_x < TITLE_BACK_X + 339 &&
		m_mou_y > TITLE_BACK_Y - 6 && m_mou_y < TITLE_BACK_Y + 38)
		Font::StrDraw(L"���^�C�g���ɖ߂�", TITLE_BACK_X -50, TITLE_BACK_Y, GAME_DOBLE_FONT, c);
	else
		Font::StrDraw(L"�^�C�g���ɖ߂�", TITLE_BACK_X, TITLE_BACK_Y, GAME_DOBLE_FONT, c);


}

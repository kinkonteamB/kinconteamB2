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
	choose = 0;
	m_time = 10;
}

//�A�N�V����
void CObjMenu::Action()
{
	if (Input::GetVKey(VK_UP) == true)
	{
		choose = 0;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		choose = 1;
	}

	if (choose == 0)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{

			if (m_key_flag == true)
			{
				Scene::SetScene(new CSceneMain());
				m_key_flag = false;
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
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
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

	if(choose==0)
		Font::StrDraw(L"���Q�[���ɖ߂�", GAME_BACK_X -40,GAME_BACK_Y, GAME_DOBLE_FONT, c);
	else
		Font::StrDraw(L"�Q�[���ɖ߂�", GAME_BACK_X, GAME_BACK_Y, GAME_DOBLE_FONT, c);
	if (choose == 1)
		Font::StrDraw(L"���^�C�g���ɖ߂�", TITLE_BACK_X -40, TITLE_BACK_Y, GAME_DOBLE_FONT, c);
	else
		Font::StrDraw(L"�^�C�g���ɖ߂�", TITLE_BACK_X, TITLE_BACK_Y, GAME_DOBLE_FONT, c);
}

//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"

#include"GameHead.h"
#include"ObjTime.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void C0bjTime::Init()
{
	m_time = 0;
	m_flag_time = false;
}

//�A�N�V����
void C0bjTime::Action()
{
	//��l���̈ʒu���擾
	C0bjHero*hero = (C0bjHero*)Objs::GetObj(COBJ_HERO);

	//�X�^�[�g�u���b�N�𓥂�ł���Ȃ�t���O���I���ɂ���
	if (gh_spx == 64.0f || gh_spy == 500.0f)
	{
		m_flag_time = true;
	}

	//�t���O���I���̎��A���Ԃ�i�߂�
	if (m_flag_time == true)
	{
		m_time++;

		if (timekeeper[i] > m_time)
		{
			timekeeper[i] = m_time;
		}
	}
}

//�h���[
void C0bjTime::Draw()
{
	//m_time����b�������߂�

	int minute;
	minute= (m_time / 60) % 999; //�b

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	wchar_t str[128];
	//��:�b�̒l�𕶎����
	swprintf_s(str, L"%d�b", ((UserData*)Save::GetData())->minute = minute);//�b��1���ڂ�0��p��
	Font::StrDraw(str, 10, 10, 20, c);
}




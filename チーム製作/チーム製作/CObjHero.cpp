//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"CObjHero.h"



//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void C0bjHero::Init()
{
	m_px = 100.0f;
	m_py = 100.0f;    //�ʒu

	m_vx = 0.0f;    //�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f; //�E����0.0f,������1,0f

	m_ani_time = 0;
	m_ani_frame = 0;  //�Î~�t���[��������������

	m_speed_power = 0.5f;//�ʏ푬�x
	m_ani_max_time = 4;  //�A�j���[�V�����Ԋu��


//�����蔻��p��HitBox���쐬
						
//Hits::SetHitBox(this, m_px, m_py, 64, 32, ELEMENT_PLAYER, COBJ_HERO, 1);
}

//�A�N�V����
void C0bjHero::Action()
{
	m_speed_power = 0.5f;

	//�L�[�̓��͕���
	//�W�����v
	if (Input::GetVKey('W') == true)
	{
		m_vy = -15;
		m_py += m_vy;
	}
	//���Ⴊ��
	if (Input::GetVKey('S') == true)
	{
		m_ani_frame = 5;
		m_ani_time = 0;
		m_speed_power = 0.3f;
		if (m_ani_frame != 5)//5�̃t���[���ȊO�Ȃ牽�����Ȃ�
		{
		}
		else if (Input::GetVKey('D') == true) //���Ⴊ�ށi�E�ړ��j
		{
			m_vx += m_speed_power;
			m_posture = 1.0f;
		}
		else if (Input::GetVKey('A') == true)//���Ⴊ�ށi�E�ړ��j
		{
			m_vx -= m_speed_power;
			m_posture = 0.0f;
		}
	}
	else if (m_ani_frame >= 4)
	{
		m_ani_frame = 0;
		m_ani_time = 0;
	}
	else if (Input::GetVKey('D') == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey('A') == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 0;   //�L�[���͂������ꍇ�Î~�t���[���ɂ���
		m_ani_time = 0;
	}
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//���C
	m_vx += -(m_vx*0.098);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//��l���@���̈�O�s���Ȃ�����
	if (m_px + 64.0f > 800.0f)
	{
		m_px = 800.0f - 64.0f;
	}

	if (m_py + 64.0f > 600.0f)
	{
		m_py = 600.0f - 64.0f;
	}

	if (m_py < 0.0f)
	{
		m_py = 0.0f;
	}

	if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}
}
//�h���[
void C0bjHero::Draw()
{
	int AniData[6] =
	{
		0,1,0,2,3,4
	};

	//�`�ʃJ���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//�`�ʌ��؂���ʒu
	RECT_F dst;//�`�ʐ�\���ʒu

			   //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f*m_posture) + m_px;
	dst.m_right = (64 - 64.0f*m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

	//0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�E���̏������ɕ`��
	Draw::Draw(0, &src, &dst, c, 0.0f);


}
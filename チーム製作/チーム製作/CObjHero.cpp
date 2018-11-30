//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"CObjHero.h"
#include"GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

float g_px = 64.0f;
float g_py = 450.0f;

//�C�j�V�����C�Y
void C0bjHero::Init()
{

	m_vx = 0.0f;    //�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f; //�E����0.0f,������1,0f

	m_ani_time = 0;
	m_ani_frame = 0;  //�Î~�t���[��������������

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0;	//����ł���u���b�N�̎��


	m_speed_power = 0.5f;//�ʏ푬�x
	m_ani_max_time = 4;  //�A�j���[�V�����Ԋu��

	m_time = 31;

//�����蔻��p��HitBox���쐬
						
Hits::SetHitBox(this, g_px, g_py,32,64, ELEMENT_PLAYER, COBJ_HERO, 1);
}

//�A�N�V����
void C0bjHero::Action()
{


	if (Input::GetVKey(VK_TAB) == true) 
	{
		Scene::SetScene(new CSceneMenu());
	}

	//�����ɂ��Q�[���I�[�o�[�����X�^�[�g
	if (g_py > 1000.0f)
	{
		//��O�ɏo���烊�X�^�[�g
		Scene::SetScene(new CSceneOver());
	}

	m_speed_power = 0.5f;

	//Shiht�L�[���͂ő��x�A�b�v

	if (Input::GetVKey(VK_SHIFT) == true)
	{
		//�_�b�V�����̑��x
		m_speed_power = 0.6f;
		m_ani_max_time = 2;
	}
	//�W�����v
	if (Input::GetVKey('W') == true)
	{
		if (m_hit_down == true &&m_time==0 )
		{
			m_vy = -9;
			g_py += m_vy;

			Audio::Start(1);

		}
	}
	if (m_time > 0) {
		m_time--;
		if (m_time <= 0) {
			m_time = 0;
		}
	}

	//���Ⴊ��
	if (Input::GetVKey('S') == true)
	{
		m_ani_frame = 5;
		m_ani_time = 0;
		m_speed_power = 0.2f;
		if (m_ani_frame != 5)//5�̃t���[���ȊO�Ȃ牽�����Ȃ�
		{
		}

		else if (Input::GetVKey('D') == true) //���Ⴊ�ށi�E�ړ��j
		{
			m_vx += m_speed_power;
			m_posture = 1.0f;
		}
		else if (Input::GetVKey('A') == true)//���Ⴊ�ށi���ړ��j
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

	//��l���@���̈�O�s���Ȃ�����
	if (g_px + 64.0f > 800.0f)
	{
		g_px = 800.0f - 64.0f;

	}

	CObjBlock*b = (CObjBlock*)Objs::GetObj(COBJ_HERO);
	//����X�N���[�����C��
	if (g_px < 80)
	{
		g_px = 80;
		b->SetScroll(b->GetScroll());
	}

	//�O���X�N���[�����C��
	if (g_px > 350)
	{
		g_px = 350;
		b->SetScroll(b->GetScroll());
	}
	
	//���C
	m_vx += -(m_vx*0.098);

	//���R�����^��
	m_vy += 9.8 / (16.0f);

	//�ʒu�̍X�V
	g_px += m_vx;
	g_py += m_vy;

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&g_px, &g_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//���g��HitBox�������Ă���
	CHitBox*hit = Hits::GetHitBox(this);

	//HitBox�̈ʒu��ύX	
	hit->SetPos(g_px+18, g_py);

	//㩂ɐڐG�����烊�X�^�[�g
	if (hit->CheckObjNameHit(OBJ_BLOCK) != nullptr)
	{
		//��O�ɏo���烊�X�^�[�g
		Scene::SetScene(new CSceneOver());
		g_px = 64.0f;
		g_py = 500.0f;
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
	dst.m_top = 0.0f + g_py;
	dst.m_left = (64.0f*m_posture) + g_px;
	dst.m_right = (64 - 64.0f*m_posture) + g_px;
	dst.m_bottom = 64.0f + g_py;

	//0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�E���̏������ɕ`��
	Draw::Draw(0, &src, &dst, c, 0.0f);

}
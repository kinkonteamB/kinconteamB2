//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"
#include"GameHead.h"
#include"ObjArrow.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
 CObjArrow::CObjArrow()
{

}
//�C�j�V�����C�Y
void CObjArrow::Init()
{
	/*m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_vx = -1.0f;

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_ARROW, 1);*/
}
//�A�N�V����
void CObjArrow::Action()
{
	/*//Resources�̕`�敨��RECT
	m_eff = GetBulletEffec(&m_ani, &m_ani_time, m_del, 2);

	//�e�ۏ��ŏ��� -----
	if (m_del == true)
	{
		//���e�A�j���[�V�����I���Ŗ{���ɃI�u�W�F�N�g��j��
		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

		return;//���ŏ����́A�����ŃA�N�V�������\�b�h���I��������
	}

	//�e�ێ��s�����@-----
	m_vx += 1.0f;
	m_x += m_vx;

	//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);          //HitBox�̈ʒu��e�ۂ̈ʒu���ɍX�V

									//�����蔻����s���I�u�W�F�N�g���S
	int data_base[6] =
	{
		OBJ_ENEMY,
		OBJ_ATTACK_ENEMY,
		OBJ_SIN_ENEMY,
		OBJ_DIFFUSION_ENEMY,
		OBJ_HOMING_ENEMY,
		OBJ_BOSS_ENEMY,
	};

	//�I�u�W�F�N�g���S�Ɠ����蔻��s���B�������Ă���΍폜
	for (int i = 0; i < 6; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			Audio::Start(3);      //���e����炷

			m_del = true;                //���Ŏ��s
			hit->SetInvincibility(true);//�����蔻�薳��
		}
	}*/

}

//�h���[
void CObjArrow::Draw()
{
	//�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��j
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


	//�A�j���[�V����RECT���
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 61.0f;
	dst.m_bottom = 16.0f;

	//�e�ۂ̏�Ԃŕ`���ύX
	//if (m_del == true)
	//{
		//���e�A�j���[�V�����`��
		//Draw::Draw(0, &m_eff, &dst, c, 0.0f);
	//}
	//else
	//{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 61.0f;
		src.m_bottom = 16.0f;
		//0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
		Draw::Draw(5, &dst, &src, c, 0.0f);
}

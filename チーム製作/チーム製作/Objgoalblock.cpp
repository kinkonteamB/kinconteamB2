//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"Objgoalblock.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjgoalblock::CObjgoalblock(float x, float y)
{
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void CObjgoalblock::Init()
{
	m_ani_time = 0;
	m_ani_frame = 0;  //�Î~�t���[��������������
	m_ani_max_time =15;  //�A�j���[�V�����Ԋu��

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_ENEMY, OBJ_GOAL_BLOCK, 1);

}

//�A�N�V����
void CObjgoalblock::Action()
{
	m_ani_time += 1;
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//���g��HitBox�������Ă���
	CHitBox*hit = Hits::GetHitBox(this);

	//��l���Ɠ������Ă��邩�m�F
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		Scene::SetScene(new CSceneClear());
	}

	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//HitBox�̈ʒu��ύX	
	hit->SetPos(m_px+block->GetScroll(),m_py);
}
//�h���[
void CObjgoalblock::Draw()
{
	int AniData[5] =
	{
		0,1,2,3,4
	};

	//�`�ʃJ���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//�`�ʌ��؂���ʒu
	RECT_F dst;//�`�ʐ�\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 32;
	src.m_right = ALL_BLOCK_SIZE + AniData[m_ani_frame] * 32;
	src.m_bottom = ALL_BLOCK_SIZE;
	
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�\���ʒu�̐ݒ�
	dst.m_top  = 0.0f  + m_py;
	dst.m_left = 0.0f  + m_px + block->GetScroll();
	dst.m_right =ALL_BLOCK_SIZE  + m_px + block->GetScroll();
	dst.m_bottom =ALL_BLOCK_SIZE + m_py;

	Draw::Draw(5, &src, &dst, c, 0.0f);

}
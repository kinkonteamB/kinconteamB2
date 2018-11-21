//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjNeedle.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjNeedle::Init()
{

	m_scroll = 0.0f;
	m_scroll_map = 0.0f;
	float m_x1 = 0.0f;

	//�����蔻��phitbox�쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_NEEDLE, 12);
}

//�A�N�V����
void CObjNeedle::Action()
{
	//HitBox�̓��e���X�V
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
}
//�h���[
void CObjNeedle::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`�挳�\���ʒu

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] == 2)
			{
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				Draw::Draw(4, &src, &dst, c,0.0f);
			}
		}
	}




}

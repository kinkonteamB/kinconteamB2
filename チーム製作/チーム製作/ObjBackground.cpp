//�g�p��vx��w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"GameL\WinInputs.h"

#include"ObjBackground.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void  C0bjBackground::Init()
{
	m_x1 = 0.0f;
}

//�A�N�V����
void  C0bjBackground::Action()
{
	//��l���̈ʒu���擾
	C0bjHero*hero = (C0bjHero*)Objs::GetObj(COBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();
}

//�h���[
void C0bjBackground::Draw()

{

	//�`�ʃJ���[���@R=RED G=Green A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,5.0f };

	RECT_F src;//�`�ʌ��؂���ʒu
	RECT_F dst;//�`�ʐ�\���ʒu

	//�؂���ʒu�̐ݒ�

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1000.0f;
	src.m_bottom = 740.0f;
	
	//�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(3, &src, &dst, c, 0.0f);

}
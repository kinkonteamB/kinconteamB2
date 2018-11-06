//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjBlock.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


C0bjBlock::C0bjBlock(int map[18][75])
{
	//�}�b�v�f�[�^�R�s�[
	memcpy(m_map, map, sizeof(int)*(18 * 75));
}

//�C�j�V�����C�Y
void C0bjBlock::Init()
{
	m_scroll = 0.0f;
	m_scroll_map = 0.0f;
	float m_x1 = 0.0f;
}



//�A�N�V����
void C0bjBlock::Action()
{
	//��l���̈ʒu���擾
	C0bjHero*hero = (C0bjHero*)Objs::GetObj(COBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

}
//�h���[
void C0bjBlock::Draw()
{

	//�`�ʃJ���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//�`�ʌ��؂���ʒu
	RECT_F dst;//�`�ʐ�\���ʒu

			   //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 34.0f;
	src.m_bottom = 34.0f;


	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 75; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i*64.0f;
				dst.m_left = j*64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;

				Draw::Draw(1, &src, &dst, c, 0.0f);
			}
		}
	}
}
//BlockHit�֐�
//�����P    float * x           :������s��object��X�ʒu
//�����Q    float * y           :������s��object��Y�ʒu
//�����R    bool     scroll_on  :������s��object�̓X�N���[���̉e���^���邩�ǂ����itrue=�^����@false=�^���Ȃ��j
//�����S    bool *   up         :�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//�����T    bool *   down       :�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//�����U    bool *   left       :�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//�����V    bool *   right      :�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//�����W    float * vx          :���E���莞�̔����ɂ��ړ������E�͂̒l�ς��ĕԂ�
//�����X    float * vy          :�㉺���莞�ɂ�鎩�R�����^���̈ړ������E�͂̒l�ς��ĕԂ�
//�����P�O  int * bt            :���������莞�A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N64�~64����ŁA�����蔻��Ə㉺���E������s��
//���̌��ʂ͈���4�`10�ɕԂ�
void C0bjBlock::BlockHit(
	float *x, float *y, bool scroll_on,
	bool*up, bool*down, bool*left, bool*right,
	float *vx, float*vy, int *bt
)
{
	//�Փˏ�Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//����ł���block�̎�ނ̏�����
	*bt = 0;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 75; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 4)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*64.0f;
				float by = i*64.0f;

				//�X�N���[���̉e��
				float scroll = scroll_on ? m_scroll : 0;

				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x + (-scroll) + 64.0f>bx) && (*x + (-scroll)<bx + 64.0f) && (*y + 64.0f>by) && (*y<by + 32.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = ((*x + (-scroll)) + 64) - (bx + 32);
					float rvy = (*y + 64) - (by + 32);


					//���������߂�
					float len = sqrt(rvx*rvx + rvy*rvy);

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 120.0f)
					{

						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r>0) || r > 315)
						{
							//�E
							*right = true;//�I�u�W�F�N�g�̍��̕������Փ˂��Ă���
							*x = bx + 64.0f + (scroll);//�u���b�N�̈ʒu+��l���̕�

							if (*vx < 0.0f)
								*vx = -(*vx)*0.1f;//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							*down = true;//��l���̉��̕������Փ˂��Ă���
							*y = by - 120.0f;//�u���b�N�̈ʒu-��l���̕�
											 //��ނ�n���̃X�^�[�g�ǃS�[���̂ݕύX����
							if (m_map[i][j] >= 2)
								*bt = m_map[i][j];//�u���b�N�̗v�f(type)����l���ɓn��
							*vy = 0.0f;
						}
						if (r > 135 && r < 225)
						{
							//��
							*left = true;//��l���̉E�̕������Փ˂��Ă���
							*x = bx - 138.0f + (scroll);//�u���b�N�̈ʒu-��l���̕�
							if (*vx > 0.0f)
								*vx = -(*vx)*0.1f;//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							*up = true;//��l���̏�̕������Փ˂��Ă���
							*y = by + 126.0f;//�u���b�N�̈ʒu+��l���̕�
							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}
					}
				}
			}
		}
	}
}

void C0bjBlock::BlockDraw(float x, float y, RECT_F * dst, float c[])
{
}
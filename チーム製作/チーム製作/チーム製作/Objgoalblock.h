#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;


extern float g_px;
extern float g_py;

//�I�u�W�F�N�g : �S�[���u���b�N
class CObjgoalblock : public CObj
{
#define ALL_BLOCK_SIZE (32.0f)
public:
	CObjgoalblock(float x,float y);
	~CObjgoalblock() {};
	void Init();   //�C��V�����C�Y
	void Action();	//�A�N�V����
	void Draw();    //�h���[
	int m_map[19][100]; //�}�b�v���

private:
	int m_ani_time; //�A�j���[�V�����t���[������Ԋu
	int m_ani_frame;  //�`��t���[��
	float m_ani_max_time;//�A�j���[�V��������Ԋu�ő�l
	int m_py;
	int m_px;
};
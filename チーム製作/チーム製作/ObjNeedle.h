#pragma once


#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�j
class CObjNeedle :public CObj
{
public:
	CObjNeedle() {};
	~CObjNeedle() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	int m_map[19][100]; //�}�b�v���
	float m_x;
	float m_y;


	float m_scroll;     //���E�X�N���[���p
	float m_scroll_map;

};
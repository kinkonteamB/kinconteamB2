#pragma once
#pragma once
//�g�p����w�b�_�[
#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : �u���b�N���w�i
class C0bjBlock : public CObj
{
public:
	C0bjBlock(int map[19][84]);
	~C0bjBlock() {};
	void Init();   //�C��V�����C�Y
	void Action();	//�A�N�V����
	void Draw();    //�h���[

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	//�u���b�N�̓����蔻��
	void BlockHit(
		float*x, float*y, bool scroll_on,
		bool*up, bool*down, bool*left, bool*right,
		float*vx, float*vy, int*bt
	);


private:
	void BlockDraw(float x, float y, RECT_F*dst, float c[]);
	int m_map[19][84]; //�}�b�v���

	float m_scroll;     //���E�X�N���[���p

	float Dot(float ax, float ay, float bx, float by);  //����
	float Cross(float ax, float ay, float bx, float by);  //�O��
	float m_scroll_map;
};

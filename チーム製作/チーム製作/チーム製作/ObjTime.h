#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : �u���b�N���w�i
class C0bjTime : public CObj
{
public:
	C0bjTime() {};
	~C0bjTime() {};
	void Init();   //�C��V�����C�Y
	void Action();	//�A�N�V����
	void Draw();    //�h���[

	void SetTimeFlag(bool b) { m_flag_time = b; }
private:
	int m_time;  //����
	bool m_flag_time;//���Ԍv���X�^�[�g�t���O
	int timekeeper[9];
	int i = 300;
	float gh_spx = 64.0f;
	float gh_spy = 500.0f;
};
#pragma once
#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�`��֌W�̒萔
#define GAME_BACK_X (250)
#define GAME_BACK_Y (380)

#define TITLE_BACK_X (225)
#define TITLE_BACK_Y (490)

#define GAME_DOBLE_FONT (50)

//�I�u�W�F�N�g:�N���A
class CObjMenu : public CObj
{
public:
	CObjMenu() {};
	~CObjMenu() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[
private:
	bool m_key_flag;//�L�[�t���O
	int choose;
	int m_time;
};
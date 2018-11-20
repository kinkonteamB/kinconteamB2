#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�`��֌W�̒萔

#define GAME_CLEAR_X (130)
#define GAME_CLEAR_Y (160)
#define GAME_CLEAR_FONT_SIZE (100)

#define NEXT_STAGE_X (230)
#define NEXT_STAGE_Y (300)
#define NEXT_STAGE_FONT_SIZE (70)

#define NEXT_STAGE_YES_X (335)
#define NEXT_STAGE_YES_Y (400)
#define NEXT_STAGE_YES_FONT_SIZE (70)

#define NEXT_STAGE_NO_X (315)
#define NEXT_STAGE_NO_Y (480)
#define NEXT_STAGE_NO_FONT_SIZE (70)

#define STR_MAX (256)
#define SCORE_INIT (1)
#define SCORE_POS_X (670)
#define SCORE_POS_Y (24)
#define SCORE_POINT_MAX (100)
#define SCORE_INTERVAL (24)
#define SCORE_FONT_SIZE (12)

#define CLICK_START_POS_X (230)
#define CLICK_START_POS_Y (400)
#define CLICK_START_FONT_SIZE (30)

#define CLICK_RESET_POS_X (680)
#define CLICK_RESET_POS_Y (380)
#define CLICK_RESET_FONT_SIZE (16)


//�I�u�W�F�N�g:�N���A
class CObjClear : public CObj
{
public:
	CObjClear() {};
	~CObjClear() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[
private:
	bool m_key_flag;//�L�[�t���O
	float m_mou_x;  //�}�E�X�̈ʒuX
	float m_mou_y;  //�}�E�X�̈ʒuY
	bool m_mou_r;   //�}�E�X�̉E�{�^��
	bool m_mou_l;   //�}�E�X�̍��{�^��
	int choose;
};
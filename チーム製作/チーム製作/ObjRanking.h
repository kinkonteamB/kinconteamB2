#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"ObjTime.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�萔
//�}�E�X�N���b�N�̃��C���J�ځi���񂢁j
#define MOU_MAIN_HIT_X (230)
#define MOU_MAIN_HIT_V (450)
#define MOU_MAIN_HIT_Y (400)
#define MOU_MAIN_HIT_H (430)

//�`��֌W�̒萔
#define RANKING_CLASS_MAX (10)
#define CLASS_INIT (1)
#define CLASS_POS_X (89)
#define CLASS_ALL_POS_X (89)
#define CLASS_ALL_POS_X2 (174)
#define CLASS_POS_Y (109)
#define CLASS_ALL_POS_Y (105)
#define CLASS_ALL_POS_Y2 (140)
#define CLASS_FONT_SIZE (35)
#define CLASS_INTERVAL (45)

#define RANKING_POS_X (256)
#define RANKING_POS_Y (22)
#define RANKING_FONT_SIZE (50)
#define RANKING_SCORE_MAX (9)

#define STR_MAX (256)
#define STR_MAX2 (256)


#define CLICK_TITLE_GO_X  (30)
#define CLICK_TITLE_GO_Y  (50)
#define TITLE_FONT_SIZE (20)

#define SCORE_INIT (1)
#define SCORE_POS_X (516)
#define SCORE_POS_Y (109)
#define SCORE_POINT_MAX (100)
#define SCORE_INTERVAL (45)
#define SCORE_FONT_SIZE (35)

#define CLICK_RESET_POS_X (670)
#define CLICK_RESET_POS_Y (570)
#define CLICK_RESET_FONT_SIZE (20)

#define CLICK_RESET_POS_X (670)
#define CLICK_RESET_POS_Y (570)
#define CLICK_RESET_FONT_SIZE (20)


//�I�u�W�F�N�g : �^�C�g��
class CObjRanking : public CObj
{
public:
	CObjRanking() {};
	~CObjRanking() {};
	void Init();   //�C��V�����C�Y
	void Action();	//�A�N�V����
	void Draw();    //�h���[

private:
	float m_mou_x;  //�}�E�X�̈ʒuX
	float m_mou_y;  //�}�E�X�̈ʒuY
	bool m_mou_r;   //�}�E�X�̉E�{�^��
	bool m_mou_l;   //�}�E�X�̍��{�^��

	//�����L���O�\�[�g���]�b�g
	void RankingSort(int rank[10]);

};
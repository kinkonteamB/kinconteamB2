//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneRanking.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneRanking::CSceneRanking()
{

}

//�f�X�g���N�^
CSceneRanking::~CSceneRanking()
{

}

//���������\�b�h
void CSceneRanking::InitScene()
{
	//�w�i�I�u�W�F�N�g�쐬
	CObjRanking* or = new CObjRanking();
	Objs::InsertObj(or, OBJ_RANKING, 4);
}
//���s�����\�b�h
void CSceneRanking::Scene()
{

}
//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include"GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"
#include "SceneTitle.h"
#include"ObjTitle.h"

//�R���X�g���N�^
CSceneClear::CSceneClear()
{

}

//�f�X�g���N�^
CSceneClear::~CSceneClear()
{

}

//���������\�b�h
void CSceneClear::InitScene()
{

	//�o�͂����镶���̃O���t�B�b�N���쐬
	Draw::LoadImage(L"GameClear.jpg", 3, TEX_SIZE_1600);

	//�w�i�I�u�W�F�N�g�쐬
	CObjClear* back = new CObjClear();
	Objs::InsertObj(back, OBJ_TITLE, 3);

	CObjClear* obj = new CObjClear();
	Objs::InsertObj(obj, OBJ_CLEAR, 1); 

	CObjClear* o = new CObjClear();
	Objs::InsertObj(o, OBJ_TITLE, 1);

	CObjClear* j = new CObjClear();
	Objs::InsertObj(j, OBJ_TITLE, 1);
}

//���s�����\�b�h
void CSceneClear::Scene()
{

}
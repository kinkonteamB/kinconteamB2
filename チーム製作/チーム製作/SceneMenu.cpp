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
#include "SceneMenu.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMenu::CSceneMenu()
{

}

//�f�X�g���N�^
CSceneMenu::~CSceneMenu()
{

}

//���������\�b�h
void CSceneMenu::InitScene()
{

	//�w�i�I�u�W�F�N�g�쐬
	CObjMenu* om1 = new CObjMenu();
	Objs::InsertObj(om1, OBJ_MENU, 1);

	CObjMenu* om2 = new CObjMenu();
	Objs::InsertObj(om2, OBJ_MENU, 1);

	CObjMenu* om3 = new CObjMenu();
	Objs::InsertObj(om3, OBJ_MENU, 1);
}
//���s�����\�b�h
void CSceneMenu::Scene()
{

}
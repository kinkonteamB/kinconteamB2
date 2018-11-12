//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\UserData.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;


//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�e�X�g���N�^
CSceneMain::~CSceneMain()
{

}


//���������\�b�h
void CSceneMain::InitScene()
{

	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p; //�X�e�[�W���|�C���^�[
	int size;              //�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"map.csv", &size);//�O���f�[�^�ǂݍ���

	int map[19][82];
	int count = 1;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 82; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}
	
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^�i576x384�s�N�Z���j
	Draw::LoadImage(L"1133010303.png", 0, TEX_SIZE_576);

	//�w�i�摜�ǂݍ���
	Draw::LoadImage(L"map.jpg", 3, TEX_SIZE_1920);

	Draw::LoadImage(L"Brock3.jpg", 2, TEX_SIZE_768);

	Draw::LoadImage(L"kusa.png", 1, TEX_SIZE_32);

	//��l���I�u�W�F�N�g�쐬
	C0bjHero* obj = new C0bjHero();   //��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, COBJ_HERO, 10);//�������l���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//�w�i�I�u�W�F�N�g�쐬
	C0bjBackground * back = new C0bjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 8);
	
	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	////�^�C���I�u�W�F�N�g�쐬
	//C0bjTime* objt = new C0bjTime();
	//Objs::InsertObj(objt, OBJ_TIME, 11);
}


//���s�����\�b�h
void CSceneMain::Scene()
{

}
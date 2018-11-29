//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;


//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"
#include"ObjArrow.h"


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
	//Font�쐬
	Font::SetStrTex(L"0123456789���b");

	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p; //�X�e�[�W���|�C���^�[
	int size;              //�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"map2-1.csv", &size);//�O���f�[�^�ǂݍ���

	int map[19][100];
	int count = 1;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;

			count += 2;
		}
	}

	//Font�쐬
	Font::SetStrTex(L"0123456789���b");
	
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^�i576x384�s�N�Z���j
	Draw::LoadImage(L"1133010303.png", 0, TEX_SIZE_576);

	//�w�i�摜�ǂݍ���
	Draw::LoadImage(L"map2haikei.png", 3, TEX_SIZE_1920);

	//�u���b�N�摜�ǂݍ���
	Draw::LoadImage(L"brock5.png", 2, TEX_SIZE_768);

	//�j㩓ǂݍ���
	Draw::LoadImage(L"blockobj2.png", 4, TEX_SIZE_768);

	//��ǂݍ���
	Draw::LoadImage(L"��2.png", 5, TEX_SIZE_768);

	//�S�[��
	Draw::LoadImage(L"efe.png", 5, TEX_SIZE_768);

	//��l���I�u�W�F�N�g�쐬
	C0bjHero* obj = new C0bjHero();   //��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, COBJ_HERO, 10);//�������l���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//�w�i�I�u�W�F�N�g�쐬
	C0bjBackground * back = new C0bjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 8);
	
	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//�^�C���I�u�W�F�N�g�쐬
	C0bjTime* objt = new C0bjTime();
	Objs::InsertObj(objt, OBJ_TIME, 12);

	//���y�ǂݍ���
	Audio::LoadAudio(0, L"moristage.wav", BACK_MUSIC);
	Audio::LoadAudio(1, L"choice.wav", EFFECT);

	//�{�����[����1.5���₷
	float v = Audio::VolumeMaster(0);

	//���y�X�^�[�g
	Audio::Start(0);
	////�e�X�g�p��̃I�u�W�F�N�g�쐬
	//CObjArrow* obja = new CObjArrow();
	//Objs::InsertObj(obja, OBJ_ARROW, 5);

	//�|��I�u�W�F�N�g�쐬
	//CObjArrow* objar = new CObjArrow();
	//Objs::InsertObj(objar, OBJ_ARROW, 12);

}


//���s�����\�b�h
void CSceneMain::Scene()
{

}
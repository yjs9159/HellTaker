#include "yaChapter1.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaTexture.h"
#include "yaResources.h"
#include "yaBackGround.h"
#include "yaSpriteRenderer.h"
#include "yaTransform.h"
#include "yaObject.h"
#include "yaPlayer.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaMonster.h"
#include "yaNpc.h"
#include "yaRock.h"
#include "yaSceneChange.h"
#include "yaFire.h"
#include "yaSound.h"
#include "yaUi.h"

//extern HWND g_hWnd;

namespace ya
{

	int Chapter1::MapInfo1[8][9] =
	{
		// 0 => �ٴ�
		// 1 => wall
		// 2 => player
		// 3 => monster
		// 4 => rock
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 2, 1, 1 },
		{ 1, 1, 0, 0, 3, 0, 0, 1, 1 },
		{ 1, 1, 0, 3, 0, 3, 1, 1, 1 },
		{ 1, 0, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 4, 0, 0, 4, 0, 1, 1 },
		{ 1, 0, 4, 0, 4, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};


	Chapter1::Chapter1()
		: LeftTop(Vector2(313.0f + 72 / 2, 84.0f + 68 / 2))
		, Animation_play(false)
	{
		pointerMap1[8][9] =
		{
			NULL,
		};
	}

	Chapter1::~Chapter1()
	{
	}

	void Chapter1::Initialize()
	{
		// Scene Change ���� �� �ִϸ��̼� ���
		SceneChange* S_C = object::Instantiate<SceneChange>(eLayerType::SceneChange);

		Transform* tr = S_C->GetComponent<Transform>();
		tr->SetPosition(Vector2(640.0f, 360.0f));

		Animator* at = S_C->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Change", L"..\\Resources\\Texture\\levelchange\\bmp", Vector2(0.0f, 0.0f), 0.05f);
		at->PlayAnimation(L"Change", false);
		at->SetScale(Vector2(0.7f, 0.7f));
		
		// ���� �� Ui
		Ui* Ui1 = object::Instantiate<Ui>(eLayerType::UI);

		tr = Ui1->GetComponent<Transform>();
		tr->SetPosition(Vector2(115.0f, 215.0f));


		Texture* T_Ui = Resources::Load<Texture>(L"Ui1"
			, L"..\\Resources\\Texture\\playui\\mainUI002.bmp");

		SpriteRenderer* sr_Ui = Ui1->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));

		// ���� �Ʒ� Ui
		Ui* Ui2 = object::Instantiate<Ui>(eLayerType::UI);

		tr = Ui2->GetComponent<Transform>();
		tr->SetPosition(Vector2(180.0f, 500.0f));


		T_Ui = Resources::Load<Texture>(L"Ui2"
			, L"..\\Resources\\Texture\\playui\\mainUI001.bmp");

		sr_Ui = Ui2->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));

		// ������ �� Ui
		Ui* Ui3 = object::Instantiate<Ui>(eLayerType::UI);

		tr = Ui3->GetComponent<Transform>();
		tr->SetPosition(Vector2(1170.0f, 215.0f));


		T_Ui = Resources::Load<Texture>(L"Ui3"
			, L"..\\Resources\\Texture\\playui\\mainUI003.bmp");

		sr_Ui = Ui3->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// ������ �Ʒ� Ui
		Ui* Ui4 = object::Instantiate<Ui>(eLayerType::UI);

		tr = Ui4->GetComponent<Transform>();
		tr->SetPosition(Vector2(1100.0f, 500.0f));


		T_Ui = Resources::Load<Texture>(L"Ui4"
			, L"..\\Resources\\Texture\\playui\\mainUI000.bmp");

		sr_Ui = Ui4->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));

		// ��� �ؽ���
		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);

		T_Ui = Resources::Load<Texture>(L"Chapter1"
			, L"..\\Resources\\Texture\\chapterbg\\chapterBG0001.bmp");

		sr_Ui = bg->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.7f, 0.7f));
		sr_Ui->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);
		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));

		// Player ����
		Player* player = object::Instantiate<Player>(eLayerType::Player); // �÷��̾� ����
		player->Hp = 34;

		tr = player->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 1)); // ĳ���� ������ġ
		pointerMap1[1][6] = player;

		at = player->AddComponent<Animator>();
		at->CreateAnimationFolder(L"player_rightidle", L"..\\Resources\\Texture\\player\\player_idle\\right_idle", Vector2(0.0f, 10.0f));
		at->CreateAnimationFolder(L"player_leftidle", L"..\\Resources\\Texture\\player\\player_idle\\left_idle", Vector2(0.0f, 10.0f));
		at->CreateAnimationFolder(L"player_rightrun", L"..\\Resources\\Texture\\player\\player_run\\right_run", Vector2(0.0f, 10.0f));
		at->CreateAnimationFolder(L"player_leftrun", L"..\\Resources\\Texture\\player\\player_run\\left_run", Vector2(0.0f, 10.0f));
		//at->CreateAnimationFolder(L"player_rightattack", L"..\\Resources\\Texture\\player\\player_attack\\right_attack", Vector2(0.0f, -10.0f));
		//at->CreateAnimationFolder(L"player_leftattack", L"..\\Resources\\Texture\\player\\player_attack\\left_attack", Vector2(0.0f, -10.0f));
		at->CreateAnimationFolder(L"player_rightsuccess", L"..\\Resources\\Texture\\player\\player_success\\right_success", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"player_rightidle", true);
		at->SetScale(Vector2(0.8f, 0.8f));
		at->SetAffectedCamera(true);

		//Collider* col = player->AddComponent<Collider>();
		//col->SetSize(Vector2(100.0f, 110.0f));
		//col->SetOffset(Vector2(0.0f, 0.0f));


		// Monster1 ���� �� �̹��� �ε�
		Monster* monster1 = object::Instantiate<Monster>(eLayerType::Monster); // ����1 ����

		tr = monster1->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 2)); // ����1 ������ġ
		pointerMap1[2][4] = monster1;

		at = monster1->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"Monster_RightIdle", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		//col = monster1->AddComponent<Collider>();
		//col->SetSize(Vector2(80.0f, 80.0f));

		// ����2 ���� �� �̹��� �ε�
		Monster* monster2 = object::Instantiate<Monster>(eLayerType::Monster); // ����2 ����

		tr = monster2->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 3)); // ����2 ������ġ
		pointerMap1[3][5] = monster2;

		at = monster2->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"Monster_RightIdle", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		//col = monster2->AddComponent<Collider>();
		//col->SetSize(Vector2(80.0f, 80.0f));

		// ����3 ���� �� �̹��� �ε�
		Monster* monster3 = object::Instantiate<Monster>(eLayerType::Monster);

		tr = monster3->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 3));
		pointerMap1[3][3] = monster3;

		at = monster3->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"Monster_RightIdle", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		//col = monster3->AddComponent<Collider>();
		//col->SetSize(Vector2(80.0f, 80.0f));



		// NPC ���� �� �̹��� �ε�
		Npc* pandemonica = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica ����

		tr = pandemonica->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 6)); // Npc pandemonica ������ġ

		at = pandemonica->AddComponent<Animator>();
		at->CreateAnimationFolder(L"pandemonica", L"..\\Resources\\Texture\\npc\\pandemonica", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"pandemonica", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		//col = pandemonica->AddComponent<Collider>();
		//col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign
		Npc* LoveSign = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica ����

		tr = LoveSign->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6 + 30, LeftTop.y + MOVE_TILE_HEIGHT * 6 - 30)); // Npc pandemonica ������ġ

		T_Ui = Resources::Load<Texture>(L"LoveSign"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		sr_Ui = LoveSign->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));



		// Rock 1 ���� �� �̹��� �ε�
		Rock* rock1 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock1->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 5));
		pointerMap1[5][2] = rock1;


		T_Ui = Resources::Load<Texture>(L"Rock8"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock008.png");
		
		sr_Ui = rock1->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 2 ���� �� �̹��� �ε�
		Rock* rock2 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock2->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 6));
		pointerMap1[6][2] = rock2;

		T_Ui = Resources::Load<Texture>(L"Rock6"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock006.png");

		sr_Ui = rock2->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 3 ���� �� �̹��� �ε�
		Rock* rock3 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock3->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 6));
		pointerMap1[6][4] = rock3;

		T_Ui = Resources::Load<Texture>(L"Rock5"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock005.png");

		sr_Ui = rock3->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 4 ���� �� �̹��� �ε�
		Rock* rock4 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock4->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 5));
		pointerMap1[5][5] = rock4;

		T_Ui = Resources::Load<Texture>(L"Rock1"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock001.png");

		sr_Ui = rock4->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1 base
		Fire* base1_1 = object::Instantiate<Fire>(eLayerType::Fire);

		tr = base1_1->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 0 + 10, LeftTop.y + MOVE_TILE_HEIGHT * 4 + 10));

		T_Ui = Resources::Load<Texture>(L"NoneBase"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0002.png");

		sr_Ui = base1_1->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Fire 2 base
		Fire* Fire1_2base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire1_2base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1 + 12, LeftTop.y + MOVE_TILE_HEIGHT * 1 + 10));

		T_Ui = Resources::Load<Texture>(L"Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		sr_Ui = Fire1_2base->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Fire 2 
		Fire* Fire1_2 = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire1_2->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1 + 12, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		at = Fire1_2->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Fire", L"..\\Resources\\Texture\\fire\\fire", Vector2(2.0f, -22.0f));
		at->PlayAnimation(L"Fire", true);
		at->SetScale(Vector2(0.4f, 0.5f));


		// Fire 3 base
		Fire* Fire1_3base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire1_3base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 0 + 5));

		T_Ui = Resources::Load<Texture>(L"NoneBase"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0002.png");

		sr_Ui = Fire1_3base->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Fire 4 base
		Fire* Fire1_4base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire1_4base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7 + 2, LeftTop.y + MOVE_TILE_HEIGHT * 4 - 20));

		T_Ui = Resources::Load<Texture>(L"Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		sr_Ui = Fire1_4base->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));

		// Fire 4 
		Fire* Fire1_4 = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire1_4->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		at = Fire1_4->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Fire", L"..\\Resources\\Texture\\fire\\fire", Vector2(4.0f, -52.0f));
		at->PlayAnimation(L"Fire", true);
		at->SetScale(Vector2(0.4f, 0.5f));

		// Hp Ui
		Fire* Ui_Hp = object::Instantiate<Fire>(eLayerType::Effect);

		tr = Ui_Hp->GetComponent<Transform>();
		tr->SetPosition(Vector2(180.0f, 500.0f));
	}

	void Chapter1::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::H))
		{
			SceneManager::LoadScene(L"HomeScene");
		}
		if (Input::GetKeyDown(eKeyCode::T))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
		if (Input::GetKeyDown(eKeyCode::E))
		{
			SceneManager::LoadScene(L"EndingScene");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter1))
		{
			SceneManager::LoadScene(L"Chapter1");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter2))
		{
			Sound* Sound_SC2 = Resources::Load<Sound>(L"SceneChange2", L"..\\Resources\\Sound\\screen_changer_part1_01.wav");
			Sound_SC2->Play(false);

			SceneManager::LoadScene(L"Chapter2");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter3))
		{
			SceneManager::LoadScene(L"Chapter3");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter4))
		{
			SceneManager::LoadScene(L"Chapter4");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter5))
		{
			SceneManager::LoadScene(L"Chapter5");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter6))
		{
			SceneManager::LoadScene(L"Chapter6");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter7))
		{
			SceneManager::LoadScene(L"Chapter7");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter8))
		{
			SceneManager::LoadScene(L"Chapter8");
		}
	}

	void Chapter1::Render(HDC hdc)
	{
		Scene::Render(hdc);

		//int maxRow = 720 / (TILE_HEIGHT * 3) + 1;
		//for (size_t y = 0; y < maxRow; y++)
		//{
		//	MoveToEx(hdc, 0, TILE_HEIGHT * y * 4 + 16, NULL);      //      ����(��) ����
		//	LineTo(hdc, 1280, TILE_HEIGHT * y * 4 + 16);        //          ����(��) ��
		//}

		//int maxColumn = 1280 / (TILE_WIDTH * 3) + 1;
		//for (size_t x = 0; x < maxColumn; x++)
		//{
		//	MoveToEx(hdc, TILE_WIDTH * x * 4 + 25, 0, NULL);      //      ����(��) ����
		//	LineTo(hdc, TILE_WIDTH * x * 4 + 25, 720);        //          ����(��) ��
		//}
	}
}

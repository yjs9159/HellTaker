#include "yaChapter2.h"
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

namespace ya
{
	int Chapter2::MapInfo2[8][9] =
	{
		// 0 => �ٴ�
		// 1 => wall
		// 2 => player
		// 3 => monster
		// 4 => rock
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 1, 1, 1 },
		{ 1, 1, 3, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 1, 1, 4, 4, 4, 1 },
		{ 1, 0, 0, 1, 1, 0, 0, 0, 1 },
		{ 1, 2, 0, 1, 1, 0, 3, 0, 1 },
		{ 1, 1, 1, 1, 1, 0, 0, 3, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};


	Chapter2::Chapter2()
		: LeftTop(Vector2(318.0f + 72 / 2, 86.0f + 68 / 2))
		, Animation_play(false)
	{
		pointerMap2[8][9] =
		{
			NULL,
		};
	}

	Chapter2::~Chapter2()
	{
	}

	void Chapter2::Initialize()
	{
		SceneChange* S_C = object::Instantiate<SceneChange>(eLayerType::SceneChange); // ����3 ����

		Transform* tr = S_C->GetComponent<Transform>();
		tr->SetPosition(Vector2(640.0f, 360.0f)); // ����3 ������ġ

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

		// ��� �̹��� ����
		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		
		T_Ui = Resources::Load<Texture>(L"Chapter2"
			, L"..\\Resources\\Texture\\chapterbg\\chapterBG0002.bmp");

		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));
		sr_Ui = bg->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.7f, 0.7f));
		sr_Ui->SetAffectCamera(false);


		// player ����
		Player* player = object::Instantiate<Player>(eLayerType::Player); // �÷��̾� ����
		
		tr = player->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1, LeftTop.y + MOVE_TILE_HEIGHT * 5)); // ĳ���� ������ġ
		pointerMap2[5][1] = player;
		
		
		at = player->AddComponent<Animator>();
		at->CreateAnimationFolder(L"player_rightidle", L"..\\Resources\\Texture\\player\\player_idle\\right_idle", Vector2(0.0f, 10.0f));
		at->CreateAnimationFolder(L"player_leftidle", L"..\\Resources\\Texture\\player\\player_idle\\left_idle", Vector2(0.0f, 10.0f));
		at->CreateAnimationFolder(L"player_rightrun", L"..\\Resources\\Texture\\player\\player_run\\right_run", Vector2(0.0f, 10.0f));
		at->CreateAnimationFolder(L"player_leftrun", L"..\\Resources\\Texture\\player\\player_run\\left_run", Vector2(0.0f, 10.0f));
		at->CreateAnimationFolder(L"player_rightattack", L"..\\Resources\\Texture\\player\\player_attack\\right_attack", Vector2(0.0f, -10.0f));
		at->CreateAnimationFolder(L"player_leftattack", L"..\\Resources\\Texture\\player\\player_attack\\left_attack", Vector2(0.0f, -10.0f));
		at->CreateAnimationFolder(L"player_rightsuccess", L"..\\Resources\\Texture\\player\\player_success\\right_success", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"player_rightidle", true);
		at->SetScale(Vector2(0.8f, 0.8f));
		at->SetAffectedCamera(true);

		Collider* col = player->AddComponent<Collider>();
		col->SetSize(Vector2(100.0f, 110.0f));
		col->SetOffset(Vector2(0.0f, 0.0f));


		// monster1 ����
		Monster* monster1 = object::Instantiate<Monster>(eLayerType::Monster); // ����1 ����

		tr = monster1->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 2)); // ����1 ������ġ
		pointerMap2[2][2] = monster1;

		at = monster1->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"Monster_RightIdle", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		col = monster1->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// monster2 ����
		Monster* monster2 = object::Instantiate<Monster>(eLayerType::Monster); // ����2 ����

		tr = monster2->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 5)); // ����2 ������ġ
		pointerMap2[5][6] = monster2;

		at = monster2->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"Monster_RightIdle", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		col = monster2->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// monster3 ����
		Monster* monster3 = object::Instantiate<Monster>(eLayerType::Monster); // ����3 ����

		tr = monster3->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 6)); // ����3 ������ġ
		pointerMap2[6][7] = monster3;

		at = monster3->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"Monster_RightIdle", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		col = monster3->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));

		// Npc ����
		Npc* modeus = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica ����

		tr = modeus->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 6)); // Npc pandemonica ������ġ

		at = modeus->AddComponent<Animator>();
		at->CreateAnimationFolder(L"modeus", L"..\\Resources\\Texture\\npc\\modeus", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"modeus", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		col = modeus->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign
		Npc* LoveSign = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica ����

		tr = LoveSign->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4 + 40, LeftTop.y + MOVE_TILE_HEIGHT * 6 - 30)); // Npc pandemonica ������ġ

		T_Ui = Resources::Load<Texture>(L"LoveSign"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		sr_Ui = LoveSign->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 1 ���� �� �̹��� �ε�
		Rock* rock1 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock1->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 3));
		pointerMap2[3][5] = rock1;

		T_Ui = Resources::Load<Texture>(L"Rock7"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock007.png");

		sr_Ui = rock1->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));

		// Rock 2 ���� �� �̹��� �ε�
		Rock* rock2 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock2->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 3));
		pointerMap2[3][6] = rock2;

		T_Ui = Resources::Load<Texture>(L"Rock5"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock005.png");

		sr_Ui = rock2->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 3 ���� �� �̹��� �ε�
		Rock* rock3 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock3->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 3));
		pointerMap2[3][7] = rock3;

		T_Ui = Resources::Load<Texture>(L"Rock3"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock003.png");

		sr_Ui = rock3->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1 base
		Fire* Fire2_1base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire2_1base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1, LeftTop.y + MOVE_TILE_HEIGHT * 0 + 8));

		T_Ui = Resources::Load<Texture>(L"Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		sr_Ui = Fire2_1base->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1 
		Fire* Fire2_1 = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire2_1->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1, LeftTop.y + MOVE_TILE_HEIGHT * 0));

		at = Fire2_1->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Fire", L"..\\Resources\\Texture\\fire\\fire", Vector2(2.0f, -25.0f));
		at->PlayAnimation(L"Fire", true);
		at->SetScale(Vector2(0.4f, 0.5f));


		// Fire 2 base
		Fire* Fire2_2base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire2_2base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6 - 3, LeftTop.y + MOVE_TILE_HEIGHT * 0 - 32));

		T_Ui = Resources::Load<Texture>(L"NoneBase"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0002.png");

		sr_Ui = Fire2_2base->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Fire 3 base
		Fire* Fire2_3base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire2_3base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8 - 3, LeftTop.y + MOVE_TILE_HEIGHT * 4 - 23));

		T_Ui = Resources::Load<Texture>(L"Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		sr_Ui = Fire2_3base->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));



		// Fire 2
		Fire* Fire2_2 = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire2_2->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		at = Fire2_2->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Fire", L"..\\Resources\\Texture\\fire\\fire", Vector2(0.0f, 10.0f));
		at->PlayAnimation(L"Fire", true);
		at->SetScale(Vector2(0.4f, 0.5f));
	}

	void Chapter2::Update()
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
			SceneManager::LoadScene(L"Chapter2");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter3))
		{
			Sound* Sound_SC3 = Resources::Load<Sound>(L"SceneChange3", L"..\\Resources\\Sound\\screen_changer_part1_01.wav");
			Sound_SC3->Play(false);

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

	void Chapter2::Render(HDC hdc)
	{
		Scene::Render(hdc);

		int maxRow = 720 / (TILE_HEIGHT * 3) + 1;
		for (size_t y = 0; y < maxRow; y++)
		{
			MoveToEx(hdc, 0, TILE_HEIGHT * y * 4 + 18, NULL);      //      ����(��) ����
			LineTo(hdc, 1280, TILE_HEIGHT * y * 4 + 18);        //          ����(��) ��
		}

		int maxColumn = 1280 / (TILE_WIDTH * 3) + 1;
		for (size_t x = 0; x < maxColumn; x++)
		{
			MoveToEx(hdc, TILE_WIDTH * x * 4 + 30, 0, NULL);      //      ����(��) ����
			LineTo(hdc, TILE_WIDTH * x * 4 + 30, 720);        //          ����(��) ��
		}


	
	
	}
}

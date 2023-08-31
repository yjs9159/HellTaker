#include "yaChapter5.h"
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
#include "yaMonster.h"
#include "yaNpc.h"
#include "yaRock.h"
#include "yaKey.h"
#include "yaLockBox.h"
#include "yaSceneChange.h"
#include "yaFire.h"
#include "yaSound.h"
#include "yaUi.h"

namespace ya
{
	int Chapter5::MapInfo5[9][8] =
	{
		// 0 => 바닥
		// 1 => wall
		// 2 => player
		// 3 => monster
		// 4 => rock
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 0, 1, 1 },
		{ 1, 1, 1, 0, 0, 4, 0, 1 },
		{ 1, 2, 1, 0, 0, 4, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 3, 1, 4, 4, 4, 4, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 0, 1 }
	};

	Chapter5::Chapter5()
		: LeftTop(Vector2(355.0f + 72 / 2, 58.0f + 68 / 2))
	{
		pointerMap5[9][8] =
		{
			NULL,
		};
	}

	Chapter5::~Chapter5()
	{
	}

	void Chapter5::Initialize()
	{
		// Scene Change 생성 및 애니메이션 재생
		SceneChange* S_C = object::Instantiate<SceneChange>(eLayerType::SceneChange);

		Transform* tr = S_C->GetComponent<Transform>();
		tr->SetPosition(Vector2(640.0f, 360.0f));

		Animator* at = S_C->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Change", L"..\\Resources\\Texture\\levelchange\\bmp", Vector2(0.0f, 0.0f), 0.05f);
		at->PlayAnimation(L"Change", false);
		at->SetScale(Vector2(0.7f, 0.7f));



		// 왼쪽 위 Ui
		Ui* Ui1 = object::Instantiate<Ui>(eLayerType::UI);

		tr = Ui1->GetComponent<Transform>();
		tr->SetPosition(Vector2(115.0f, 215.0f));


		Texture* T_Ui = Resources::Load<Texture>(L"Ui1"
			, L"..\\Resources\\Texture\\playui\\mainUI002.bmp");

		SpriteRenderer* sr_Ui = Ui1->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));

		// 왼쪽 아래 Ui
		Ui* Ui2 = object::Instantiate<Ui>(eLayerType::UI);

		tr = Ui2->GetComponent<Transform>();
		tr->SetPosition(Vector2(180.0f, 500.0f));


		T_Ui = Resources::Load<Texture>(L"Ui2"
			, L"..\\Resources\\Texture\\playui\\mainUI001.bmp");

		sr_Ui = Ui2->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));

		// 오른쪽 위 Ui
		Ui* Ui3 = object::Instantiate<Ui>(eLayerType::UI);

		tr = Ui3->GetComponent<Transform>();
		tr->SetPosition(Vector2(1170.0f, 215.0f));


		T_Ui = Resources::Load<Texture>(L"Ui3"
			, L"..\\Resources\\Texture\\playui\\mainUI003.bmp");

		sr_Ui = Ui3->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// 오른쪽 아래 Ui
		Ui* Ui4 = object::Instantiate<Ui>(eLayerType::UI);

		tr = Ui4->GetComponent<Transform>();
		tr->SetPosition(Vector2(1100.0f, 500.0f));


		T_Ui = Resources::Load<Texture>(L"Ui4"
			, L"..\\Resources\\Texture\\playui\\mainUI000.bmp");

		sr_Ui = Ui4->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// 배경 이미지 생성
		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));

		T_Ui = Resources::Load<Texture>(L"Chapter5"
			, L"..\\Resources\\Texture\\chapterbg\\chapterBG0005.bmp");
		
		sr_Ui = bg->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.7f, 0.7f));
		sr_Ui->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);


		// player 생성
		Player* player = object::Instantiate<Player>(eLayerType::Player); // 플레이어 생성

		tr = player->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1, LeftTop.y + MOVE_TILE_HEIGHT * 3)); // 플레이어 시작위치
		pointerMap5[3][1] = player;

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

		//Collider* col = player->AddComponent<Collider>();
		//col->SetSize(Vector2(85.0f, 90.0f));
		//col->SetOffset(Vector2(0.0f, -10.0f));


		// monster1 생성
		Monster* monster1 = object::Instantiate<Monster>(eLayerType::Monster); // 몬스터1 생성

		tr = monster1->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1, LeftTop.y + MOVE_TILE_HEIGHT * 5)); // 몬스터1 시작위치
		pointerMap5[5][1] = monster1;

		at = monster1->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"Monster_RightIdle", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		//col = monster1->AddComponent<Collider>();
		//col->SetSize(Vector2(80.0f, 80.0f));

		// Npc pandemonica 생성
		Npc* zdrada = object::Instantiate<Npc>(eLayerType::Npc);

		tr = zdrada->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 1)); // Npc pandemonica 시작위치

		at = zdrada->AddComponent<Animator>();
		at->CreateAnimationFolder(L"zdrada", L"..\\Resources\\Texture\\npc\\zdrada", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"zdrada", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		//col = zdrada->AddComponent<Collider>();
		//col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign
		Npc* LoveSign = object::Instantiate<Npc>(eLayerType::Npc);

		tr = LoveSign->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4 + 40, LeftTop.y + MOVE_TILE_HEIGHT * 1 - 30));

		T_Ui = Resources::Load<Texture>(L"LoveSign"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		sr_Ui = LoveSign->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 1 생성 및 이미지 로드
		Rock* rock1 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock1->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 5));
		pointerMap5[5][3] = rock1;

		T_Ui = Resources::Load<Texture>(L"Rock3"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock003.png");

		sr_Ui = rock1->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 2 생성 및 이미지 로드
		Rock* rock2 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock2->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 5));
		pointerMap5[5][4] = rock2;

		T_Ui = Resources::Load<Texture>(L"Rock5"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock005.png");

		sr_Ui = rock2->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 3 생성 및 이미지 로드
		Rock* rock3 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock3->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 5));
		pointerMap5[5][5] = rock3;

		T_Ui = Resources::Load<Texture>(L"Rock1"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock001.png");

		sr_Ui = rock3->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 4 생성 및 이미지 로드
		Rock* rock4 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock4->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 5));
		pointerMap5[5][6] = rock4;

		T_Ui = Resources::Load<Texture>(L"Rock8"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock008.png");

		sr_Ui = rock4->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 5 생성 및 이미지 로드
		Rock* rock5 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock5->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 3));
		pointerMap5[3][6] = rock5;

		T_Ui = Resources::Load<Texture>(L"Rock7"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock007.png");

		sr_Ui = rock5->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 6 생성 및 이미지 로드
		Rock* rock6 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock6->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 2));
		pointerMap5[2][5] = rock6;

		T_Ui = Resources::Load<Texture>(L"Rock11"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock011.png");

		sr_Ui = rock6->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));

		// Key 생성 및 이미지 로드
		Key* myKey = object::Instantiate<Key>(eLayerType::myKey);

		tr = myKey->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 7));

		at = myKey->AddComponent<Animator>();
		at->CreateAnimationFolder(L"myKey", L"..\\Resources\\Texture\\obstacle\\Key", Vector2(10.0f, 10.0f));
		at->PlayAnimation(L"myKey", true);
		at->SetScale(Vector2(0.8f, 0.8f));


		// LockBox 생성 및 이미지 로드
		LockBox* lockbox = object::Instantiate<LockBox>(eLayerType::LockBox);

		tr = lockbox->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 2));

		T_Ui = Resources::Load<Texture>(L"Box"
			, L"..\\Resources\\Texture\\obstacle\\lockbox\\lockbox001.png");

		sr_Ui = lockbox->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1 base
		Fire* Fire5_1base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire5_1base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 0 + 4, LeftTop.y + MOVE_TILE_HEIGHT * 4 + 3));

		T_Ui = Resources::Load<Texture>(L"Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		sr_Ui = Fire5_1base->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1
		Fire* Fire5_1 = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire5_1->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 0, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		at = Fire5_1->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Fire", L"..\\Resources\\Texture\\fire\\fire", Vector2(5.0f, -30.0f));
		at->PlayAnimation(L"Fire", true);
		at->SetScale(Vector2(0.4f, 0.5f));


		// Fire 2 base
		Fire* Fire5_2base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire5_2base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 4 - 30));

		T_Ui = Resources::Load<Texture>(L"Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		sr_Ui = Fire5_2base->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Fire 2
		Fire* Fire5_2 = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire5_2->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		at = Fire5_2->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Fire", L"..\\Resources\\Texture\\fire\\fire", Vector2(0.0f, 0.0f));
		at->PlayAnimation(L"Fire", true);
		at->SetScale(Vector2(0.4f, 0.5f));


		// Fire 3 base
		Fire* Fire5_3base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire5_3base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7 - 6, LeftTop.y + MOVE_TILE_HEIGHT * 5 + 5));

		T_Ui = Resources::Load<Texture>(L"NoneBase"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0002.png");

		sr_Ui = Fire5_3base->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));
	}

	void ya::Chapter5::Update()
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
			Sound* Sound_SC6 = Resources::Load<Sound>(L"SceneChange6", L"..\\Resources\\Sound\\screen_changer_part1_01.wav");
			Sound_SC6->Play(false);

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

	void ya::Chapter5::Render(HDC hdc)
	{
		Scene::Render(hdc);

		int maxRow = 720 / (TILE_HEIGHT * 3) + 1;
		for (size_t y = 0; y < maxRow; y++)
		{
			MoveToEx(hdc, 0, TILE_HEIGHT * y * 4 - 10, NULL);      //      라인(선) 시작
			LineTo(hdc, 1280, TILE_HEIGHT * y * 4 - 10);        //          라인(선) 끝
		}

		int maxColumn = 1280 / (TILE_WIDTH * 3) + 1;
		for (size_t x = 0; x < maxColumn; x++)
		{
			MoveToEx(hdc, TILE_WIDTH * x * 4 - 5, 0, NULL);      //      라인(선) 시작
			LineTo(hdc, TILE_WIDTH * x * 4 - 5, 720);        //          라인(선) 끝
		}
	}
}

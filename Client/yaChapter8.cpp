#include "yaChapter8.h"
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
#include "yaRock.h"
#include "yaKey.h"
#include "yaLockBox.h"
#include "yaSceneChange.h"
#include "yaFire.h"
#include "yaUi.h"

namespace ya
{
	int Chapter8::MapInfo8[8][11] =
	{
		// 0 => 바닥
		// 1 => wall
		// 2 => player
		// 3 => monster
		// 4 => rock
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 4, 0, 4, 1, 1, 1, 1 },
		{ 1, 1, 4, 1, 4, 0, 0, 1, 0, 1, 1 },
		{ 1, 4, 0, 0, 4, 4, 4, 0, 0, 0, 1 },
		{ 1, 0, 4, 4, 4, 0, 0, 4, 4, 0, 1 },
		{ 1, 1, 2, 0, 4, 0, 0, 4, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};

	ya::Chapter8::Chapter8()
		: LeftTop(Vector2(244.0f + 72 / 2, 161.0f + 68 / 2))
	{
		pointerMap8[8][11] =
		{
			NULL,
		};
	}

	ya::Chapter8::~Chapter8()
	{
	}

	void ya::Chapter8::Initialize()
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

		SpriteRenderer* sr = Ui1->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));

		// 왼쪽 아래 Ui
		Ui* Ui2 = object::Instantiate<Ui>(eLayerType::UI);

		tr = Ui2->GetComponent<Transform>();
		tr->SetPosition(Vector2(180.0f, 500.0f));


		T_Ui = Resources::Load<Texture>(L"Ui2"
			, L"..\\Resources\\Texture\\playui\\mainUI001.bmp");

		sr = Ui2->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));

		// 오른쪽 위 Ui
		Ui* Ui3 = object::Instantiate<Ui>(eLayerType::UI);

		tr = Ui3->GetComponent<Transform>();
		tr->SetPosition(Vector2(1170.0f, 215.0f));


		T_Ui = Resources::Load<Texture>(L"Ui3"
			, L"..\\Resources\\Texture\\playui\\mainUI003.bmp");

		sr = Ui3->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// 오른쪽 아래 Ui
		Ui* Ui4 = object::Instantiate<Ui>(eLayerType::UI);

		tr = Ui4->GetComponent<Transform>();
		tr->SetPosition(Vector2(1100.0f, 500.0f));


		T_Ui = Resources::Load<Texture>(L"Ui4"
			, L"..\\Resources\\Texture\\playui\\mainUI000.bmp");

		sr = Ui4->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// 배경 이미지 적용
		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));

		T_Ui = Resources::Load<Texture>(L"Chapter8"
			, L"..\\Resources\\Texture\\chapterbg\\chapterBG0008.bmp");


		sr = bg->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.7f, 0.7f));
		sr->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);


		Player* player = object::Instantiate<Player>(eLayerType::Player); // 플레이어 생성
		
		tr = player->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 6)); // 플레이어 시작위치
		pointerMap8[6][2] = player;

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


		// Rock 1 생성 및 이미지 로드
		Rock* rock1 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock1->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1, LeftTop.y + MOVE_TILE_HEIGHT * 4));
		pointerMap8[4][1] = rock1;

		T_Ui = Resources::Load<Texture>(L"Rock4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock004.png");

		sr = rock1->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 2 생성 및 이미지 로드
		Rock* rock2 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock2->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 3));
		pointerMap8[3][2] = rock2;
		
		T_Ui = Resources::Load<Texture>(L"Rock5"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock005.png");

		sr = rock2->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 3 생성 및 이미지 로드
		Rock* rock3 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock3->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 5));
		pointerMap8[5][2] = rock3;

		T_Ui = Resources::Load<Texture>(L"Rock6"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock006.png");

		sr = rock3->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 4 생성 및 이미지 로드
		Rock* rock4 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock4->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 5));
		pointerMap8[5][3] = rock4;

		T_Ui = Resources::Load<Texture>(L"Rock8"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock008.png");

		sr = rock4->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 5 생성 및 이미지 로드
		Rock* rock5 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock5->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 2));
		pointerMap8[2][4] = rock5;

		T_Ui = Resources::Load<Texture>(L"Rock6"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock006.png");

		sr = rock5->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 6 생성 및 이미지 로드
		Rock* rock6 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock6->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 3));
		pointerMap8[3][4] = rock6;

		T_Ui = Resources::Load<Texture>(L"Rock1"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock001.png");

		sr = rock6->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 7 생성 및 이미지 로드
		Rock* rock7 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock7->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 4));
		pointerMap8[4][4] = rock7;

		T_Ui = Resources::Load<Texture>(L"Rock3"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock003.png");

		sr = rock7->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 8 생성 및 이미지 로드
		Rock* rock8 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock8->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 5));
		pointerMap8[5][4] = rock8;

		T_Ui = Resources::Load<Texture>(L"Rock7"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock007.png");

		sr = rock8->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 9 생성 및 이미지 로드
		Rock* rock9 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock9->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 6));
		pointerMap8[6][4] = rock9;

		T_Ui = Resources::Load<Texture>(L"Rock5"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock005.png");

		sr = rock9->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 10 생성 및 이미지 로드
		Rock* rock10 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock10->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 4));
		pointerMap8[4][5] = rock10;

		T_Ui = Resources::Load<Texture>(L"Rock2"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock002.png");

		sr = rock10->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 11 생성 및 이미지 로드
		Rock* rock11 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock11->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 2));
		pointerMap8[2][6] = rock11;

		T_Ui = Resources::Load<Texture>(L"Rock7"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock007.png");

		sr = rock11->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 12 생성 및 이미지 로드
		Rock* rock12 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock12->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 4));
		pointerMap8[4][6] = rock12;

		T_Ui = Resources::Load<Texture>(L"Rock8"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock008.png");

		sr = rock12->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 13 생성 및 이미지 로드
		Rock* rock13 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock13->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 5));
		pointerMap8[5][7] = rock13;

		T_Ui = Resources::Load<Texture>(L"Rock1"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock001.png");

		sr = rock13->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 14 생성 및 이미지 로드
		Rock* rock14 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock14->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 6));
		pointerMap8[6][7] = rock14;

		T_Ui = Resources::Load<Texture>(L"Rock4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock004.png");

		sr = rock14->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 15 생성 및 이미지 로드
		Rock* rock15 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock15->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8, LeftTop.y + MOVE_TILE_HEIGHT * 5));
		pointerMap8[5][8] = rock15;

		T_Ui = Resources::Load<Texture>(L"Rock3"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock003.png");

		sr = rock15->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Key 생성 및 이미지 로드
		Key* myKey = object::Instantiate<Key>(eLayerType::myKey);

		tr = myKey->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 9, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		at = myKey->AddComponent<Animator>();
		at->CreateAnimationFolder(L"myKey", L"..\\Resources\\Texture\\obstacle\\Key", Vector2(10.0f, 0.0f));
		at->PlayAnimation(L"myKey", true);
		at->SetScale(Vector2(0.8f, 0.8f));


		// LockBox 생성 및 이미지 로드
		LockBox* lockbox = object::Instantiate<LockBox>(eLayerType::LockBox);

		tr = lockbox->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 2));

		T_Ui = Resources::Load<Texture>(L"Box"
			, L"..\\Resources\\Texture\\obstacle\\lockbox\\lockbox001.png");

		sr = lockbox->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1 base
		Fire* Fire8_1base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire8_1base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2 + 9, LeftTop.y + MOVE_TILE_HEIGHT * 0 - 30));

		T_Ui = Resources::Load<Texture>(L"Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		sr = Fire8_1base->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1
		Fire* Fire8_1 = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire8_1->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * -1));

		at = Fire8_1->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Fire", L"..\\Resources\\Texture\\fire\\fire", Vector2(10.0f, 0.0f));
		at->PlayAnimation(L"Fire", true);
		at->SetScale(Vector2(0.4f, 0.5f));


		// Fire 2 base
		Fire* Fire8_2base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire8_2base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3 + 4, LeftTop.y + MOVE_TILE_HEIGHT * 2 - 31));

		T_Ui = Resources::Load<Texture>(L"Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		sr = Fire8_2base->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 2
		Fire* Fire8_2 = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire8_2->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		at = Fire8_2->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Fire", L"..\\Resources\\Texture\\fire\\fire", Vector2(5.0f, 0.0f));
		at->PlayAnimation(L"Fire", true);
		at->SetScale(Vector2(0.4f, 0.5f));


		// Fire 3 base
		Fire* Fire8_3base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire8_3base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7 - 3, LeftTop.y + MOVE_TILE_HEIGHT * 2 - 31));

		T_Ui = Resources::Load<Texture>(L"Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		sr = Fire8_3base->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 3
		Fire* Fire8_3 = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire8_3->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		at = Fire8_3->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Fire", L"..\\Resources\\Texture\\fire\\fire", Vector2(0.0f, 0.0f));
		at->PlayAnimation(L"Fire", true);
		at->SetScale(Vector2(0.4f, 0.5f));


		// Fire 4 base
		Fire* Fire8_4base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire8_4base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8 - 8, LeftTop.y + MOVE_TILE_HEIGHT * 0 - 31));

		T_Ui = Resources::Load<Texture>(L"Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		sr = Fire8_4base->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 4
		Fire* Fire8_4 = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire8_4->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8, LeftTop.y + MOVE_TILE_HEIGHT * -1));

		at = Fire8_4->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Fire", L"..\\Resources\\Texture\\fire\\fire", Vector2(-5.0f, 0.0f));
		at->PlayAnimation(L"Fire", true);
		at->SetScale(Vector2(0.4f, 0.5f));
	}

	void ya::Chapter8::Update()
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

	void ya::Chapter8::Render(HDC hdc)
	{
		Scene::Render(hdc);

		//int maxRow = 720 / (TILE_HEIGHT * 3) + 1;
		//for (size_t y = 0; y < maxRow; y++)
		//{
		//	MoveToEx(hdc, 0, TILE_HEIGHT * y * 4 + 25, NULL);      //      라인(선) 시작
		//	LineTo(hdc, 1280, TILE_HEIGHT * y * 4 + 25);        //          라인(선) 끝
		//}

		//int maxColumn = 1280 / (TILE_WIDTH * 3) + 1;
		//for (size_t x = 0; x < maxColumn; x++)
		//{
		//	MoveToEx(hdc, TILE_WIDTH * x * 4 + 28, 0, NULL);      //      라인(선) 시작
		//	LineTo(hdc, TILE_WIDTH * x * 4 + 28, 720);        //          라인(선) 끝
		//}
	}
}

#include "yaChapter3.h"
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
#include "yaKey.h"
#include "yaLockBox.h"
#include "yaSceneChange.h"
#include "yaFire.h"

namespace ya
{
	int Chapter3::MapInfo3[9][10] =
	{
		// 0 => 바닥
		// 1 => wall
		// 2 => player
		// 3 => monster
		// 4 => rock
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 2, 1 },
		{ 1, 1, 1, 0, 1, 0, 1, 0, 0, 1 },
		{ 1, 1, 1, 0, 0, 3, 0, 0, 1, 1 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 3, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};

	ya::Chapter3::Chapter3()
		: LeftTop(Vector2(281.0f + 72 / 2, 43.0f + 68 / 2))
	{
	}

	ya::Chapter3::~Chapter3()
	{
	}

	void ya::Chapter3::Initialize()
	{
		// Scene Change 생성 및 애니메이션 재생
		SceneChange* S_C = object::Instantiate<SceneChange>(eLayerType::SceneChange);

		Transform* tr_SC = S_C->GetComponent<Transform>();
		tr_SC->SetPosition(Vector2(640.0f, 360.0f));

		Animator* at_SC = S_C->AddComponent<Animator>();
		at_SC->CreateAnimationFolder(L"Change", L"..\\Resources\\Texture\\levelchange\\bmp", Vector2(0.0f, 0.0f), 0.05f);
		at_SC->PlayAnimation(L"Change", false);
		at_SC->SetScale(Vector2(0.7f, 0.7f));


		Texture* Chapter3 = Resources::Load<Texture>(L"Chapter3"
			, L"..\\Resources\\Texture\\chapterbg\\chapterBG0003.bmp");


		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(Chapter3);
		bgsr->SetScale(Vector2(0.7f, 0.7f));
		bgsr->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);
		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));

		Player* player = object::Instantiate<Player>(eLayerType::Player); // 플레이어 생성
		Transform* tr = player->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8, LeftTop.y + MOVE_TILE_HEIGHT * 3)); // 플레이어 시작위치

		Animator* at = player->AddComponent<Animator>();
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
		col->SetSize(Vector2(85.0f, 90.0f));
		col->SetOffset(Vector2(0.0f, -10.0f));


		// monster 1 생성 및 이미지 로드
		Monster* monster1 = object::Instantiate<Monster>(eLayerType::Monster);
		Transform* tr_M1 = monster1->GetComponent<Transform>();
		tr_M1->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 5));

		Animator* at_M1 = monster1->AddComponent<Animator>();
		at_M1->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at_M1->PlayAnimation(L"Monster_RightIdle", true);
		at_M1->SetScale(Vector2(0.8f, 0.8f));

		col = monster1->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// monster 2 생성 및 이미지 로드
		Monster* monster2 = object::Instantiate<Monster>(eLayerType::Monster);
		Transform* tr_M2 = monster2->GetComponent<Transform>();
		tr_M2->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 7));

		Animator* at_M2 = monster2->AddComponent<Animator>();
		at_M2->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at_M2->PlayAnimation(L"Monster_RightIdle", true);
		at_M2->SetScale(Vector2(0.8f, 0.8f));

		col = monster2->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc 1 생성 및 이미지 로드
		Npc* cerberus1 = object::Instantiate<Npc>(eLayerType::Npc);

		Transform* Npc_1 = cerberus1->GetComponent<Transform>();
		Npc_1->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		Animator* at_Npc1 = cerberus1->AddComponent<Animator>();
		at_Npc1->CreateAnimationFolder(L"cerberus", L"..\\Resources\\Texture\\npc\\cerberus", Vector2(0.0f, -10.0f));
		at_Npc1->PlayAnimation(L"cerberus", true);
		at_Npc1->SetScale(Vector2(0.8f, 0.8f));

		col = cerberus1->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));
		

		// Npc 2 생성 및 이미지 로드
		Npc* cerberus2 = object::Instantiate<Npc>(eLayerType::Npc);

		Transform* Npc_2 = cerberus2->GetComponent<Transform>();
		Npc_2->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		Animator* at_Npc2 = cerberus2->AddComponent<Animator>();
		at_Npc2->CreateAnimationFolder(L"cerberus", L"..\\Resources\\Texture\\npc\\cerberus", Vector2(0.0f, -10.0f));
		at_Npc2->PlayAnimation(L"cerberus", true);
		at_Npc2->SetScale(Vector2(0.8f, 0.8f));

		col = cerberus2->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc 3 생성 및 이미지 로드
		Npc* cerberus3 = object::Instantiate<Npc>(eLayerType::Npc);

		Transform* Npc_3 = cerberus3->GetComponent<Transform>();
		Npc_3->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		Animator* at_Npc3 = cerberus3->AddComponent<Animator>();
		at_Npc3->CreateAnimationFolder(L"cerberus", L"..\\Resources\\Texture\\npc\\cerberus", Vector2(0.0f, -10.0f));
		at_Npc3->PlayAnimation(L"cerberus", true);
		at_Npc3->SetScale(Vector2(0.8f, 0.8f));

		col = cerberus3->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));

		
		// Key 생성 및 이미지 로드
		Key* myKey = object::Instantiate<Key>(eLayerType::myKey);

		Transform* tr_Key = myKey->GetComponent<Transform>();
		tr_Key->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1, LeftTop.y + MOVE_TILE_HEIGHT * 6));

		Animator* at_Key = myKey->AddComponent<Animator>();
		at_Key->CreateAnimationFolder(L"myKey", L"..\\Resources\\Texture\\obstacle\\Key", Vector2(10.0f, 0.0f));
		at_Key->PlayAnimation(L"myKey", true);
		at_Key->SetScale(Vector2(0.8f, 0.8f));


		// LockBox 생성 및 이미지 로드
		LockBox* lockbox = object::Instantiate<LockBox>(eLayerType::LockBox);

		Transform* tr_Box = lockbox->GetComponent<Transform>();
		tr_Box->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 2));

		Texture* Box = Resources::Load<Texture>(L"Box"
			, L"..\\Resources\\Texture\\obstacle\\lockbox\\lockbox001.png");

		SpriteRenderer* sr_Box = lockbox->AddComponent<SpriteRenderer>();
		sr_Box->SetImage(Box);
		sr_Box->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1 base
		Fire* Fire3_1base = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr3_1Firebase = Fire3_1base->GetComponent<Transform>();
		tr3_1Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8 - 4, LeftTop.y + MOVE_TILE_HEIGHT * 1 + 11));

		Texture* Fire3_1Base = Resources::Load<Texture>(L"Fire3_1Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		SpriteRenderer* Fire3_1Sr = Fire3_1base->AddComponent<SpriteRenderer>();
		Fire3_1Sr->SetImage(Fire3_1Base);
		Fire3_1Sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 2
		Fire* Fire3_1 = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr3_1Fire = Fire3_1->GetComponent<Transform>();
		tr3_1Fire->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		Animator* at3_1Fire = Fire3_1->AddComponent<Animator>();
		at3_1Fire->CreateAnimationFolder(L"Fire3_1", L"..\\Resources\\Texture\\fire\\fire", Vector2(-2.0f, -25.0f));
		at3_1Fire->PlayAnimation(L"Fire3_1", true);
		at3_1Fire->SetScale(Vector2(0.4f, 0.5f));


		// Fire 3 base
		Fire* Fire3_2base = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr3_2Firebase = Fire3_2base->GetComponent<Transform>();
		tr3_2Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2 + 1, LeftTop.y + MOVE_TILE_HEIGHT * 5 - 13));

		Texture* Fire3_2Base = Resources::Load<Texture>(L"Fire3_1Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		SpriteRenderer* Fire3_2Sr = Fire3_2base->AddComponent<SpriteRenderer>();
		Fire3_2Sr->SetImage(Fire3_2Base);
		Fire3_2Sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 2
		Fire* Fire3_2 = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr3_2Fire = Fire3_2->GetComponent<Transform>();
		tr3_2Fire->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		Animator* at3_2Fire = Fire3_2->AddComponent<Animator>();
		at3_2Fire->CreateAnimationFolder(L"Fire3_2", L"..\\Resources\\Texture\\fire\\fire", Vector2(2.0f, 20.0f));
		at3_2Fire->PlayAnimation(L"Fire3_2", true);
		at3_2Fire->SetScale(Vector2(0.4f, 0.5f));
	}

	void ya::Chapter3::Update()
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

	void ya::Chapter3::Render(HDC hdc)
	{
		Scene::Render(hdc);

		//int maxRow = 720 / (TILE_HEIGHT * 3) + 1;
		//for (size_t y = 0; y < maxRow; y++)
		//{
		//	MoveToEx(hdc, 0, TILE_HEIGHT * y * 4 - 25, NULL);      //      라인(선) 시작
		//	LineTo(hdc, 1280, TILE_HEIGHT * y * 4 - 25);        //          라인(선) 끝
		//}

		//int maxColumn = 1280 / (TILE_WIDTH * 3) + 1;
		//for (size_t x = 0; x < maxColumn; x++)
		//{
		//	MoveToEx(hdc, TILE_WIDTH * x * 4 - 7, 0, NULL);      //      라인(선) 시작
		//	LineTo(hdc, TILE_WIDTH * x * 4 - 7, 720);        //          라인(선) 끝
		//}
	}
}

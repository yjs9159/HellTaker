#include "yaChapter4.h"
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
#include "yaNpc.h"
#include "yaRock.h"
#include "yaKey.h"
#include "yaLockBox.h"
#include "yaSceneChange.h"
#include "yaFire.h"
#include "yaSound.h"

namespace ya
{
	int Chapter4::MapInfo4[7][11] =
	{
		// 0 => 바닥
		// 1 => wall
		// 2 => player
		// 3 => monster
		// 4 => rock
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 2, 1, 0, 0, 4, 1, 1, 1, 1 },
		{ 1, 1, 0, 4, 0, 4, 0, 0, 0, 1, 1 },
		{ 1, 1, 4, 0, 4, 0, 4, 4, 0, 0, 1 },
		{ 1, 1, 0, 4, 0, 4, 0, 4, 4, 0, 1 },
		{ 1, 1, 1, 0, 4, 0, 4, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};

	Chapter4::Chapter4()
		: LeftTop(Vector2(216.0f + 72 / 2, 115.0f + 68 / 2))
	{
	}

	Chapter4::~Chapter4()
	{
	}

	void Chapter4::Initialize()
	{
		// Scene Change 생성 및 애니메이션 재생
		SceneChange* S_C = object::Instantiate<SceneChange>(eLayerType::SceneChange);

		Transform* tr_SC = S_C->GetComponent<Transform>();
		tr_SC->SetPosition(Vector2(640.0f, 360.0f));

		Animator* at_SC = S_C->AddComponent<Animator>();
		at_SC->CreateAnimationFolder(L"Change", L"..\\Resources\\Texture\\levelchange\\bmp", Vector2(0.0f, 0.0f), 0.05f);
		at_SC->PlayAnimation(L"Change", false);
		at_SC->SetScale(Vector2(0.7f, 0.7f));


		Texture* Chapter4 = Resources::Load<Texture>(L"Chapter4"
			, L"..\\Resources\\Texture\\chapterbg\\chapterBG0004.bmp");


		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(Chapter4);
		bgsr->SetScale(Vector2(0.7f, 0.7f));
		bgsr->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);
		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));


		Player* player = object::Instantiate<Player>(eLayerType::Player); // 플레이어 생성
		Transform* tr = player->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 1)); // 플레이어 시작위치

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


		// Npc pandemonica 생성
		Npc* malina = object::Instantiate<Npc>(eLayerType::Npc);

		Transform* tr_malina = malina->GetComponent<Transform>();
		tr_malina->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 9, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		Animator* at_malina = malina->AddComponent<Animator>();
		at_malina->CreateAnimationFolder(L"malina", L"..\\Resources\\Texture\\npc\\malina", Vector2(0.0f, -10.0f));
		at_malina->PlayAnimation(L"malina", true);
		at_malina->SetScale(Vector2(0.8f, 0.8f));

		col = malina->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign
		Npc* LoveSign = object::Instantiate<Npc>(eLayerType::Npc);

		Transform* tr_LoveSign = LoveSign->GetComponent<Transform>();
		tr_LoveSign->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8 + 40, LeftTop.y + MOVE_TILE_HEIGHT * 3 - 30));

		Texture* T_LoveSign = Resources::Load<Texture>(L"LoveSign"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		SpriteRenderer* sr_LoveSign = LoveSign->AddComponent<SpriteRenderer>();
		sr_LoveSign->SetImage(T_LoveSign);
		sr_LoveSign->SetScale(Vector2(0.75f, 0.75f));


		// Rock 1 생성 및 이미지 로드
		Rock* rock1 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock1 = rock1->GetComponent<Transform>();
		tr_Rock1->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		Texture* Rock1 = Resources::Load<Texture>(L"Rock1_4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock001.png");

		SpriteRenderer* Rock1sr = rock1->AddComponent<SpriteRenderer>();
		Rock1sr->SetImage(Rock1);
		Rock1sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 2 생성 및 이미지 로드
		Rock* rock2 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock2 = rock2->GetComponent<Transform>();
		tr_Rock2->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 2));

		Texture* Rock2 = Resources::Load<Texture>(L"Rock2_4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock003.png");

		SpriteRenderer* Rock2sr = rock2->AddComponent<SpriteRenderer>();
		Rock2sr->SetImage(Rock2);
		Rock2sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 3 생성 및 이미지 로드
		Rock* rock3 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock3 = rock3->GetComponent<Transform>();
		tr_Rock3->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		Texture* Rock3 = Resources::Load<Texture>(L"Rock3_4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock002.png");

		SpriteRenderer* Rock3sr = rock3->AddComponent<SpriteRenderer>();
		Rock3sr->SetImage(Rock3);
		Rock3sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 4 생성 및 이미지 로드
		Rock* rock4 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock4 = rock4->GetComponent<Transform>();
		tr_Rock4->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		Texture* Rock4 = Resources::Load<Texture>(L"Rock4_4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock004.png");

		SpriteRenderer* Rock4sr = rock4->AddComponent<SpriteRenderer>();
		Rock4sr->SetImage(Rock4);
		Rock4sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 5 생성 및 이미지 로드
		Rock* rock5 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock5 = rock5->GetComponent<Transform>();
		tr_Rock5->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 5));

		Texture* Rock5 = Resources::Load<Texture>(L"Rock5_4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock005.png");

		SpriteRenderer* Rock5sr = rock5->AddComponent<SpriteRenderer>();
		Rock5sr->SetImage(Rock5);
		Rock5sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 6 생성 및 이미지 로드
		Rock* rock6 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock6 = rock6->GetComponent<Transform>();
		tr_Rock6->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 2));

		Texture* Rock6 = Resources::Load<Texture>(L"Rock6_4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock007.png");

		SpriteRenderer* Rock6sr = rock6->AddComponent<SpriteRenderer>();
		Rock6sr->SetImage(Rock6);
		Rock6sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 7 생성 및 이미지 로드
		Rock* rock7 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock7 = rock7->GetComponent<Transform>();
		tr_Rock7->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		Texture* Rock7 = Resources::Load<Texture>(L"Rock7_4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock006.png");

		SpriteRenderer* Rock7sr = rock7->AddComponent<SpriteRenderer>();
		Rock7sr->SetImage(Rock7);
		Rock7sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 8 생성 및 이미지 로드
		Rock* rock8 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock8 = rock8->GetComponent<Transform>();
		tr_Rock8->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		Texture* Rock8 = Resources::Load<Texture>(L"Rock8_4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock002.png");

		SpriteRenderer* Rock8sr = rock8->AddComponent<SpriteRenderer>();
		Rock8sr->SetImage(Rock8);
		Rock8sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 9 생성 및 이미지 로드
		Rock* rock9 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock9 = rock9->GetComponent<Transform>();
		tr_Rock9->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		Texture* Rock9 = Resources::Load<Texture>(L"Rock9_4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock008.png");

		SpriteRenderer* Rock9sr = rock9->AddComponent<SpriteRenderer>();
		Rock9sr->SetImage(Rock9);
		Rock9sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 10 생성 및 이미지 로드
		Rock* rock10 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock10 = rock10->GetComponent<Transform>();
		tr_Rock10->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 5));

		Texture* Rock10 = Resources::Load<Texture>(L"Rock10_4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock001.png");

		SpriteRenderer* Rock10sr = rock10->AddComponent<SpriteRenderer>();
		Rock10sr->SetImage(Rock10);
		Rock10sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 11 생성 및 이미지 로드
		Rock* rock11 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock11 = rock11->GetComponent<Transform>();
		tr_Rock11->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		Texture* Rock11 = Resources::Load<Texture>(L"Rock11_4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock003.png");

		SpriteRenderer* Rock11sr = rock11->AddComponent<SpriteRenderer>();
		Rock11sr->SetImage(Rock11);
		Rock11sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 12 생성 및 이미지 로드
		Rock* rock12 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock12 = rock12->GetComponent<Transform>();
		tr_Rock12->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		Texture* Rock12 = Resources::Load<Texture>(L"Rock12_4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock007.png");

		SpriteRenderer* Rock12sr = rock12->AddComponent<SpriteRenderer>();
		Rock12sr->SetImage(Rock12);
		Rock12sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 13 생성 및 이미지 로드
		Rock* rock13 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock13 = rock13->GetComponent<Transform>();
		tr_Rock13->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		Texture* Rock13 = Resources::Load<Texture>(L"Rock13_4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock010.png");

		SpriteRenderer* Rock13sr = rock13->AddComponent<SpriteRenderer>();
		Rock13sr->SetImage(Rock13);
		Rock13sr->SetScale(Vector2(0.75f, 0.75f));


		// Key 생성 및 이미지 로드
		Key* myKey = object::Instantiate<Key>(eLayerType::myKey);

		Transform* tr_Key = myKey->GetComponent<Transform>();
		tr_Key->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 1));

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
		Fire* Fire4_1base = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr4_1Firebase = Fire4_1base->GetComponent<Transform>();
		tr4_1Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3 - 3, LeftTop.y + MOVE_TILE_HEIGHT * 0 + 10));

		Texture* Fire4_1Base = Resources::Load<Texture>(L"Fire4_1Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		SpriteRenderer* Fire4_1Sr = Fire4_1base->AddComponent<SpriteRenderer>();
		Fire4_1Sr->SetImage(Fire4_1Base);
		Fire4_1Sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1
		Fire* Fire4_1 = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr4_1Fire = Fire4_1->GetComponent<Transform>();
		tr4_1Fire->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 0));

		Animator* at4_1Fire = Fire4_1->AddComponent<Animator>();
		at4_1Fire->CreateAnimationFolder(L"Fire4_1", L"..\\Resources\\Texture\\fire\\fire", Vector2(-2.0f, -25.0f));
		at4_1Fire->PlayAnimation(L"Fire4_1", true);
		at4_1Fire->SetScale(Vector2(0.4f, 0.5f));


		// Fire 2 base
		Fire* Fire4_2base = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr4_2Firebase = Fire4_2base->GetComponent<Transform>();
		tr4_2Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7 - 7, LeftTop.y + MOVE_TILE_HEIGHT * 0 - 25));

		Texture* Fire4_2Base = Resources::Load<Texture>(L"Fire4_2Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0002.png");

		SpriteRenderer* Fire4_2Sr = Fire4_2base->AddComponent<SpriteRenderer>();
		Fire4_2Sr->SetImage(Fire4_2Base);
		Fire4_2Sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 3 base
		Fire* Fire4_3base = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr4_3Firebase = Fire4_3base->GetComponent<Transform>();
		tr4_3Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 9 - 12, LeftTop.y + MOVE_TILE_HEIGHT * 0 - 20));

		Texture* Fire4_3Base = Resources::Load<Texture>(L"Fire4_3Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0002.png");

		SpriteRenderer* Fire4_3Sr = Fire4_3base->AddComponent<SpriteRenderer>();
		Fire4_3Sr->SetImage(Fire4_3Base);
		Fire4_3Sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 4 base
		Fire* Fire4_4base = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr4_4Firebase = Fire4_4base->GetComponent<Transform>();
		tr4_4Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 10 - 13, LeftTop.y + MOVE_TILE_HEIGHT * 2 - 20));

		Texture* Fire4_4Base = Resources::Load<Texture>(L"Fire4_4Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		SpriteRenderer* Fire4_4Sr = Fire4_4base->AddComponent<SpriteRenderer>();
		Fire4_4Sr->SetImage(Fire4_4Base);
		Fire4_4Sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 2
		Fire* Fire4_2 = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr4_2Fire = Fire4_2->GetComponent<Transform>();
		tr4_2Fire->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 10, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		Animator* at4_2Fire = Fire4_2->AddComponent<Animator>();
		at4_2Fire->CreateAnimationFolder(L"Fire4_1", L"..\\Resources\\Texture\\fire\\fire", Vector2(-10.0f, 10.0f));
		at4_2Fire->PlayAnimation(L"Fire4_1", true);
		at4_2Fire->SetScale(Vector2(0.4f, 0.5f));
	}

	void Chapter4::Update()
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
			Sound* Sound_SC5 = Resources::Load<Sound>(L"SceneChange5", L"..\\Resources\\Sound\\screen_changer_part1_01.wav");
			Sound_SC5->Play(false);

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

	void Chapter4::Render(HDC hdc)
	{
		Scene::Render(hdc);

		//int maxRow = 720 / (TILE_HEIGHT * 3) + 1;
		//for (size_t y = 0; y < maxRow; y++)
		//{
		//	MoveToEx(hdc, 0, TILE_HEIGHT * y * 4 - 15, NULL);      //      라인(선) 시작
		//	LineTo(hdc, 1280, TILE_HEIGHT * y * 4 - 15);        //          라인(선) 끝
		//}

		//int maxColumn = 1280 / (TILE_WIDTH * 3) + 1;
		//for (size_t x = 0; x < maxColumn; x++)
		//{
		//	MoveToEx(hdc, TILE_WIDTH * x * 4, 0, NULL);      //      라인(선) 시작
		//	LineTo(hdc, TILE_WIDTH * x * 4, 720);        //          라인(선) 끝
		//}
	}
}

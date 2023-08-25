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

namespace ya
{
	int Chapter2::MapInfo2[8][9] =
	{
		// 0 => 바닥
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
	{

	}

	Chapter2::~Chapter2()
	{
	}

	void Chapter2::Initialize()
	{
		SceneChange* S_C = object::Instantiate<SceneChange>(eLayerType::SceneChange); // 몬스터3 생성

		Transform* tr_SC = S_C->GetComponent<Transform>();
		tr_SC->SetPosition(Vector2(640.0f, 360.0f)); // 몬스터3 시작위치

		Animator* at_SC = S_C->AddComponent<Animator>();
		at_SC->CreateAnimationFolder(L"Change", L"..\\Resources\\Texture\\levelchange\\bmp", Vector2(0.0f, 0.0f));
		at_SC->PlayAnimation(L"Change", false);
		at_SC->SetScale(Vector2(0.7f, 0.7f));


		Texture* Chapter2 = Resources::Load<Texture>(L"Chapter2"
			, L"..\\Resources\\Texture\\chapterbg\\chapterBG0002.bmp");

		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(Chapter2);
		bgsr->SetScale(Vector2(0.7f, 0.7f));
		bgsr->SetAffectCamera(false);
		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));


		Player* player = object::Instantiate<Player>(eLayerType::Player); // 플레이어 생성
		Transform* tr = player->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1, LeftTop.y + MOVE_TILE_HEIGHT * 5)); // 캐릭터 시작위치
		
		
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
		col->SetSize(Vector2(100.0f, 110.0f));
		col->SetOffset(Vector2(0.0f, 0.0f));


		Monster* monster1 = object::Instantiate<Monster>(eLayerType::Monster); // 몬스터1 생성

		Transform* tr_M1 = monster1->GetComponent<Transform>();
		tr_M1->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 2)); // 몬스터1 시작위치

		Animator* at_M1 = monster1->AddComponent<Animator>();
		at_M1->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at_M1->PlayAnimation(L"Monster_RightIdle", true);
		at_M1->SetScale(Vector2(0.8f, 0.8f));

		col = monster1->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));

		Monster* monster2 = object::Instantiate<Monster>(eLayerType::Monster); // 몬스터2 생성

		Transform* tr_M2 = monster2->GetComponent<Transform>();
		tr_M2->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 5)); // 몬스터2 시작위치

		Animator* at_M2 = monster2->AddComponent<Animator>();
		at_M2->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at_M2->PlayAnimation(L"Monster_RightIdle", true);
		at_M2->SetScale(Vector2(0.8f, 0.8f));

		col = monster2->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));

		Monster* monster3 = object::Instantiate<Monster>(eLayerType::Monster); // 몬스터3 생성

		Transform* tr_M3 = monster3->GetComponent<Transform>();
		tr_M3->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 6)); // 몬스터3 시작위치

		Animator* at_M3 = monster3->AddComponent<Animator>();
		at_M3->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at_M3->PlayAnimation(L"Monster_RightIdle", true);
		at_M3->SetScale(Vector2(0.8f, 0.8f));

		col = monster3->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));

		Npc* modeus = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_Npc = modeus->GetComponent<Transform>();
		tr_Npc->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 6)); // Npc pandemonica 시작위치

		Animator* at_Npc = modeus->AddComponent<Animator>();
		at_Npc->CreateAnimationFolder(L"modeus", L"..\\Resources\\Texture\\npc\\modeus", Vector2(0.0f, -10.0f));
		at_Npc->PlayAnimation(L"modeus", true);
		at_Npc->SetScale(Vector2(0.8f, 0.8f));

		col = modeus->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Rock 1 생성 및 이미지 로드
		Rock* rock1 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock1 = rock1->GetComponent<Transform>();
		tr_Rock1->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		Texture* Rock1 = Resources::Load<Texture>(L"Rock1_2"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock007.png");

		SpriteRenderer* Rock1sr = rock1->AddComponent<SpriteRenderer>();
		Rock1sr->SetImage(Rock1);
		Rock1sr->SetScale(Vector2(0.75f, 0.75f));

		// Rock 2 생성 및 이미지 로드
		Rock* rock2 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock2 = rock2->GetComponent<Transform>();
		tr_Rock2->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		Texture* Rock2 = Resources::Load<Texture>(L"Rock2_2"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock005.png");

		SpriteRenderer* Rock2sr = rock2->AddComponent<SpriteRenderer>();
		Rock2sr->SetImage(Rock2);
		Rock2sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 3 생성 및 이미지 로드
		Rock* rock3 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock3 = rock3->GetComponent<Transform>();
		tr_Rock3->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		Texture* Rock3 = Resources::Load<Texture>(L"Rock3_2"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock003.png");

		SpriteRenderer* Rock3sr = rock3->AddComponent<SpriteRenderer>();
		Rock3sr->SetImage(Rock3);
		Rock3sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1 base
		Fire* Fire2_1base = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr2_1Firebase = Fire2_1base->GetComponent<Transform>();
		tr2_1Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1, LeftTop.y + MOVE_TILE_HEIGHT * 0 + 8));

		Texture* Fire2_1Base = Resources::Load<Texture>(L"Fire2_1Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		SpriteRenderer* Fire2_1Sr = Fire2_1base->AddComponent<SpriteRenderer>();
		Fire2_1Sr->SetImage(Fire2_1Base);
		Fire2_1Sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1 
		Fire* Fire2_1 = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr2_1Fire = Fire2_1->GetComponent<Transform>();
		tr2_1Fire->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1, LeftTop.y + MOVE_TILE_HEIGHT * 0));

		Animator* at2_1Fire = Fire2_1->AddComponent<Animator>();
		at2_1Fire->CreateAnimationFolder(L"Fire2_1", L"..\\Resources\\Texture\\fire\\fire", Vector2(2.0f, -25.0f));
		at2_1Fire->PlayAnimation(L"Fire2_1", true);
		at2_1Fire->SetScale(Vector2(0.4f, 0.5f));


		// Fire 2 base
		Fire* Fire2_2base = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr2_2Firebase = Fire2_2base->GetComponent<Transform>();
		tr2_2Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6 - 3, LeftTop.y + MOVE_TILE_HEIGHT * 0 - 32));

		Texture* Fire2_2Base = Resources::Load<Texture>(L"Fire2_2Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0002.png");

		SpriteRenderer* Fire2_2Sr = Fire2_2base->AddComponent<SpriteRenderer>();
		Fire2_2Sr->SetImage(Fire2_2Base);
		Fire2_2Sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 3 base
		Fire* Fire2_3base = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr2_3Firebase = Fire2_3base->GetComponent<Transform>();
		tr2_3Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8 - 3, LeftTop.y + MOVE_TILE_HEIGHT * 4 - 23));

		Texture* Fire2_3Base = Resources::Load<Texture>(L"Fire2_3Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		SpriteRenderer* Fire2_3Sr = Fire2_3base->AddComponent<SpriteRenderer>();
		Fire2_3Sr->SetImage(Fire2_3Base);
		Fire2_3Sr->SetScale(Vector2(0.75f, 0.75f));



		// Fire 2
		Fire* Fire2_2 = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr2_2Fire = Fire2_2->GetComponent<Transform>();
		tr2_2Fire->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		Animator* at2_2Fire = Fire2_2->AddComponent<Animator>();
		at2_2Fire->CreateAnimationFolder(L"Fire2_2", L"..\\Resources\\Texture\\fire\\fire", Vector2(0.0f, 10.0f));
		at2_2Fire->PlayAnimation(L"Fire2_2", true);
		at2_2Fire->SetScale(Vector2(0.4f, 0.5f));
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

		//int maxRow = 720 / (TILE_HEIGHT * 3) + 1;
		//for (size_t y = 0; y < maxRow; y++)
		//{
		//	MoveToEx(hdc, 0, TILE_HEIGHT * y * 4 + 18, NULL);      //      라인(선) 시작
		//	LineTo(hdc, 1280, TILE_HEIGHT * y * 4 + 18);        //          라인(선) 끝
		//}

		//int maxColumn = 1280 / (TILE_WIDTH * 3) + 1;
		//for (size_t x = 0; x < maxColumn; x++)
		//{
		//	MoveToEx(hdc, TILE_WIDTH * x * 4 + 30, 0, NULL);      //      라인(선) 시작
		//	LineTo(hdc, TILE_WIDTH * x * 4 + 30, 720);        //          라인(선) 끝
		//}


	
	
	}
}

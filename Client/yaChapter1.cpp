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
#include "yaCollisionManager.h"
#include "yaFloor.h"
#include "yaUi.h"

namespace ya
{
	int Chapter1::MapInfo1[8][9] =
	{
		// 0 => 바닥
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
	}

	Chapter1::~Chapter1()
	{
	}

	void Chapter1::Initialize()
	{
		// Scene Change 생성 및 애니메이션 재생
		SceneChange* S_C = object::Instantiate<SceneChange>(eLayerType::SceneChange);

		Transform* tr_SC = S_C->GetComponent<Transform>();
		tr_SC->SetPosition(Vector2(640.0f, 360.0f));

		Animator* at_SC = S_C->AddComponent<Animator>();
		at_SC->CreateAnimationFolder(L"Change", L"..\\Resources\\Texture\\levelchange\\bmp", Vector2(0.0f, 0.0f), 0.05f);
		at_SC->PlayAnimation(L"Change", false);
		at_SC->SetScale(Vector2(0.7f, 0.7f));
		
		// 왼쪽 위 Ui
		Ui* Ui1 = object::Instantiate<Ui>(eLayerType::UI);

		Transform* tr_Ui1 = Ui1->GetComponent<Transform>();
		tr_Ui1->SetPosition(Vector2(115.0f, 215.0f));


		Texture* T_Ui1 = Resources::Load<Texture>(L"Ui1"
			, L"..\\Resources\\Texture\\playui\\mainUI002.bmp");

		SpriteRenderer* sr_Ui1 = Ui1->AddComponent<SpriteRenderer>();
		sr_Ui1->SetImage(T_Ui1);
		sr_Ui1->SetScale(Vector2(0.75f, 0.75f));

		// 왼쪽 아래 Ui
		Ui* Ui2 = object::Instantiate<Ui>(eLayerType::UI);

		Transform* tr_Ui2 = Ui2->GetComponent<Transform>();
		tr_Ui2->SetPosition(Vector2(180.0f, 500.0f));


		Texture* T_Ui2 = Resources::Load<Texture>(L"Ui2"
			, L"..\\Resources\\Texture\\playui\\mainUI001.bmp");

		SpriteRenderer* sr_Ui2 = Ui2->AddComponent<SpriteRenderer>();
		sr_Ui2->SetImage(T_Ui2);
		sr_Ui2->SetScale(Vector2(0.75f, 0.75f));

		// 오른쪽 위 Ui
		Ui* Ui3 = object::Instantiate<Ui>(eLayerType::UI);

		Transform* tr_Ui3 = Ui3->GetComponent<Transform>();
		tr_Ui3->SetPosition(Vector2(1170.0f, 215.0f));


		Texture* T_Ui3 = Resources::Load<Texture>(L"Ui3"
			, L"..\\Resources\\Texture\\playui\\mainUI003.bmp");

		SpriteRenderer* sr_Ui3 = Ui3->AddComponent<SpriteRenderer>();
		sr_Ui3->SetImage(T_Ui3);
		sr_Ui3->SetScale(Vector2(0.75f, 0.75f));


		// 오른쪽 아래 Ui
		Ui* Ui4 = object::Instantiate<Ui>(eLayerType::UI);

		Transform* tr_Ui4 = Ui4->GetComponent<Transform>();
		tr_Ui4->SetPosition(Vector2(1100.0f, 500.0f));


		Texture* T_Ui4 = Resources::Load<Texture>(L"Ui4"
			, L"..\\Resources\\Texture\\playui\\mainUI000.bmp");

		SpriteRenderer* sr_Ui4 = Ui4->AddComponent<SpriteRenderer>();
		sr_Ui4->SetImage(T_Ui4);
		sr_Ui4->SetScale(Vector2(0.75f, 0.75f));

		// 배경 텍스쳐
		Texture* Chapter1 = Resources::Load<Texture>(L"Chapter1"
			, L"..\\Resources\\Texture\\chapterbg\\chapterBG0001.bmp");


		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(Chapter1);
		bgsr->SetScale(Vector2(0.7f, 0.7f));
		bgsr->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);
		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));

		// Player 생성
		Player* player = object::Instantiate<Player>(eLayerType::Player); // 플레이어 생성

		Transform* tr = player->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 1)); // 캐릭터 시작위치

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


		// Monster1 생성 및 이미지 로드
		Monster* monster1 = object::Instantiate<Monster>(eLayerType::Monster); // 몬스터1 생성

		Transform* tr_M1 = monster1->GetComponent<Transform>();
		tr_M1->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 2)); // 몬스터1 시작위치

		Animator* at_M1 = monster1->AddComponent<Animator>();
		at_M1->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at_M1->PlayAnimation(L"Monster_RightIdle", true);
		at_M1->SetScale(Vector2(0.8f, 0.8f));

		col = monster1->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));

		// 몬스터2 생성 및 이미지 로드
		Monster* monster2 = object::Instantiate<Monster>(eLayerType::Monster); // 몬스터2 생성

		Transform* tr_M2 = monster2->GetComponent<Transform>();
		tr_M2->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 3)); // 몬스터2 시작위치

		Animator* at_M2 = monster2->AddComponent<Animator>();
		at_M2->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at_M2->PlayAnimation(L"Monster_RightIdle", true);
		at_M2->SetScale(Vector2(0.8f, 0.8f));

		col = monster2->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));

		// 몬스터3 생성 및 이미지 로드
		Monster* monster3 = object::Instantiate<Monster>(eLayerType::Monster);

		Transform* tr_M3 = monster3->GetComponent<Transform>();
		tr_M3->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		Animator* at_M3 = monster3->AddComponent<Animator>();
		at_M3->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at_M3->PlayAnimation(L"Monster_RightIdle", true);
		at_M3->SetScale(Vector2(0.8f, 0.8f));

		col = monster3->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));



		// NPC 생성 및 이미지 로드
		Npc *pandemonica = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_Npc = pandemonica->GetComponent<Transform>();
		tr_Npc->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 6)); // Npc pandemonica 시작위치

		Animator* at_Npc = pandemonica->AddComponent<Animator>();
		at_Npc->CreateAnimationFolder(L"pandemonica", L"..\\Resources\\Texture\\npc\\pandemonica", Vector2(0.0f, -10.0f));
		at_Npc->PlayAnimation(L"pandemonica", true);
		at_Npc->SetScale(Vector2(0.8f, 0.8f));

		col = pandemonica->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign
		Npc* LoveSign = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_LoveSign = LoveSign->GetComponent<Transform>();
		tr_LoveSign->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6 + 30, LeftTop.y + MOVE_TILE_HEIGHT * 6 - 30)); // Npc pandemonica 시작위치

		Texture* T_LoveSign = Resources::Load<Texture>(L"LoveSign"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		SpriteRenderer* sr_LoveSign = LoveSign->AddComponent<SpriteRenderer>();
		sr_LoveSign->SetImage(T_LoveSign);
		sr_LoveSign->SetScale(Vector2(0.75f, 0.75f));



		// Rock 1 생성 및 이미지 로드
		Rock* rock1 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock1 = rock1->GetComponent<Transform>();
		tr_Rock1->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 5));

		Texture* Rock1 = Resources::Load<Texture>(L"Rock1_1"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock008.png");
		
		SpriteRenderer* Rock1sr = rock1->AddComponent<SpriteRenderer>();
		Rock1sr->SetImage(Rock1);
		Rock1sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 2 생성 및 이미지 로드
		Rock* rock2 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock2 = rock2->GetComponent<Transform>();
		tr_Rock2->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 6));

		Texture* Rock2 = Resources::Load<Texture>(L"Rock2_1"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock006.png");

		SpriteRenderer* Rock2sr = rock2->AddComponent<SpriteRenderer>();
		Rock2sr->SetImage(Rock2);
		Rock2sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 3 생성 및 이미지 로드
		Rock* rock3 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock3 = rock3->GetComponent<Transform>();
		tr_Rock3->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 6));

		Texture* Rock3 = Resources::Load<Texture>(L"Rock3_1"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock005.png");

		SpriteRenderer* Rock3sr = rock3->AddComponent<SpriteRenderer>();
		Rock3sr->SetImage(Rock3);
		Rock3sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 4 생성 및 이미지 로드
		Rock* rock4 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock4 = rock4->GetComponent<Transform>();
		tr_Rock4->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 5));

		Texture* Rock4 = Resources::Load<Texture>(L"Rock4_1"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock001.png");

		SpriteRenderer* Rock4sr = rock4->AddComponent<SpriteRenderer>();
		Rock4sr->SetImage(Rock4);
		Rock4sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1 base
		Fire* base1_1 = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr1_1Firebase = base1_1->GetComponent<Transform>();
		tr1_1Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 0 + 10, LeftTop.y + MOVE_TILE_HEIGHT * 4 + 10));

		Texture* Fire1_1Base = Resources::Load<Texture>(L"Fire1_1Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0002.png");

		SpriteRenderer* Fire1_1Sr = base1_1->AddComponent<SpriteRenderer>();
		Fire1_1Sr->SetImage(Fire1_1Base);
		Fire1_1Sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 2 base
		Fire* Fire1_2base = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr1_2Firebase = Fire1_2base->GetComponent<Transform>();
		tr1_2Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1 + 12, LeftTop.y + MOVE_TILE_HEIGHT * 1 + 10));

		Texture* Fire1_2Base = Resources::Load<Texture>(L"Fire1_2Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		SpriteRenderer* Fire1_2Sr = Fire1_2base->AddComponent<SpriteRenderer>();
		Fire1_2Sr->SetImage(Fire1_2Base);
		Fire1_2Sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 2 
		Fire* Fire1_2 = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr1_2Fire = Fire1_2->GetComponent<Transform>();
		tr1_2Fire->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1 + 12, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		Animator* at1_2Fire = Fire1_2->AddComponent<Animator>();
		at1_2Fire->CreateAnimationFolder(L"Fire1_2", L"..\\Resources\\Texture\\fire\\fire", Vector2(2.0f, -22.0f));
		at1_2Fire->PlayAnimation(L"Fire1_2", true);
		at1_2Fire->SetScale(Vector2(0.4f, 0.5f));


		// Fire 3 base
		Fire* Fire1_3base = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr1_3Firebase = Fire1_3base->GetComponent<Transform>();
		tr1_3Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 0 + 5));

		Texture* Fire1_3Base = Resources::Load<Texture>(L"Fire1_3Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0002.png");

		SpriteRenderer* Fire1_3Sr = Fire1_3base->AddComponent<SpriteRenderer>();
		Fire1_3Sr->SetImage(Fire1_3Base);
		Fire1_3Sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 4 base
		Fire* Fire1_4base = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr1_4Firebase = Fire1_4base->GetComponent<Transform>();
		tr1_4Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7 + 2, LeftTop.y + MOVE_TILE_HEIGHT * 4 - 20));

		Texture* Fire1_4Base = Resources::Load<Texture>(L"Fire1_4Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		SpriteRenderer* Fire1_4Sr = Fire1_4base->AddComponent<SpriteRenderer>();
		Fire1_4Sr->SetImage(Fire1_4Base);
		Fire1_4Sr->SetScale(Vector2(0.75f, 0.75f));

		// Fire 4 
		Fire* Fire1_4 = object::Instantiate<Fire>(eLayerType::Fire);

		Transform* tr1_4Fire = Fire1_4->GetComponent<Transform>();
		tr1_4Fire->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		Animator* at1_4Fire = Fire1_4->AddComponent<Animator>();
		at1_4Fire->CreateAnimationFolder(L"Fire4", L"..\\Resources\\Texture\\fire\\fire", Vector2(4.0f, -52.0f));
		at1_4Fire->PlayAnimation(L"Fire4", true);
		at1_4Fire->SetScale(Vector2(0.4f, 0.5f));

		Floor* floor1 = object::Instantiate<Floor>(eLayerType::Floor);

		tr = floor1->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 0, LeftTop.y + MOVE_TILE_HEIGHT * 5));

		col = floor1->AddComponent<Collider>();
		col->SetSize(Vector2(MOVE_TILE_WIDTH * 1, MOVE_TILE_HEIGHT * 3));


		Floor* floor2 = object::Instantiate<Floor>(eLayerType::Floor);

		tr = floor2->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1, LeftTop.y + MOVE_TILE_HEIGHT * 2));

		col = floor2->AddComponent<Collider>();
		col->SetSize(Vector2(MOVE_TILE_WIDTH * 1, MOVE_TILE_HEIGHT * 3));


		Floor* floor3 = object::Instantiate<Floor>(eLayerType::Floor);

		tr = floor3->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		col = floor3->AddComponent<Collider>();
		col->SetSize(Vector2(MOVE_TILE_WIDTH * 3, MOVE_TILE_HEIGHT * 1));


		Floor* floor4 = object::Instantiate<Floor>(eLayerType::Floor);

		tr = floor4->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5.5, LeftTop.y + MOVE_TILE_HEIGHT * 0));

		col = floor4->AddComponent<Collider>();
		col->SetSize(Vector2(MOVE_TILE_WIDTH * 2, MOVE_TILE_HEIGHT * 1));


		Floor* floor5 = object::Instantiate<Floor>(eLayerType::Floor);

		tr = floor5->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		col = floor5->AddComponent<Collider>();
		col->SetSize(Vector2(MOVE_TILE_WIDTH * 1, MOVE_TILE_HEIGHT * 3));


		Floor* floor6 = object::Instantiate<Floor>(eLayerType::Floor);

		tr = floor6->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 3.5));

		col = floor6->AddComponent<Collider>();
		col->SetSize(Vector2(MOVE_TILE_WIDTH * 1, MOVE_TILE_HEIGHT * 2));


		Floor* floor7 = object::Instantiate<Floor>(eLayerType::Floor);

		tr = floor7->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		col = floor7->AddComponent<Collider>();
		col->SetSize(Vector2(MOVE_TILE_WIDTH * 3, MOVE_TILE_HEIGHT * 1));


		Floor* floor8 = object::Instantiate<Floor>(eLayerType::Floor);

		tr = floor8->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 4.5));

		col = floor8->AddComponent<Collider>();
		col->SetSize(Vector2(MOVE_TILE_WIDTH * 1, MOVE_TILE_HEIGHT * 2));


		Floor* floor9 = object::Instantiate<Floor>(eLayerType::Floor);

		tr = floor9->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8, LeftTop.y + MOVE_TILE_HEIGHT * 5.5));

		col = floor9->AddComponent<Collider>();
		col->SetSize(Vector2(MOVE_TILE_WIDTH * 1, MOVE_TILE_HEIGHT * 2));


		Floor* floor10 = object::Instantiate<Floor>(eLayerType::Floor);

		tr = floor10->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 7));

		col = floor10->AddComponent<Collider>();
		col->SetSize(Vector2(MOVE_TILE_WIDTH * 9, MOVE_TILE_HEIGHT * 1));

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Monster, eLayerType::Floor, true);
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

		int maxRow = 720 / (TILE_HEIGHT * 3) + 1;
		for (size_t y = 0; y < maxRow; y++)
		{
			MoveToEx(hdc, 0, TILE_HEIGHT * y * 4 + 16, NULL);      //      라인(선) 시작
			LineTo(hdc, 1280, TILE_HEIGHT * y * 4 + 16);        //          라인(선) 끝
		}

		int maxColumn = 1280 / (TILE_WIDTH * 3) + 1;
		for (size_t x = 0; x < maxColumn; x++)
		{
			MoveToEx(hdc, TILE_WIDTH * x * 4 + 25, 0, NULL);      //      라인(선) 시작
			LineTo(hdc, TILE_WIDTH * x * 4 + 25, 720);        //          라인(선) 끝
		}



	}
}

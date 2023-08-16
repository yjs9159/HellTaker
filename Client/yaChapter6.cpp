#include "yaChapter6.h"
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
#include "yaKey.h"

namespace ya
{
	ya::Chapter6::Chapter6()
		: LeftTop(Vector2(318.0f + 72 / 2, 15.0f + 68 / 2))
	{
	}

	ya::Chapter6::~Chapter6()
	{
	}

	void ya::Chapter6::Initialize()
	{
		Texture* Chapter6 = Resources::Load<Texture>(L"Chapter6"
			, L"..\\Resources\\Texture\\chapterbg\\chapterBG0006.bmp");


		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(Chapter6);
		bgsr->SetScale(Vector2(0.7f, 0.7f));
		bgsr->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);
		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));


		Player* player = object::Instantiate<Player>(eLayerType::Player); // 플레이어 생성
		Transform* tr = player->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 1)); // 플레이어 시작위치

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

		Monster* monster1 = object::Instantiate<Monster>(eLayerType::Monster); // 몬스터1 생성
		Transform* tr_M1 = monster1->GetComponent<Transform>();
		tr_M1->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 5)); // 몬스터1 시작위치

		Animator* at_M1 = monster1->AddComponent<Animator>();
		at_M1->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at_M1->PlayAnimation(L"Monster_RightIdle", true);
		at_M1->SetScale(Vector2(0.8f, 0.8f));

		col = monster1->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));

		Monster* monster2 = object::Instantiate<Monster>(eLayerType::Monster); // 몬스터2 생성
		Transform* tr_M2 = monster2->GetComponent<Transform>();
		tr_M2->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 6)); // 몬스터2 시작위치

		Animator* at_M2 = monster2->AddComponent<Animator>();
		at_M2->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at_M2->PlayAnimation(L"Monster_RightIdle", true);
		at_M2->SetScale(Vector2(0.8f, 0.8f));

		col = monster2->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		Npc* azazel = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_azazel = azazel->GetComponent<Transform>();
		tr_azazel->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 8)); // Npc pandemonica 시작위치

		Animator* at_azazel = azazel->AddComponent<Animator>();
		at_azazel->CreateAnimationFolder(L"azazel ", L"..\\Resources\\Texture\\npc\\azazel", Vector2(0.0f, -10.0f));
		at_azazel->PlayAnimation(L"azazel ", true);
		at_azazel->SetScale(Vector2(0.8f, 0.8f));

		col = azazel->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Rock 1 생성 및 이미지 로드
		Rock* rock1 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock1 = rock1->GetComponent<Transform>();
		tr_Rock1->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 2));

		Texture* Rock1 = Resources::Load<Texture>(L"Rock1_6"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock004.png");

		SpriteRenderer* Rock1sr = rock1->AddComponent<SpriteRenderer>();
		Rock1sr->SetImage(Rock1);
		Rock1sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 2 생성 및 이미지 로드
		Rock* rock2 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock2 = rock2->GetComponent<Transform>();
		tr_Rock2->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 2));

		Texture* Rock2 = Resources::Load<Texture>(L"Rock2_6"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock005.png");

		SpriteRenderer* Rock2sr = rock2->AddComponent<SpriteRenderer>();
		Rock2sr->SetImage(Rock2);
		Rock2sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 3 생성 및 이미지 로드
		Rock* rock3 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock3 = rock3->GetComponent<Transform>();
		tr_Rock3->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 2));

		Texture* Rock3 = Resources::Load<Texture>(L"Rock3_6"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock006.png");

		SpriteRenderer* Rock3sr = rock3->AddComponent<SpriteRenderer>();
		Rock3sr->SetImage(Rock3);
		Rock3sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 4 생성 및 이미지 로드
		Rock* rock4 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock4 = rock4->GetComponent<Transform>();
		tr_Rock4->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		Texture* Rock4 = Resources::Load<Texture>(L"Rock4_6"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock007.png");

		SpriteRenderer* Rock4sr = rock4->AddComponent<SpriteRenderer>();
		Rock4sr->SetImage(Rock4);
		Rock4sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 5 생성 및 이미지 로드
		Rock* rock5 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock5 = rock5->GetComponent<Transform>();
		tr_Rock5->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 5));

		Texture* Rock5 = Resources::Load<Texture>(L"Rock5_6"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock008.png");

		SpriteRenderer* Rock5sr = rock5->AddComponent<SpriteRenderer>();
		Rock5sr->SetImage(Rock5);
		Rock5sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 6 생성 및 이미지 로드
		Rock* rock6 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock6 = rock6->GetComponent<Transform>();
		tr_Rock6->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 6));

		Texture* Rock6 = Resources::Load<Texture>(L"Rock6_6"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock002.png");

		SpriteRenderer* Rock6sr = rock6->AddComponent<SpriteRenderer>();
		Rock6sr->SetImage(Rock6);
		Rock6sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 7 생성 및 이미지 로드
		Rock* rock7 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock7 = rock7->GetComponent<Transform>();
		tr_Rock7->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 5));

		Texture* Rock7 = Resources::Load<Texture>(L"Rock7_6"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock001.png");

		SpriteRenderer* Rock7sr = rock7->AddComponent<SpriteRenderer>();
		Rock7sr->SetImage(Rock7);
		Rock7sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 8 생성 및 이미지 로드
		Rock* rock8 = object::Instantiate<Rock>(eLayerType::Rock);

		Transform* tr_Rock8 = rock8->GetComponent<Transform>();
		tr_Rock8->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 7));

		Texture* Rock8 = Resources::Load<Texture>(L"Rock8_6"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock009.png");

		SpriteRenderer* Rock8sr = rock8->AddComponent<SpriteRenderer>();
		Rock8sr->SetImage(Rock8);
		Rock8sr->SetScale(Vector2(0.75f, 0.75f));


		// Key 생성 및 이미지 로드
		Key* myKey = object::Instantiate<Key>(eLayerType::myKey);

		Transform* tr_Key = myKey->GetComponent<Transform>();
		tr_Key->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		Animator* at_Key = myKey->AddComponent<Animator>();
		at_Key->CreateAnimationFolder(L"myKey", L"..\\Resources\\Texture\\obstacle\\Key", Vector2(10.0f, 0.0f));
		at_Key->PlayAnimation(L"myKey", true);
		at_Key->SetScale(Vector2(0.8f, 0.8f));
	}

	void ya::Chapter6::Update()
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

	void ya::Chapter6::Render(HDC hdc)
	{
		Scene::Render(hdc);

		int maxRow = 720 / (TILE_HEIGHT * 3) + 1;
		for (size_t y = 0; y < maxRow; y++)
		{
			MoveToEx(hdc, 0, TILE_HEIGHT * y * 4 + 15, NULL);      //      라인(선) 시작
			LineTo(hdc, 1280, TILE_HEIGHT * y * 4 + 15);        //          라인(선) 끝
		}

		int maxColumn = 1280 / (TILE_WIDTH * 3) + 1;
		for (size_t x = 0; x < maxColumn; x++)
		{
			MoveToEx(hdc, TILE_WIDTH * x * 4 + 30, 0, NULL);      //      라인(선) 시작
			LineTo(hdc, TILE_WIDTH * x * 4 + 30, 720);        //          라인(선) 끝
		}
	}
}

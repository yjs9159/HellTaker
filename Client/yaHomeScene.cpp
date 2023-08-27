#include "yaHomeScene.h"
#include "yaSpriteRenderer.h"
#include "yaObject.h"
#include "yaInput.h"
#include "yaSpriteRenderer.h"
#include "yaObject.h"
#include "yaInput.h"
#include "yaTexture.h"
#include "yaTransform.h"
#include "yaResources.h"
#include "yaBackGround.h"
#include "yaCamera.h"
#include "yaAnimator.h"
#include "yaSceneChange.h"
#include "yaNpc.h"
#include "yaPlayer.h"
#include "yaCollider.h"

namespace ya
{
	HomeScene::HomeScene()
		:LeftTop(Vector2(0.0f + 72/2, 0.0f + 68/2))
	{
	}
	HomeScene::~HomeScene()
	{
	}

	void HomeScene::Initialize()
	{
		// ScneChange 생성 및 애니메이션 로드
		SceneChange* S_C = object::Instantiate<SceneChange>(eLayerType::SceneChange);

		Transform* tr_SC = S_C->GetComponent<Transform>();
		tr_SC->SetPosition(Vector2(640.0f, 360.0f));

		Animator* at_SC = S_C->AddComponent<Animator>();
		at_SC->CreateAnimationFolder(L"Change", L"..\\Resources\\Texture\\levelchange\\bmp", Vector2(0.0f, 0.0f), 0.05f);
		at_SC->PlayAnimation(L"Change", false);
		at_SC->SetScale(Vector2(0.7f, 0.7f));

		Texture* HomeScene = Resources::Load<Texture>(L"HomeScene"
			, L"..\\Resources\\Texture\\Home.png");


		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(HomeScene);
		bgsr->SetScale(Vector2(0.7f, 0.7f));
		bgsr->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);
		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));


		Player* player = object::Instantiate<Player>(eLayerType::Player); // 플레이어 생성

		Transform* tr = player->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 15, LeftTop.y + MOVE_TILE_HEIGHT * 2)); // 캐릭터 시작위치

		HomeScene = Resources::Load<Texture>(L"PlayerImage"
			, L"..\\Resources\\Texture\\Hero.bmp");

		// Hero Idle 리소스 편집하기
		Animator* at = player->AddComponent<Animator>();
		at->CreateAnimation(L"hero_rightIdle", HomeScene, Vector2(0.0f, 583.2f), Vector2(100.0f, 194.4f), 12);
		//at->CreateAnimationFolder(L"Hero_rightidle", L"..\\Resources\\Texture\\player\\hero_Idle\\right_idle", Vector2(0.0f, 10.0f));
		at->CreateAnimationFolder(L"player_leftidle", L"..\\Resources\\Texture\\player\\player_idle\\left_idle", Vector2(0.0f, 10.0f));
		at->CreateAnimationFolder(L"player_rightrun", L"..\\Resources\\Texture\\player\\player_run\\right_run", Vector2(0.0f, 10.0f));
		at->CreateAnimationFolder(L"player_leftrun", L"..\\Resources\\Texture\\player\\player_run\\left_run", Vector2(0.0f, 10.0f));
		at->CreateAnimationFolder(L"player_rightattack", L"..\\Resources\\Texture\\player\\player_attack\\right_attack", Vector2(0.0f, -10.0f));
		at->CreateAnimationFolder(L"player_leftattack", L"..\\Resources\\Texture\\player\\player_attack\\left_attack", Vector2(0.0f, -10.0f));
		at->CreateAnimationFolder(L"player_rightsuccess", L"..\\Resources\\Texture\\player\\player_success\\right_success", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"PlayerIdle", true);
		at->SetScale(Vector2(0.8f, 0.8f));
		at->SetAffectedCamera(true);

		Collider* col = player->AddComponent<Collider>();
		col->SetSize(Vector2(100.0f, 110.0f));
		col->SetOffset(Vector2(0.0f, 0.0f));


		// cerberus 첫번째 Npc 생성 
		Npc* cerberus1 = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_cerberus1 = cerberus1->GetComponent<Transform>();
		tr_cerberus1->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 5)); // Npc pandemonica 시작위치

		Animator* at_cerberus1 = cerberus1->AddComponent<Animator>();
		at_cerberus1->CreateAnimationFolder(L"cerberus1", L"..\\Resources\\Texture\\npc\\cerberus", Vector2(0.0f, -10.0f));
		at_cerberus1->PlayAnimation(L"cerberus1", true);
		at_cerberus1->SetScale(Vector2(0.8f, 0.8f));

		col = cerberus1->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign 1
		Npc* LoveSign1 = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_LoveSign1 = LoveSign1->GetComponent<Transform>();
		tr_LoveSign1->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1 + 30, LeftTop.y + MOVE_TILE_HEIGHT * 5 - 30)); // Npc pandemonica 시작위치

		Texture* T_LoveSign = Resources::Load<Texture>(L"LoveSign1"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		SpriteRenderer* sr_LoveSign1 = LoveSign1->AddComponent<SpriteRenderer>();
		sr_LoveSign1->SetImage(T_LoveSign);
		sr_LoveSign1->SetScale(Vector2(0.75f, 0.75f));


		// cerberus 두번째 Npc 생성 
		Npc* cerberus2 = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_cerberus2 = cerberus2->GetComponent<Transform>();
		tr_cerberus2->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 6)); // Npc pandemonica 시작위치

		Animator* at_cerberus2 = cerberus2->AddComponent<Animator>();
		at_cerberus2->CreateAnimationFolder(L"cerberus2", L"..\\Resources\\Texture\\npc\\cerberus", Vector2(0.0f, -10.0f));
		at_cerberus2->PlayAnimation(L"cerberus2", true);
		at_cerberus2->SetScale(Vector2(0.8f, 0.8f));

		col = cerberus2->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign 2
		Npc* LoveSign2 = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_LoveSign2 = LoveSign2->GetComponent<Transform>();
		tr_LoveSign2->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1 + 30, LeftTop.y + MOVE_TILE_HEIGHT * 6 - 30)); // Npc pandemonica 시작위치

		Texture* T_LoveSign2 = Resources::Load<Texture>(L"LoveSign2"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		SpriteRenderer* sr_LoveSign2 = LoveSign2->AddComponent<SpriteRenderer>();
		sr_LoveSign2->SetImage(T_LoveSign2);
		sr_LoveSign2->SetScale(Vector2(0.75f, 0.75f));



		// cerberus 세번째 Npc 생성  
		Npc* cerberus3 = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_cerberus3 = cerberus3->GetComponent<Transform>();
		tr_cerberus3->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 7)); // Npc pandemonica 시작위치

		Animator* at_cerberus3 = cerberus3->AddComponent<Animator>();
		at_cerberus3->CreateAnimationFolder(L"cerberus3", L"..\\Resources\\Texture\\npc\\cerberus", Vector2(0.0f, -10.0f));
		at_cerberus3->PlayAnimation(L"cerberus3", true);
		at_cerberus3->SetScale(Vector2(0.8f, 0.8f));

		col = cerberus3->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign 3
		Npc* LoveSign3 = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_LoveSign3 = LoveSign3->GetComponent<Transform>();
		tr_LoveSign3->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1 + 30, LeftTop.y + MOVE_TILE_HEIGHT * 7 - 30)); // Npc pandemonica 시작위치

		Texture* T_LoveSign3 = Resources::Load<Texture>(L"LoveSign2"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		SpriteRenderer* sr_LoveSign3 = LoveSign3->AddComponent<SpriteRenderer>();
		sr_LoveSign3->SetImage(T_LoveSign3);
		sr_LoveSign3->SetScale(Vector2(0.75f, 0.75f));



		// azazel Npc 생성  
		Npc* azazel = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_azazel = azazel->GetComponent<Transform>();
		tr_azazel->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 1)); // Npc pandemonica 시작위치

		Animator* at_azazel = azazel->AddComponent<Animator>();
		at_azazel->CreateAnimationFolder(L"azazel", L"..\\Resources\\Texture\\npc\\azazel", Vector2(0.0f, -10.0f));
		at_azazel->PlayAnimation(L"azazel", true);
		at_azazel->SetScale(Vector2(0.8f, 0.8f));

		col = azazel->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign 4
		Npc* LoveSign4 = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_LoveSign4 = LoveSign4->GetComponent<Transform>();
		tr_LoveSign4->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2 + 30, LeftTop.y + MOVE_TILE_HEIGHT * 1 - 30)); // Npc pandemonica 시작위치

		Texture* T_LoveSign4 = Resources::Load<Texture>(L"LoveSign1"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		SpriteRenderer* sr_LoveSign4 = LoveSign4->AddComponent<SpriteRenderer>();
		sr_LoveSign4->SetImage(T_LoveSign4);
		sr_LoveSign4->SetScale(Vector2(0.75f, 0.75f));


		// judgement Npc 생성  <= 리소스 파일 이상함
		Npc* judgement = object::Instantiate<Npc>(eLayerType::Npc);

		Transform* tr_judgement = judgement->GetComponent<Transform>();
		tr_judgement->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 6));

		HomeScene = Resources::Load<Texture>(L"judgement"
			, L"..\\Resources\\Texture\\npc\\judgement\\Judgement.bmp");

		Animator* at_judgement = judgement->AddComponent<Animator>();
		at_judgement->CreateAnimation(L"judgement", HomeScene, Vector2(0.0f,0.0f), Vector2(100.0f, 96.0f), 12);
		at_judgement->PlayAnimation(L"judgement", true);
		at_judgement->SetScale(Vector2(0.8f, 0.8f));

		col = judgement->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign 5
		Npc* LoveSign5 = object::Instantiate<Npc>(eLayerType::Npc);

		Transform* tr_LoveSign5 = LoveSign5->GetComponent<Transform>();
		tr_LoveSign5->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3 + 30, LeftTop.y + MOVE_TILE_HEIGHT * 6 - 30));

		Texture* T_LoveSign5 = Resources::Load<Texture>(L"LoveSign"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		SpriteRenderer* sr_LoveSign5 = LoveSign5->AddComponent<SpriteRenderer>();
		sr_LoveSign5->SetImage(T_LoveSign5);
		sr_LoveSign5->SetScale(Vector2(0.75f, 0.75f));


		// zdrada Npc 생성  
		Npc* zdrada = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_zdrada = zdrada->GetComponent<Transform>();
		tr_zdrada->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 1)); // Npc pandemonica 시작위치

		Animator* at_zdrada = zdrada->AddComponent<Animator>();
		at_zdrada->CreateAnimationFolder(L"zdrada", L"..\\Resources\\Texture\\npc\\zdrada", Vector2(0.0f, -10.0f));
		at_zdrada->PlayAnimation(L"zdrada", true);
		at_zdrada->SetScale(Vector2(0.8f, 0.8f));

		col = zdrada->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign 6
		Npc* LoveSign6 = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_LoveSign6 = LoveSign6->GetComponent<Transform>();
		tr_LoveSign6->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6 + 30, LeftTop.y + MOVE_TILE_HEIGHT * 1 - 30)); // Npc pandemonica 시작위치

		Texture* T_LoveSign6 = Resources::Load<Texture>(L"LoveSign1"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		SpriteRenderer* sr_LoveSign6 = LoveSign6->AddComponent<SpriteRenderer>();
		sr_LoveSign6->SetImage(T_LoveSign6);
		sr_LoveSign6->SetScale(Vector2(0.75f, 0.75f));


		// malina Npc 생성  
		Npc* malina = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_malina = malina->GetComponent<Transform>();
		tr_malina->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 5)); // Npc pandemonica 시작위치

		Animator* at_malina = malina->AddComponent<Animator>();
		at_malina->CreateAnimationFolder(L"malina", L"..\\Resources\\Texture\\npc\\malina", Vector2(0.0f, -10.0f));
		at_malina->PlayAnimation(L"malina", true);
		at_malina->SetScale(Vector2(0.8f, 0.8f));

		col = malina->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign 7
		Npc* LoveSign7 = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_LoveSign7 = LoveSign7->GetComponent<Transform>();
		tr_LoveSign7->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6 + 30, LeftTop.y + MOVE_TILE_HEIGHT * 5 - 30)); // Npc pandemonica 시작위치

		Texture* T_LoveSign7 = Resources::Load<Texture>(L"LoveSign1"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		SpriteRenderer* sr_LoveSign7 = LoveSign7->AddComponent<SpriteRenderer>();
		sr_LoveSign7->SetImage(T_LoveSign7);
		sr_LoveSign7->SetScale(Vector2(0.75f, 0.75f));


		// pandemonica Npc 생성  
		Npc* pandemonica = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_pandemonica = pandemonica->GetComponent<Transform>();
		tr_pandemonica->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8, LeftTop.y + MOVE_TILE_HEIGHT * 7)); // Npc pandemonica 시작위치

		Animator* at_pandemonica = pandemonica->AddComponent<Animator>();
		at_pandemonica->CreateAnimationFolder(L"pandemonica", L"..\\Resources\\Texture\\npc\\pandemonica", Vector2(0.0f, -10.0f));
		at_pandemonica->PlayAnimation(L"pandemonica", true);
		at_pandemonica->SetScale(Vector2(0.8f, 0.8f));

		col = pandemonica->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign 8
		Npc* LoveSign8 = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_LoveSign8 = LoveSign8->GetComponent<Transform>();
		tr_LoveSign8->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7 + 30, LeftTop.y + MOVE_TILE_HEIGHT * 7 - 30)); // Npc pandemonica 시작위치

		Texture* T_LoveSign8 = Resources::Load<Texture>(L"LoveSign1"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		SpriteRenderer* sr_LoveSign8 = LoveSign8->AddComponent<SpriteRenderer>();
		sr_LoveSign8->SetImage(T_LoveSign8);
		sr_LoveSign8->SetScale(Vector2(0.75f, 0.75f));


		// justice Npc 생성  
		Npc* justice = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_justice = justice->GetComponent<Transform>();
		tr_justice->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 11, LeftTop.y + MOVE_TILE_HEIGHT * 4)); // Npc pandemonica 시작위치

		Animator* at_justice = justice->AddComponent<Animator>();
		at_justice->CreateAnimationFolder(L"justice", L"..\\Resources\\Texture\\npc\\justice", Vector2(0.0f, -10.0f));
		at_justice->PlayAnimation(L"justice", true);
		at_justice->SetScale(Vector2(0.8f, 0.8f));

		col = justice->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign 9
		Npc* LoveSign9 = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_LoveSign9 = LoveSign9->GetComponent<Transform>();
		tr_LoveSign9->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 10 + 30, LeftTop.y + MOVE_TILE_HEIGHT * 4 - 30)); // Npc pandemonica 시작위치

		Texture* T_LoveSign9 = Resources::Load<Texture>(L"LoveSign1"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		SpriteRenderer* sr_LoveSign9 = LoveSign9->AddComponent<SpriteRenderer>();
		sr_LoveSign9->SetImage(T_LoveSign9);
		sr_LoveSign9->SetScale(Vector2(0.75f, 0.75f));


		// lucyh Npc 생성  
		Npc* lucyh = object::Instantiate<Npc>(eLayerType::Npc);

		Transform* tr_lucyh = lucyh->GetComponent<Transform>();
		tr_lucyh->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 12, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		Animator* at_lucyh = lucyh->AddComponent<Animator>();
		at_lucyh->CreateAnimationFolder(L"lucyh", L"..\\Resources\\Texture\\npc\\lucyh", Vector2(0.0f, -10.0f));
		at_lucyh->PlayAnimation(L"lucyh", true);
		at_lucyh->SetScale(Vector2(0.8f, 0.8f));

		col = lucyh->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign 10
		Npc* LoveSign10 = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_LoveSign10 = LoveSign10->GetComponent<Transform>();
		tr_LoveSign10->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 11 + 30, LeftTop.y + MOVE_TILE_HEIGHT * 4 - 30)); // Npc pandemonica 시작위치

		Texture* T_LoveSign10 = Resources::Load<Texture>(L"LoveSign1"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		SpriteRenderer* sr_LoveSign10 = LoveSign10->AddComponent<SpriteRenderer>();
		sr_LoveSign10->SetImage(T_LoveSign10);
		sr_LoveSign10->SetScale(Vector2(0.75f, 0.75f));


		// modeus Npc 생성  
		Npc* modeus = object::Instantiate<Npc>(eLayerType::Npc);

		Transform* tr_modeus = modeus->GetComponent<Transform>();
		tr_modeus->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 15, LeftTop.y + MOVE_TILE_HEIGHT * 5));

		Animator* at_modeus = modeus->AddComponent<Animator>();
		at_modeus->CreateAnimationFolder(L"modeus", L"..\\Resources\\Texture\\npc\\modeus", Vector2(0.0f, -10.0f));
		at_modeus->PlayAnimation(L"modeus", true);
		at_modeus->SetScale(Vector2(0.8f, 0.8f));

		col = modeus->AddComponent<Collider>();
		col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign 11
		Npc* LoveSign11 = object::Instantiate<Npc>(eLayerType::Npc); // Npc pandemonica 생성

		Transform* tr_LoveSign11 = LoveSign11->GetComponent<Transform>();
		tr_LoveSign11->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 14 + 30, LeftTop.y + MOVE_TILE_HEIGHT * 5 - 30)); // Npc pandemonica 시작위치

		Texture* T_LoveSign11 = Resources::Load<Texture>(L"LoveSign1"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		SpriteRenderer* sr_LoveSign11 = LoveSign11->AddComponent<SpriteRenderer>();
		sr_LoveSign11->SetImage(T_LoveSign11);
		sr_LoveSign11->SetScale(Vector2(0.75f, 0.75f));
	}

	void HomeScene::Update()
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
	void HomeScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		int maxRow = 720 / (TILE_HEIGHT * 3) + 1;
		for (size_t y = 0; y < maxRow; y++)
		{
			MoveToEx(hdc, 0, TILE_HEIGHT * y * 4 - 20, NULL);      //      라인(선) 시작
			LineTo(hdc, 1280, TILE_HEIGHT * y * 4 - 20);        //          라인(선) 끝
		}

		int maxColumn = 1280 / (TILE_WIDTH * 3) + 1;
		for (size_t x = 0; x < maxColumn; x++)
		{
			MoveToEx(hdc, TILE_WIDTH * x * 4 - 30, 0, NULL);      //      라인(선) 시작
			LineTo(hdc, TILE_WIDTH * x * 4 - 30, 720);        //          라인(선) 끝
		}

		
	}
}

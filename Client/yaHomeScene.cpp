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


		// cerberus 첫번째 Npc 생성  
		Npc* cerberus1 = object::Instantiate<Npc>(eLayerType::Npc);

		Transform* tr_cerberus1 = cerberus1->GetComponent<Transform>();
		tr_cerberus1->SetPosition(Vector2(0.0f, 0.0f));

		Animator* at_cerberus1 = cerberus1->AddComponent<Animator>();
		at_cerberus1->CreateAnimationFolder(L"cerberus1", L"..\\Resources\\Texture\\npc\\cerberus", Vector2(0.0f, 0.0f));
		at_cerberus1->PlayAnimation(L"cerberus1");
		at_cerberus1->SetScale(Vector2(0.8f, 0.8f));
		at_cerberus1->SetAffectedCamera(true);


		// cerberus 두번째 Npc 생성  
		Npc* cerberus2 = object::Instantiate<Npc>(eLayerType::Npc);

		Transform* tr_cerberus2 = cerberus2->GetComponent<Transform>();
		tr_cerberus2->SetPosition(Vector2(0.0f, 0.0f));

		Animator* at_cerberus2 = cerberus2->AddComponent<Animator>();
		at_cerberus2->CreateAnimationFolder(L"cerberus2", L"..\\Resources\\Texture\\npc\\cerberus", Vector2(0.0f, 0.0f));
		at_cerberus2->PlayAnimation(L"cerberus2");
		at_cerberus2->SetScale(Vector2(0.8f, 0.8f));
		at_cerberus2->SetAffectedCamera(true);


		// cerberus 세번째 Npc 생성  
		Npc* cerberus3 = object::Instantiate<Npc>(eLayerType::Npc);

		Transform* tr_cerberus3 = cerberus3->GetComponent<Transform>();
		tr_cerberus3->SetPosition(Vector2(0.0f, 0.0f));

		Animator* at_cerberus3 = cerberus3->AddComponent<Animator>();
		at_cerberus3->CreateAnimationFolder(L"cerberus3", L"..\\Resources\\Texture\\npc\\cerberus", Vector2(0.0f, 0.0f));
		at_cerberus3->PlayAnimation(L"cerberus3");
		at_cerberus3->SetScale(Vector2(0.8f, 0.8f));
		at_cerberus3->SetAffectedCamera(true);




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

#include "yaHomeScene.h"
#include "yaPlayer.h"
#include "yaSpriteRenderer.h"
#include "yaObject.h"
#include "yaInput.h"
#include "yaPlayer.h"
#include "yaSpriteRenderer.h"
#include "yaObject.h"
#include "yaInput.h"
#include "yaTexture.h"
#include "yaTransform.h"
#include "yaResources.h"
#include "yaBackGround.h"
#include "yaCamera.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaMonster.h"
#include "yaCollisionManager.h"
#include "yaRigidBody.h"
#include "yaFloor.h"
#include "yaSceneChange.h"

namespace ya
{
	HomeScene::HomeScene()
		:LeftTop(Vector2(313.0f + 72/2, 84.0f + 68/2))
	{
	}
	HomeScene::~HomeScene()
	{
	}

	void HomeScene::Initialize()
	{
		Texture* HomeScene = Resources::Load<Texture>(L"HomeScene"
			, L"..\\Resources\\Image\\Sprite\\Map\\chapterBG0001.bmp");


		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(HomeScene);
		bgsr->SetScale(Vector2(0.7f, 0.7f));
		bgsr->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);
		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));

		Texture* image = Resources::Load<Texture>(L"Hero"
			, L"..\\Resources\\Image\\Sprite\\HeroSprite\\Hero.bmp");

		Player* player = object::Instantiate<Player>(eLayerType::Player);
		Transform* tr = player->GetComponent<Transform>();

		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 1)); // 캐릭터 시작위치

		//tr->SetPosition(Vector2(640.0f, 360.0f));

		image = Resources::Load<Texture>(L"PlayerImage"
			, L"..\\Resources\\Image\\Sprite\\Player");

		// 가로 100 세로 194.4
		Animator* at = player->AddComponent<Animator>();
		//at->CreateAnimation(L"HeroIdle", image, Vector2(0.0f, 0.0f), Vector2(100.0f, 194.4f), 12);
		//at->CreateAnimation(L"HeroRight", image, Vector2(0.0f, 388.8f), Vector2(100.0f, 194.4f), 6);
		at->CreateAnimationFolder(L"Player_Rightidle", L"..\\Resources\\Texture\\player\\player_idle\\right_idle", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"Player_Leftidle", L"..\\Resources\\Texture\\player\\player_idle\\left_idle", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"Player_Rightrun", L"..\\Resources\\Texture\\player\\player_run\\right_run", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"Player_Leftrun", L"..\\Resources\\Texture\\player\\player_run\\left_run", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"Player_Rightattack", L"..\\Resources\\Texture\\player\\player_attack\\right_attack", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"Player_Leftattack", L"..\\Resources\\Texture\\player\\player_attack\\left_attack", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"Player_Rightsuccess", L"..\\Resources\\Texture\\player\\player_success\\right_success", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"Player_Leftsuccess", L"..\\Resources\\Texture\\player\\player_success\\left_success", Vector2(0.0f, 0.0f));
		
		at->PlayAnimation(L"Player_Rightidle", true);
		at->SetAffectedCamera(true);

		Collider* col = player->AddComponent<Collider>();
		col->SetSize(Vector2(100.0f, 110.0f));
		col->SetOffset(Vector2(0.0f, -30.0f));


		Monster* monster = object::Instantiate<Monster>(eLayerType::Monster);
		
		Animator* Skeleton_at = monster->AddComponent<Animator>();
		Skeleton_at->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, 0.0f));
		Skeleton_at->CreateAnimationFolder(L"Monster_LeftIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\left_idle", Vector2(0.0f, 0.0f));
		Skeleton_at->CreateAnimationFolder(L"Monster_RightMove", L"..\\Resources\\Texture\\obstacle\\undead_move\\Right_Move", Vector2(0.0f, 0.0f));
		Skeleton_at->PlayAnimation(L"Monster_RightIdle", true);

		col = monster->AddComponent<Collider>();
		col->SetSize(Vector2(100.0f, 100.0f));
		//col->SetOffset(Vector2(10.0f, 10.0f));
		tr = monster->GetComponent<Transform>();

		tr->SetPosition(Vector2(940.0f, 360.0f));

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
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

			SceneChange* SC = object::Instantiate<SceneChange>(eLayerType::SceneChange);

			Animator* change = SC->AddComponent<Animator>();
			change->CreateAnimationFolder(L"SceneChange", L"..\\Resources\\Texture\\levelchange\\BMP", Vector2(0.0f, 0.0f));
			change->PlayAnimation(L"SceneChange", false);
			change->SetScale(Vector2(1.0f, 1.0f));

			Transform* tr_SC = SC->GetComponent<Transform>();
			tr_SC->SetPosition(Vector2(640.0f, 360.0f));
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

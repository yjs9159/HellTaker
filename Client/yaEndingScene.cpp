#include "yaEndingScene.h"
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
//#include "yaRock.h"

namespace ya
{
	EndingScene::EndingScene()
	{
	}
	EndingScene::~EndingScene()
	{
	}

	void EndingScene::Initialize()
	{
		Texture* chapter2 = Resources::Load<Texture>(L"chapter2"
			, L"..\\Resources\\Image\\Sprite\\Map\\chapterBG0002.bmp");


		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(chapter2);
		bgsr->SetScale(Vector2(0.7f, 0.7f));
		bgsr->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);
		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));

		Player* player = object::Instantiate<Player>(eLayerType::Player);
		Transform* tr = player->GetComponent<Transform>();

		tr->SetPosition(Vector2(640.0f, 360.0f));

		Animator* at = player->AddComponent<Animator>();
		at->CreateAnimationFolder(L"player_rightidle", L"..\\Resources\\Texture\\player\\player_idle\\right_idle", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"player_leftidle", L"..\\Resources\\Texture\\player\\player_idle\\left_idle", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"player_rightrun", L"..\\Resources\\Texture\\player\\player_run\\right_run", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"player_leftrun", L"..\\Resources\\Texture\\player\\player_run\\left_run", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"player_rightattack", L"..\\Resources\\Texture\\player\\player_attack\\right_attack", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"player_leftattack", L"..\\Resources\\Texture\\player\\player_attack\\left_attack", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"player_rightsuccess", L"..\\Resources\\Texture\\player\\player_success\\right_success", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"player_leftsuccess", L"..\\Resources\\Texture\\player\\player_success\\left_success", Vector2(0.0f, 0.0f));

		at->PlayAnimation(L"player_rightidle", true);
		at->SetAffectedCamera(true);

		Collider* col = player->AddComponent<Collider>();
		col->SetSize(Vector2(100.0f, 110.0f));
		col->SetOffset(Vector2(0.0f, -30.0f));


		//Rock* rock = object::Instantiate<Rock>(eLayerType::Rock);

		//Texture* rock1 = Resources::Load<Texture>(L"rock1"
		//	, L"..\\Resources\\Texture\\obstacle\\rock\\Rock001.png");

		//Animator* Rock_at = rock->AddComponent<Animator>();
		//Rock_at->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\rock\\right_idle", Vector2(0.0f, 0.0f));
		//Rock_at->PlayAnimation(L"Monster_RightIdle", true);



		Monster* monster = object::Instantiate<Monster>(eLayerType::Monster);

		Animator* rock = monster->AddComponent<Animator>();
		rock->CreateAnimationFolder(L"Rock1", L"..\\Resources\\Texture\\obstacle\\rock", Vector2(0.0f, 0.0f));
		rock->PlayAnimation(L"Rock1", true);

		col = monster->AddComponent<Collider>();
		col->SetSize(Vector2(90.0f, 90.0f));
		//col->SetOffset(Vector2(10.0f, 10.0f));
		tr = monster->GetComponent<Transform>();

		tr->SetPosition(Vector2(800.0f, 360.0f));

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
	}

	void EndingScene::Update()
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
	}
	void EndingScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}

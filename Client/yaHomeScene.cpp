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

namespace ya
{
	HomeScene::HomeScene()
	{
	}
	HomeScene::~HomeScene()
	{
	}

	void HomeScene::Initialize()
	{
		Texture* chapter1 = Resources::Load<Texture>(L"chapter1"
			, L"..\\Resources\\Image\\Sprite\\Map\\chapterBG0001.bmp");


		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(chapter1);
		bgsr->SetScale(Vector2(0.7f, 0.7f));
		bgsr->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);
		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));

		Texture* image = Resources::Load<Texture>(L"Hero"
			, L"..\\Resources\\Image\\Sprite\\HeroSprite\\Hero.bmp");

		Player* player = object::Instantiate<Player>(eLayerType::Player);
		Transform* tr = player->GetComponent<Transform>();

		tr->SetPosition(Vector2(640.0f, 360.0f));

		image = Resources::Load<Texture>(L"PlayerImage"
			, L"..\\Resources\\Image\\Sprite\\Player");

		// ���� 100 ���� 194.4
		Animator* at = player->AddComponent<Animator>();
		//at->CreateAnimation(L"HeroIdle", image, Vector2(0.0f, 0.0f), Vector2(100.0f, 194.4f), 12);
		//at->CreateAnimation(L"HeroRight", image, Vector2(0.0f, 388.8f), Vector2(100.0f, 194.4f), 6);
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
	}
	void HomeScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}

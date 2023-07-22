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
		Texture* image = Resources::Load<Texture>(L"Hero"
			, L"..\\Resources\\Image\\Sprite\\HeroSprite\\Hero.bmp");

		Player* player = object::Instantiate<Player>(eLayerType::Player);
		Transform* tr = player->GetComponent<Transform>();

		tr->SetPosition(Vector2(640.0f, 360.0f));

		image = Resources::Load<Texture>(L"Smile"
			, L"..\\Resources\\Image\\Sprite\\Player");

		// 가로 100 세로 194.4
		Animator* at = player->AddComponent<Animator>();
		at->CreateAnimation(L"HeroIdle", image, Vector2(0.0f, 0.0f), Vector2(100.0f, 194.4f), 12);
		at->CreateAnimation(L"HeroRight", image, Vector2(0.0f, 388.8f), Vector2(100.0f, 194.4f), 6);
		at->CreateAnimationFolder(L"player_idle", L"..\\Resources\\Texture\\player\\player_idle", Vector2(0.0f, 100.0f));
		at->CreateAnimationFolder(L"player_run", L"..\\Resources\\Texture\\player\\player_run", Vector2(0.0f, 100.0f));
		at->PlayAnimation(L"player_idle", true);
		at->SetAffectedCamera(true);

		at->SetScale(Vector2(2.0f, 2.0f));
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

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
		//SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		//sr->SetImage(image);

		// 가로 100 세로 194.4
		Animator* at = player->AddComponent<Animator>();
		at->CreateAnimation(L"HeroIdle", image, Vector2(0.0f, 0.0f), Vector2(100.0f, 194.4f)
			, Vector2(0.0f, 0.0f), 12, 0.1f);
		at->CreateAnimation(L"HeroRightMove", image, Vector2(0.0f, 388.8f), Vector2(100.0f, 194.4f)
			, Vector2(0.0f, 0.0f), 6, 0.1f);
		at->CreateAnimation(L"HeroRightKick", image, Vector2(0.0f, 388.8f), Vector2(100.0f, 194.4f)
			, Vector2(0.0f, 0.0f), 6, 0.1f);
		at->PlayAnimation(L"HeroIdle", true);
		at->SetAffectedCamera(true);


		Camera::SetTarget(player);
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

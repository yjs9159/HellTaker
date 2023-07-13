#include "yaHomeScene.h"
#include "yaPlayer.h"
#include "yaSpriteRenderer.h"
#include "yaObject.h"
#include "yaInput.h"

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
		Player* player = Object::Instantiate<Player>(eLayerType::Player);
		player->AddComponent<SpriteRenderer>();

		// mLayers[(int)eLayerType::Player].AddGameObject(player);
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


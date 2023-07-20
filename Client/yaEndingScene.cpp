#include "yaEndingScene.h"
#include "yaPlayer.h"
#include "yaSpriteRenderer.h"
#include "yaObject.h"
#include "yaInput.h"


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
		Player* player = object::Instantiate<Player>(eLayerType::Player);
		player->AddComponent<SpriteRenderer>();

		//mLayers[(int)eLayerType::Player].AddGameObject(player);
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

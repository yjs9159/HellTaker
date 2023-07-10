#include "yaTitleScene.h"
#include "yaPlayer.h"
#include "yaSpriteRenderer.h"
#include "yaObject.h"

namespace ya
{
	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		Player* player = Object::Instantiate<Player>(eLayerType::Player);
		player->AddComponent<SpriteRenderer>();

		// mLayers[(int)eLayerType::Player].AddGameObject(player);
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

}

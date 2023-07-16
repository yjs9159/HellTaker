#include "yaTitleScene.h"
#include "yaPlayer.h"
#include "yaSpriteRenderer.h"
#include "yaObject.h"
#include "yaInput.h"
#include "yaTexture.h"
#include "yaResources.h"
#include "yaBackGround.h"


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
		Texture* image = Resources::Load<Texture>(L"TitleBackGroundImage"
						, L"..\\Resources\\Image\\Home.png");
		
		//Player* player = Object::Instantiate<Player>(eLayerType::Player);
		//SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		//sr->SetImage(image);

		BackGround* bg = Object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(image);
		bgsr->SetScale(Vector2(0.75f, 0.75f));

		image = Resources::Load<Texture>(L"Smile"
			, L"..\\Resources\\Image\\Smile.png");

		Player* player = Object::Instantiate<Player>(eLayerType::Player);
		SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		sr->SetImage(image);
		sr->SetScale(Vector2(0.2f, 0.2f));

		// std::wstring name = player->GetName();

		// mLayers[(int)eLayerType::Player].AddGameObject(player);
	}

	void TitleScene::Update()
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

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

}

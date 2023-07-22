#include "yaTitleScene.h"
#include "yaPlayer.h"
#include "yaSpriteRenderer.h"
#include "yaObject.h"
#include "yaInput.h"
#include "yaTexture.h"
#include "yaTransform.h"
#include "yaResources.h"
#include "yaBackGround.h"
#include "yaCamera.h"

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
		//Texture* image = Resources::Load<Texture>(L"TitleBackGroundImage"
		//	, L"..\\Resources\\Image\\Sprite\\Map\\chapterBG0001.bmp");


		//BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		//SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		//bgsr->SetImage(image);
		//bgsr->SetScale(Vector2(0.7f, 0.7f));
		//bgsr->SetAffectCamera(false);
		////bgsr->SetAlpha(0.2f);
		//bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));

		// 이미지 회전
		Texture* image = Resources::Load<Texture>(L"TitleBackGroundImgae"
			, L"..\\Resources\\Texture\\Bulidings\\coop.png");

		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		bg->GetComponent<Transform>()->SetPosition(Vector2(600.0f, 320.0f));
		bg->GetComponent<Transform>()->SetRotation(45);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(image);
		bgsr->SetAffectCamera(false);


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

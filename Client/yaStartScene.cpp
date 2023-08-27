#include "yaStartScene.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaSceneChange.h"
#include "yaObject.h"
#include "yaTransform.h"
#include "yaAnimator.h"

namespace ya
{
	StartScene::StartScene()
	{
	}
	StartScene::~StartScene()
	{
	}
	void StartScene::Initialize()
	{
		// Start CutScene 애니메이션 로드
		SceneChange* Ending = object::Instantiate<SceneChange>(eLayerType::SceneChange);

		Transform* tr_Ending = Ending->GetComponent<Transform>();
		tr_Ending->SetPosition(Vector2(640.0f, 360.0f));

		Animator* at_Ending = Ending->AddComponent<Animator>();
		at_Ending->CreateAnimationFolder(L"Start", L"..\\Resources\\Texture\\Cut_Start", Vector2(0.0f, 0.0f), 2.0f);
		at_Ending->PlayAnimation(L"Start", false);
		at_Ending->SetScale(Vector2(1.0f, 1.1f));
	}
	void StartScene::Update()
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
	void StartScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
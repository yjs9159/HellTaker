#include "yaSceneManager.h"
#include "yaTitleScene.h"
#include "yaHomeScene.h"
#include "yaEndingScene.h"
#include "yaToolScene.h"
#include "yaChapter1.h"
#include "yaChapter2.h"
#include "yaChapter3.h"
#include "yaChapter4.h"
#include "yaChapter5.h"
#include "yaChapter6.h"
#include "yaChapter7.h"
#include "yaChapter8.h"


namespace ya
{
	std::map<std::wstring, Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		CreateScene<TitleScene>(L"TitleScene");
		CreateScene<HomeScene>(L"HomeScene");
		CreateScene<EndingScene>(L"EndingScene");
		CreateScene<ToolScene>(L"ToolScene");
		CreateScene<Chapter1>(L"Chapter1");
		CreateScene<Chapter2>(L"Chapter2");
		CreateScene<Chapter3>(L"Chapter3");
		CreateScene<Chapter4>(L"Chapter4");
		CreateScene<Chapter5>(L"Chapter5");
		CreateScene<Chapter6>(L"Chapter6");
		CreateScene<Chapter7>(L"Chapter7");
		CreateScene<Chapter8>(L"Chapter8");

		LoadScene(L"TitleScene");
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		std::map<std::wstring, Scene*>::iterator iter
			= mScenes.find(name);

		if (iter == mScenes.end())
			return nullptr;

		mActiveScene = iter->second;
		return iter->second;
	}
}

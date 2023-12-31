#include "yaScene.h"
#include "yaPlayer.h"
#include "yaSpriteRenderer.h"

namespace ya
{
	Scene::Scene()
	{
		mLayers.resize((int)eLayerType::End);
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{

	}
	void Scene::Update()
	{
		//for (size_t i = 0; i < mLayers.size(); i++)
		//{

		//}

		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer& layer : mLayers)
		{
			layer.Render(hdc);
		}
	}
}

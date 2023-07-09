#include "Scene.h"


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
		mLayers[(int)eLayerType::Player].AddGameObject();
	}

	void Scene::Update()
	{
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

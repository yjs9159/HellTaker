#include "yaLayer.h"

namespace ya
{
	Layer::Layer()
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::Initialize()
	{
	}

	void Layer::Update()
	{
		for (GameObject* obj : mGameObjects)
		{
			obj->Update();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (GameObject* obj : mGameObjects)
		{
			obj->Render(hdc);
		}
	}
}
#include "yaBackGround.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"


namespace ya
{
	BackGround::BackGround()
	{
	}

	BackGround::~BackGround()
	{
	}

	void BackGround::Initialize()
	{
	}

	void BackGround::Update()
	{
		GameObject::Update();
	}

	void BackGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

}

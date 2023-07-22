#include "yaBackGround.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaSpriteRenderer.h"


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

		SpriteRenderer* sr = GetComponent<SpriteRenderer>();

		//float alpha = sr->GetAlpha();
		//alpha -= 0.2f * Time::DeltaTime();
		//sr->SetAlpha(alpha);
	}

	void BackGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
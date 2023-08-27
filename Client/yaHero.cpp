#include "yaHero.h"

namespace ya
{
	Hero::Hero()
	{
	}

	Hero::~Hero()
	{
	}

	void Hero::Initialize()
	{

	}

	void Hero::Update()
	{
		GameObject::Update();
	}

	void Hero::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

}

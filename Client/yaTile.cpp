#include "yaTile.h"
#include "yaSpriteRenderer.h"
#include "yaCollider.h"
#include "yaTexture.h"
#include "yaResources.h"

namespace ya
{
	UINT Tile::mSelectedX = 0;
	UINT Tile::mSelectedY = 0;
	


	Tile::Tile()
		:mSpriteRenderer(nullptr)
	{
	}

	Tile::~Tile()
	{
	}

	void Tile::Initialize()
	{
		SpriteRenderer* sr = AddComponent<SpriteRenderer>();
		//AddComponent<Collider>();

		ya::Texture* springFloor
			= ya::Resources::Find<ya::Texture>(L"SprintFloorTile");

		sr->SetImage(springFloor);
		sr->SetTile(1, 0);
		sr->SetScale(Vector2(3.0f, 3.0f));
		//TransparentBlt(hdc
		//	, 0, 0, springFloor->GetWidth(), springFloor->GetHeight()
		//	, springFloor->GetHdc()
		//	, 0, 0, springFloor->GetWidth(), springFloor->GetHeight()
		//	, RGB(255, 0, 255));
	}

	void Tile::Update()
	{
		GameObject::Update();
	}

	void Tile::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

}
#include "yaSpriteRenderer.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaCamera.h"

namespace ya
{
	SpriteRenderer::SpriteRenderer()
		: Component(eComponentType::SpriteRenderer)
		, mScale(Vector2::One)
		, mbAffectCamera(true)
		, mTexture(nullptr)
		, mAlpha(1.0f)
		, mbTile(false)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			return;
		//24 ( 16)  // 25 ( 16)
		if (mbTile)
		{
			GameObject* gameObj = GetOwner();
			Transform* tr = gameObj->GetComponent<Transform>();
			mTexture->Render(hdc
				, tr->GetPosition()
				, Vector2(TILE_WIDTH, TILE_HEIGHT)
				// cut area
				, Vector2(mTileIndexX * TILE_WIDTH
					, mTileIndexY * TILE_HEIGHT)
				, Vector2(TILE_WIDTH, TILE_HEIGHT)
				, Vector2::Zero
				, mScale
				, mAlpha
				, tr->GetRotation());
		}
		else
		{
			GameObject* gameObj = GetOwner();
			Transform* tr = gameObj->GetComponent<Transform>();
			mTexture->Render(hdc
				, tr->GetPosition()
				, Vector2(mTexture->GetWidth(), mTexture->GetHeight())
				, Vector2(0.0f, 0.0f)
				, Vector2(mTexture->GetWidth(), mTexture->GetHeight())
				, Vector2::Zero
				, mScale
				, mAlpha
				, tr->GetRotation());
		}
	}
}

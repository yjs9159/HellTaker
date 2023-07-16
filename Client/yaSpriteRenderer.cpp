#include "yaSpriteRenderer.h"
#include "yaTransform.h"
#include "yaGameObject.h"

namespace ya
{
	SpriteRenderer::SpriteRenderer()
		: Component(eComponentType::Spriterenderer)
		, mScale(Vector2::One)
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

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mTexture->GetType() == eTextureType::Bmp)
		{
			TransparentBlt(hdc, (int)pos.x, (int)pos.y
				, mTexture->GetWidth() * mScale.x, mTexture->GetHeight() * mScale.y
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(), RGB(255, 0, 255));
		}
		else if (mTexture->GetType() == eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage(), (int)pos.x, (int)pos.y
				, (int)(mTexture->GetWidth() * mScale.x)
				, (int)(mTexture->GetHeight() * mScale.y));
		}
	}
}
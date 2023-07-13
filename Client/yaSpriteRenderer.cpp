#include "yaSpriteRenderer.h"
#include "yaTransform.h"
#include "yaGameObject.h"

namespace ya
{
	SpriteRenderer::SpriteRenderer()
		: Component(eComponentType::Spriterenderer)
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
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		TransparentBlt(hdc, (int)pos.x, (int)pos.y
			, mImage->GetWidth(), mImage->GetHeight()
			, mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(255, 0, 255));
	}
}
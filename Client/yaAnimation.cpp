#include "yaAnimation.h"
#include "yaTexture.h"
#include "yaAnimator.h"
#include "yaTime.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaCamera.h"

namespace ya
{
	Animation::Animation()
		: mAnimator(nullptr)
		, mTexture(nullptr)
		, mSpriteSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false)
	{
	}

	Animation::~Animation()
	{
	}

	void Animation::Update()
	{
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();
		if (mSpriteSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;

			if (mIndex < mSpriteSheet.size() - 1)
				mIndex++;
			else
				mbComplete = true;
		}
	}

	void Animation::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			return;

		Transform* tr = mAnimator->GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mAnimator->GetAffectedCamera())
			pos = Camera::CalculatePosition(pos);

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		// 0.0f ~ 1.0f -> 0 ~ 255
		int alpha = (int)(mAnimator->GetAlpha() * 255.0f);
		if (alpha <= 0)
			alpha = 0;
		func.SourceConstantAlpha = alpha; // 0 ~ 255


		AlphaBlend(hdc, (int)pos.x - (mSpriteSheet[mIndex].size.x / 2.0f) + mSpriteSheet[mIndex].offset.x
			, (int)pos.y - (mSpriteSheet[mIndex].size.y / 2.0f) + mSpriteSheet[mIndex].offset.y
			, mSpriteSheet[mIndex].size.x
			, mSpriteSheet[mIndex].size.y
			, mTexture->GetHdc()
			, mSpriteSheet[mIndex].leftTop.x
			, mSpriteSheet[mIndex].leftTop.y
			, mSpriteSheet[mIndex].size.x
			, mSpriteSheet[mIndex].size.y
			, func);
	}

	void Animation::Create(const std::wstring& name, Texture* texture
		, Vector2 leftTop, Vector2 size, Vector2 offset
		, UINT spriteLength, float duration)
	{
		mTexture = texture;

		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};

			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mSpriteSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}

}

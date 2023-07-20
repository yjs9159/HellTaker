#include "yaCamera.h"
#include "yaApplication.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"

extern ya::Application application;

namespace ya
{
	Vector2 Camera::mResolution = Vector2::Zero;
	Vector2 Camera::mLookPosition = Vector2::Zero;
	Vector2 Camera::mDistance = Vector2::Zero;
	GameObject* Camera::mTarget = nullptr;


	void Camera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = mResolution / 2.0f;
	}

	void Camera::Update()
	{
		if (Input::GetKey(eKeyCode::Up))
		{
			mLookPosition.y -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			mLookPosition.x -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mLookPosition.y += 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mLookPosition.x += 300.0f * Time::DeltaTime();
		}


		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}

		mDistance = mLookPosition - (mResolution / 2.0f);
	}
}

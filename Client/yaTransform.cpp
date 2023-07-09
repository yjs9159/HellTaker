#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"

namespace ya
{
	Transform::Transform()
		: Component(eComponentType::Transform)
	{
	}

	Transform::~Transform()
	{
	}

	void Transform::Initialize()
	{
	}

	void Transform::Update()
	{
		if (Input::GetKey(eKeyCode::W))
		{
			mPosition.y -= 300.0f * Time::Deltatime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			mPosition.x -= 300.0f * Time::Deltatime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mPosition.y += 300.0f * Time::Deltatime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mPosition.x += 300.0f * Time::Deltatime();
		}
	}

	void Transform::Render(HDC hdc)
	{
	}
}
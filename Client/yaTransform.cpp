#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"

namespace ya
{
	Transform::Transform()
		: Component(eComponentType::Transform)
		, mRotation(0.0f)
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

	}
	void Transform::Render(HDC hdc)
	{
		//Rectangle(hdc
		//	, mPosition.x, mPosition.y
		//	, mPosition.x + 10, mPosition.y + 10);
	}
}
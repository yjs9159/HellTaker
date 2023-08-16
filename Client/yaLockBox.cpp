#include "yaLockBox.h"

namespace ya
{
	LockBox::LockBox()
		: mState(eState::Idle)
	{
	}

	LockBox::~LockBox()
	{
	}
	void LockBox::Initialize()
	{

	}

	void LockBox::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case LockBox::eState::Idle:
			Idle();
			break;
		case LockBox::eState::Success:
			Success();
			break;
		case LockBox::eState::End:
			break;
		default:
			break;
		}
	}

	void LockBox::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void LockBox::Idle()
	{
	}
	void LockBox::Success()
	{
	}
}
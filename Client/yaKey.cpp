#include "yaKey.h"

namespace ya
{
	Key::Key()
		: mState(eState::Idle)
	{
	}
	Key::~Key()
	{
	}
	void Key::Initialize()
	{
	}
	void Key::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case Key::eState::Idle:
			Idle();
			break;
		case Key::eState::Success:
			Success();
			break;
		case Key::eState::End:
			break;
		default:
			break;
		}

	}
	void Key::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Key::Idle()
	{
	}
	void Key::Success()
	{
	}
}
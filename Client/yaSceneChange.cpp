#include "yaSceneChange.h"

namespace ya
{
	SceneChange::SceneChange()
		: mState(eState::Idle)
	{
	}
	SceneChange::~SceneChange()
	{
	}
	void SceneChange::Initialize()
	{
	}
	void SceneChange::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case SceneChange::eState::Idle:
			Idle();
			break;
		case SceneChange::eState::On:
			On();
			break;
		case SceneChange::eState::End:
			break;
		default:
			break;
		}

	}
	void SceneChange::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void SceneChange::Idle()
	{
	}
	void SceneChange::On()
	{
	}
}
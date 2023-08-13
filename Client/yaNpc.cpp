#include "yaNpc.h"

namespace ya
{
	Npc::Npc()
		: mState(eState::Idle)
	{
	}

	Npc::~Npc()
	{
	}

	void Npc::Initialize()
	{
	}

	void Npc::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case Npc::eState::Idle:
			Idle();
			break;
		case Npc::eState::End:
			break;
		default:
			break;
		}
	}

	void Npc::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Npc::Idle()
	{
	}
}

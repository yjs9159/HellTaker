#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Hero : public GameObject
	{
	public:
		enum class eState
		{
			Idle,
			Move,
			Attack,
			Success,
			Death,
			End,
		};

		Hero();
		virtual ~Hero();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		eState mState;

	};
}


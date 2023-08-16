#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Key : public GameObject
	{
	public:
		enum class eState
		{
			Idle,
			Success,
			End,
		};

		Key();
		virtual ~Key();

		void Initialize() override;
		void Update() override;
		void Render(HDC hdc) override;

		void Idle();
		void Success();

	private:
		eState mState;
	};
}


#pragma once
#include "yaGameObject.h"

namespace ya
{
	class LockBox : public GameObject
	{
	public:
		enum class eState
		{
			Idle,
			Success,
			End,
		};

		LockBox();
		virtual ~LockBox();

		void Initialize() override;
		void Update() override;
		void Render(HDC hdc) override;

		void Idle();
		void Success();


	private:
		eState mState;
	};
}


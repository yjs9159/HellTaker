#pragma once
#include "yaGameObject.h"

namespace ya
{
	class SceneChange : public GameObject
	{
	public:
		enum class eState
		{
			Idle,
			Success,
			End,
		};

		SceneChange();
		virtual ~SceneChange();

		void Initialize() override;
		void Update() override;
		void Render(HDC hdc) override;

		void Idle();
		void Success();

	private:
		eState mState;
	};
}


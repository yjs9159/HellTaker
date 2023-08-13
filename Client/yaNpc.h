#pragma once
#include "yaGameObject.h"


namespace ya
{
	class Npc : public GameObject
	{
	public:
		enum class eState
		{
			Idle,
			End,
		};

		Npc();
		virtual ~Npc();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void Idle();

	private:
		eState mState;
	};
}
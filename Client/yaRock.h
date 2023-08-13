#pragma once
#include "yaGameObject.h"


namespace ya
{
	class Rock : public GameObject
	{
	public:
		enum class eState
		{
			Idle,
			Move,
			End,
		};

		Rock();
		~Rock();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void Idle();
		void Hit();
		void Move();

	private:
		eState mState;
		int Hp;
	};
}
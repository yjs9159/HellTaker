#pragma once
#include "yaGameObject.h"


namespace ya
{
	class Player : public GameObject
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

		Player();
		virtual ~Player();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		//virtual void OnCollisionEnter(class Collider* other) override;
		//virtual void OnCollisionStay(class Collider* other) override;
		//virtual void OnCollisionExit(class Collider* other) override;

		void Idle();
		void Move(int _dir);
		void Attack();
		void Dead();
		void Success();
		int Hp;

	private:
		eState mState;
		// Vector2 mPos;
		int dir;
	};
}

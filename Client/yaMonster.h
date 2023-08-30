#pragma once
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaTime.h"
#include "yaObject.h"

namespace ya
{
	class Monster : public GameObject
	{
	public:
		enum class eState
		{
			Idle,
			Hit,
			Move,
			Death,
			End,
		};

		Monster();
		~Monster();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void Idle();
		void Hit(int _dir);
		void Dead();
		void Move();

		//virtual void OnCollisionEnter(class Collider* other);
		//virtual void OnCollisionStay(class Collider* other);
		//virtual void OnCollisionExit(class Collider* other);

	private:
		eState mState;
		int dir;
		bool IsDead;
	};
}
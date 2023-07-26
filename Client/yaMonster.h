#pragma once
#include "yaGameObject.h"


namespace ya
{
	class Monster : public GameObject
	{
	public:
		Monster();
		~Monster();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);
	};
}
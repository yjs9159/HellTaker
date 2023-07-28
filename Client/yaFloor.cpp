#include "yaFloor.h"
#include "yaPlayer.h"
#include "yaCollider.h"
#include "yaRigidbody.h"
#include "yaTransform.h"

namespace ya
{
	Floor::Floor()
	{
	}
	Floor::~Floor()
	{
	}
	void Floor::Initialize()
	{
	}
	void Floor::Update()
	{
		GameObject::Update();
	}
	void Floor::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Floor::OnCollisionEnter(Collider* other)
	{
		Player* player = dynamic_cast<Player*>(other->GetOwner());
		Transform* tr = player->GetComponent<Transform>();
		Rigidbody* rb = player->GetComponent<Rigidbody>();

		float len = fabs(other->GetPosition().y - this->GetComponent<Collider>()->GetPosition().y);
		float scale = fabs(other->GetSize().y / 2.0f + this->GetComponent<Collider>()->GetSize().y / 2.0f);


		if (len < scale)
		{
			Vector2 playerPos = tr->GetPosition();
			playerPos.y -= (scale - len) - 1.0f;
			tr->SetPosition(playerPos);
		}

		rb->SetGround(true);
	}

	void Floor::OnCollisionStay(Collider* other)
	{
	}
	void Floor::OnCollisionExit(Collider* other)
	{
	}
}

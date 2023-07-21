#include "yaPlayer.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaAnimator.h"

namespace ya
{
	Player::Player()
	{
	}
	Player::~Player()
	{
	}
	void Player::Initialize()
	{
	}
	void Player::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* anim = GetComponent<Animator>();


		if (Input::GetKey(eKeyCode::W))
		{
			pos.y -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			

			pos.x -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			pos.y += 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			anim->PlayAnimation(L"player_run", true);

			pos.x += 300.0f * Time::DeltaTime();
		}


		tr->SetPosition(pos);

	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}

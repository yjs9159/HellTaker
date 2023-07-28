#include "yaPlayer.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaAnimator.h"
#include "yaRigidBody.h"


namespace ya
{
	Player::Player()
		: mState(eState::Idle)
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

		switch (mState)
		{
		case ya::Player::eState::Idle:
			Idle();
			break;
		case ya::Player::eState::Move:
			Move();
			break;
		case ya::Player::eState::Attack:
			Attack();
			break;
		case ya::Player::eState::Death:
			Dead();
			break;
		case ya::Player::eState::End:
			break;
		default:
			break;
		}
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Player::OnCollisionEnter(Collider* other)
	{
	}
	void Player::OnCollisionStay(Collider* other)
	{
	}
	void Player::OnCollisionExit(Collider* other)
	{
	}
	void Player::Idle()
	{
		Animator* animator = GetComponent<Animator>();

		if (Input::GetKey(eKeyCode::W))
		{
			animator->PlayAnimation(L"PlayerUpMove", true);
			mState = eState::Move;
		}
		if (Input::GetKey(eKeyCode::A))
		{
			animator->PlayAnimation(L"player_leftrun", true);
			mState = eState::Move;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			animator->PlayAnimation(L"PlayerDownMove", true);
			mState = eState::Move;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			animator->PlayAnimation(L"player_rightrun", true);
			mState = eState::Move;
		}

		if (Input::GetKey(eKeyCode::MouseLeft))
		{
			animator->PlayAnimation(L"player_rightattack", false);
			mState = eState::Attack;
		}

		if (Input::GetKey(eKeyCode::F))
		{
			animator->PlayAnimation(L"player_rightsuccess", false);
			mState = eState::Attack;
		}
	}

	void Player::Move()
	{
		Transform* tr = GetComponent<Transform>();
		// Vector2 pos = tr->GetPosition();
		if (Input::GetKey(eKeyCode::W))
		{
			GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, -200.0f));
			//pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			//pos.x -= 100.0f * Time::DeltaTime();
			GetComponent<Rigidbody>()->AddForce(Vector2(-200.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::S))
		{
			//pos.y += 100.0f * Time::DeltaTime();
			GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, 200.0f));
		}
		if (Input::GetKey(eKeyCode::D))
		{
			//pos.x += 100.0f * Time::DeltaTime();
			GetComponent<Rigidbody>()->AddForce(Vector2(200.0f, 0.0f));
		}
		// tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::W)
			|| Input::GetKeyUp(eKeyCode::S)
			|| Input::GetKeyUp(eKeyCode::D))
		{
			Animator* animator = GetComponent<Animator>();
			animator->PlayAnimation(L"player_rightidle", true);
			mState = eState::Idle;
		}
			
		if (Input::GetKeyUp(eKeyCode::A))
		{
			Animator* animator = GetComponent<Animator>();
				animator->PlayAnimation(L"player_leftidle", true);
				mState = eState::Idle;
		}
	}


	void Player::Attack()
	{
		// 농작물에 물을 주는 로직이 추가가된다.(나한텐 attack)
		Animator* animator = GetComponent<Animator>();

		if (animator->IsActiveAnimationComplete())
		{
			animator->PlayAnimation(L"player_rightidle", true);
			mState = eState::Idle;
		}
	}

	void Player::Success()
	{

		Animator* animator = GetComponent<Animator>();

		if (animator->IsActiveAnimationComplete())
		{
			animator->PlayAnimation(L"player_rightidle", true);
			mState = eState::Idle;
		}
	}

	void Player::Dead()
	{
	}

}

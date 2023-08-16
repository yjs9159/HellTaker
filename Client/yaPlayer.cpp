#include "yaPlayer.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaAnimator.h"
#include "yaRigidBody.h"
#include "yaMonster.h"
#include "yaObject.h"
#include "yaHomeScene.h"

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
	//void Player::OnCollisionEnter(Collider* other)
	//{
	//}
	//void Player::OnCollisionStay(Collider* other)
	//{
	//}
	//void Player::OnCollisionExit(Collider* other)
	//{
	//}
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
		Vector2 pos = tr->GetPosition();
		if (Input::GetKeyUp(eKeyCode::W))
		{
			//Rigidbody* rb = GetComponent<Rigidbody>();
			//Vector2 velocity = rb->GetVelocity();
			//velocity.y -= 500.0f;
			//rb->SetVelocity(velocity);
			//rb->SetGround(false);

			//GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, -200.0f));
			// pos.y -= 100.0f * Time::DeltaTime();
			// pos.y

			tr->SetPosition(Vector2( pos.x, pos.y - MOVE_TILE_HEIGHT));

		}
		if (Input::GetKeyUp(eKeyCode::A))
		{
			tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));
		}
		if (Input::GetKeyUp(eKeyCode::S))
		{
			tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));
		}
		if (Input::GetKeyUp(eKeyCode::D))
		{
			tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));
		}
		//tr->SetPosition(pos);

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
		// Attack ·ÎÁ÷
		Scene* scene = SceneManager::GetActiveScene();
		Layer& layer = scene->GetLayer(eLayerType::Monster);
		GameObject* obj = layer.GetGameObjects().front();
		dynamic_cast<Monster*>(obj)->Hit();

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

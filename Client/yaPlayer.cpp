#include "yaPlayer.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaAnimator.h"
#include "yaRigidBody.h"
#include "yaMonster.h"
#include "yaObject.h"
#include "yaSound.h"
#include "yaResources.h"
#include "yaChapter1.h"
#include "yaCollisionManager.h"

namespace ya
{
	Player::Player()
		: mState(eState::Idle)
		, Hp(0)
		, dir(0)
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
		case Player::eState::Idle:
			Idle();
			break;
		case Player::eState::Move:
			Move();
			break;
		case Player::eState::Attack:
			Attack();
			break;
		case Player::eState::Success:
			Success();
			break;
		case Player::eState::Death:
			Dead();
			break;
		case Player::eState::End:
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

		if (Input::GetKeyDown(eKeyCode::W))
		{
			animator->PlayAnimation(L"PlayerUpMove", true);
			mState = eState::Move;
			dir = 0;
		}
		if (Input::GetKeyDown(eKeyCode::A))
		{
			animator->PlayAnimation(L"player_leftrun", true);
			mState = eState::Move;
			dir = 2;
		}
		if (Input::GetKeyDown(eKeyCode::S))
		{
			animator->PlayAnimation(L"PlayerDownMove", true);
			mState = eState::Move;
			dir = 1;
		}
		if (Input::GetKeyDown(eKeyCode::D))
		{
			animator->PlayAnimation(L"player_rightrun", true);
			mState = eState::Move;
			dir = 3;
		}

		if (Input::GetKey(eKeyCode::MouseLeft))
		{
			animator->PlayAnimation(L"player_rightattack", false);
			mState = eState::Attack;
		}

		if (Input::GetKey(eKeyCode::F))
		{
			animator->PlayAnimation(L"player_rightsuccess", false);
			mState = eState::Success;
		}


	}

	void Player::Move()
	{
		Sound* sound = Resources::Load<Sound>(L"Move", L"..\\Resources\\Sound\\character_move_01.wav");

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();


		if (dir == 0 && Input::GetKeyUp(eKeyCode::W))
		{
			//Rigidbody* rb = GetComponent<Rigidbody>();
			//Vector2 velocity = rb->GetVelocity();
			//velocity.y -= 500.0f;
			//rb->SetVelocity(velocity);
			//rb->SetGround(false);

			//GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, -200.0f));
			// pos.y -= 100.0f * Time::DeltaTime();
			// pos.y

			tr->SetPosition(Vector2(pos.x, pos.y - MOVE_TILE_HEIGHT));
			sound->Play(false);
		}
		else if (dir == 2 && Input::GetKeyUp(eKeyCode::A))
		{
			tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));
			sound->Play(false);
		}
		else if (dir == 1 && Input::GetKeyUp(eKeyCode::S))
		{
			tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));
			sound->Play(false);
		}
		else if (dir == 3 && Input::GetKeyUp(eKeyCode::D))
		{
			tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));
			sound->Play(false);
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
		std::wstring Now = scene->GetName();
		
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Now == L"Chapter1")
		{
			static_cast<Chapter1*>(scene)->MapInfo1 ;
			
			
		}


		//Layer& layer = scene->GetLayer(eLayerType::Monster);
		//GameObject* obj = layer.GetGameObjects().front();
		//dynamic_cast<Monster*>(obj)->Hit(/*dir*/);



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

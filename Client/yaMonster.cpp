#include "yaMonster.h"
#include "yaAnimator.h"
#include "yaTransform.h"
#include "yaTime.h"
#include "yaInput.h"

namespace ya
{
	ya::Monster::Monster()
		: Hp(10000)
		, mState(eState::Idle)
	{
	}
	Monster::~Monster()
	{
	}
	void Monster::Initialize()
	{
	}
	void Monster::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case ya::Monster::eState::Idle:
			Idle();
			break;
		case ya::Monster::eState::Move:
			Move();
			break;
		case ya::Monster::eState::Death:
			Dead();
			break;
		case ya::Monster::eState::End:
			break;
		default:
			break;
		}
	}
	void Monster::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Monster::Idle()
	{
		
		if (Hp > 0)
		{
			//Move();
			mState = eState::Move;
		}

		if (Hp <= 0)
		{
			//Dead();
			mState = eState::Death;
		}
	}

	void Monster::Hit()
	{
		Hp--;
		
	}

	void Monster::Move()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Animator* animator = GetComponent<Animator>();
		//animator->PlayAnimation(L"Monster_RightIdle", true);

		if (Input::GetKeyDown(eKeyCode::MouseLeft))
		{
			//Move();
			pos.x += 3000.0f * Time::DeltaTime();
			Animator* animator = GetComponent<Animator>();
			animator->PlayAnimation(L"Monster_RightMove", false);
			mState = eState::Move;
		}
		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::MouseLeft))
		{
			Animator* animator = GetComponent<Animator>();
			animator->PlayAnimation(L"Monster_RightIdle", true);
			mState = eState::Idle;
		}
		

		if (animator->IsActiveAnimationComplete())
		{
			animator->PlayAnimation(L"Monster_RightIdle", true);
			mState = eState::Idle;
		}
	}

	void Monster::Dead()
	{
		/*Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.x -= 100.0f * Time::DeltaTime();

		Animator* at = GetComponent<Animator>();
		at->CreateAnimationFolder(L"Monster_Move", L"..\\Resources\\Texture\\obstacle\\undead_move\\Right_Move", Vector2(0.0f, 0.0f));
		at->PlayAnimation(L"Monster_Move", true);
		
		if (at->IsActiveAnimationComplete())
		{
			at->PlayAnimation(L"Monster_RightIdle", true);
			mState = eState::Idle;
		}*/
	}

	//void Monster::OnCollisionEnter(Collider* other)
	//{
	//}
	//void Monster::OnCollisionStay(Collider* other)
	//{
	//}
	//void Monster::OnCollisionExit(Collider* other)
	//{
	//}
}

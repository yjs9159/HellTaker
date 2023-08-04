//#include "yaRock.h"
//#include "yaAnimator.h"
//#include "yaTransform.h"
//#include "yaTime.h"
//#include "yaInput.h"
//
//namespace ya
//{
//	ya::Rock::Rock()
//		: Hp(2)
//		, mState(eState::Idle)
//	{
//	}
//	Rock::~Rock()
//	{
//	}
//	void Rock::Initialize()
//	{
//	}
//	void Rock::Update()
//	{
//		GameObject::Update();
//
//		switch (mState)
//		{
//		case ya::Rock::eState::Idle:
//			Idle();
//			break;
//		case ya::Rock::eState::Move:
//			Move();
//			break;
//		case ya::Rock::eState::Death:
//			Dead();
//			break;
//		case ya::Rock::eState::End:
//			break;
//		default:
//			break;
//		}
//	}
//	void Rock::Render(HDC hdc)
//	{
//		GameObject::Render(hdc);
//	}
//
//	void Rock::Idle()
//	{
//		
//		if (Hp > 0)
//		{
//			//Move();
//			mState = eState::Move;
//		}
//
//		else if (Hp <= 0)
//		{
//			//Dead();
//			mState = eState::Death;
//		}
//	}
//
//	void Rock::Hit()
//	{
//		Hp -= 1;
//		
//	}
//
//	void Rock::Move()
//	{
//		Transform* tr = GetComponent<Transform>();
//		Vector2 pos = tr->GetPosition();
//
//		//Animator* animator = GetComponent<Animator>();
//		//animator->PlayAnimation(L"Monster_RightIdle", true);
//
//		if (Input::GetKeyDown(eKeyCode::MouseLeft))
//		{
//			//Move();
//			pos.x += 500.0f * Time::DeltaTime();
//			//Animator* animator = GetComponent<Animator>();
//			//animator->PlayAnimation(L"Monster_RightMove", false);
//			mState = eState::Move;
//		}
//		tr->SetPosition(pos);
//
//		if (Input::GetKeyUp(eKeyCode::MouseLeft))
//		{
//			//Animator* animator = GetComponent<Animator>();
//			//animator->PlayAnimation(L"Monster_RightIdle", true);
//			mState = eState::Idle;
//		}
//		
//
//		//if (animator->IsActiveAnimationComplete())
//		//{
//		//	//animator->PlayAnimation(L"Monster_RightIdle", true);
//		//	mState = eState::Idle;
//		//}
//	}
//
//	void Rock::Dead()
//	{
//	}
//}

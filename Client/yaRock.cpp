#include "yaRock.h"


namespace ya
{
	Rock::Rock()
		: mState(eState::Idle)
	{
	}
	Rock::~Rock()
	{
	}
	void Rock::Initialize()
	{
	}
	void Rock::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case Rock::eState::Idle:
			Idle();
			break;
		case Rock::eState::Hit:
			Hit();
			break;
		case Rock::eState::End:
			break;
		default:
			break;
		}
	}
	void Rock::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Rock::Idle()
	{
		
	}

	void Rock::Hit()
	{
	//	Transform* tr = GetComponent<Transform>();
	//	Vector2 pos = tr->GetPosition();

	//	if (Input::GetKeyDown(eKeyCode::MouseLeft))
	//	{
	//		//Move();
	//		pos.x += 500.0f * Time::DeltaTime();
	//		//Animator* animator = GetComponent<Animator>();
	//		//animator->PlayAnimation(L"Monster_RightMove", false);
	//		mState = eState::Hit;
	//	}
	//	tr->SetPosition(pos);

	//	if (Input::GetKeyUp(eKeyCode::MouseLeft))
	//	{
	//		//Animator* animator = GetComponent<Animator>();
	//		//animator->PlayAnimation(L"Monster_RightIdle", true);
	//		mState = eState::Idle;
	//	}
	}
}

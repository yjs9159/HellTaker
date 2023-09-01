#include "yaNpc.h"
#include "yaAnimator.h"
#include "yaInput.h"
#include "yaSpriteRenderer.h"
#include "yaTime.h"

namespace ya
{
	Npc::Npc()
		: mState(eState::Idle)
	{
	}

	Npc::~Npc()
	{
	}

	void Npc::Initialize()
	{
	}

	void Npc::Update()
	{
		GameObject::Update();

		if (Input::GetKeyDown(eKeyCode::F))
		{
			Animator* animator = GetComponent<Animator>();
			//animator->CreateAnimationFolder(L"Plosion", L"..\\Resources\\Texture\\vfx\\lovePlosion_vfx");
			//animator->PlayAnimation(L"Plosion", false);
			//mState = eState::Success;

			//float alpha = animator->GetAlpha();
			//alpha -= 0.2f * Time::DeltaTime();
			//animator->SetAlpha(alpha);
		}

		switch (mState)
		{
		case Npc::eState::Idle:
			Idle();
			break;
		case Npc::eState::Success:
			Success();
			break;
		case Npc::eState::End:
			break;
		default:
			break;
		}
	}

	void Npc::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Npc::Idle()
	{

		//if (Input::GetKeyUp(eKeyCode::F))
		//{
		//	Animator* animator = GetComponent<Animator>();
		//	//animator->CreateAnimationFolder(L"Plosion", L"..\\Resources\\Texture\\vfx\\lovePlosion_vfx");
		//	//animator->PlayAnimation(L"Plosion", false);
		//	//mState = eState::Success;

		//	float alpha = animator->GetAlpha();
		//	alpha -= 0.2f * Time::DeltaTime();
		//	animator->SetAlpha(alpha);
		//}
	}

	void Npc::Success()
	{
		//Animator* animator = GetComponent<Animator>();

		//if (animator->IsActiveAnimationComplete())
		//{
		//	animator->PlayAnimation(L"pandemonica", true);
		//	mState = eState::Idle;
		//}
	}
}

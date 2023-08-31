#include "yaMonster.h"
#include "yaAnimator.h"
#include "yaTransform.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaPlayer.h"
#include "yaChapter1.h"
#include "yaChapter2.h"
#include "yaChapter3.h"
#include "yaChapter4.h"
#include "yaChapter5.h"
#include "yaChapter6.h"
#include "yaChapter7.h"
#include "yaChapter8.h"

namespace ya
{
	Monster::Monster()
		: mState(eState::Idle)
		, dir(100)
		, IsDead(false)
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
		case Monster::eState::Idle:
			Idle();
			break;
		case Monster::eState::Hit:
			Hit(dir);
			break;
		case Monster::eState::Death:
			Dead();
			break;
		case Monster::eState::End:
			break;
		default:
			break;
		}

		if (IsDead/* && GetComponent<Animator>()->IsActiveAnimationComplete()*/)
		{
			Destroy(this);
		}
	}

	void Monster::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Monster::Idle()
	{
		Animator* at = GetComponent<Animator>();

		if (at->IsActiveAnimationComplete())
		{
			at->PlayAnimation(L"Monster_Idle", true);
		}
	}

	void Monster::Hit(int _dir)
	{
		dir = _dir;

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Animator* at = GetComponent<Animator>();
		at->CreateAnimationFolder(L"Monster_RightMove", L"..\\Resources\\Texture\\obstacle\\undead_move\\Right_Move", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"Monster_LeftMove", L"..\\Resources\\Texture\\obstacle\\undead_move\\Left_Move", Vector2(0.0f, 0.0f));

		Scene* scene = SceneManager::GetActiveScene();

		if (Chapter1* chpt1 = dynamic_cast<Chapter1*>(scene))
		{
			int MonsterY = int(pos.y - chpt1->LeftTop.y) / MOVE_TILE_HEIGHT;
			int MonsterX = int(pos.x - chpt1->LeftTop.x) / MOVE_TILE_WIDTH;
			int ObjectInfo;

			switch (_dir)
			{
			case 0:
				ObjectInfo = chpt1->MapInfo1[MonsterY - 1][MonsterX];
				break;
			case 1:
				ObjectInfo = chpt1->MapInfo1[MonsterY + 1][MonsterX];
				break;
			case 2:
				ObjectInfo = chpt1->MapInfo1[MonsterY][MonsterX - 1];
				break;
			case 3:
				ObjectInfo = chpt1->MapInfo1[MonsterY][MonsterX + 1];
				break;
			default:
				break;
			}

			if (ObjectInfo == 0)
			{
				Move();
			}

			else
			{
				mState = eState::Death;
				IsDead = true;

				//Animator* at = GetComponent<Animator>();
				//at->CreateAnimationFolder(L"Monster_Move", L"..\\Resources\\Texture\\obstacle\\undead_move\\Right_Move", Vector2(0.0f, 0.0f));
				//at->PlayAnimation(L"Monster_Move", false);

				Dead();
			}
		}

		if (Chapter2* chpt2 = dynamic_cast<Chapter2*>(scene))
		{
			int MonsterY = int(pos.y - chpt2->LeftTop.y) / MOVE_TILE_HEIGHT;
			int MonsterX = int(pos.x - chpt2->LeftTop.x) / MOVE_TILE_WIDTH;
			int ObjectInfo;

			switch (_dir)
			{
			case 0:
				ObjectInfo = chpt2->MapInfo2[MonsterY - 1][MonsterX];
				break;
			case 1:
				ObjectInfo = chpt2->MapInfo2[MonsterY + 1][MonsterX];
				break;
			case 2:
				ObjectInfo = chpt2->MapInfo2[MonsterY][MonsterX - 1];
				break;
			case 3:
				ObjectInfo = chpt2->MapInfo2[MonsterY][MonsterX + 1];
				break;
			default:
				break;
			}

			if (ObjectInfo == 0)
			{
				Move();
			}

			else
			{
				mState = eState::Death;
				IsDead = true;

				//Animator* at = GetComponent<Animator>();
				//at->CreateAnimationFolder(L"Monster_Move", L"..\\Resources\\Texture\\obstacle\\undead_move\\Right_Move", Vector2(0.0f, 0.0f));
				//at->PlayAnimation(L"Monster_Move", false);

				Dead();
			}
		}

		if (Chapter3* chpt3 = dynamic_cast<Chapter3*>(scene))
		{
			int MonsterY = int(pos.y - chpt3->LeftTop.y) / MOVE_TILE_HEIGHT;
			int MonsterX = int(pos.x - chpt3->LeftTop.x) / MOVE_TILE_WIDTH;
			int ObjectInfo;

			switch (_dir)
			{
			case 0:
				ObjectInfo = chpt3->MapInfo3[MonsterY - 1][MonsterX];
				break;
			case 1:
				ObjectInfo = chpt3->MapInfo3[MonsterY + 1][MonsterX];
				break;
			case 2:
				ObjectInfo = chpt3->MapInfo3[MonsterY][MonsterX - 1];
				break;
			case 3:
				ObjectInfo = chpt3->MapInfo3[MonsterY][MonsterX + 1];
				break;
			default:
				break;
			}

			if (ObjectInfo == 0)
			{
				Move();
			}

			else
			{
				mState = eState::Death;
				IsDead = true;

				//Animator* at = GetComponent<Animator>();
				//at->CreateAnimationFolder(L"Monster_Move", L"..\\Resources\\Texture\\obstacle\\undead_move\\Right_Move", Vector2(0.0f, 0.0f));
				//at->PlayAnimation(L"Monster_Move", false);

				Dead();
			}
		}

		if (Chapter4* chpt4 = dynamic_cast<Chapter4*>(scene))
		{
			int MonsterY = int(pos.y - chpt4->LeftTop.y) / MOVE_TILE_HEIGHT;
			int MonsterX = int(pos.x - chpt4->LeftTop.x) / MOVE_TILE_WIDTH;
			int ObjectInfo;

			switch (_dir)
			{
			case 0:
				ObjectInfo = chpt4->MapInfo4[MonsterY - 1][MonsterX];
				break;
			case 1:
				ObjectInfo = chpt4->MapInfo4[MonsterY + 1][MonsterX];
				break;
			case 2:
				ObjectInfo = chpt4->MapInfo4[MonsterY][MonsterX - 1];
				break;
			case 3:
				ObjectInfo = chpt4->MapInfo4[MonsterY][MonsterX + 1];
				break;
			default:
				break;
			}

			if (ObjectInfo == 0)
			{
				Move();
			}

			else
			{
				mState = eState::Death;
				IsDead = true;

				//Animator* at = GetComponent<Animator>();
				//at->CreateAnimationFolder(L"Monster_Move", L"..\\Resources\\Texture\\obstacle\\undead_move\\Right_Move", Vector2(0.0f, 0.0f));
				//at->PlayAnimation(L"Monster_Move", false);

				Dead();
			}
		}

		if (Chapter5* chpt5 = dynamic_cast<Chapter5*>(scene))
		{
			int MonsterY = int(pos.y - chpt5->LeftTop.y) / MOVE_TILE_HEIGHT;
			int MonsterX = int(pos.x - chpt5->LeftTop.x) / MOVE_TILE_WIDTH;
			int ObjectInfo;

			switch (_dir)
			{
			case 0:
				ObjectInfo = chpt5->MapInfo5[MonsterY - 1][MonsterX];
				break;
			case 1:
				ObjectInfo = chpt5->MapInfo5[MonsterY + 1][MonsterX];
				break;
			case 2:
				ObjectInfo = chpt5->MapInfo5[MonsterY][MonsterX - 1];
				break;
			case 3:
				ObjectInfo = chpt5->MapInfo5[MonsterY][MonsterX + 1];
				break;
			default:
				break;
			}

			if (ObjectInfo == 0)
			{
				Move();
			}

			else
			{
				mState = eState::Death;
				IsDead = true;

				//Animator* at = GetComponent<Animator>();
				//at->CreateAnimationFolder(L"Monster_Move", L"..\\Resources\\Texture\\obstacle\\undead_move\\Right_Move", Vector2(0.0f, 0.0f));
				//at->PlayAnimation(L"Monster_Move", false);

				Dead();
			}
		}
	}

	void Monster::Move()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Animator* at = GetComponent<Animator>();
		at->CreateAnimationFolder(L"Monster_RightMove", L"..\\Resources\\Texture\\obstacle\\undead_move\\Right_Move", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"Monster_LeftMove", L"..\\Resources\\Texture\\obstacle\\undead_move\\Left_Move", Vector2(0.0f, 0.0f));
		at->CreateAnimationFolder(L"Monster_Idle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, 0.0f));

		// 0 => ¹Ù´Ú
		// 1 => wall
		// 2 => player
		// 3 => monster
		// 4 => rock

		Scene* scene = SceneManager::GetActiveScene();

		if (Chapter1* chpt1 = dynamic_cast<Chapter1*>(scene))
		{
			int posY = int(pos.y - chpt1->LeftTop.y) / MOVE_TILE_HEIGHT;
			int posX = int(pos.x - chpt1->LeftTop.x) / MOVE_TILE_WIDTH;

			switch (dir)
			{
			case 0:
				chpt1->MapInfo1[posY - 1][posX] = 3;
				chpt1->MapInfo1[posY][posX] = 0;
				chpt1->pointerMap1[posY - 1][posX] = this;
				chpt1->pointerMap1[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x, pos.y - MOVE_TILE_HEIGHT));
			
				at->PlayAnimation(L"Monster_RightMove", false);
				mState = eState::Idle;

				break;

			case 1:
				chpt1->MapInfo1[posY + 1][posX] = 3;
				chpt1->MapInfo1[posY][posX] = 0;
				chpt1->pointerMap1[posY + 1][posX] = this;
				chpt1->pointerMap1[posY][posX] = nullptr;
			
				tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));

				at->PlayAnimation(L"Monster_RightMove", false);
				mState = eState::Idle;
				break;

			case 2:
				chpt1->MapInfo1[posY][posX - 1] = 3;
				chpt1->MapInfo1[posY][posX] = 0;
				chpt1->pointerMap1[posY][posX - 1] = this;
				chpt1->pointerMap1[posY][posX] = nullptr;
			
				tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));

				at->PlayAnimation(L"Monster_LeftMove", false);
				mState = eState::Idle;
				break;

			case 3:
				chpt1->MapInfo1[posY][posX + 1] = 3;
				chpt1->MapInfo1[posY][posX] = 0;
				chpt1->pointerMap1[posY][posX + 1] = this;
				chpt1->pointerMap1[posY][posX] = nullptr;
			
				tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));

				at->PlayAnimation(L"Monster_RightMove", false);
				mState = eState::Idle;
				break;

			default:
				break;
			}
		}

		if (Chapter2* chpt2 = dynamic_cast<Chapter2*>(scene))
		{
			int posY = int(pos.y - chpt2->LeftTop.y) / MOVE_TILE_HEIGHT;
			int posX = int(pos.x - chpt2->LeftTop.x) / MOVE_TILE_WIDTH;

			switch (dir)
			{
			case 0:
				chpt2->MapInfo2[posY - 1][posX] = 3;
				chpt2->MapInfo2[posY][posX] = 0;
				chpt2->pointerMap2[posY - 1][posX] = this;
				chpt2->pointerMap2[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x, pos.y - MOVE_TILE_HEIGHT));

				at->PlayAnimation(L"Monster_RightMove", false);
				mState = eState::Idle;

				break;

			case 1:
				chpt2->MapInfo2[posY + 1][posX] = 3;
				chpt2->MapInfo2[posY][posX] = 0;
				chpt2->pointerMap2[posY + 1][posX] = this;
				chpt2->pointerMap2[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));

				at->PlayAnimation(L"Monster_RightMove", false);
				mState = eState::Idle;
				break;

			case 2:
				chpt2->MapInfo2[posY][posX - 1] = 3;
				chpt2->MapInfo2[posY][posX] = 0;
				chpt2->pointerMap2[posY][posX - 1] = this;
				chpt2->pointerMap2[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));

				at->PlayAnimation(L"Monster_LeftMove", false);
				mState = eState::Idle;
				break;

			case 3:
				chpt2->MapInfo2[posY][posX + 1] = 3;
				chpt2->MapInfo2[posY][posX] = 0;
				chpt2->pointerMap2[posY][posX + 1] = this;
				chpt2->pointerMap2[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));

				at->PlayAnimation(L"Monster_RightMove", false);
				mState = eState::Idle;
				break;

			default:
				break;
			}
		}

		if (Chapter3* chpt3 = dynamic_cast<Chapter3*>(scene))
		{
			int posY = int(pos.y - chpt3->LeftTop.y) / MOVE_TILE_HEIGHT;
			int posX = int(pos.x - chpt3->LeftTop.x) / MOVE_TILE_WIDTH;

			switch (dir)
			{
			case 0:
				chpt3->MapInfo3[posY - 1][posX] = 3;
				chpt3->MapInfo3[posY][posX] = 0;
				chpt3->pointerMap3[posY - 1][posX] = this;
				chpt3->pointerMap3[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x, pos.y - MOVE_TILE_HEIGHT));

				at->PlayAnimation(L"Monster_RightMove", false);
				mState = eState::Idle;

				break;

			case 1:
				chpt3->MapInfo3[posY + 1][posX] = 3;
				chpt3->MapInfo3[posY][posX] = 0;
				chpt3->pointerMap3[posY + 1][posX] = this;
				chpt3->pointerMap3[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));

				at->PlayAnimation(L"Monster_RightMove", false);
				mState = eState::Idle;
				break;

			case 2:
				chpt3->MapInfo3[posY][posX - 1] = 3;
				chpt3->MapInfo3[posY][posX] = 0;
				chpt3->pointerMap3[posY][posX - 1] = this;
				chpt3->pointerMap3[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));

				at->PlayAnimation(L"Monster_LeftMove", false);
				mState = eState::Idle;
				break;

			case 3:
				chpt3->MapInfo3[posY][posX + 1] = 3;
				chpt3->MapInfo3[posY][posX] = 0;
				chpt3->pointerMap3[posY][posX + 1] = this;
				chpt3->pointerMap3[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));

				at->PlayAnimation(L"Monster_RightMove", false);
				mState = eState::Idle;
				break;

			default:
				break;
			}
		}

		if (Chapter4* chpt4 = dynamic_cast<Chapter4*>(scene))
		{
			int posY = int(pos.y - chpt4->LeftTop.y) / MOVE_TILE_HEIGHT;
			int posX = int(pos.x - chpt4->LeftTop.x) / MOVE_TILE_WIDTH;

			switch (dir)
			{
			case 0:
				chpt4->MapInfo4[posY - 1][posX] = 3;
				chpt4->MapInfo4[posY][posX] = 0;
				chpt4->pointerMap4[posY - 1][posX] = this;
				chpt4->pointerMap4[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x, pos.y - MOVE_TILE_HEIGHT));

				at->PlayAnimation(L"Monster_RightMove", false);
				mState = eState::Idle;

				break;

			case 1:
				chpt4->MapInfo4[posY + 1][posX] = 3;
				chpt4->MapInfo4[posY][posX] = 0;
				chpt4->pointerMap4[posY + 1][posX] = this;
				chpt4->pointerMap4[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));

				at->PlayAnimation(L"Monster_RightMove", false);
				mState = eState::Idle;
				break;

			case 2:
				chpt4->MapInfo4[posY][posX - 1] = 3;
				chpt4->MapInfo4[posY][posX] = 0;
				chpt4->pointerMap4[posY][posX - 1] = this;
				chpt4->pointerMap4[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));

				at->PlayAnimation(L"Monster_LeftMove", false);
				mState = eState::Idle;
				break;

			case 3:
				chpt4->MapInfo4[posY][posX + 1] = 3;
				chpt4->MapInfo4[posY][posX] = 0;
				chpt4->pointerMap4[posY][posX + 1] = this;
				chpt4->pointerMap4[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));

				at->PlayAnimation(L"Monster_RightMove", false);
				mState = eState::Idle;
				break;

			default:
				break;
			}
		}

		if (Chapter5* chpt5 = dynamic_cast<Chapter5*>(scene))
		{
			int posY = int(pos.y - chpt5->LeftTop.y) / MOVE_TILE_HEIGHT;
			int posX = int(pos.x - chpt5->LeftTop.x) / MOVE_TILE_WIDTH;

			switch (dir)
			{
			case 0:
				chpt5->MapInfo5[posY - 1][posX] = 3;
				chpt5->MapInfo5[posY][posX] = 0;
				chpt5->pointerMap5[posY - 1][posX] = this;
				chpt5->pointerMap5[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x, pos.y - MOVE_TILE_HEIGHT));

				at->PlayAnimation(L"Monster_RightMove", false);
				mState = eState::Idle;

				break;

			case 1:
				chpt5->MapInfo5[posY + 1][posX] = 3;
				chpt5->MapInfo5[posY][posX] = 0;
				chpt5->pointerMap5[posY + 1][posX] = this;
				chpt5->pointerMap5[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));

				at->PlayAnimation(L"Monster_RightMove", false);
				mState = eState::Idle;
				break;

			case 2:
				chpt5->MapInfo5[posY][posX - 1] = 3;
				chpt5->MapInfo5[posY][posX] = 0;
				chpt5->pointerMap5[posY][posX - 1] = this;
				chpt5->pointerMap5[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));

				at->PlayAnimation(L"Monster_LeftMove", false);
				mState = eState::Idle;
				break;

			case 3:
				chpt5->MapInfo5[posY][posX + 1] = 3;
				chpt5->MapInfo5[posY][posX] = 0;
				chpt5->pointerMap5[posY][posX + 1] = this;
				chpt5->pointerMap5[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));

				at->PlayAnimation(L"Monster_RightMove", false);
				mState = eState::Idle;
				break;

			default:
				break;
			}
		}
	}

	void Monster::Dead()
	{

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Scene* scene = SceneManager::GetActiveScene();

		if (Chapter1* chpt1 = dynamic_cast<Chapter1*>(scene))
		{
			int posY = int(pos.y - chpt1->LeftTop.y) / MOVE_TILE_HEIGHT;
			int posX = int(pos.x - chpt1->LeftTop.x) / MOVE_TILE_WIDTH;

		
			chpt1->MapInfo1[posY][posX] = 0;
			chpt1->pointerMap1[posY][posX] = nullptr;
		}

		if (Chapter2* chpt2 = dynamic_cast<Chapter2*>(scene))
		{
			int posY = int(pos.y - chpt2->LeftTop.y) / MOVE_TILE_HEIGHT;
			int posX = int(pos.x - chpt2->LeftTop.x) / MOVE_TILE_WIDTH;


			chpt2->MapInfo2[posY][posX] = 0;
			chpt2->pointerMap2[posY][posX] = nullptr;
		}

		if (Chapter3* chpt3 = dynamic_cast<Chapter3*>(scene))
		{
			int posY = int(pos.y - chpt3->LeftTop.y) / MOVE_TILE_HEIGHT;
			int posX = int(pos.x - chpt3->LeftTop.x) / MOVE_TILE_WIDTH;


			chpt3->MapInfo3[posY][posX] = 0;
			chpt3->pointerMap3[posY][posX] = nullptr;
		}

		if (Chapter4* chpt4 = dynamic_cast<Chapter4*>(scene))
		{
			int posY = int(pos.y - chpt4->LeftTop.y) / MOVE_TILE_HEIGHT;
			int posX = int(pos.x - chpt4->LeftTop.x) / MOVE_TILE_WIDTH;


			chpt4->MapInfo4[posY][posX] = 0;
			chpt4->pointerMap4[posY][posX] = nullptr;
		}

		if (Chapter5* chpt5 = dynamic_cast<Chapter5*>(scene))
		{
			int posY = int(pos.y - chpt5->LeftTop.y) / MOVE_TILE_HEIGHT;
			int posX = int(pos.x - chpt5->LeftTop.x) / MOVE_TILE_WIDTH;


			chpt5->MapInfo5[posY][posX] = 0;
			chpt5->pointerMap5[posY][posX] = nullptr;
		}
	}
}

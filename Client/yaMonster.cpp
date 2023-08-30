#include "yaMonster.h"
#include "yaAnimator.h"
#include "yaTransform.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaPlayer.h"
#include "yaChapter1.h"

namespace ya
{
	Monster::Monster()
		: mState(eState::Idle)
		, dir(-1)
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

		if (IsDead && GetComponent<Animator>()->IsActiveAnimationComplete())
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
		
		//if (Hp > 0)
		//{
		//	//Move();
		//	mState = eState::Hit;
		//}

		//if (Hp <= 0)
		//{
		//	//Dead();
		//	mState = eState::Death;
		//}
	}

	void Monster::Hit(int _dir)
	{
		dir = _dir;

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Animator* animator = GetComponent<Animator>();

		Scene* scene = SceneManager::GetActiveScene();

		if (Chapter1* chpt1 = dynamic_cast<Chapter1*>(scene))
		{
			int MonsterY = int(pos.y - chpt1->LeftTop.y) / MOVE_TILE_HEIGHT;
			int MonsterX = int(pos.x - chpt1->LeftTop.x) / MOVE_TILE_WIDTH;
			int ObjectInfo;

			switch (dir)
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

				Animator* at = GetComponent<Animator>();
				at->CreateAnimationFolder(L"Monster_Move", L"..\\Resources\\Texture\\obstacle\\undead_move\\Right_Move", Vector2(0.0f, 0.0f));
				at->PlayAnimation(L"Monster_Move", false);

				Dead();
			}

		}
	}



	void Monster::Move()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Scene* scene = SceneManager::GetActiveScene();
		Chapter1* chpt1 = dynamic_cast<Chapter1*>(scene);

		int posY = int(pos.y - chpt1->LeftTop.y) / MOVE_TILE_HEIGHT;
		int posX = int(pos.x - chpt1->LeftTop.x) / MOVE_TILE_WIDTH;

		switch (dir)
		{
		case 0:
			chpt1->MapInfo1[posY - 1][posX] = 3;
			chpt1->MapInfo1[posY][posX] = 0;
			chpt1->pointerMap[posY - 1][posX] = this;
			chpt1->pointerMap[posY][posX] = nullptr;

			tr->SetPosition(Vector2(pos.x, pos.y - MOVE_TILE_HEIGHT));
			break;

		case 1:
			chpt1->MapInfo1[posY + 1][posX] = 3;
			chpt1->MapInfo1[posY][posX] = 0;
			chpt1->pointerMap[posY + 1][posX] = this;
			chpt1->pointerMap[posY][posX] = nullptr;

			tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));
			break;
		case 2:
			chpt1->MapInfo1[posY][posX - 1] = 3;
			chpt1->MapInfo1[posY][posX] = 0;
			chpt1->pointerMap[posY][posX - 1] = this;
			chpt1->pointerMap[posY][posX] = nullptr;

			tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));
			break;
		case 3:
			chpt1->MapInfo1[posY][posX + 1] = 3;
			chpt1->MapInfo1[posY][posX] = 0;
			chpt1->pointerMap[posY][posX + 1] = this;
			chpt1->pointerMap[posY][posX] = nullptr;

			tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));
			break;

		default:
			break;
		}
	}

	void Monster::Dead()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Scene* scene = SceneManager::GetActiveScene();
		Chapter1* chpt1 = dynamic_cast<Chapter1*>(scene);

		int posY = int(pos.y - chpt1->LeftTop.y) / MOVE_TILE_HEIGHT;
		int posX = int(pos.x - chpt1->LeftTop.x) / MOVE_TILE_WIDTH;

		
		chpt1->MapInfo1[posY][posX] = 0;
		chpt1->pointerMap[posY][posX] = nullptr;

		


		//Animator* at = GetComponent<Animator>();
		//at->CreateAnimationFolder(L"Monster_Move", L"..\\Resources\\Texture\\obstacle\\undead_move\\Right_Move", Vector2(0.0f, 0.0f));
		//at->PlayAnimation(L"Monster_Move", false);
	}


}

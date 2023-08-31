#include "yaRock.h"
#include "yaTransform.h"
#include "yaScene.h"
#include "yaSceneManager.h"
#include "yaChapter1.h"
#include "yaChapter2.h"

namespace ya
{
	Rock::Rock()
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
	}

	void Rock::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	// 0 => ¹Ù´Ú
// 1 => wall
// 2 => player
// 3 => monster
// 4 => rock
	void Rock::RockHit(int _dir)
	{
		dir = _dir;

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Scene* scene = SceneManager::GetActiveScene();

		if (Chapter1* chpt1 = dynamic_cast<Chapter1*>(scene))
		{
			int MonsterY = int(pos.y - chpt1->LeftTop.y) / MOVE_TILE_HEIGHT;
			int MonsterX = int(pos.x - chpt1->LeftTop.x) / MOVE_TILE_WIDTH;
			chpt1->pointerMap1[MonsterY - 1][MonsterX];

			switch (_dir)
			{
			case 0:
				if (chpt1->MapInfo1[MonsterY - 1][MonsterX] == 0)
					RockMove();
				break;

			case 1:
				if (chpt1->MapInfo1[MonsterY + 1][MonsterX] == 0)
					RockMove();
				break;

			case 2:
				if (chpt1->MapInfo1[MonsterY][MonsterX - 1] == 0)
					RockMove();
				break;

			case 3:
				if (chpt1->MapInfo1[MonsterY][MonsterX + 1] == 0)
					RockMove();
				break;

			default:
				break;
			}
		}

		if (Chapter2* chpt2 = dynamic_cast<Chapter2*>(scene))
		{
			int MonsterY = int(pos.y - chpt2->LeftTop.y) / MOVE_TILE_HEIGHT;
			int MonsterX = int(pos.x - chpt2->LeftTop.x) / MOVE_TILE_WIDTH;
			chpt2->pointerMap2[MonsterY - 1][MonsterX];

			switch (_dir)
			{
			case 0:
				if (chpt2->MapInfo2[MonsterY - 1][MonsterX] == 0)
					RockMove();
				break;

			case 1:
				if (chpt2->MapInfo2[MonsterY + 1][MonsterX] == 0)
					RockMove();
				break;

			case 2:
				if (chpt2->MapInfo2[MonsterY][MonsterX - 1] == 0)
					RockMove();
				break;

			case 3:
				if (chpt2->MapInfo2[MonsterY][MonsterX + 1] == 0)
					RockMove();
				break;

			default:
				break;
			}
		}

	}

	void Rock::RockMove()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Scene* scene = SceneManager::GetActiveScene();

		if (Chapter1* chpt1 = dynamic_cast<Chapter1*>(scene))
		{
			int posY = int(pos.y - chpt1->LeftTop.y) / MOVE_TILE_HEIGHT;
			int posX = int(pos.x - chpt1->LeftTop.x) / MOVE_TILE_WIDTH;

			switch (dir)
			{
			case 0:
				chpt1->MapInfo1[posY - 1][posX] = 4;
				chpt1->MapInfo1[posY][posX] = 0;
				chpt1->pointerMap1[posY - 1][posX] = this;
				chpt1->pointerMap1[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x, pos.y - MOVE_TILE_HEIGHT));
				break;

			case 1:
				chpt1->MapInfo1[posY + 1][posX] = 4;
				chpt1->MapInfo1[posY][posX] = 0;
				chpt1->pointerMap1[posY + 1][posX] = this;
				chpt1->pointerMap1[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));
				break;
			case 2:
				chpt1->MapInfo1[posY][posX - 1] = 4;
				chpt1->MapInfo1[posY][posX] = 0;
				chpt1->pointerMap1[posY][posX - 1] = this;
				chpt1->pointerMap1[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));
				break;
			case 3:
				chpt1->MapInfo1[posY][posX + 1] = 4;
				chpt1->MapInfo1[posY][posX] = 0;
				chpt1->pointerMap1[posY][posX + 1] = this;
				chpt1->pointerMap1[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));
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
				chpt2->MapInfo2[posY - 1][posX] = 4;
				chpt2->MapInfo2[posY][posX] = 0;
				chpt2->pointerMap2[posY - 1][posX] = this;
				chpt2->pointerMap2[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x, pos.y - MOVE_TILE_HEIGHT));
				break;

			case 1:
				chpt2->MapInfo2[posY + 1][posX] = 4;
				chpt2->MapInfo2[posY][posX] = 0;
				chpt2->pointerMap2[posY + 1][posX] = this;
				chpt2->pointerMap2[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));
				break;
			case 2:
				chpt2->MapInfo2[posY][posX - 1] = 4;
				chpt2->MapInfo2[posY][posX] = 0;
				chpt2->pointerMap2[posY][posX - 1] = this;
				chpt2->pointerMap2[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));
				break;
			case 3:
				chpt2->MapInfo2[posY][posX + 1] = 4;
				chpt2->MapInfo2[posY][posX] = 0;
				chpt2->pointerMap2[posY][posX + 1] = this;
				chpt2->pointerMap2[posY][posX] = nullptr;

				tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));
				break;

			default:
				break;
			}
		}
	}
}

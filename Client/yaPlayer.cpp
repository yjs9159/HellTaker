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
#include "yaRock.h"
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
			Move(dir);
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

	void Player::Idle()
	{
		Animator* animator = GetComponent<Animator>();

		if (Input::GetKeyDown(eKeyCode::W))
		{
			Hp--;
			animator->PlayAnimation(L"PlayerUpMove", true);
			mState = eState::Move;
			dir = 0;
		}
		if (Input::GetKeyDown(eKeyCode::A))
		{
			Hp--;
			animator->PlayAnimation(L"player_leftrun", true);
			mState = eState::Move;
			dir = 2;
		}
		if (Input::GetKeyDown(eKeyCode::S))
		{
			Hp--;
			animator->PlayAnimation(L"PlayerDownMove", true);
			mState = eState::Move;
			dir = 1;
		}
		if (Input::GetKeyDown(eKeyCode::D))
		{
			Hp--;
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

	void Player::Move(int _dir)
	{
		dir = _dir;
		Sound* sound = Resources::Load<Sound>(L"Move", L"..\\Resources\\Sound\\character_move_01.wav");

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Animator* at = GetComponent<Animator>();
		at->CreateAnimationFolder(L"Player_Right_Attack", L"..\\Resources\\Texture\\player\\player_attack\\right_attack");
		at->CreateAnimationFolder(L"Player_Left_Attack", L"..\\Resources\\Texture\\player\\player_attack\\left_attack");
		at->CreateAnimationFolder(L"Player_Idle", L"..\\Resources\\Texture\\player\\player_Idle\\right_Idle");

		// 0 => 바닥
		// 1 => wall
		// 2 => player
		// 3 => monster
		// 4 => rock

		if (_dir == 0 && Input::GetKeyUp(eKeyCode::W))
		{
			Scene* scene = SceneManager::GetActiveScene();

			if (Chapter1* chpt1 = dynamic_cast<Chapter1*>(scene))
			{
				int PlayerY = int(pos.y - chpt1->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt1->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt1->MapInfo1[PlayerY - 1][PlayerX])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x, pos.y - MOVE_TILE_HEIGHT));
					chpt1->pointerMap1[PlayerY][PlayerX] = nullptr;
					chpt1->pointerMap1[PlayerY - 1][PlayerX] = this;

					chpt1->MapInfo1[PlayerY][PlayerX] = 0;
					chpt1->MapInfo1[PlayerY - 1][PlayerX] = 2;

					break; 
				case 1:
					Hp++;
					return;
				case 3:
					static_cast<Monster*>(chpt1->pointerMap1[PlayerY - 1][PlayerX])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt1->pointerMap1[PlayerY - 1][PlayerX])->RockHit(_dir);
					break;
				default:
					break;
				}				
			}

			if (Chapter2* chpt2 = dynamic_cast<Chapter2*>(scene))
			{
				int PlayerY = int(pos.y - chpt2->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt2->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt2->MapInfo2[PlayerY - 1][PlayerX])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x, pos.y - MOVE_TILE_HEIGHT));
					chpt2->pointerMap2[PlayerY][PlayerX] = nullptr;
					chpt2->pointerMap2[PlayerY - 1][PlayerX] = this;

					chpt2->MapInfo2[PlayerY][PlayerX] = 0;
					chpt2->MapInfo2[PlayerY - 1][PlayerX] = 2;

					break;
				case 1:
					Hp++;
					return;
				case 3:
					static_cast<Monster*>(chpt2->pointerMap2[PlayerY - 1][PlayerX])->Hit(dir); /* 몬스터 내부에 공격받는 함수 만들고 */
					break;
				case 4:
					static_cast<Rock*>(chpt2->pointerMap2[PlayerY - 1][PlayerX])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter3* chpt3 = dynamic_cast<Chapter3*>(scene))
			{
				int PlayerY = int(pos.y - chpt3->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt3->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt3->MapInfo3[PlayerY - 1][PlayerX])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x, pos.y - MOVE_TILE_HEIGHT));
					chpt3->pointerMap3[PlayerY][PlayerX] = nullptr;
					chpt3->pointerMap3[PlayerY - 1][PlayerX] = this;

					chpt3->MapInfo3[PlayerY][PlayerX] = 0;
					chpt3->MapInfo3[PlayerY - 1][PlayerX] = 2;

					break;
				case 1:
					Hp++;
					return;
				case 3:
					static_cast<Monster*>(chpt3->pointerMap3[PlayerY - 1][PlayerX])->Hit(dir); /* 몬스터 내부에 공격받는 함수 만들고 */
					break;
				case 4:
					static_cast<Rock*>(chpt3->pointerMap3[PlayerY - 1][PlayerX])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter4* chpt4 = dynamic_cast<Chapter4*>(scene))
			{
				int PlayerY = int(pos.y - chpt4->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt4->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt4->MapInfo4[PlayerY - 1][PlayerX])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x, pos.y - MOVE_TILE_HEIGHT));
					chpt4->pointerMap4[PlayerY][PlayerX] = nullptr;
					chpt4->pointerMap4[PlayerY - 1][PlayerX] = this;

					chpt4->MapInfo4[PlayerY][PlayerX] = 0;
					chpt4->MapInfo4[PlayerY - 1][PlayerX] = 2;

					break;
				case 1:
					Hp++;
					return;
				case 3:
					static_cast<Monster*>(chpt4->pointerMap4[PlayerY - 1][PlayerX])->Hit(dir); /* 몬스터 내부에 공격받는 함수 만들고 */
					break;
				case 4:
					static_cast<Rock*>(chpt4->pointerMap4[PlayerY - 1][PlayerX])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter5* chpt5 = dynamic_cast<Chapter5*>(scene))
			{
				int PlayerY = int(pos.y - chpt5->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt5->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt5->MapInfo5[PlayerY - 1][PlayerX])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x, pos.y - MOVE_TILE_HEIGHT));
					chpt5->pointerMap5[PlayerY][PlayerX] = nullptr;
					chpt5->pointerMap5[PlayerY - 1][PlayerX] = this;

					chpt5->MapInfo5[PlayerY][PlayerX] = 0;
					chpt5->MapInfo5[PlayerY - 1][PlayerX] = 2;

					break;
				case 1:
					Hp++;
					return;
				case 3:
					static_cast<Monster*>(chpt5->pointerMap5[PlayerY - 1][PlayerX])->Hit(dir); /* 몬스터 내부에 공격받는 함수 만들고 */
					break;
				case 4:
					static_cast<Rock*>(chpt5->pointerMap5[PlayerY - 1][PlayerX])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter6* chpt6 = dynamic_cast<Chapter6*>(scene))
			{
				int PlayerY = int(pos.y - chpt6->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt6->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt6->MapInfo6[PlayerY - 1][PlayerX])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x, pos.y - MOVE_TILE_HEIGHT));
					chpt6->pointerMap6[PlayerY][PlayerX] = nullptr;
					chpt6->pointerMap6[PlayerY - 1][PlayerX] = this;

					chpt6->MapInfo6[PlayerY][PlayerX] = 0;
					chpt6->MapInfo6[PlayerY - 1][PlayerX] = 2;

					break;
				case 1:
					Hp++;
					return;
				case 3:
					static_cast<Monster*>(chpt6->pointerMap6[PlayerY - 1][PlayerX])->Hit(dir); /* 몬스터 내부에 공격받는 함수 만들고 */
					break;
				case 4:
					static_cast<Rock*>(chpt6->pointerMap6[PlayerY - 1][PlayerX])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			sound->Play(false);
		}
		else if (_dir == 2 && Input::GetKeyUp(eKeyCode::A))
		{
			Scene* scene = SceneManager::GetActiveScene();
			if (Chapter1* chpt1 = dynamic_cast<Chapter1*>(scene))
			{
				int PlayerY = int(pos.y - chpt1->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt1->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt1->MapInfo1[PlayerY][PlayerX - 1])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));
					chpt1->pointerMap1[PlayerY][PlayerX] = nullptr;
					chpt1->pointerMap1[PlayerY][PlayerX - 1] = this;

					chpt1->MapInfo1[PlayerY][PlayerX] = 0;
					chpt1->MapInfo1[PlayerY][PlayerX - 1] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt1->pointerMap1[PlayerY][PlayerX - 1])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt1->pointerMap1[PlayerY][PlayerX - 1])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter2* chpt2 = dynamic_cast<Chapter2*>(scene))
			{
				int PlayerY = int(pos.y - chpt2->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt2->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt2->MapInfo2[PlayerY][PlayerX - 1])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));
					chpt2->pointerMap2[PlayerY][PlayerX] = nullptr;
					chpt2->pointerMap2[PlayerY][PlayerX - 1] = this;

					chpt2->MapInfo2[PlayerY][PlayerX] = 0;
					chpt2->MapInfo2[PlayerY][PlayerX - 1] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt2->pointerMap2[PlayerY][PlayerX - 1])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt2->pointerMap2[PlayerY][PlayerX - 1])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter3* chpt3 = dynamic_cast<Chapter3*>(scene))
			{
				int PlayerY = int(pos.y - chpt3->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt3->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt3->MapInfo3[PlayerY][PlayerX - 1])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));
					chpt3->pointerMap3[PlayerY][PlayerX] = nullptr;
					chpt3->pointerMap3[PlayerY][PlayerX - 1] = this;

					chpt3->MapInfo3[PlayerY][PlayerX] = 0;
					chpt3->MapInfo3[PlayerY][PlayerX - 1] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt3->pointerMap3[PlayerY][PlayerX - 1])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt3->pointerMap3[PlayerY][PlayerX - 1])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter4* chpt4 = dynamic_cast<Chapter4*>(scene))
			{
				int PlayerY = int(pos.y - chpt4->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt4->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt4->MapInfo4[PlayerY][PlayerX - 1])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));
					chpt4->pointerMap4[PlayerY][PlayerX] = nullptr;
					chpt4->pointerMap4[PlayerY][PlayerX - 1] = this;

					chpt4->MapInfo4[PlayerY][PlayerX] = 0;
					chpt4->MapInfo4[PlayerY][PlayerX - 1] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt4->pointerMap4[PlayerY][PlayerX - 1])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt4->pointerMap4[PlayerY][PlayerX - 1])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter5* chpt5 = dynamic_cast<Chapter5*>(scene))
			{
				int PlayerY = int(pos.y - chpt5->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt5->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt5->MapInfo5[PlayerY][PlayerX - 1])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));
					chpt5->pointerMap5[PlayerY][PlayerX] = nullptr;
					chpt5->pointerMap5[PlayerY][PlayerX - 1] = this;

					chpt5->MapInfo5[PlayerY][PlayerX] = 0;
					chpt5->MapInfo5[PlayerY][PlayerX - 1] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt5->pointerMap5[PlayerY][PlayerX - 1])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt5->pointerMap5[PlayerY][PlayerX - 1])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter6* chpt6 = dynamic_cast<Chapter6*>(scene))
			{
				int PlayerY = int(pos.y - chpt6->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt6->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt6->MapInfo6[PlayerY][PlayerX - 1])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x - MOVE_TILE_WIDTH, pos.y));
					chpt6->pointerMap6[PlayerY][PlayerX] = nullptr;
					chpt6->pointerMap6[PlayerY][PlayerX - 1] = this;

					chpt6->MapInfo6[PlayerY][PlayerX] = 0;
					chpt6->MapInfo6[PlayerY][PlayerX - 1] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt6->pointerMap6[PlayerY][PlayerX - 1])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt6->pointerMap6[PlayerY][PlayerX - 1])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			sound->Play(false);
		}
		else if (_dir == 1 && Input::GetKeyUp(eKeyCode::S))
		{
			Scene* scene = SceneManager::GetActiveScene();
			if (Chapter1* chpt1 = dynamic_cast<Chapter1*>(scene))
			{
				int PlayerY = int(pos.y - chpt1->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt1->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt1->MapInfo1[PlayerY + 1][PlayerX])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));
					chpt1->pointerMap1[PlayerY][PlayerX] = nullptr;
					chpt1->pointerMap1[PlayerY + 1][PlayerX] = this;

					chpt1->MapInfo1[PlayerY][PlayerX] = 0;
					chpt1->MapInfo1[PlayerY + 1][PlayerX] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt1->pointerMap1[PlayerY + 1][PlayerX])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt1->pointerMap1[PlayerY + 1][PlayerX])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter2* chpt2 = dynamic_cast<Chapter2*>(scene))
			{
				int PlayerY = int(pos.y - chpt2->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt2->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt2->MapInfo2[PlayerY + 1][PlayerX])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));
					chpt2->pointerMap2[PlayerY][PlayerX] = nullptr;
					chpt2->pointerMap2[PlayerY + 1][PlayerX] = this;

					chpt2->MapInfo2[PlayerY][PlayerX] = 0;
					chpt2->MapInfo2[PlayerY + 1][PlayerX] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt2->pointerMap2[PlayerY + 1][PlayerX])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt2->pointerMap2[PlayerY + 1][PlayerX])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter3* chpt3 = dynamic_cast<Chapter3*>(scene))
			{
				int PlayerY = int(pos.y - chpt3->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt3->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt3->MapInfo3[PlayerY + 1][PlayerX])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));
					chpt3->pointerMap3[PlayerY][PlayerX] = nullptr;
					chpt3->pointerMap3[PlayerY + 1][PlayerX] = this;

					chpt3->MapInfo3[PlayerY][PlayerX] = 0;
					chpt3->MapInfo3[PlayerY + 1][PlayerX] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt3->pointerMap3[PlayerY + 1][PlayerX])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt3->pointerMap3[PlayerY + 1][PlayerX])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter4* chpt4 = dynamic_cast<Chapter4*>(scene))
			{
				int PlayerY = int(pos.y - chpt4->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt4->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt4->MapInfo4[PlayerY + 1][PlayerX])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));
					chpt4->pointerMap4[PlayerY][PlayerX] = nullptr;
					chpt4->pointerMap4[PlayerY + 1][PlayerX] = this;

					chpt4->MapInfo4[PlayerY][PlayerX] = 0;
					chpt4->MapInfo4[PlayerY + 1][PlayerX] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt4->pointerMap4[PlayerY + 1][PlayerX])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt4->pointerMap4[PlayerY + 1][PlayerX])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter5* chpt5 = dynamic_cast<Chapter5*>(scene))
			{
				int PlayerY = int(pos.y - chpt5->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt5->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt5->MapInfo5[PlayerY + 1][PlayerX])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));
					chpt5->pointerMap5[PlayerY][PlayerX] = nullptr;
					chpt5->pointerMap5[PlayerY + 1][PlayerX] = this;

					chpt5->MapInfo5[PlayerY][PlayerX] = 0;
					chpt5->MapInfo5[PlayerY + 1][PlayerX] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt5->pointerMap5[PlayerY + 1][PlayerX])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt5->pointerMap5[PlayerY + 1][PlayerX])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter6* chpt6 = dynamic_cast<Chapter6*>(scene))
			{
				int PlayerY = int(pos.y - chpt6->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt6->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt6->MapInfo6[PlayerY + 1][PlayerX])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x, pos.y + MOVE_TILE_HEIGHT));
					chpt6->pointerMap6[PlayerY][PlayerX] = nullptr;
					chpt6->pointerMap6[PlayerY + 1][PlayerX] = this;

					chpt6->MapInfo6[PlayerY][PlayerX] = 0;
					chpt6->MapInfo6[PlayerY + 1][PlayerX] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt6->pointerMap6[PlayerY + 1][PlayerX])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt6->pointerMap6[PlayerY + 1][PlayerX])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			sound->Play(false);
		}
		else if (_dir == 3 && Input::GetKeyUp(eKeyCode::D))
		{
			Scene* scene = SceneManager::GetActiveScene();
			if (Chapter1* chpt1 = dynamic_cast<Chapter1*>(scene))
			{
				int PlayerY = int(pos.y - chpt1->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt1->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt1->MapInfo1[PlayerY][PlayerX + 1])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));
					chpt1->pointerMap1[PlayerY][PlayerX] = nullptr;
					chpt1->pointerMap1[PlayerY][PlayerX + 1] = this;

					chpt1->MapInfo1[PlayerY][PlayerX] = 0;
					chpt1->MapInfo1[PlayerY][PlayerX + 1] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt1->pointerMap1[PlayerY][PlayerX + 1])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt1->pointerMap1[PlayerY][PlayerX + 1])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter2* chpt2 = dynamic_cast<Chapter2*>(scene))
			{
				int PlayerY = int(pos.y - chpt2->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt2->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt2->MapInfo2[PlayerY][PlayerX + 1])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));
					chpt2->pointerMap2[PlayerY][PlayerX] = nullptr;
					chpt2->pointerMap2[PlayerY][PlayerX + 1] = this;

					chpt2->MapInfo2[PlayerY][PlayerX] = 0;
					chpt2->MapInfo2[PlayerY][PlayerX + 1] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt2->pointerMap2[PlayerY][PlayerX + 1])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt2->pointerMap2[PlayerY][PlayerX + 1])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter3* chpt3 = dynamic_cast<Chapter3*>(scene))
			{
				int PlayerY = int(pos.y - chpt3->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt3->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt3->MapInfo3[PlayerY][PlayerX + 1])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));
					chpt3->pointerMap3[PlayerY][PlayerX] = nullptr;
					chpt3->pointerMap3[PlayerY][PlayerX + 1] = this;

					chpt3->MapInfo3[PlayerY][PlayerX] = 0;
					chpt3->MapInfo3[PlayerY][PlayerX + 1] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt3->pointerMap3[PlayerY][PlayerX + 1])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt3->pointerMap3[PlayerY][PlayerX + 1])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter4* chpt4 = dynamic_cast<Chapter4*>(scene))
			{
				int PlayerY = int(pos.y - chpt4->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt4->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt4->MapInfo4[PlayerY][PlayerX + 1])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));
					chpt4->pointerMap4[PlayerY][PlayerX] = nullptr;
					chpt4->pointerMap4[PlayerY][PlayerX + 1] = this;

					chpt4->MapInfo4[PlayerY][PlayerX] = 0;
					chpt4->MapInfo4[PlayerY][PlayerX + 1] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt4->pointerMap4[PlayerY][PlayerX + 1])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt4->pointerMap4[PlayerY][PlayerX + 1])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter5* chpt5 = dynamic_cast<Chapter5*>(scene))
			{
				int PlayerY = int(pos.y - chpt5->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt5->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt5->MapInfo5[PlayerY][PlayerX + 1])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));
					chpt5->pointerMap5[PlayerY][PlayerX] = nullptr;
					chpt5->pointerMap5[PlayerY][PlayerX + 1] = this;

					chpt5->MapInfo5[PlayerY][PlayerX] = 0;
					chpt5->MapInfo5[PlayerY][PlayerX + 1] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt5->pointerMap5[PlayerY][PlayerX + 1])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt5->pointerMap5[PlayerY][PlayerX + 1])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			if (Chapter6* chpt6 = dynamic_cast<Chapter6*>(scene))
			{
				int PlayerY = int(pos.y - chpt6->LeftTop.y) / MOVE_TILE_HEIGHT;
				int PlayerX = int(pos.x - chpt6->LeftTop.x) / MOVE_TILE_WIDTH;

				switch (chpt6->MapInfo6[PlayerY][PlayerX + 1])
				{
				case 0:
					//캐릭터 이동시키고 맵정보 2개 갱신
					tr->SetPosition(Vector2(pos.x + MOVE_TILE_WIDTH, pos.y));
					chpt6->pointerMap6[PlayerY][PlayerX] = nullptr;
					chpt6->pointerMap6[PlayerY][PlayerX + 1] = this;

					chpt6->MapInfo6[PlayerY][PlayerX] = 0;
					chpt6->MapInfo6[PlayerY][PlayerX + 1] = 2;

					break;
				case 1:
					return;
				case 3:
					static_cast<Monster*>(chpt6->pointerMap6[PlayerY][PlayerX + 1])->Hit(_dir) /* 몬스터 내부에 공격받는 함수 만들고 */;
					break;
				case 4:
					static_cast<Rock*>(chpt6->pointerMap6[PlayerY][PlayerX + 1])->RockHit(_dir);
					break;
				default:
					break;
				}
			}

			sound->Play(false);
		}

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
		//Layer& layer = scene->GetLayer(eLayerType::Monster);
		//GameObject* obj = layer.GetGameObjects().front();
		//dynamic_cast<Monster*>(obj)->Hit(/*dir*/);


		// Attack 로직
		Scene* scene = SceneManager::GetActiveScene();
		std::wstring Now = scene->GetName();
		
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Now == L"Chapter1")
		{
			static_cast<Chapter1*>(scene)->MapInfo1 ;
			
			
		}

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

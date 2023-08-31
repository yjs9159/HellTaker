#include "yaChapter6.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaTexture.h"
#include "yaResources.h"
#include "yaBackGround.h"
#include "yaSpriteRenderer.h"
#include "yaTransform.h"
#include "yaObject.h"
#include "yaPlayer.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaMonster.h"
#include "yaNpc.h"
#include "yaRock.h"
#include "yaKey.h"
#include "yaLockBox.h"
#include "yaSceneChange.h"
#include "yaFire.h"
#include "yaSound.h"
#include "yaUi.h"

namespace ya
{
	int Chapter6::MapInfo6[10][9] =
	{
		// 0 => �ٴ�
		// 1 => wall
		// 2 => player
		// 3 => monster
		// 4 => rock
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 2, 0, 1, 1, 1, 1 },
		{ 1, 1, 4, 4, 4, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 1, 1, 1, 1 },
		{ 1, 1, 0, 4, 0, 0, 1, 1, 1 },
		{ 1, 1, 3, 1, 4, 4, 0, 0, 1 },
		{ 1, 1, 0, 0, 4, 0, 3, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 4, 0, 1 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};

	ya::Chapter6::Chapter6()
		: LeftTop(Vector2(318.0f + 72 / 2, 15.0f + 68 / 2))
	{
		pointerMap6[10][9] =
		{
			NULL,
		};
	}

	ya::Chapter6::~Chapter6()
	{
	}

	void ya::Chapter6::Initialize()
	{
		// Scene Change ���� �� �ִϸ��̼� ���
		SceneChange* S_C = object::Instantiate<SceneChange>(eLayerType::SceneChange);

		Transform* tr = S_C->GetComponent<Transform>();
		tr->SetPosition(Vector2(640.0f, 360.0f));

		Animator* at = S_C->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Change", L"..\\Resources\\Texture\\levelchange\\bmp", Vector2(0.0f, 0.0f), 0.05f);
		at->PlayAnimation(L"Change", false);
		at->SetScale(Vector2(0.7f, 0.7f));


		// ���� �� Ui
		Ui* Ui1 = object::Instantiate<Ui>(eLayerType::UI);

		tr = Ui1->GetComponent<Transform>();
		tr->SetPosition(Vector2(115.0f, 215.0f));


		Texture* T_Ui = Resources::Load<Texture>(L"Ui1"
			, L"..\\Resources\\Texture\\playui\\mainUI002.bmp");

		SpriteRenderer* sr = Ui1->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));

		// ���� �Ʒ� Ui
		Ui* Ui2 = object::Instantiate<Ui>(eLayerType::UI);

		tr = Ui2->GetComponent<Transform>();
		tr->SetPosition(Vector2(180.0f, 500.0f));


		T_Ui = Resources::Load<Texture>(L"Ui2"
			, L"..\\Resources\\Texture\\playui\\mainUI001.bmp");

		sr = Ui2->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));

		// ������ �� Ui
		Ui* Ui3 = object::Instantiate<Ui>(eLayerType::UI);

		tr = Ui3->GetComponent<Transform>();
		tr->SetPosition(Vector2(1170.0f, 215.0f));


		T_Ui = Resources::Load<Texture>(L"Ui3"
			, L"..\\Resources\\Texture\\playui\\mainUI003.bmp");

		sr = Ui3->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// ������ �Ʒ� Ui
		Ui* Ui4 = object::Instantiate<Ui>(eLayerType::UI);

		tr = Ui4->GetComponent<Transform>();
		tr->SetPosition(Vector2(1100.0f, 500.0f));


		T_Ui = Resources::Load<Texture>(L"Ui4"
			, L"..\\Resources\\Texture\\playui\\mainUI000.bmp");

		sr = Ui4->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// ��� �̹��� ����
		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);

		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));
		
		T_Ui = Resources::Load<Texture>(L"Chapter6"
			, L"..\\Resources\\Texture\\chapterbg\\chapterBG0006.bmp");

		sr = bg->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.7f, 0.7f));
		sr->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);

		// player ����
		Player* player = object::Instantiate<Player>(eLayerType::Player); // �÷��̾� ����

		tr = player->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 1)); // �÷��̾� ������ġ
		pointerMap6[1][3] = player;

		at = player->AddComponent<Animator>();
		at->CreateAnimationFolder(L"player_rightidle", L"..\\Resources\\Texture\\player\\player_idle\\right_idle", Vector2(0.0f, 10.0f));
		at->CreateAnimationFolder(L"player_leftidle", L"..\\Resources\\Texture\\player\\player_idle\\left_idle", Vector2(0.0f, 10.0f));
		at->CreateAnimationFolder(L"player_rightrun", L"..\\Resources\\Texture\\player\\player_run\\right_run", Vector2(0.0f, 10.0f));
		at->CreateAnimationFolder(L"player_leftrun", L"..\\Resources\\Texture\\player\\player_run\\left_run", Vector2(0.0f, 10.0f));
		at->CreateAnimationFolder(L"player_rightattack", L"..\\Resources\\Texture\\player\\player_attack\\right_attack", Vector2(0.0f, -10.0f));
		at->CreateAnimationFolder(L"player_leftattack", L"..\\Resources\\Texture\\player\\player_attack\\left_attack", Vector2(0.0f, -10.0f));
		at->CreateAnimationFolder(L"player_rightsuccess", L"..\\Resources\\Texture\\player\\player_success\\right_success", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"player_rightidle", true);
		at->SetScale(Vector2(0.8f, 0.8f));
		at->SetAffectedCamera(true);

		//Collider* col = player->AddComponent<Collider>();
		//col->SetSize(Vector2(85.0f, 90.0f));
		//col->SetOffset(Vector2(0.0f, -10.0f));


		// monster 1
		Monster* monster1 = object::Instantiate<Monster>(eLayerType::Monster); // ����1 ����

		tr = monster1->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 5)); // ����1 ������ġ
		pointerMap6[5][2] = monster1;

		at = monster1->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"Monster_RightIdle", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		//col = monster1->AddComponent<Collider>();
		//col->SetSize(Vector2(80.0f, 80.0f));


		// monster2
		Monster* monster2 = object::Instantiate<Monster>(eLayerType::Monster); // ����2 ����

		tr = monster2->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 6)); // ����2 ������ġ
		pointerMap6[6][6] = monster2;

		at = monster2->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Monster_RightIdle", L"..\\Resources\\Texture\\obstacle\\undead_idle\\right_idle", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"Monster_RightIdle", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		//col = monster2->AddComponent<Collider>();
		//col->SetSize(Vector2(80.0f, 80.0f));


		// Npc pandemonica ����
		Npc* azazel = object::Instantiate<Npc>(eLayerType::Npc);

		tr = azazel->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 8)); // Npc pandemonica ������ġ

		at = azazel->AddComponent<Animator>();
		at->CreateAnimationFolder(L"azazel ", L"..\\Resources\\Texture\\npc\\azazel", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"azazel ", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		//col = azazel->AddComponent<Collider>();
		//col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign
		Npc* LoveSign = object::Instantiate<Npc>(eLayerType::Npc);

		tr = LoveSign->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5 + 40, LeftTop.y + MOVE_TILE_HEIGHT * 8 - 30));

		T_Ui = Resources::Load<Texture>(L"LoveSign"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		sr = LoveSign->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));



		// Rock 1 ���� �� �̹��� �ε�
		Rock* rock1 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock1->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 2));
		pointerMap6[2][2] = rock1;

		T_Ui = Resources::Load<Texture>(L"Rock4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock004.png");

		sr = rock1->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 2 ���� �� �̹��� �ε�
		Rock* rock2 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock2->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 2));
		pointerMap6[2][3] = rock2;

		T_Ui = Resources::Load<Texture>(L"Rock5"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock005.png");

		sr = rock2->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 3 ���� �� �̹��� �ε�
		Rock* rock3 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock3->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 2));
		pointerMap6[2][4] = rock3;

		T_Ui = Resources::Load<Texture>(L"Rock6"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock006.png");

		sr = rock3->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 4 ���� �� �̹��� �ε�
		Rock* rock4 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock4->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 4));
		pointerMap6[4][3] = rock4;

		T_Ui = Resources::Load<Texture>(L"Rock7"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock007.png");

		sr = rock4->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 5 ���� �� �̹��� �ε�
		Rock* rock5 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock5->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 5));
		pointerMap6[5][4] = rock5;
		
		T_Ui = Resources::Load<Texture>(L"Rock8"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock008.png");

		sr = rock5->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 6 ���� �� �̹��� �ε�
		Rock* rock6 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock6->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 6));
		pointerMap6[6][4] = rock6;

		T_Ui = Resources::Load<Texture>(L"Rock2"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock002.png");

		sr = rock6->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 7 ���� �� �̹��� �ε�
		Rock* rock7 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock7->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 5));
		pointerMap6[5][5] = rock7;

		T_Ui = Resources::Load<Texture>(L"Rock1"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock001.png");

		sr = rock7->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Rock 8 ���� �� �̹��� �ε�
		Rock* rock8 = object::Instantiate<Rock>(eLayerType::Rock);

		tr = rock8->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 7));
		pointerMap6[7][6] = rock8;

		T_Ui = Resources::Load<Texture>(L"Rock9"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock009.png");

		sr = rock8->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Key ���� �� �̹��� �ε�
		Key* myKey = object::Instantiate<Key>(eLayerType::myKey);

		tr = myKey->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		at = myKey->AddComponent<Animator>();
		at->CreateAnimationFolder(L"myKey", L"..\\Resources\\Texture\\obstacle\\Key", Vector2(10.0f, 0.0f));
		at->PlayAnimation(L"myKey", true);
		at->SetScale(Vector2(0.8f, 0.8f));


		// LockBox ���� �� �̹��� �ε�
		LockBox* lockbox = object::Instantiate<LockBox>(eLayerType::LockBox);

		tr = lockbox->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 7));

		T_Ui = Resources::Load<Texture>(L"Box"
			, L"..\\Resources\\Texture\\obstacle\\lockbox\\lockbox001.png");

		sr = lockbox->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1 base
		Fire* Fire6_1base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire6_1base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1, LeftTop.y + MOVE_TILE_HEIGHT * 1 + 7));

		T_Ui = Resources::Load<Texture>(L"Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		sr = Fire6_1base->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1
		Fire* Fire6_1 = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire6_1->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 1, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		at = Fire6_1->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Fire", L"..\\Resources\\Texture\\fire\\fire", Vector2(0.0f, -30.0f));
		at->PlayAnimation(L"Fire", true);
		at->SetScale(Vector2(0.4f, 0.5f));


		// Fire 2 base
		Fire* Fire6_2base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire6_2base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5 - 1, LeftTop.y + MOVE_TILE_HEIGHT * 2 + 6));

		T_Ui = Resources::Load<Texture>(L"NoneBase"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0002.png");

		sr = Fire6_2base->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 3 base
		Fire* Fire6_3base = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire6_3base->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6 - 1, LeftTop.y + MOVE_TILE_HEIGHT * 2 - 23));

		T_Ui = Resources::Load<Texture>(L"Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		sr = Fire6_3base->AddComponent<SpriteRenderer>();
		sr->SetImage(T_Ui);
		sr->SetScale(Vector2(0.75f, 0.75f));


		// Fire 2
		Fire* Fire6_2 = object::Instantiate<Fire>(eLayerType::Fire);

		tr = Fire6_2->GetComponent<Transform>();
		tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		at = Fire6_2->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Fire", L"..\\Resources\\Texture\\fire\\fire", Vector2(0.0f, 10.0f));
		at->PlayAnimation(L"Fire", true);
		at->SetScale(Vector2(0.4f, 0.5f));
	}

	void ya::Chapter6::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::H))
		{
			SceneManager::LoadScene(L"HomeScene");
		}
		if (Input::GetKeyDown(eKeyCode::T))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
		if (Input::GetKeyDown(eKeyCode::E))
		{
			SceneManager::LoadScene(L"EndingScene");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter1))
		{
			SceneManager::LoadScene(L"Chapter1");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter2))
		{
			SceneManager::LoadScene(L"Chapter2");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter3))
		{
			SceneManager::LoadScene(L"Chapter3");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter4))
		{
			SceneManager::LoadScene(L"Chapter4");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter5))
		{
			SceneManager::LoadScene(L"Chapter5");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter6))
		{
			SceneManager::LoadScene(L"Chapter6");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter7))
		{
			Sound* Sound_SC7 = Resources::Load<Sound>(L"SceneChange7", L"..\\Resources\\Sound\\screen_changer_part1_01.wav");
			Sound_SC7->Play(false);

			SceneManager::LoadScene(L"Chapter7");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter8))
		{
			SceneManager::LoadScene(L"Chapter8");
		}
	}

	void ya::Chapter6::Render(HDC hdc)
	{
		Scene::Render(hdc);

		//int maxRow = 720 / (TILE_HEIGHT * 3) + 1;
		//for (size_t y = 0; y < maxRow; y++)
		//{
		//	MoveToEx(hdc, 0, TILE_HEIGHT * y * 4 + 15, NULL);      //      ����(��) ����
		//	LineTo(hdc, 1280, TILE_HEIGHT * y * 4 + 15);        //          ����(��) ��
		//}

		//int maxColumn = 1280 / (TILE_WIDTH * 3) + 1;
		//for (size_t x = 0; x < maxColumn; x++)
		//{
		//	MoveToEx(hdc, TILE_WIDTH * x * 4 + 30, 0, NULL);      //      ����(��) ����
		//	LineTo(hdc, TILE_WIDTH * x * 4 + 30, 720);        //          ����(��) ��
		//}
	}
}

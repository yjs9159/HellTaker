#include "yaChapter4.h"
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
	int Chapter4::MapInfo4[7][11] =
	{
		// 0 => 바닥
		// 1 => wall
		// 2 => player
		// 3 => monster
		// 4 => rock
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 2, 1, 0, 0, 4, 1, 1, 1, 1 },
		{ 1, 1, 0, 4, 0, 4, 0, 0, 0, 1, 1 },
		{ 1, 1, 4, 0, 4, 0, 4, 4, 0, 0, 1 },
		{ 1, 1, 0, 4, 0, 4, 0, 4, 4, 0, 1 },
		{ 1, 1, 1, 0, 4, 0, 4, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};

	Chapter4::Chapter4()
		: LeftTop(Vector2(216.0f + 72 / 2, 115.0f + 68 / 2))
	{
		pointerMap4[7][11] =
		{
			NULL,
		};
	}

	Chapter4::~Chapter4()
	{
	}

	void Chapter4::Initialize()
	{
		// Scene Change 생성 및 애니메이션 재생
		SceneChange* S_C = object::Instantiate<SceneChange>(eLayerType::SceneChange);
		S_C->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));

		//Transform* tr = S_C->GetComponent<Transform>();
		//tr->SetPosition(Vector2(640.0f, 360.0f));

		Animator* at = S_C->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Change", L"..\\Resources\\Texture\\levelchange\\bmp", Vector2(0.0f, 0.0f), 0.05f);
		at->PlayAnimation(L"Change", false);
		at->SetScale(Vector2(0.7f, 0.7f));


		// 왼쪽 위 Ui
		Ui* Ui1 = object::Instantiate<Ui>(eLayerType::UI);
		Ui1->GetComponent<Transform>()->SetPosition(Vector2(115.0f, 215.0f));
		//tr = Ui1->GetComponent<Transform>();
		//tr->SetPosition(Vector2(115.0f, 215.0f));


		Texture* T_Ui = Resources::Load<Texture>(L"Ui1"
			, L"..\\Resources\\Texture\\playui\\mainUI002.bmp");

		SpriteRenderer* sr_Ui = Ui1->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));

		// 왼쪽 아래 Ui
		Ui* Ui2 = object::Instantiate<Ui>(eLayerType::UI);
		Ui2->GetComponent<Transform>()->SetPosition(Vector2(180.0f, 500.0f));
		//tr = Ui2->GetComponent<Transform>();
		//tr->SetPosition(Vector2(180.0f, 500.0f));


		T_Ui = Resources::Load<Texture>(L"Ui2"
			, L"..\\Resources\\Texture\\playui\\mainUI001.bmp");

		sr_Ui = Ui2->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));

		// 오른쪽 위 Ui
		Ui* Ui3 = object::Instantiate<Ui>(eLayerType::UI);
		Ui3->GetComponent<Transform>()->SetPosition(Vector2(1170.0f, 215.0f));
		//tr = Ui3->GetComponent<Transform>();
		//tr->SetPosition(Vector2(1170.0f, 215.0f));


		T_Ui = Resources::Load<Texture>(L"Ui3"
			, L"..\\Resources\\Texture\\playui\\mainUI003.bmp");

		sr_Ui = Ui3->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// 오른쪽 아래 Ui
		Ui* Ui4 = object::Instantiate<Ui>(eLayerType::UI);
		Ui4->GetComponent<Transform>()->SetPosition(Vector2(1100.0f, 500.0f));
		//tr = Ui4->GetComponent<Transform>();
		//tr->SetPosition(Vector2(1100.0f, 500.0f));


		T_Ui = Resources::Load<Texture>(L"Ui4"
			, L"..\\Resources\\Texture\\playui\\mainUI000.bmp");

		sr_Ui = Ui4->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// 배경 이미지 생성
		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		bg->GetComponent<Transform>()->SetPosition(Vector2(640.0f, 360.0f));

		T_Ui = Resources::Load<Texture>(L"Chapter4"
			, L"..\\Resources\\Texture\\chapterbg\\chapterBG0004.bmp");

		sr_Ui = bg->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.7f, 0.7f));
		sr_Ui->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);


		// player 생성
		Player* player = object::Instantiate<Player>(eLayerType::Player); // 플레이어 생성
		player->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 1));
		pointerMap4[1][2] = player;

		//tr = player->GetComponent<Transform>();
		//tr->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 1)); // 플레이어 시작위치

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


		// Npc pandemonica 생성
		Npc* malina = object::Instantiate<Npc>(eLayerType::Npc);
		malina->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 9, LeftTop.y + MOVE_TILE_HEIGHT * 3));
		
		//Transform* tr_malina = malina->GetComponent<Transform>();
		//tr_malina->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 9, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		at = malina->AddComponent<Animator>();
		at->CreateAnimationFolder(L"malina", L"..\\Resources\\Texture\\npc\\malina", Vector2(0.0f, -10.0f));
		at->PlayAnimation(L"malina", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		//col = malina->AddComponent<Collider>();
		//col->SetSize(Vector2(80.0f, 80.0f));


		// Npc LoveSign
		Npc* LoveSign = object::Instantiate<Npc>(eLayerType::Npc);
		LoveSign->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8 + 40, LeftTop.y + MOVE_TILE_HEIGHT * 3 - 30));
		
		//Transform* tr_LoveSign = LoveSign->GetComponent<Transform>();
		//tr_LoveSign->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8 + 40, LeftTop.y + MOVE_TILE_HEIGHT * 3 - 30));

		T_Ui = Resources::Load<Texture>(L"LoveSign"
			, L"..\\Resources\\Texture\\npc\\lovesign\\lovesign.png");

		sr_Ui = LoveSign->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 1 생성 및 이미지 로드
		Rock* rock1 = object::Instantiate<Rock>(eLayerType::Rock);
		rock1->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 3));
		pointerMap4[3][2] = rock1;

		//Transform* tr_Rock1 = rock1->GetComponent<Transform>();
		//tr_Rock1->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 2, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		T_Ui = Resources::Load<Texture>(L"Rock1"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock001.png");

		sr_Ui = rock1->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 2 생성 및 이미지 로드
		Rock* rock2 = object::Instantiate<Rock>(eLayerType::Rock);
		rock2->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 2));
		pointerMap4[2][3] = rock2;

		//Transform* tr_Rock2 = rock2->GetComponent<Transform>();
		//tr_Rock2->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 2));

		T_Ui = Resources::Load<Texture>(L"Rock3"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock003.png");

		sr_Ui = rock2->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 3 생성 및 이미지 로드
		Rock* rock3 = object::Instantiate<Rock>(eLayerType::Rock);
		rock3->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 4));
		pointerMap4[4][3] = rock3;

		//Transform* tr_Rock3 = rock3->GetComponent<Transform>();
		//tr_Rock3->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		T_Ui = Resources::Load<Texture>(L"Rock2"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock002.png");

		sr_Ui = rock3->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 4 생성 및 이미지 로드
		Rock* rock4 = object::Instantiate<Rock>(eLayerType::Rock);
		rock4->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 3));
		pointerMap4[3][4] = rock4;

		//Transform* tr_Rock4 = rock4->GetComponent<Transform>();
		//tr_Rock4->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		T_Ui = Resources::Load<Texture>(L"Rock4"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock004.png");

		sr_Ui = rock4->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 5 생성 및 이미지 로드
		Rock* rock5 = object::Instantiate<Rock>(eLayerType::Rock);
		rock5->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 5));
		pointerMap4[5][4] = rock5;

		//Transform* tr_Rock5 = rock5->GetComponent<Transform>();
		//tr_Rock5->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 5));

		T_Ui = Resources::Load<Texture>(L"Rock5"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock005.png");

		sr_Ui = rock5->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 6 생성 및 이미지 로드
		Rock* rock6 = object::Instantiate<Rock>(eLayerType::Rock);
		rock6->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 2));
		pointerMap4[2][5] = rock6;

		//Transform* tr_Rock6 = rock6->GetComponent<Transform>();
		//tr_Rock6->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 2));

		T_Ui = Resources::Load<Texture>(L"Rock7"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock007.png");

		sr_Ui = rock6->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 7 생성 및 이미지 로드
		Rock* rock7 = object::Instantiate<Rock>(eLayerType::Rock);
		rock7->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 4));
		pointerMap4[4][5] = rock7;

		//Transform* tr_Rock7 = rock7->GetComponent<Transform>();
		//tr_Rock7->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 5, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		T_Ui = Resources::Load<Texture>(L"Rock6"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock006.png");

		sr_Ui = rock7->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 8 생성 및 이미지 로드
		Rock* rock8 = object::Instantiate<Rock>(eLayerType::Rock);
		rock8->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 1));
		pointerMap4[1][6] = rock8;

		//Transform* tr_Rock8 = rock8->GetComponent<Transform>();
		//tr_Rock8->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		T_Ui = Resources::Load<Texture>(L"Rock2"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock002.png");

		sr_Ui = rock8->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 9 생성 및 이미지 로드
		Rock* rock9 = object::Instantiate<Rock>(eLayerType::Rock);
		rock9->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 3));
		pointerMap4[3][6] = rock9;

		//Transform* tr_Rock9 = rock9->GetComponent<Transform>();
		//tr_Rock9->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		T_Ui = Resources::Load<Texture>(L"Rock8"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock008.png");

		sr_Ui = rock9->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 10 생성 및 이미지 로드
		Rock* rock10 = object::Instantiate<Rock>(eLayerType::Rock);
		rock10->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 5));
		pointerMap4[5][6] = rock10;

		//Transform* tr_Rock10 = rock10->GetComponent<Transform>();
		//tr_Rock10->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 6, LeftTop.y + MOVE_TILE_HEIGHT * 5));

		T_Ui = Resources::Load<Texture>(L"Rock1"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock001.png");

		sr_Ui = rock10->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 11 생성 및 이미지 로드
		Rock* rock11 = object::Instantiate<Rock>(eLayerType::Rock);
		rock11->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 3));
		pointerMap4[3][7] = rock11;

		//Transform* tr_Rock11 = rock11->GetComponent<Transform>();
		//tr_Rock11->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 3));

		T_Ui = Resources::Load<Texture>(L"Rock3"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock003.png");

		sr_Ui = rock11->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 12 생성 및 이미지 로드
		Rock* rock12 = object::Instantiate<Rock>(eLayerType::Rock);
		rock12->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 4));
		pointerMap4[4][7] = rock12;

		//Transform* tr_Rock12 = rock12->GetComponent<Transform>();
		//tr_Rock12->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		T_Ui = Resources::Load<Texture>(L"Rock7"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock007.png");

		sr_Ui = rock12->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Rock 13 생성 및 이미지 로드
		Rock* rock13 = object::Instantiate<Rock>(eLayerType::Rock);
		rock13->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8, LeftTop.y + MOVE_TILE_HEIGHT * 4));
		pointerMap4[4][8] = rock13;

		//Transform* tr_Rock13 = rock13->GetComponent<Transform>();
		//tr_Rock13->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 8, LeftTop.y + MOVE_TILE_HEIGHT * 4));

		T_Ui = Resources::Load<Texture>(L"Rock10"
			, L"..\\Resources\\Texture\\obstacle\\rock\\Rock010.png");

		sr_Ui = rock13->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Key 생성 및 이미지 로드
		Key* myKey = object::Instantiate<Key>(eLayerType::myKey);
		myKey->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		//Transform* tr_Key = myKey->GetComponent<Transform>();
		//tr_Key->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 4, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		at = myKey->AddComponent<Animator>();
		at->CreateAnimationFolder(L"myKey", L"..\\Resources\\Texture\\obstacle\\Key", Vector2(10.0f, 0.0f));
		at->PlayAnimation(L"myKey", true);
		at->SetScale(Vector2(0.8f, 0.8f));


		// LockBox 생성 및 이미지 로드
		LockBox* lockbox = object::Instantiate<LockBox>(eLayerType::LockBox);
		lockbox->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 2));

		//Transform* tr_Box = lockbox->GetComponent<Transform>();
		//tr_Box->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7, LeftTop.y + MOVE_TILE_HEIGHT * 2));

		T_Ui = Resources::Load<Texture>(L"Box"
			, L"..\\Resources\\Texture\\obstacle\\lockbox\\lockbox001.png");

		sr_Ui = lockbox->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1 base
		Fire* Fire4_1base = object::Instantiate<Fire>(eLayerType::Fire);
		Fire4_1base->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3 - 3, LeftTop.y + MOVE_TILE_HEIGHT * 0 + 10));

		//Transform* tr4_1Firebase = Fire4_1base->GetComponent<Transform>();
		//tr4_1Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3 - 3, LeftTop.y + MOVE_TILE_HEIGHT * 0 + 10));

		T_Ui = Resources::Load<Texture>(L"Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		sr_Ui = Fire4_1base->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Fire 1
		Fire* Fire4_1 = object::Instantiate<Fire>(eLayerType::Fire);
		Fire4_1->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 0));

		//Transform* tr4_1Fire = Fire4_1->GetComponent<Transform>();
		//tr4_1Fire->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 3, LeftTop.y + MOVE_TILE_HEIGHT * 0));

		at = Fire4_1->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Fire", L"..\\Resources\\Texture\\fire\\fire", Vector2(-2.0f, -25.0f));
		at->PlayAnimation(L"Fire", true);
		at->SetScale(Vector2(0.4f, 0.5f));


		// Fire 2 base
		Fire* Fire4_2base = object::Instantiate<Fire>(eLayerType::Fire);
		Fire4_2base->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7 - 7, LeftTop.y + MOVE_TILE_HEIGHT * 0 - 25));

		//Transform* tr4_2Firebase = Fire4_2base->GetComponent<Transform>();
		//tr4_2Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 7 - 7, LeftTop.y + MOVE_TILE_HEIGHT * 0 - 25));

		T_Ui = Resources::Load<Texture>(L"NoneBase"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0002.png");

		sr_Ui = Fire4_2base->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Fire 3 base
		Fire* Fire4_3base = object::Instantiate<Fire>(eLayerType::Fire);
		Fire4_3base->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 9 - 12, LeftTop.y + MOVE_TILE_HEIGHT * 0 - 20));

		//Transform* tr4_3Firebase = Fire4_3base->GetComponent<Transform>();
		//tr4_3Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 9 - 12, LeftTop.y + MOVE_TILE_HEIGHT * 0 - 20));

		T_Ui = Resources::Load<Texture>(L"NoneBase"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0002.png");

		sr_Ui = Fire4_3base->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Fire 4 base
		Fire* Fire4_4base = object::Instantiate<Fire>(eLayerType::Fire);
		Fire4_4base->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 10 - 13, LeftTop.y + MOVE_TILE_HEIGHT * 2 - 20));

		//Transform* tr4_4Firebase = Fire4_4base->GetComponent<Transform>();
		//tr4_4Firebase->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 10 - 13, LeftTop.y + MOVE_TILE_HEIGHT * 2 - 20));

		T_Ui = Resources::Load<Texture>(L"Base"
			, L"..\\Resources\\Texture\\fire\\FLAMEbase0001.png");

		sr_Ui = Fire4_4base->AddComponent<SpriteRenderer>();
		sr_Ui->SetImage(T_Ui);
		sr_Ui->SetScale(Vector2(0.75f, 0.75f));


		// Fire 2
		Fire* Fire4_2 = object::Instantiate<Fire>(eLayerType::Fire);
		Fire4_2->GetComponent<Transform>()->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 10, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		//Transform* tr4_2Fire = Fire4_2->GetComponent<Transform>();
		//tr4_2Fire->SetPosition(Vector2(LeftTop.x + MOVE_TILE_WIDTH * 10, LeftTop.y + MOVE_TILE_HEIGHT * 1));

		at = Fire4_2->AddComponent<Animator>();
		at->CreateAnimationFolder(L"Fire", L"..\\Resources\\Texture\\fire\\fire", Vector2(-10.0f, 10.0f));
		at->PlayAnimation(L"Fire", true);
		at->SetScale(Vector2(0.4f, 0.5f));
	}

	void Chapter4::Update()
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
			Sound* Sound_SC5 = Resources::Load<Sound>(L"SceneChange5", L"..\\Resources\\Sound\\screen_changer_part1_01.wav");
			Sound_SC5->Play(false);

			SceneManager::LoadScene(L"Chapter5");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter6))
		{
			SceneManager::LoadScene(L"Chapter6");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter7))
		{
			SceneManager::LoadScene(L"Chapter7");
		}
		if (Input::GetKeyDown(eKeyCode::Chapter8))
		{
			SceneManager::LoadScene(L"Chapter8");
		}
	}

	void Chapter4::Render(HDC hdc)
	{
		Scene::Render(hdc);

		//int maxRow = 720 / (TILE_HEIGHT * 3) + 1;
		//for (size_t y = 0; y < maxRow; y++)
		//{
		//	MoveToEx(hdc, 0, TILE_HEIGHT * y * 4 - 15, NULL);      //      라인(선) 시작
		//	LineTo(hdc, 1280, TILE_HEIGHT * y * 4 - 15);        //          라인(선) 끝
		//}

		//int maxColumn = 1280 / (TILE_WIDTH * 3) + 1;
		//for (size_t x = 0; x < maxColumn; x++)
		//{
		//	MoveToEx(hdc, TILE_WIDTH * x * 4, 0, NULL);      //      라인(선) 시작
		//	LineTo(hdc, TILE_WIDTH * x * 4, 720);        //          라인(선) 끝
		//}
	}
}

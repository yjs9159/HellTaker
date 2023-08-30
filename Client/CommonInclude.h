#pragma once
#include <vector>
#include <list>	// 링크드리스트
#include <map>	// 트리
#include <set>	// 
#include <functional>	// 함수포인터
#include <string>
#include <filesystem>
#include <bitset>
#include <assert.h>

#include "framework.h"	
#include "yaMath.h"

#pragma comment(lib, "Msimg32.lib")

#include <mmsystem.h>
#include <dsound.h>
#include <dinput.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dsound.lib")

#define TILE_WIDTH 18
#define TILE_HEIGHT 17

#define MOVE_TILE_WIDTH 72
#define MOVE_TILE_HEIGHT 68

namespace ya::enums
{
	enum class eLayerType
	{
		BackGround,
		Tile,
		Floor,
		Player,
		Monster,
		Npc,
		Rock,
		myKey,
		LockBox,
		Fire,
		UI,
		Effect,
		SceneChange,
		End,
	};

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animation,
		Animator,
		Collider,
		Rigidbody,
		End,
	};
}
#pragma once
#include <vector>
#include <list>	// ��ũ�帮��Ʈ
#include <map>	// Ʈ��
#include <set>	// 
#include <functional>	// �Լ�������
#include <string>
#include <filesystem>
#include <bitset>

#include "framework.h"	
#include "yaMath.h"

#pragma comment(lib, "Msimg32.lib")

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
		Effect,
		UI,
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
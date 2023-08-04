#pragma once
#include <vector>
#include <list>	// 링크드리스트
#include <map>	// 트리
#include <set>	// 
#include <functional>	// 함수포인터
#include <string>
#include <filesystem>
#include <bitset>

#include "framework.h"	
#include "yaMath.h"

#pragma comment(lib, "Msimg32.lib")

namespace ya::enums
{
	enum class eLayerType
	{
		BackGround,
		Tile,
		Floor,
		Player,
		Monster,
		Rock,
		Effect,
		UI,
		End,
	};

	enum class eComponentType
	{
		Transform,
		Spriterenderer,
		Animation,
		Animator,
		Collider,
		Rigidbody,
		End,
	};
}
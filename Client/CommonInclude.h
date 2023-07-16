#pragma once
#include <vector>
#include <list>	// 링크드리스트
#include <map>	// 트리
#include <set>	// 
#include <functional>	// 함수포인터
#include <string>

#include "framework.h"	
#include "yaMath.h"

#pragma comment(lib, "Msimg32.lib")

namespace ya::enums
{
	enum class eLayerType
	{
		BackGround,
		Player,
		Monster,
		Effect,
		UI,
		End,
	};

	enum class eComponentType
	{
		Transform,
		Spriterenderer,
		End,
	};
}
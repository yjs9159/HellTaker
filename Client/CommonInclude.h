#pragma once
#include <vector>
#include <list>	// ��ũ�帮��Ʈ
#include <map>	// Ʈ��
#include <set>	// 
#include <functional>	// �Լ�������
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
#pragma once
#include <vector>
#include <list>	// ��ũ�帮��Ʈ
#include <map>	// Ʈ��
#include <set>	// 
#include <functional>	// �Լ�������
#include <string>
//#include <gdiplus.h>
//
//#pragma comment(lib, "Gdiplus.lib")
#pragma comment(lib, "Msimg32.lib")

#include "framework.h"	
#include "yaMath.h"


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
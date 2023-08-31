#pragma once
#include "yaScene.h"

namespace ya
{
	class Chapter2 : public Scene
	{
	public:
		Chapter2();
		virtual ~Chapter2();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		static int MapInfo2[8][9];
		GameObject* pointerMap2[8][9];

		math::Vector2 LeftTop;
	private:
		bool Animation_play;
	};
}


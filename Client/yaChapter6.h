#pragma once
#include "yaScene.h"

namespace ya
{
	class Chapter6 : public Scene
	{
	public:
		Chapter6();
		virtual ~Chapter6();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		static int MapInfo6[10][9];
	private:
		math::Vector2 LeftTop;

	};
}


#pragma once
#include "yaScene.h"

namespace ya
{
	class Chapter8 : public Scene
	{
	public:
		Chapter8();
		virtual ~Chapter8();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		static int MapInfo8[8][11];
	private:
		math::Vector2 LeftTop;

	};
}


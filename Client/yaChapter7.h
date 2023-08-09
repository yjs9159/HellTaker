#pragma once
#include "yaScene.h"

namespace ya
{
	class Chapter7 : public Scene
	{
	public:
		Chapter7();
		virtual ~Chapter7();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

	private:
		math::Vector2 LeftTop;

	};
}


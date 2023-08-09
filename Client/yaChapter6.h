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

	private:
		math::Vector2 LeftTop;

	};
}


#pragma once
#include "yaScene.h"

namespace ya
{
	class Chapter3 : public Scene
	{
	public:
		Chapter3();
		virtual ~Chapter3();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

	private:
		math::Vector2 LeftTop;

	};
}


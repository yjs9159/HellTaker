#pragma once
#include "yaScene.h"

namespace ya
{
	class Chapter5 : public Scene
	{
	public:
		Chapter5();
		virtual ~Chapter5();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

	private:
		math::Vector2 LeftTop;

	};
}


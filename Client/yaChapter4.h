#pragma once
#include "yaScene.h"

namespace ya
{
	class Chapter4 : public Scene
	{
	public:
		Chapter4();
		virtual ~Chapter4();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

	private:
		math::Vector2 LeftTop;

	};
}

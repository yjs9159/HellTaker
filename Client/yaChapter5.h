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

		static int MapInfo5[9][8];
		GameObject* pointerMap5[9][8];

		math::Vector2 LeftTop;
	
	private:

	};
}


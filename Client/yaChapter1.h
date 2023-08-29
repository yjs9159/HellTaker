#pragma once
#include "yaScene.h"

namespace ya
{
	class Chapter1 : public Scene
	{
	public:
		Chapter1();
		virtual ~Chapter1();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		static int MapInfo1[8][9];

	private:
		math::Vector2 LeftTop;
		std::wstring NextScene = L"";
		bool Animation_play;
	};
}


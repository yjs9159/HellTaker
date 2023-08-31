#pragma once
#include "yaScene.h"
#include "yaGameObject.h"

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
		GameObject* pointerMap1[8][9];

		math::Vector2 LeftTop;
	private:
		bool Animation_play;
	};
}


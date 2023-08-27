#pragma once
#include "yaScene.h"

namespace ya
{
	class StartScene : public Scene
	{
	public:
		StartScene();
		virtual ~StartScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}


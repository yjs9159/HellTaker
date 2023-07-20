#pragma once
#include "yaScene.h"

namespace ya
{
	class HomeScene : public Scene
	{
	public:
		HomeScene();
		virtual ~HomeScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}

#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Ui : public GameObject
	{
	public:
		Ui();
		virtual ~Ui();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;


	private:

	};
}


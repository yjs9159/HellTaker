#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Fire : public GameObject
	{
	public:
		Fire();
		~Fire();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:

	};

}


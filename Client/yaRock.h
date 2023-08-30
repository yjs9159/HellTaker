#pragma once
#include "yaGameObject.h"


namespace ya
{
	class Rock : public GameObject
	{
	public:

		Rock();
		virtual ~Rock();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void RockHit(int _dir);
		void RockMove();

	private:
		int dir;
	};
}
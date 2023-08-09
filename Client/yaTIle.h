#pragma once
#include "yaGameObject.h"


namespace ya
{
	enum class TTYPE
	{
		NO,//NE,
		WA,//LL,
		PL,//ayer
		NP,//C,
		UN,//dead,
		RO,//ck
		LO,//ckBox

		EN,//D
	};

	enum class OTYPE
	{
		NO,//NE,
		SP,//ike always,
		SO,//pike on,
		SF,// pike off,
		KE,//Y
		EN,//D
	};

	class Tile : public GameObject
	{
	public:
		static UINT mSelectedX;
		static UINT mSelectedY;

		Tile();
		~Tile();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void SetTile(int x, int y);

	private:
		class SpriteRenderer* mSpriteRenderer;
		//std::vector<std::pair<TTYPE, >>

	};
}

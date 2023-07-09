#pragma once
#include "CommonInclude.h"
#include "Scene.h"

namespace ya
{
	using namespace math;
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;
		UINT mWidth;
		UINT mHeight;

		HDC mBackHdc;
		HBITMAP mBackBuffer;	

		Scene* mScene;
	};
}



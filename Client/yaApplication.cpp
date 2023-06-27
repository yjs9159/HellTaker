#include "yaApplication.h"
//#include <imgui>
//#include "imgui.h"

namespace ya
{
	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mPlayerPos.x -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mPlayerPos.x += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mPlayerPos.y -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mPlayerPos.y += 0.01f;
		}
	}

	void Application::Render()
	{
		//Rectangle(mHdc, 100, 100, 200, 200);
		Ellipse(mHdc, 100 + mPlayerPos.x, 100 + mPlayerPos.y
			, 200 + mPlayerPos.x, 200 + mPlayerPos.y);
	}
}

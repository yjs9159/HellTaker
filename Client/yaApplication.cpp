#include "yaApplication.h"
//#include <imgui>
//#include "imgui.h"
#include "yaInput.h"

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

		Input::Initialize();
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		Input::Update();

		if (Input::GetKey(eKeyCode::W))
		{
			mPlayerPos.y -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::A))
		{
			mPlayerPos.x -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mPlayerPos.y += 0.01f;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mPlayerPos.x += 0.01f;
		}
	}

	void Application::Render()
	{
		//Rectangle(mHdc, 100, 100, 200, 200);
		Ellipse(mHdc, 100 + mPlayerPos.x, 100 + mPlayerPos.y
			, 200 + mPlayerPos.x, 200 + mPlayerPos.y);
	}
}

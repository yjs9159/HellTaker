#include "yaApplication.h"
//#include <imgui>
//#include "imgui.h"
#include "yaInput.h"
#include "yaTime.h"
#include <time.h>

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

		Time::Initialize();
		Input::Initialize();
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();

		//if (Input::GetKey(eKeyCode::W))
		//{
		//	mPlayerPos.y -= 300.0f * Time::Deltatime();
		//}
		//if (Input::GetKey(eKeyCode::A))
		//{
		//	mPlayerPos.x -= 300.0f * Time::Deltatime();
		//}
		//if (Input::GetKey(eKeyCode::S))
		//{
		//	mPlayerPos.y += 300.0f * Time::Deltatime();
		//}
		//if (Input::GetKey(eKeyCode::D))
		//{
		//	mPlayerPos.x += 300.0f * Time::Deltatime();
		//}

		srand(static_cast<unsigned int>(time(0)));
		mRandom = rand() % 8;

		if (mRandom == 0) // 위
		{
			// x, y가 150, 150
			// 윈도우 크기는 1600, 900

			mPlayerPos.y -= 300.0f * Time::Deltatime();

			if (mPlayerPos.y <= 150)
			{
				mRandom = rand() % 8;
			}
		}

		else if (mRandom == 1) // 오른쪽 위 대각선
		{
			mPlayerPos.x += 300.0f * Time::Deltatime();
			mPlayerPos.y -= 300.0f * Time::Deltatime();

			if (mPlayerPos.x >= 1550 || mPlayerPos.y <= 150)
			{
				mRandom = rand() % 8;
			}
		}

		else if (mRandom == 2) // 오른쪽
		{
			mPlayerPos.x += 300.0f * Time::Deltatime();

			if (mPlayerPos.x >= 1450)
			{
				mRandom = rand() % 8;
			}
		}

		else if (mRandom == 3) // 오른쪽 아래 대각선
		{
			mPlayerPos.x += 300.0f * Time::Deltatime();
			mPlayerPos.y += 300.0f * Time::Deltatime();

			if (mPlayerPos.x >= 1550 || mPlayerPos.y >= 750)
			{
				mRandom = rand() % 8;
			}
		}

		else if (mRandom == 4) // 아래
		{
			mPlayerPos.y += 300.0f * Time::Deltatime();

			if (mPlayerPos.y >= 750)
			{
				mRandom = rand() % 8;
			}
		}

		else if (mRandom == 5) // 왼쪽 아래 대각선
		{
			mPlayerPos.x -= 300.0f * Time::Deltatime();
			mPlayerPos.y += 300.0f * Time::Deltatime();

			if (mPlayerPos.x <= 150 || mPlayerPos.y >= 750)
			{
				mRandom = rand() % 8;
			}
		}

		else if (mRandom == 6) // 왼쪽
		{
			mPlayerPos.x -= 300.0f * Time::Deltatime();

			if (mPlayerPos.x <= 150)
			{
				mRandom = rand() % 8;
			}
		}

		else if (mRandom == 7) // 왼쪽 위 대각선
		{
			mPlayerPos.x -= 300.0f * Time::Deltatime();
			mPlayerPos.y -= 300.0f * Time::Deltatime();

			if (mPlayerPos.x <= 150 || mPlayerPos.y >= 150)
			{
				mRandom = rand() % 8;
			}
		}

		
		
	}

	void Application::Render()
	{
		Time::Render(mHdc);
		//Rectangle(mHdc, 100, 100, 200, 200);
		Ellipse(mHdc, 100 + mPlayerPos.x, 100 + mPlayerPos.y
			, 200 + mPlayerPos.x, 200 + mPlayerPos.y);
	}
}

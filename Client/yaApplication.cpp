#include "yaApplication.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaTitleScene.h"
#include "yaSceneManager.h"
#include "yaCamera.h"
#include "yaCollisionManager.h"
#include "yaSoundManager.h"

namespace ya
{
	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
		, mBackBuffer(NULL)
		, mBackHdc(NULL)
	{

	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		mWidth = 1280;
		mHeight = 720;


		RECT rect = { 0, 0, mWidth, mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHwnd
			, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(mHwnd, true);

		// 윈도우 해상도 동일한 비트맵 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);

		// 새로 생성한 비트맵을 가리키는 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		// 새로 생성한 비트맵과 DC를 서로 연결
		HBITMAP defaultBitmap
			= (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(defaultBitmap);

		Time::Initialize();
		Input::Initailize();
		SoundManager::Initialize();
		Camera::Initialize();

		CollisionManager::Initialize();
		SceneManager::Initialize();

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
		Camera::Update();

		CollisionManager::Update();
		SceneManager::Update();

	}

	void Application::Render()
	{
		HBRUSH brush = CreateSolidBrush(RGB(125, 125, 125));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, brush);
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);
		SelectObject(mBackHdc, oldBrush);
		DeleteObject(brush);

		Time::Render(mBackHdc);

		CollisionManager::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		BitBlt(mHdc, 0, 0, mWidth, mHeight
			, mBackHdc, 0, 0, SRCCOPY);
	}
}
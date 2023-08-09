#include "yaInput.h"
#include "yaApplication.h"

extern ya::Application application;

namespace ya
{
	std::vector<Input::Key> Input::mKeys = {};
	math::Vector2 Input::mMousePosition = math::Vector2::Zero;

	int ASCII[(int)eKeyCode::End] =
	{
		'1', '2', '3', '4', '5', '6', '7', '8',
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT,
		VK_LBUTTON, VK_RBUTTON, VK_MBUTTON,
		VK_SPACE,
	};

	void Input::Initailize()
	{
		for (size_t i = 0
			; i < (int)eKeyCode::End
			; i++)
		{
			Key key = {};
			key.code = (eKeyCode)i;
			key.state = eKeyState::None;
			key.bPressed = false;

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0
			; i < (int)eKeyCode::End
			; i++)
		{
			// �ش�Ű�� ��������.
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// ���� �����ӿ��� ������ �־���.
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Pressed;
				else
					mKeys[i].state = eKeyState::Down;

				mKeys[i].bPressed = true;
			}
			else // �ش�Ű�� �ȴ����� �ִ�.
			{
				// ���������ӿ� ������ �־���.
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Up;
				else
					mKeys[i].state = eKeyState::None;

				mKeys[i].bPressed = false;
			}
		}

		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(application.GetHwnd(), &mousePos);
		mMousePosition.x = (float)mousePos.x;
		mMousePosition.y = (float)mousePos.y;

	}
}

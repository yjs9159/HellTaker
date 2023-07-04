#include "yaInput.h"
#

namespace ya
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(int)eKeyCode::END] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	};

	void Input::Initialize()
	{
		for (size_t i = 0
			; i < (int)eKeyCode::END
			; i++)
		{
			Key Key = {};
			Key.code = (eKeyCode)i;
			Key.State = eKeyState::None;
			Key.bPressed = false;

			mKeys.push_back(Key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0
			; i < (int)eKeyCode::END
			; i++)
		{
			// �ش� Ű�� ��������
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// ���� �����ӿ��� ������ �־���
				if (mKeys[i].bPressed == true)
					mKeys[i].State = eKeyState::Pressed;
				else
					mKeys[i].State = eKeyState::Down;

				mKeys[i].bPressed = true;
			}

			else // �ش� Ű�� �ȴ����� �ִ�
			{
				// ���� �����ӿ� ������ �־���
				if (mKeys[i].bPressed == true)
					mKeys[i].State = eKeyState::Up;
				else
					mKeys[i].State = eKeyState::None;

				mKeys[i].bPressed = false;
			}
		}
	}
}


#pragma once
#include "CommonInclude.h"

namespace ya
{
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L, 
		Z, X, C, V, B, N, M,
		END,
	};

	// Ű�� ����
	enum class eKeyState // enum�� ���ڸ� ���ڷ� �ٲܼ� �ִ� ����
	{
		Down,	// 0
		Up,		// 1
		Pressed,// 2
		None,	// 3
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode code;
			eKeyState State;
			bool bPressed;
		};

		static void Initialize();
		static void	Update();

		static bool GetKeyDown(eKeyCode code) { return mKeys[(int)code].State == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return mKeys[(int)code].State == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return mKeys[(int)code].State == eKeyState::Pressed; }


	private:
		static std::vector<Key> mKeys;
	};
}


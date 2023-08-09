#pragma once
#include "CommonInclude.h"

namespace ya
{
	enum class eKeyCode
	{
		Chapter1, Chapter2, Chapter3, Chapter4, Chapter5, Chapter6, Chapter7, Chapter8,
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Up, Down, Left, Right,
		MouseLeft, MouseRight, MouseWheel,
		Space,
		End,
	};
	enum class eKeyState
	{
		Down,
		Up,
		Pressed,
		None,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode code;
			eKeyState state;
			bool bPressed;
		};

		static void Initailize();
		static void Update();

		__forceinline static bool GetKeyDown(eKeyCode code)
		{
			return mKeys[(int)code].state == eKeyState::Down;
		}
		__forceinline static bool GetKeyUp(eKeyCode code)
		{
			return mKeys[(int)code].state == eKeyState::Up;
		}
		__forceinline static bool GetKey(eKeyCode code)
		{
			return mKeys[(int)code].state == eKeyState::Pressed;
		}
		__forceinline static math::Vector2 GetMousePosition()
		{
			return mMousePosition;
		}

	private:
		static std::vector<Key> mKeys;
		static math::Vector2 mMousePosition;
	};
}

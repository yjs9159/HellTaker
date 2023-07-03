#pragma once
#include "CommonInclude.h"

namespace ya
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		
		__forceinline static float Deltatime() { return mDeltaTime; };

	private:
		static LARGE_INTEGER mCpuFrequency;
		static LARGE_INTEGER mPrevFrequency;
		static LARGE_INTEGER mCurFrequency;
		static float mDeltaTime;
	};
}

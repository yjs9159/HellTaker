#pragma once
#include "yaEntity.h"

namespace ya
{
	class Resource : public Entity
	{
	public:
		Resource();
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; 
		// 순수가상함수 => 이 클래스는 추상클래스가 된다
		// 자식 클래스는 무조건 이 함수를 override받는다

		std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		std::wstring mPath;
	};
}

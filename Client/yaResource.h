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
		// ���������Լ� => �� Ŭ������ �߻�Ŭ������ �ȴ�
		// �ڽ� Ŭ������ ������ �� �Լ��� override�޴´�

		std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		std::wstring mPath;
	};
}

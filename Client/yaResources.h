#pragma once
#include "yaResource.h"

namespace ya
{
	class Resources
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& name)
		{
			auto iter = mResources.find(name);
			if (iter == mResources.end())
				return nullptr;

			return dynamic_cast<T*>(iter->second);
		}
		// 리소스 로드하는 함수
		template <typename T>
		static T* Load(const std::wstring& name, const std::wstring& path)
		{
			T* resource = Resources::Find<T>(name);

			if (resource != nullptr)
				return resource;

			resource = new T();
			if (FAILED(resource->Load(path)))
			{
				MessageBox(nullptr, L"Resource Load Failed!", L"Error", MB_OK);
				delete resource;
				return nullptr;
			}

			resource->SetName(name);
			resource->SetPath(path);
			mResources.insert(std::make_pair(name, resource));

			return resource;
		}

	private:
		static std::map<std::wstring /*키*/, Resource* /*실제 데이터*/> mResources;
	};
}

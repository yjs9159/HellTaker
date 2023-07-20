#pragma once
#include "yaScene.h"


namespace ya
{
	class SceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		template <typename T>
		static T* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			mScenes.insert(std::make_pair(name, scene));
			mActiveScene = scene;
			scene->Initialize();

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name);
		static Scene* GetActiveScene() { return mActiveScene; }

	private:
		// Ʈ�� �ڷᱸ��
		static std::map<std::wstring, Scene*> mScenes;
		static Scene* mActiveScene;
		// key value ������ �̷���� �ֵ�.
		// key�� �����͸� �˻��ϴ� �뵵
		// value ���� �츮�� ����� ������
	};
}


//class Parent
//{
//public:
//	void Test();
//};
//
//class Child : public Parent
//{
//public:
//	void Howlring()
//	{
//
//	}
//};
//
//Parent* pp = new Child();
//pp->Test();
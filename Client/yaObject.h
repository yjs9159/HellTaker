#pragma once
#include "yaScene.h"
#include "yaGameObject.h"
#include "yaSceneManager.h"


namespace ya::object
{
	template <typename T>
	static __forceinline T* Instantiate(eLayerType type)
	{
		T* gameObject = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameObject);

		return gameObject;
	}


}

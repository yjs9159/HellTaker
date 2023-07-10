#pragma once
#include "yaScene.h"
#include "yaGameObject.h"
#include "yaSceneManager.h"

namespace ya :: Object
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
#pragma once
#include "yaGameObject.h"


namespace ya
{
	using namespace math;
	class Camera
	{
	public:
		static void Initialize();
		static void Update();

		static Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; }

		static GameObject* GetTarget() { return mTarget; }
		static void SetTarget(GameObject* target) { mTarget = target; }


	private:
		static Vector2 mResolution;		// ȭ�� �ػ�
		static Vector2 mLookPosition;	// ī�޶� �ٶ󺸰� �ִ� ��ġ
		static Vector2 mDistance;		// ����� �������� �̵��� �Ÿ�
		static GameObject* mTarget;		// ī�޶� �ٶ󺸴� ���� ������Ʈ
	};
}

#include "yaToolScene.h"
#include "yaTitleScene.h"
#include "yaPlayer.h"
#include "yaSpriteRenderer.h"
#include "yaObject.h"
#include "yaInput.h"
#include "yaTexture.h"
#include "yaTransform.h"
#include "yaResources.h"
#include "yaBackGround.h"
#include "yaCamera.h"
#include "yaTile.h"

namespace ya
{
	ToolScene::ToolScene()
	{
	}
	ToolScene::~ToolScene()
	{
	}
	void ToolScene::Initialize()
	{
		Texture* springFloor
			= Resources::Load<Texture>(L"SprintFloorTile", L"..\\Resources\\Texture\\Maps\\SpringFloor.bmp");

		Tile* tile
			= object::Instantiate<Tile>(eLayerType::Tile, Vector2(600.0f, 400.0f));
	}

	void ToolScene::Update()
	{
		Scene::Update();



	}
	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		int maxRow = 720 / (TILE_HEIGHT * 3) + 1;
		for (size_t y = 0; y < maxRow; y++)
		{
			MoveToEx(hdc, 0, TILE_HEIGHT * y * 3, NULL);      //      라인(선) 시작
			LineTo(hdc, 1280, TILE_HEIGHT * y * 3);        //          라인(선) 끝
		}

		int maxColumn = 1280 / (TILE_WIDTH * 3) + 1;
		for (size_t x = 0; x < maxColumn; x++)
		{
			MoveToEx(hdc, TILE_WIDTH * x * 3, 0, NULL);      //      라인(선) 시작
			LineTo(hdc, TILE_WIDTH * x * 3, 720);        //          라인(선) 끝
		}
	}
}

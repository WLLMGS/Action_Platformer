#include "stdafx.h"
#include "DungeonScene.h"
#include "CharacterPrefab.h"


DungeonScene::DungeonScene() :
Scene("Dungeon Scene")
{
	auto player = new CharacterPrefab();
	AddChild(player);

	player->Transform()->SetScale(4, 4, 4);
	player->Transform()->SetPosition(200.0f, 200.0f);
}


DungeonScene::~DungeonScene()
{
}

void DungeonScene::Update(float elapsedSec)
{
}

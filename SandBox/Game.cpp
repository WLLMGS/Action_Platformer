#include "stdafx.h"
#include "Game.h"
#include "SceneManager.h"

#include "DungeonScene.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::LoadGameData()
{
	dae::SceneManager::GetInstance().AddScene(new DungeonScene());
}

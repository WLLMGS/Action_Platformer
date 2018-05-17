#pragma once
#include "Scene.h"

class DungeonScene : public dae::Scene
{
public:
	DungeonScene();
	~DungeonScene();
	virtual void Update(float elapsedSec) override;

private:

};


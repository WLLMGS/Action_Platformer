#pragma once
#include "GameObject.h"
#include "SpriteComponent.h"

class CharacterPrefab : public dae::GameObject
{
	enum State
	{
		Idle = 0,
		Running = 1,
		Jumping = 2
	};

public:
	CharacterPrefab();
	~CharacterPrefab();
	virtual void Update(float elapsedSec) override;
private:
	State m_PreviousState = Idle;
	State m_State = Idle;
	const float m_Speed = 150.0f;
	dae::SpriteComponent* m_pSpriteComp = nullptr;
private:
	void HandleControls(float elapsedSec);
	void HandleAnimations();
};


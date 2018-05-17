#include "stdafx.h"
#include "CharacterPrefab.h"
#include "SpriteComponent.h"
#include "ResourceManager.h"
#include "InputManager.h"


CharacterPrefab::CharacterPrefab()
{
	m_pSpriteComp = new dae::SpriteComponent(dae::MAIN_CHARACTER);
	m_pSpriteComp->SetAnimated(true);

	//idle
	//sprite->SetAnimationParameters(4, 4, 32, 32);

	//run
	/*sprite->SetAnimationParameters(8, 8, 32, 32);
	sprite->SetStartHeight(33.0f);*/

	//jump
	m_pSpriteComp->SetAnimationParameters(6, 6, 32, 32);
	m_pSpriteComp->SetStartHeight(204.0f);

	AddComponent(m_pSpriteComp);
}


CharacterPrefab::~CharacterPrefab()
{
}

void CharacterPrefab::Update(float elapsedSec)
{
	
	HandleControls(elapsedSec);
}

void CharacterPrefab::HandleControls(float elapsedSec)
{
	auto& input = dae::InputManager::GetInstance();

	float x{ 0.0f }, y{ 0.0f };

	input.GetThumbstickLeft(x, y);


	if (input.IsKeyPressed(SDLK_d))
	{
		x = 1;
	}
	if (input.IsKeyPressed(SDLK_q))
	{
		x = -1;
	}

	if(x != 0.0f && m_State != Running)
	{
		m_State = Running;
		HandleAnimations();
	}
	else if(x == 0.0f && m_State == Running)
	{
		m_State = Idle;
		HandleAnimations();
	}

	Transform()->Translate(m_Speed * elapsedSec * x, 0.0f, 0.0f);
}

void CharacterPrefab::HandleAnimations()
{
	switch(m_State)
	{
	case Idle:
		m_pSpriteComp->SetAnimationParameters(4, 4, 32, 32);
		m_pSpriteComp->SetStartHeight(0.0f);
		break;
	case Running:
		m_pSpriteComp->SetAnimationParameters(8, 8, 32, 32);
		m_pSpriteComp->SetStartHeight(33.0f);
		break;
	case Jumping:
		m_pSpriteComp->SetAnimationParameters(6, 6, 32, 32);
		m_pSpriteComp->SetStartHeight(204.0f);
		break;
	}

	
}

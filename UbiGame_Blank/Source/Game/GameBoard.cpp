#include "GameBoard.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/Components/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h" //<-- Remember to include the new component we will use

using namespace Game;

GameBoard::GameBoard()
{
    CreatePlayer();
}

void GameBoard::CreatePlayer()
{
    m_player = new GameEngine::Entity();                            // <-- Create new entity
    GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player); // <-- Add the entity to the engine

    m_player->SetPos(sf::Vector2f(50.0f, 50.0f));            // <-- Give the position 10,10 to the entity
    m_player->SetSize(sf::Vector2f(50.0f, 50.0f));           // <-- Give the size 10,10 to the entity

    GameEngine::SpriteRenderComponent* render = m_player->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

    render->SetFillColor(sf::Color::Transparent);
    render->SetTexture(GameEngine::eTexture::Player);  // <-- Assign the texture to this entity

    //Movement
    m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}
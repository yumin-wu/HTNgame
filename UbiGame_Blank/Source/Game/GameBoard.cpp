#include "GameBoard.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/Components/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

using namespace Game;

GameBoard::GameBoard()
{
    CreatePlayer();
    CreateWall();
    CreateBackground();
}

void GameBoard::CreatePlayer()
{
    m_player = new GameEngine::Entity();                            // <-- Create new entity
    GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player); // <-- Add the entity to the engine

    m_player->SetPos(sf::Vector2f(32.0f, 32.0f));            // <-- Give the position to the entity
    m_player->SetSize(sf::Vector2f(32.0f, 32.0f));           // <-- Give the size to the entity

    GameEngine::SpriteRenderComponent* render = m_player->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

    render->SetFillColor(sf::Color::White);
    render->SetTexture(GameEngine::eTexture::PlayerDown);  // <-- Assign the texture to this entity

    //Movement
    m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player
    m_player->AddComponent<GameEngine::AnimationComponent>();

    m_player->AddComponent<GameEngine::CollidablePhysicsComponent>();
}

void GameBoard::CreateWall() {
    GameEngine::Entity* wall = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(wall);

    wall->SetPos(sf::Vector2f(48.f, 48.f));
    wall->SetSize(sf::Vector2f(96.f, 96.f));

    //Render
    GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
            (wall->AddComponent<GameEngine::SpriteRenderComponent>());

    spriteRender->SetFillColor(sf::Color::Transparent);
    spriteRender->SetTexture(GameEngine::eTexture::IceWall);

    wall->AddComponent<GameEngine::CollidableComponent>();
}

void GameBoard::CreateBackground() {
    GameEngine::Entity* background = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

    background->SetPos(sf::Vector2f(96.f, 160.f));
    background->SetSize(sf::Vector2f(96.f, 96.f));

    //Render
    GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
            (background->AddComponent<GameEngine::SpriteRenderComponent>());

    spriteRender->SetFillColor(sf::Color::Transparent);
    spriteRender->SetTexture(GameEngine::eTexture::IceFloor1);
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}
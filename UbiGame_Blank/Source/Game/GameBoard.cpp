#include "GameBoard.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/Components/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

using namespace Game;

GameBoard::GameBoard()
    : m_player(nullptr)
    , m_gridSize(32.f)
{
    CreatePlayer();
    CreateBackground();
    CreateLevel1();
    CreateSlimeKing();
}

void GameBoard::CreatePlayer()
{
    m_player = new GameEngine::Entity();                            // <-- Create new entity
    GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player); // <-- Add the entity to the engine
    m_player->SetEntityType(GameEngine::EEntityType::Player);

    m_player->SetPos(sf::Vector2f(48.f, 112.f));            // <-- Give the position to the entity
    m_player->SetSize(sf::Vector2f(32.0f, 32.0f));           // <-- Give the size to the entity

    GameEngine::SpriteRenderComponent* render = m_player->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

    render->SetFillColor(sf::Color::Transparent);
    render->SetTexture(GameEngine::eTexture::Player);  // <-- Assign the texture to this entity

    //Movement
    m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player
    m_player->AddComponent<GameEngine::AnimationComponent>();

    m_player->AddComponent<GameEngine::CollidablePhysicsComponent>();
}

void GameBoard::CreateBackground() {
    GameEngine::Entity* background = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

    background->SetPos(sf::Vector2f(176.f, 176.f));
    background->SetSize(sf::Vector2f(288.f, 160.f));

    //Render
    GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>
            (background->AddComponent<GameEngine::SpriteRenderComponent>());

    render->SetFillColor(sf::Color::Transparent);
    render->SetTexture(GameEngine::eTexture::IceFloor1);
    render->SetZLevel(-1);
}

void GameBoard::CreateLevel1() {
    // Top wall
    GameEngine::Entity* topWall = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(topWall);
    topWall->SetEntityType(GameEngine::EEntityType::Obstacle);

    topWall->SetPos(sf::Vector2f(160.f, 48.f));
    topWall->SetSize(sf::Vector2f(256.f, 96.f));

    // Render
    GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
    (topWall->AddComponent<GameEngine::SpriteRenderComponent>());

    spriteRender->SetFillColor(sf::Color::Transparent);
    spriteRender->SetTexture(GameEngine::eTexture::IceWall1Top);

    topWall->AddComponent<GameEngine::CollidableComponent>();

    // Left wall
    GameEngine::Entity* leftWall = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(leftWall);
    leftWall->SetEntityType(GameEngine::EEntityType::Obstacle);

    leftWall->SetPos(sf::Vector2f(16.f, 160.f));
    leftWall->SetSize(sf::Vector2f(32.f, 320.f));

    // Render
    GameEngine::SpriteRenderComponent* spriteRender2 = static_cast<GameEngine::SpriteRenderComponent*>
    (leftWall->AddComponent<GameEngine::SpriteRenderComponent>());

    spriteRender2->SetFillColor(sf::Color::Transparent);
    spriteRender2->SetTexture(GameEngine::eTexture::IceWall1Left);

    leftWall->AddComponent<GameEngine::CollidableComponent>();


    // Bottom wall
    GameEngine::Entity* bottomWall = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(bottomWall);
    bottomWall->SetEntityType(GameEngine::EEntityType::Obstacle);

    bottomWall->SetPos(sf::Vector2f(160.f, 288.f));
    bottomWall->SetSize(sf::Vector2f(256.f, 64.f));

    // Render
    GameEngine::SpriteRenderComponent* spriteRender3 = static_cast<GameEngine::SpriteRenderComponent*>
    (bottomWall->AddComponent<GameEngine::SpriteRenderComponent>());

    spriteRender3->SetFillColor(sf::Color::Transparent);
    spriteRender3->SetTexture(GameEngine::eTexture::IceWall1Bottom);

    bottomWall->AddComponent<GameEngine::CollidableComponent>();


    // Right top wall
    GameEngine::Entity* rightTopWall = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(rightTopWall);
    rightTopWall->SetEntityType(GameEngine::EEntityType::Obstacle);

    rightTopWall->SetPos(sf::Vector2f(304.f, 96.f));
    rightTopWall->SetSize(sf::Vector2f(32.f, 192.f));

    // Render
    GameEngine::SpriteRenderComponent* spriteRender4 = static_cast<GameEngine::SpriteRenderComponent*>
    (rightTopWall->AddComponent<GameEngine::SpriteRenderComponent>());

    spriteRender4->SetFillColor(sf::Color::Transparent);
    spriteRender4->SetTexture(GameEngine::eTexture::IceWall1RightTop);

    rightTopWall->AddComponent<GameEngine::CollidableComponent>();


    // Right bottom wall
    GameEngine::Entity* rightBottomWall = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(rightBottomWall);
    rightBottomWall->SetEntityType(GameEngine::EEntityType::Obstacle);

    rightBottomWall->SetPos(sf::Vector2f(304.f, 272.f));
    rightBottomWall->SetSize(sf::Vector2f(32.f, 96.f));

    // Render
    GameEngine::SpriteRenderComponent* spriteRender5 = static_cast<GameEngine::SpriteRenderComponent*>
    (rightBottomWall->AddComponent<GameEngine::SpriteRenderComponent>());

    spriteRender5->SetFillColor(sf::Color::Transparent);
    spriteRender5->SetTexture(GameEngine::eTexture::IceWall1RightBottom);

    rightBottomWall->AddComponent<GameEngine::CollidableComponent>();
}

void GameBoard::CreateSlimeKing() {
    GameEngine::Entity* slimeKing = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(slimeKing);
    slimeKing->SetEntityType(GameEngine::EEntityType::Obstacle);

    slimeKing->SetPos(sf::Vector2f(304.f, 208.f));
    slimeKing->SetSize(sf::Vector2f(32.f, 32.f));

    // Render
    GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
    (slimeKing->AddComponent<GameEngine::SpriteRenderComponent>());

    spriteRender->SetFillColor(sf::Color::Transparent);
    spriteRender->SetTexture(GameEngine::eTexture::SlimeKing);

    slimeKing->AddComponent<GameEngine::CollidableComponent>();
}

GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}
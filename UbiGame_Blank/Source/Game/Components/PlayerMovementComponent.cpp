#include "PlayerMovementComponent.h"
#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs
#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames
#include <iostream> // debug

using namespace Game;

void PlayerMovementComponent::Update() {
    Component::Update();

    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();

    //By default the displacement is 0,0
    sf::Vector2f displacement{ 0.0f,0.0f };

    //The amount of speed that we will apply when input is received
    const float inputAmount = 100.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        displacement.x -= inputAmount * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        displacement.x += inputAmount * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        displacement.y -= inputAmount * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        displacement.y += inputAmount * dt;
    }

    //Update the entity position
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        GameEngine::AnimationComponent *animComponent = GetEntity()->GetComponent<GameEngine::AnimationComponent>();
        if (animComponent) {
            animComponent->SetIsLooping(true);
            animComponent->PlayAnim(GameEngine::EAnimationId::PlayerStatic);
        }
    }

    int maxFaces = 4;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_uWasPressed = true; // <-- Add a new bool m_fwasPressed and initialize it to false;
    }
    else if (m_uWasPressed) // <-- Check if it was pressed ( we already know here that is not currently pressed )
    {
        m_uWasPressed = false; // <-- Reset our WasPressed flag
        ++m_currentFaceIndex;  // <-- We need to add a new int m_currentFaceIndex attribute member to the class
        if (m_currentFaceIndex>= maxFaces) m_currentFaceIndex= 0;
        GameEngine::SpriteRenderComponent* render = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();
        if (render)
        {
            render->SetTileIndex(sf::Vector2i(m_currentFaceIndex,0));
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        GameEngine::SpriteRenderComponent* render = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();
        if (render)
        {
//            std::cout<<"hi";
            render->SetTexture(GameEngine::eTexture::PlayerUp);
        }
    }
}

void PlayerMovementComponent::OnAddToWorld() {}
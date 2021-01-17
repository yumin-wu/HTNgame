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

    // Continous
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//    {
//        displacement.x -= inputAmount * dt;
//    }
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//    {
//        displacement.x += inputAmount * dt;
//    }
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//    {
//        displacement.y -= inputAmount * dt;
//    }
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//    {
//        displacement.y += inputAmount * dt;
//    }

    int maxFaces = 12;
    bool skipUpdate = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_dWasPressed = true; // <-- Add a new bool m_fwasPressed and initialize it to false;
    }
    else if (m_dWasPressed) // <-- Check if it was pressed ( we already know here that is not currently pressed )
    {
        if (GetEntity()->GetPos().y >= 240.f)
        {
            skipUpdate = true;
        }

        displacement.y += 32.f;

        m_dWasPressed = false; // <-- Reset our WasPressed flag
        if (m_currentFaceIndex >= 2) {
            m_currentFaceIndex = 0;
        } else {
            ++m_currentFaceIndex;
        }
        GameEngine::SpriteRenderComponent* render = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();
        if (render)
        {
            render->SetTileIndex(sf::Vector2i(m_currentFaceIndex,0));
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_uWasPressed = true; // <-- Add a new bool m_fwasPressed and initialize it to false;
    }
    else if (m_uWasPressed) // <-- Check if it was pressed ( we already know here that is not currently pressed )
    {
        displacement.y -= 32.f;
        m_uWasPressed = false; // <-- Reset our WasPressed flag
        if (m_currentFaceIndex >= 5 || m_currentFaceIndex < 3) {
            m_currentFaceIndex = 3;
        } else {
            ++m_currentFaceIndex;
        }
        GameEngine::SpriteRenderComponent* render = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();
        if (render)
        {
            render->SetTileIndex(sf::Vector2i(m_currentFaceIndex,0));
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_lWasPressed = true; // <-- Add a new bool m_fwasPressed and initialize it to false;
    }
    else if (m_lWasPressed) // <-- Check if it was pressed ( we already know here that is not currently pressed )
    {
        if (GetEntity()->GetPos().x <= 48.f)
        {
            skipUpdate = true;
        }

        displacement.x -= 32.f;
        m_lWasPressed = false; // <-- Reset our WasPressed flag
        if (m_currentFaceIndex >= 8 || m_currentFaceIndex < 6) {
            m_currentFaceIndex = 6;
        } else {
            ++m_currentFaceIndex;
        }
        GameEngine::SpriteRenderComponent* render = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();
        if (render)
        {
            render->SetTileIndex(sf::Vector2i(m_currentFaceIndex,0));
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_rWasPressed = true; // <-- Add a new bool m_fwasPressed and initialize it to false;
    }
    else if (m_rWasPressed) // <-- Check if it was pressed ( we already know here that is not currently pressed )
    {
        if (GetEntity()->GetPos().x >= 272.f && (GetEntity()->GetPos().y == 112
        || GetEntity()->GetPos().y == 144
        || GetEntity()->GetPos().y == 176
        || GetEntity()->GetPos().y == 240))
        {
            skipUpdate = true;
        }
        displacement.x += 32.f;
        m_rWasPressed = false; // <-- Reset our WasPressed flag
        if (m_currentFaceIndex >= 11 || m_currentFaceIndex < 9) {
            m_currentFaceIndex = 9;
        } else {
            ++m_currentFaceIndex;
        }
        GameEngine::SpriteRenderComponent* render = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();
        if (render)
        {
            render->SetTileIndex(sf::Vector2i(m_currentFaceIndex,0));
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        GetEntity()->SetPos(sf::Vector2f(48.f, 112.f));
    }

    if (skipUpdate) {
        return;
    }
    //Update the entity position
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
     std::cout<<GetEntity()->GetPos().x<<std::endl;
}

void PlayerMovementComponent::OnAddToWorld() {}
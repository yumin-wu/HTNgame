#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

namespace Game
{
    class PlayerMovementComponent : public GameEngine::Component
    {
    public:
        virtual void Update() override;
        virtual void OnAddToWorld() override;
    private:
        int m_currentFaceIndex;
        bool m_uWasPressed = false;
        bool m_dWasPressed = false;
        bool m_lWasPressed = false;
        bool m_rWasPressed = false;
    };
}
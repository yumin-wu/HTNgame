#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,
            Player,     //<-- Add a new entry for our new texture
            Gasbone,
            PlayerUp,
            PlayerDown,
            IceWall1Top,
            IceFloor1,
			Count,
		};
	}	

	inline const char* GetPath(eTexture::type texture)
	{
        switch (texture)
        {
            case eTexture::Player: return "slime/slime_walk_row.png"; //<-- The name of the image on disk
            case eTexture::Gasbone: return "monster/gasbone.png";
            case eTexture::PlayerUp: return "Robin/robin_back_all.png";
            case eTexture::PlayerDown: return "Robin/robin_front_all.png";
            case eTexture::IceWall1Top: return "level_1/wall_up.png";
            case eTexture::IceFloor1: return "level_1/floor.png";
        }
        return "UnknownTexType";
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture);
}


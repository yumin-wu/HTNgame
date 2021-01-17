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
            IceFloor1,
            IceWall1Top,
            IceWall1Left,
            IceWall1Bottom,
            IceWall1RightTop,
            IceWall1RightBottom,
            Level1,
            SlimeKing,
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
            case eTexture::IceFloor1: return "level_1/floor.png";
            case eTexture::IceWall1Top: return "level_1/wall_up.png";
            case eTexture::IceWall1Left: return "level_1/wall_left.png";
            case eTexture::IceWall1Bottom: return "level_1/wall_bottom.png";
            case eTexture::IceWall1RightTop: return "level_1/wall_top_right.png";
            case eTexture::IceWall1RightBottom: return "level_1/wall_bottom_right.png";
            case eTexture::SlimeKing: return "slime/slime_king.png";
            case eTexture::Level1: return "level_1/level_1_all.png";
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


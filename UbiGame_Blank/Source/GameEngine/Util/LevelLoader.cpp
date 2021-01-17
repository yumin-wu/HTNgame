#include "LevelLoader.h"
#include "SFML/Graphics/Texture.hpp"
#include "GameEngine/Util/TextureManager.h"
#include "SFML/Graphics/Color.hpp"
#include "Game/GameBoard.h"

using namespace Game;

LevelLoader* LevelLoader::sm_instance = nullptr;

LevelLoader::LevelLoader() {}

LevelLoader::~LevelLoader() {}

void LevelLoader::LoadLevel(GameBoard* board) {

}

#include <vector>

namespace Game
{
    class GameBoard;

    class LevelLoader
    {
    public:
        ~LevelLoader();
        static LevelLoader* GetInstance() {if (!sm_instance) sm_instance = new LevelLoader(); return sm_instance;}
        void LoadLevel(GameBoard* board);
    private:
        LevelLoader();
        static LevelLoader* sm_instance;
    };
}
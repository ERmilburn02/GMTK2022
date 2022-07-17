#pragma once

#include "Core/Screens.hpp"
#include "Core/App.hpp"
#include <vector>
#include <string>
#include <random>
#include <functional>

namespace gmtk2022
{
    class GameplayScreen : public Screen
    {
    public:
        GameplayScreen(App* app);
        void Init();
        void Update();
        void Draw();
        void Unload();
    private:
        App* m_App;
        unsigned short m_CurrentDiceValue;
        unsigned short m_RollsLeft;
        unsigned short m_StartingRolls = 10;
        unsigned short m_Score;
        std::vector<std::string> m_DiceRes;
        std::default_random_engine m_RndGen;
        std::uniform_int_distribution<int> m_RndDst;
    };
}
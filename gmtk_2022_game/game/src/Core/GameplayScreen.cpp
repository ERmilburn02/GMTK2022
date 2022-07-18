#include "Core/GameplayScreen.hpp"
#include "Core/Assets.hpp"

#define BIG_DICE_SCALE 2

namespace gmtk2022
{
    GameplayScreen::GameplayScreen(App* app)
    {
        m_App = app;
    }

    void GameplayScreen::Init()
    {
        m_CurrentDiceValue = 1;

        m_RollsLeft = m_StartingRolls;
        m_Score = 0;

        m_DiceRes.clear();
        m_DiceRes.push_back("ERROR");
        m_DiceRes.push_back("resources/images/dieWhite_border1.png");
		m_DiceRes.push_back("resources/images/dieWhite_border2.png");
		m_DiceRes.push_back("resources/images/dieWhite_border3.png");
		m_DiceRes.push_back("resources/images/dieWhite_border4.png");
		m_DiceRes.push_back("resources/images/dieWhite_border5.png");
		m_DiceRes.push_back("resources/images/dieWhite_border6.png");

        m_RndDst = std::uniform_int_distribution<int>(1, 6);
        // engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    }

    void GameplayScreen::Update()
    {
        if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_SPACE)) && m_RollsLeft > 0)
        {
            m_CurrentDiceValue = m_RndDst(m_RndGen);
            m_Score += m_CurrentDiceValue;
            m_RollsLeft--;
        }
    }

    void GameplayScreen::Draw()
    {
        int rolls = MeasureText(std::to_string(m_RollsLeft).c_str(), 24);
        DrawText(std::to_string(m_RollsLeft).c_str(), GetScreenWidth() / 2 - rolls / 2, 25, 24, RAYWHITE);

        int rollsLeft = MeasureText("Rolls left", 24);
        DrawText("Rolls left", GetScreenWidth() / 2 - rollsLeft / 2, 50, 24, RAYWHITE);

        int clickReminder = MeasureText("Click to roll", 48);
		DrawText("Click to roll", GetScreenWidth() / 2 - clickReminder / 2, GetScreenHeight() / 4, 48, RAYWHITE);

        DrawTextureEx(Assets::GetTexture(m_DiceRes.at(m_CurrentDiceValue)), Vector2{(float)GetScreenWidth() / 2  - (68 / 2 * BIG_DICE_SCALE), (float)GetScreenHeight() / 2 - (68 / 2 * BIG_DICE_SCALE)}, 0, BIG_DICE_SCALE, WHITE);

        int scoreText = MeasureText("Score", 48);
        int score = MeasureText(std::to_string(m_Score).c_str(), 48);

		DrawText("Score", GetScreenWidth() / 2 - scoreText / 2, GetScreenHeight() - 100, 48, RAYWHITE);
		DrawText(std::to_string(m_Score).c_str(), GetScreenWidth() / 2 - score / 2, GetScreenHeight() - 50, 48, RAYWHITE);
    }

    void GameplayScreen::Unload()
    {
        
    }
}
#include "Core/TitleScreen.hpp"
#include <raylib.h>
#include "Core/Assets.hpp"
#include "Core/GameplayScreen.hpp"

namespace gmtk2022
{
	TitleScreen::TitleScreen(App* app)
	{
		m_App = app;
	}

	void TitleScreen::Init()
	{
		
	}

	void TitleScreen::Update()
	{
		if (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) m_App->ChangeScreen(new GameplayScreen(m_App));
	}

	void TitleScreen::Draw()
	{
		int titleSize = MeasureText("Dice game", 72);
		DrawText("Dice game", GetScreenWidth() / 2 - titleSize / 2, GetScreenHeight() / 4, 72, RAYWHITE);

		int startSize = MeasureText("Click to start", 48);
		DrawText("Click to start", GetScreenWidth() / 2 - startSize / 2, GetScreenHeight() / 4 * 3, 48, RAYWHITE);
	}

	void TitleScreen::Unload()
	{

	}
}
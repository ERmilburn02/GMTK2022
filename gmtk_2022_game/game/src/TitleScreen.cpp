#include "TitleScreen.hpp"
#include <raylib.h>
#include "Assets.hpp"

namespace gmtk2022
{
	void TitleScreen::Init()
	{

	}

	void TitleScreen::Update()
	{
		DrawRectangle(25, 25, GetScreenWidth() - 50, GetScreenHeight() - 50, SKYBLUE);
		DrawTexture(Assets::GetTexture("Jam Logo Big"), 0, 0, WHITE);
	}

	void TitleScreen::Draw()
	{
		
	}

	void TitleScreen::Unload()
	{

	}
}
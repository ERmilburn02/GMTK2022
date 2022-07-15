#include <raylib.h>
#include "Screens.hpp"
#include "TitleScreen.hpp"

gmtk2022::Screen* currentScreen = nullptr;

void ChangeScreen(gmtk2022::Screen* screen)
{
	if (currentScreen != nullptr) currentScreen->Unload();
	delete currentScreen;
	currentScreen = screen;
	currentScreen->Init();

}

int main(int argc, char** argv)
{
	InitWindow(960, 540, "Test Window");
	SetExitKey(KEY_NULL);
	SetTargetFPS(60);

	ChangeScreen(new gmtk2022::TitleScreen);

	while (!WindowShouldClose())
	{
		currentScreen->Update();

		BeginDrawing();
		ClearBackground(RAYWHITE);

		currentScreen->Draw();

		DrawFPS(10, 10);
		EndDrawing();
	}

	currentScreen->Unload();
	delete currentScreen;

	CloseWindow();

	return 0;
}
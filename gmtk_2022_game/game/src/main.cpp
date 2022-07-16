#include "App.hpp"
#include "TitleScreen.hpp"

int main(int argc, char** argv)
{
	gmtk2022::App* app = new gmtk2022::App;
	app->ChangeScreen(new gmtk2022::TitleScreen);
	app->Start();
	delete app;

	return 0;
}
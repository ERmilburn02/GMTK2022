#include "App.hpp"
#include "TitleScreen.hpp"
#include "Assets.hpp"

int main(int argc, char** argv)
{
	gmtk2022::App* app = new gmtk2022::App;
	// TODO: Move this call into loading screen
	gmtk2022::Assets::LoadAllResources();
	app->ChangeScreen(new gmtk2022::TitleScreen);
	app->Start();
	delete app;

	return 0;
}
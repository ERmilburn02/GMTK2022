#include "App.hpp"
#include "LoadingScreen.hpp"
#include "Assets.hpp"

int main(int argc, char** argv)
{
	gmtk2022::App* app = new gmtk2022::App;
	// TODO: Move this call into loading screen
	// gmtk2022::Assets::LoadAllResources();
	app->ChangeScreen(new gmtk2022::LoadingScreen(app));
	app->Start();
	delete app;

	return 0;
}
#include "Core/App.hpp"
#include "Core/LoadingScreen.hpp"

int main(int argc, char** argv)
{
	gmtk2022::App* app = new gmtk2022::App;
	app->ChangeScreen(new gmtk2022::LoadingScreen(app));
	app->Start();
	delete app;

	return 0;
}
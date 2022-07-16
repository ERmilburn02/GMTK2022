#include "Core/App.hpp"
#include "Core/LoadingScreen.hpp"

#include <raylib.h>

int main(int argc, char** argv)
{
#if defined(NDEBUG)
	SetTraceLogLevel(LOG_ERROR);
#endif
	gmtk2022::App* app = new gmtk2022::App;
	app->ChangeScreen(new gmtk2022::LoadingScreen(app));
	app->Start();
	delete app;

	return 0;
}
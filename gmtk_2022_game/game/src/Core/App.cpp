#include "Core/App.hpp"
#include <raylib.h>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

namespace gmtk2022
{
    App::App()
    {
        InitWindow(960, 540, "GMTK 2022");
        InitAudioDevice();
        SetExitKey(KEY_NULL);
    }

    App::~App()
    {
        m_CurrentScreen->Unload();
        delete m_CurrentScreen;
        CloseAudioDevice();
        CloseWindow();
    }

    void App::Start()
    {
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }
#endif
    }

    void App::UpdateDrawFrame()
    {
        m_CurrentScreen->Update();

        BeginDrawing();
        ClearBackground(BLACK);

        m_CurrentScreen->Draw();

        EndDrawing();
    }

    void App::ChangeScreen(gmtk2022::Screen* screen)
    {
	    if (m_CurrentScreen != nullptr) m_CurrentScreen->Unload();
	    delete m_CurrentScreen;
	    m_CurrentScreen = screen;
	    m_CurrentScreen->Init();
    }
}
#pragma once

#include "Screens.hpp"

namespace gmtk2022
{
    class App
    {
    public:
        App();
        ~App();
        void Start();
        void ChangeScreen(gmtk2022::Screen* screen);
    private:
        void UpdateDrawFrame();
        gmtk2022::Screen* m_CurrentScreen = nullptr;
    };
}
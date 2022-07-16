#pragma once

#include "Core/Screens.hpp"
#include "Core/App.hpp"

namespace gmtk2022
{
    class GameplayScreen : public Screen
    {
    public:
        GameplayScreen(App* app);
        void Init();
        void Update();
        void Draw();
        void Unload();
    private:
        App* m_App;
    };
}
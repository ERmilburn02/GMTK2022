#pragma once

#include "Core/Screens.hpp"
#include "Core/App.hpp"
#include <vector>
#include <string>

namespace gmtk2022
{
    class LoadingScreen : public Screen
    {
    public:
        LoadingScreen(App* app);
        void Init();
        void Update();
        void Draw();
        void Unload();
    private:
        App* m_App;
        std::vector<std::string> m_Textures;
        std::string m_NextTexture;
        int m_TextureStartSize;
    };
}
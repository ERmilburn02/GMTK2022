#include "Core/LoadingScreen.hpp"
#include "Core/Assets.hpp"
#include "Core/LogoScreen.hpp"
#include <raylib.h>

namespace gmtk2022
{
    LoadingScreen::LoadingScreen(App* app)
    {
        m_App = app;
    }

    void LoadingScreen::Init()
    {
        m_Textures = Assets::GetTextureList();
        m_NextTexture = m_Textures[0];
        m_Textures.erase(m_Textures.begin());
    }

    void LoadingScreen::Update()
    {
        if (m_NextTexture == "NEXT_TEXTURE")
        {
            m_NextTexture = m_Textures[0];
            m_Textures.erase(m_Textures.begin());
        }
        else if (m_NextTexture == "NO_TEXTURES_LEFT")
        {
            m_App->ChangeScreen(new LogoScreen(m_App));
        }
        else
        {
            Texture2D texture = LoadTexture(m_NextTexture.c_str());
            Assets::AddTexture(m_NextTexture, texture);
            if (m_Textures.size() == 0)
            {
                m_NextTexture = "NO_TEXTURES_LEFT";
            }
            else
            {
                m_NextTexture = "NEXT_TEXTURE";
            }
        }
    }

    void LoadingScreen::Draw()
    {
        DrawText(m_NextTexture.c_str(), 25, 25, 24, WHITE);
    }

    void LoadingScreen::Unload()
    {

    }
}
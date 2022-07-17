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
        m_TextureStartSize = m_Textures.size();
        m_NextTexture = "NEXT_TEXTURE";
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
        /*
            // Create a box for the progress bar
            context.strokeRect(canvas.width / 2 - 200, canvas.height / 2 - 50, 400, 100);

            // Fill the progress bar
            context.fillRect(canvas.width / 2 - 200, canvas.height / 2 - 50, 400 * ((totalAssets - remainingAssets) / totalAssets), 100);

            // Draw the text
            context.font = '30px Arial';
            context.textAlign = 'center';
            context.fillStyle = '#00ff00'
            // Align the text to the center of the progress bar
            // context.fillText('Downloading assets...', canvas.width / 2 - 200, canvas.height / 2 - 25);
            // context.fillText('(' + (totalAssets - remainingAssets) + '/' + totalAssets + ')', canvas.width / 2 - 200, canvas.height / 2 + 25);
            context.fillText('Downloading assets...', canvas.width / 2, canvas.height / 2 - 15);
            context.fillText('(' + (totalAssets - remainingAssets) + '/' + totalAssets + ')', canvas.width / 2, canvas.height / 2 + 35);
        */

        int nextTextureWidth = MeasureText(m_NextTexture.c_str(), 24);
        int loadingTextWidth = MeasureText("Loading assets...", 24);
 
        // DrawRectangle(GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 50, 800, 100, DARKGRAY);
        // DrawRectangle(GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 50, (int)(800 * (float)((m_TextureStartSize - m_Textures.size()) / m_TextureStartSize)), 100, ORANGE);
        DrawText("Loading assets...", GetScreenWidth() / 2 - loadingTextWidth / 2, GetScreenHeight() / 2 - 20, 24, RAYWHITE);
        if (m_NextTexture != "NO_NEXTURES_LEFT" && m_NextTexture != "NEXT_TEXTURE") DrawText(m_NextTexture.c_str(), GetScreenWidth() / 2 - nextTextureWidth / 2, GetScreenHeight() / 2 + 20, 24, RAYWHITE);
    }

    void LoadingScreen::Unload()
    {

    }
}
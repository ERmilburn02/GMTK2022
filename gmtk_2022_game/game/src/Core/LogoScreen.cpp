#include <raylib.h>

#include "Core/LogoScreen.hpp"
#include "Core/Assets.hpp"
#include "Core/TitleScreen.hpp"

namespace gmtk2022
{
    LogoScreen::LogoScreen(App* app)
    {
        m_App = app;
    }

	void LogoScreen::Init()
	{
		m_Timer = m_TimerMax;
		m_LogoAlpha = 255;
	}

	void LogoScreen::Update()
	{
		if (m_Timer > 0) m_Timer -= GetFrameTime();
		if (m_Timer < 0.5f)
		{
			m_LogoAlpha = (int)((m_Timer / 0.5f) * 255);
		}
        if (m_Timer < 0)
        {
            m_Timer = 0;
            m_App->ChangeScreen(new TitleScreen(m_App));
        }
	}

	void LogoScreen::Draw()
	{
		DrawTextureEx(Assets::GetTexture("resources/images/jam_logo_big.png"), Vector2{0, 0}, 0, 0.24, Color{255, 255, 255, (unsigned char)m_LogoAlpha});
	}

	void LogoScreen::Unload()
	{

	}
}
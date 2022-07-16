#pragma once

#include "Screens.hpp"
#include "App.hpp"

namespace gmtk2022
{
    class LogoScreen : public Screen
	{
	public:
        LogoScreen(App* app);
		void Init();
		void Update();
		void Draw();
		void Unload();
	private:
		float m_Timer;
		int m_LogoAlpha;
		const float m_TimerMax = 5.0f;
        App* m_App;
	};
}
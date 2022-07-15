#pragma once

#include "Screens.hpp"

namespace gmtk2022
{
	class TitleScreen : public Screen
	{
	public:
		void Init();
		void Update();
		void Draw();
		void Unload();
	};
}
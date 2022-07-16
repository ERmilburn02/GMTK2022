#pragma once

namespace gmtk2022
{
	class Screen
	{
	public:

		// Initialize any local variables
		virtual void Init() = 0;

		// Update the variables
		virtual void Update() = 0;

		// Draw the variables
		virtual void Draw() = 0;

		// Unload any local variables
		virtual void Unload() = 0;
	};
}
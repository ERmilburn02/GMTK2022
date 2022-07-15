#pragma once

#include <map>
#include <string>
#include <raylib.h>

namespace gmtk2022
{
	class Assets
	{
	public:
		static void AddTexture(std::string name, Texture2D texture);
		static Texture2D GetTexture(std::string name);
	private:
		static std::map<std::string, Texture2D> s_Textures;
	};
}
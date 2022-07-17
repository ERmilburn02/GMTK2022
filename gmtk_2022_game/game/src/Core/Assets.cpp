#include "Core/Assets.hpp"
#include <cassert>

namespace gmtk2022
{
	std::map<std::string, Texture2D> Assets::s_Textures;

	std::vector<std::string> Assets::GetTextureList()
	{
		std::vector<std::string> textures;
		textures.push_back("resources/images/jam_logo_big.png");
		textures.push_back("resources/images/dieWhite_border1.png");
		textures.push_back("resources/images/dieWhite_border2.png");
		textures.push_back("resources/images/dieWhite_border3.png");
		textures.push_back("resources/images/dieWhite_border4.png");
		textures.push_back("resources/images/dieWhite_border5.png");
		textures.push_back("resources/images/dieWhite_border6.png");
		return textures;
	}

	Texture2D Assets::GetTexture(std::string name)
	{
		std::map<std::string, Texture2D>::iterator itr;

		for (itr = s_Textures.begin(); itr != s_Textures.end(); ++itr)
		{
			if (itr->first == name)
			{
				return itr->second;
			}
		}

		assert(false);

		return Texture2D{};
	}

	void Assets::AddTexture(std::string name, Texture2D texture)
	{
		s_Textures.insert(make_pair(name, texture));
	}
}
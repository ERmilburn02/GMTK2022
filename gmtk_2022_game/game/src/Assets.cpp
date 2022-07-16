#include "Assets.hpp"
#include <cassert>

namespace gmtk2022
{
	std::map<std::string, Texture2D> Assets::s_Textures;

	// TODO: Move into Loading Screen
	void Assets::LoadAllResources()
	{
		// Jam Logo Big
		Texture2D jamLogoBig = LoadTexture("resources/images/jam_logo_big.png");
		AddTexture("Jam Logo Big", jamLogoBig);
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
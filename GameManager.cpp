#include "GameManager.h"

std::map<std::string, sf::Texture> GameManager::textures;

sf::Texture* GameManager::getTexture(std::string& texturePath)
{
	if (textures.count(texturePath))
	{
		return &(textures[texturePath]);
	}
	else
	{
		textures[texturePath] = sf::Texture();
		if (textures[texturePath].loadFromFile(texturePath))
		{
			return &(textures[texturePath]);
		}
	}
	return nullptr;
}

sf::Texture* GameManager::getTexture(std::string&& texturePath)
{
	return getTexture(texturePath);
}


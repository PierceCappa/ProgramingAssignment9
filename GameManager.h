#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <map>

namespace GameManager
{
	extern std::map<std::string, sf::Texture> textures;
	sf::Texture* getTexture(std::string& texturePath);
	sf::Texture* getTexture(std::string&& texturePath);

}

#endif
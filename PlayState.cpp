#include "PlayState.h"

PlayState::PlayState()
{
	sf::Texture* tex = GameManager::getTexture("textures/test.png");

	sprite = sf::Sprite(*tex);
	sprite.move(20, 0);
}

void PlayState::onSwitch()
{
}

int hori = 10;
int verti = 10;
States PlayState::update(vector<sf::Event>& events)
{
	auto pos = sprite.getPosition();
	if (pos.x > 800)
	{
		hori = -10;
	}
	else if (pos.x < 0)
	{
		hori = 10;
	}

	if (pos.y > 800)
	{
		verti = -10;
	}
	else if (pos.y < 0)
	{
		verti = 10;
	}

	sprite.move(hori, verti);
	return States::NO_CHANGE;
}

void PlayState::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

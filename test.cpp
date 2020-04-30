#include "test.h"

bool runTest(bool input, std::string&& name)
{
	static unsigned int test_counter = 0;

	if (input)
	{
		std::cout << test_counter << ") Test " << name << " succeeded." << std::endl;
	}
	else
	{
		std::cout << test_counter << ") Test " << name << " failed." << std::endl;
	}
	++test_counter;

	return input;
}

int testing::run()
{
	bool success_state = 0;
	success_state += !runTest(testGameManagerLoad(), "GameManager");
	return success_state;
}

bool testing::testGameManagerLoad()
{
	sf::Texture* tex = GameManager::getTexture("textures/test.png");

	return tex != nullptr;
}

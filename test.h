#pragma once

#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <iostream>
#include <string>
#include "main.cpp"

class testing
{
public:
	// this will run all tests.
	testing()
	{

	}
	~testing()
	{

	}
	int gameTest();
	bool testWindow(RenderWindow& window);
	bool testGameManagerLoad();
	bool runTest(bool input, std::string&& name);
	// add what tests you need here

};
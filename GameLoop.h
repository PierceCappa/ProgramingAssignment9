#pragma once
#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <conio.h>
#include "MainMenuState.h"
#include "GameState.h"
#include "Board.h"
#include "BoardAI.h"

//this function calls the game loop, this thing is probably gonna need to get broken up so it fits the way you guys want it to.
void runGame(sf::RenderWindow& window);

#endif
#pragma once
#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <conio.h>
#include "MainMenuState.h"
#include "LoadState.h"
#include "GameState.h"
#include "Board.h"
#include "BoardAI.h"


#define PLAY 0
#define RULES 1
#define EXIT 2

//this function calls the game loop, this thing is probably gonna need to get broken up so it fits the way you guys want it to.
void runGame();



#endif
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

void runGame();



#endif
#ifndef MAIN_H
#define MAIN_H

#include <string>
#include "Game.h"

#define WINDOW_TITLE "Mijngilde"
#define SCREEN_WIDTH 3000
#define SCREEN_HEIGHT 1500

class Main : public Game
{
public:
	int init();
};

#endif

#ifndef MAIN_H
#define MAIN_H

#include <string>
#include "Game.h"

#define WINDOW_TITLE "Mijngilde"
#define SCREEN_WIDTH 2000
#define SCREEN_HEIGHT 1200

class Main : public Game
{
public:
	int init();
};

#endif

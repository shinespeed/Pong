#include <iostream>
#include <SDL.h>
#include "Game.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));
	Game app;
	return app.onExecute();
}

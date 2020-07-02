#ifndef BASE_APP_H
#define BASE_APP_H

#include <iostream>
#include <Windows.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <algorithm>
#include <time.h>
#include <conio.h>
#include <assert.h>
#include <strsafe.h>
#include <string>
#include "GlobalConst.h"

using namespace std;

class BaseApp
{
private:
	bool onInit();
	void onEvent(SDL_Event* e);
	void onQuit();
	void onRun();

public:
	BaseApp();
	virtual ~BaseApp();

	bool runnung;

	int onExecute();
	int sum;
	int counter;
	int deltaTime;

	SDL_Window *window;
	SDL_Renderer *render;
	SDL_Event event;

	SDL_Texture* renderText(const std::string &message, const std::string &fontFile, 
	SDL_Color color, int fontSize, SDL_Renderer *renderer);

	void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
	void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);

	virtual void onUpdate(float deltaTime) = 0;
	virtual void KeyPressed(SDL_Event* event) = 0;
};

#endif
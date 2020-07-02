#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "GlobalConst.h"
#include <SDL.h>

class GameObject
{
public:
	GameObject();
	virtual ~GameObject() {};
	void moveObject();
	SDL_Rect* returnRect();

protected:
	double* _objectX;
	double* _objectY;
	int _objectW;
	int _objectH;

	SDL_Rect* _rect;
};

#endif
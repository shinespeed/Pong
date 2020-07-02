#include "Paddles.h"

Paddles::Paddles(double* objectX, double* objectY)
{
	_objectH = H_PADDLES;
	_objectW = W_PADDLES;
	_objectX = objectX;
	_objectY = objectY;

	_rect = new SDL_Rect();

	_rect->h = _objectH;
	_rect->w = _objectW;
	_rect->x = *_objectX;
	_rect->y = *_objectY;
}


Paddles::~Paddles()
{
	delete _rect;
}

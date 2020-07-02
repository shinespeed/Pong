#include "Ball.h"

Ball::Ball(double* objectX, double* objectY)
{
	_objectH = H_BALL;
	_objectW = H_BALL;
	_objectX = objectX;
	_objectY = objectY;

	_rect = new SDL_Rect();

	_rect->h = _objectH;
	_rect->w = _objectW;
	_rect->x = *_objectX;
	_rect->y = *_objectY;
}

Ball::~Ball()
{
	delete _rect;
}

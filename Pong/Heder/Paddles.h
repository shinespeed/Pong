#ifndef PADDLES_H
#define PADDLES_H

#include "GameObject.h"

class Paddles: public GameObject
{
public:
	Paddles(double* objectX, double* objectY);
	~Paddles();
};

#endif

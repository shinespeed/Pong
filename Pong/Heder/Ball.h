#ifndef BALL_H
#define BALL_H

#include "GameObject.h"

class Ball: public GameObject
{
public:
	Ball(double* _objectX, double* _objectY);
	~Ball();
};

#endif 



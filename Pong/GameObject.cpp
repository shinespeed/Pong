#include "GameObject.h"

GameObject::GameObject()
{}

void GameObject::moveObject() 
{
	_rect->x = *_objectX;
	_rect->y = *_objectY;
}

SDL_Rect* GameObject::returnRect() 
{
	return _rect;
}

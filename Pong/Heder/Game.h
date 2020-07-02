#ifndef H_GAME
#define H_GAME

#include "BaseApp.h"
#include "GameObject.h"
#include "Ball.h"
#include "Paddles.h"
#include <vector>
#include <math.h>

class Game : public BaseApp
{
private:
	double _speedBall;
	double _speedBot;
	double _speedPlayer;

	double _playerX;
	double _playerY;

	double _botX;
	double _botY;

	double _ballX;
	double _ballY;

	double _staticCoefficSpeed;

	double _directX;
	double _directY;

	float _sumTimer;
	float _delayBotTimer;

	int _pointBot;
	int _pointPlayer;

	int _randomPointBot;

	bool _changePoint;

public:
	Game();

	SDL_Texture *textPointBot;
	SDL_Texture *textPointPlayer;
	std::vector<GameObject*> vecObject;

	void startGame();

	void moveBot();
	void moveBall();

	void logicMoveBall(double x, double y, int coof);

	void KeyPressed(SDL_Event* event);
	void renderPoint();

	int  randomPointBot();

	void onUpdate(float deltaTime);
};

#endif
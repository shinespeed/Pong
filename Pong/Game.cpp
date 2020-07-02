#include "Game.h"

Game::Game() :
	_pointBot(0),
	_pointPlayer(0),
	_changePoint(true),
	_delayBotTimer(0),
	_speedBot(SPEED_BOT),
	_speedPlayer(SPEED_PLAYER),
	_speedBall(SPEED_BALL)
{
	startGame();

	vecObject.push_back(new Paddles(&_playerX, &_playerY));
	vecObject.push_back(new Paddles(&_botX, &_botY));
	vecObject.push_back(new Ball(&_ballX, &_ballY));
}

void Game::startGame()
{
	_directX             = 1;
	_directY             = rand()%3 - 1;
	_staticCoefficSpeed  = _speedBall;

	_playerX             = X_PADDLES_PALYER;
	_playerY             = Y_PADDLES_PALYER;

	_botX                = X_PADDLES_BOT;
	_botY                = Y_PADDLES_BOT;

	_ballX               = X_BALL;
	_ballY               = Y_BALL;

	_randomPointBot = randomPointBot();
}

void Game::moveBot()
{
	if ((_directX < 0)&&(_ballX < WINDOW_WIDTH / 2))
	{
	     if(_botY < _playerY)
		 {
			 _botY+= _speedBot;
		 }
		 else if(_botY > _playerY)
		 {
			 _botY-= _speedBot;
		 }
	}
	else if ((_directX > 0)&&(_ballX > WINDOW_WIDTH / 2))
	{
		if ((_ballY > _botY + _randomPointBot)
			&&(WINDOW_HEIGHT > (_botY + H_PADDLES + _randomPointBot) 
			&& (abs(_ballY - _botY + _randomPointBot) > _speedBot)))
		{
			_botY += _speedBot;
		}
		else if ((_ballY < _botY + _randomPointBot)
			&&(0 < (_botY + H_PADDLES + _randomPointBot) 
			&& (abs(_ballY - (_botY + _randomPointBot)) > _speedBot)))
		{
			_botY -= _speedBot;
		}
	}
}

void Game::moveBall()
{
	_ballX += (_directX * _staticCoefficSpeed);
	_ballY += (_directY * _staticCoefficSpeed);
	
	if (_ballX <= 0) 
	{
		startGame();
		_changePoint = true;
		_pointBot++;
	}

	if (_ballX >= WINDOW_WIDTH-1)
	{
		startGame();
		_changePoint = true;
		_pointPlayer++;
	}
		
	if (_ballX >= WINDOW_WIDTH)
	{
		_directX *= (-1);
	}

	if ((_ballY <= 0) || (_ballY >= WINDOW_HEIGHT))
	{
		_directY *= (-1);
	}

	if (((_playerX + W_PADDLES) >= _ballX)&&(_ballY >= _playerY)&&(_ballY <= (_playerY + H_PADDLES)))
	{
	    logicMoveBall(_playerX, _playerY, 1);
	}

	if ((_botX <= _ballX) && (_ballY >= _botY- _speedBall) && (_ballY <= (_botY + H_PADDLES)))
	{
		logicMoveBall(_botX, _botY, -1);
		_randomPointBot = randomPointBot();
	}
}

int Game::randomPointBot() 
{
	return rand()%H_PADDLES;
}

void Game::logicMoveBall(double x, double y, int coof)
{
	_directX = coof * std::abs(std::cos(sqrt(pow((y + (H_PADDLES / 2) - _ballY), 2) + pow((H_PADDLES / 2), 2))));
	_directY = std::sin((y + (H_PADDLES / 2) - _ballY));
	
	cout << _directX << "  " << _directY << " " << _randomPointBot << endl;

	if (((y + (H_PADDLES / 2) - _ballY) > 0)&&(_directY > 0))
	{
		_directY *= (-1);
	}
	if (((y + (H_PADDLES / 2) - _ballY) < 0) && (_directY < 0))
	{
		_directY *= (-1);
	}

	_staticCoefficSpeed = _speedBall;

	while ((pow((_directX * _staticCoefficSpeed), 2) + pow((_directY * _staticCoefficSpeed), 2)) < pow(_speedBall, 2))
	{
		_staticCoefficSpeed++;
	};   
}

void Game::KeyPressed(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN) {
		if ((event->key.keysym.sym == SDLK_UP)&&(_playerY > 10))
		{
			_playerY -= _speedPlayer;
		}
		if ((event->key.keysym.sym == SDLK_DOWN)&&(_playerY < WINDOW_HEIGHT - H_PADDLES - 10)) {
			_playerY += _speedPlayer;
		}
	}
}

void Game::renderPoint() 
{
	if (_changePoint)
	{
		SDL_Color color = { 255, 255, 255, 255 };
		textPointPlayer = renderText(std::to_string(_pointPlayer), "sample.ttf", color, 64, render);
		textPointBot    = renderText(std::to_string(_pointBot),    "sample.ttf", color, 64, render);
		_changePoint    = false;
	}
	renderTexture(textPointPlayer, render, X_POINT_PLAYER, Y_POINT_PLAYER);
	renderTexture(textPointBot   , render, X_POINT_BOT   , Y_POINT_BOT);
}

void Game::onUpdate(float deltaTime)
{
	SDL_SetRenderDrawColor(render, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(render);
	SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);

	renderPoint();
	moveBall();
	moveBot();

	for (auto rect : vecObject)
	{
		rect->moveObject();
		SDL_RenderFillRect(render, rect->returnRect());
	}

	for (int i = 0; i <= WINDOW_HEIGHT; i += 4) {
		SDL_RenderDrawPoint(render, WINDOW_WIDTH / 2, i);
	}

	SDL_RenderPresent(render);
	SDL_UpdateWindowSurface(window);
}

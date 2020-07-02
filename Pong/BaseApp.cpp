#include "BaseApp.h"

#define MY_PERFORMENCE_COUNTER

#include "PerformanceCounter.h"

BaseApp::BaseApp():
	sum(0), 
	counter(0),
	deltaTime(0),
	runnung(true),
	window(NULL),
	render(NULL)
{}

BaseApp::~BaseApp(){}

int BaseApp::onExecute()
{
	if (!onInit())
		return -1;

	if (TTF_Init() != 0) 
		return 1;

	while (runnung)
	{
		while (SDL_PollEvent(&event))
		{
			onEvent(&event);
		}
		onRun();
	}
	onQuit();

	return 0;
}

void BaseApp::onEvent(SDL_Event* event)
{
	if (event->type == SDL_QUIT)
	{
		runnung = false;
	}
	KeyPressed(event);
}

bool BaseApp::onInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}
	//----------------------------------
	window = SDL_CreateWindow(WINDOW_CAPTION, SDL_WINDOWPOS_UNDEFINED
		,SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		return false;
	}
	//----------------------------------
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (render == NULL) {
		cout << "Can't create renderer: " << SDL_GetError() << endl;
		return false;
	}
	//-----------------------------------
	return true;
}

void BaseApp::onQuit()
{
	SDL_DestroyWindow(window);
	window = NULL;

	SDL_DestroyRenderer(render);
	render = NULL;

	SDL_Quit();
}

SDL_Texture* BaseApp::renderText(const std::string &message, const std::string &fontFile,
	SDL_Color color, int fontSize, SDL_Renderer *renderer)
{
	TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (font == nullptr) {
		std::cout << "ERROR LOAD FONT";
		return nullptr;
	}

	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	if (surf == nullptr) {
		TTF_CloseFont(font);
		return nullptr;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == nullptr) {
	}

	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}

void BaseApp::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

void BaseApp::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y)
{
	int w, h;
	SDL_QueryTexture(tex, NULL, NULL, &w, &h);
	renderTexture(tex, ren, x, y, w, h);
}

void BaseApp::onRun()
{
	CStopwatch g_timer;

	g_timer.Start();
	onUpdate((float)deltaTime / 1000.0f);

	while (true)
	{
		deltaTime = g_timer.Now();
		if (deltaTime > 20)
			break;
	}

	sum += deltaTime;
	counter++;
}
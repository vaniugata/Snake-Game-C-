#pragma once

#include <SDL.h>
#include "../Snake.h"
#include "../Fruit.h"

class Game
{
public:
	Game(int Window_width, int Window_height);
	~Game();

	void run();
	void update();
	void close();

	void drawRect(int x, int y, int width, int height, Uint32 color);
	Uint32 makeColor(int r, int  g, int b);

	int getWidth() { return width; }
	int getHeight() { return height; }

private: 
	int count;
	int width;
	int height;
	int wallsize;

	int fruit_randpos();

	Snake snake;
	Fruit fruit;

	bool running;
	//The window we'll be rendering to
	SDL_Window * gWindow = nullptr;
	//The surface contained by the window
	SDL_Surface * gScreenSurface = nullptr;
	//The image we will load and show on the screen
	SDL_Surface * gHelloWorld = nullptr;
};


#include "Game.h"
#include <stdio.h>
#include <windows.h>
#include <cstdlib>
#include <time.h>
Game::Game(int Window_width, int Window_height)
: width(Window_width)
, height(Window_height)
, snake(width / 2, height / 2)
, fruit(fruit_randpos(), fruit_randpos())
, wallsize(10)
{	
	srand(time(NULL));

	running = true;
	count = 0;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	//Load splash image
	gHelloWorld = SDL_LoadBMP("image.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "image.bmp", SDL_GetError());
		
	}
}

Game::~Game()
{
	
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
	
}

void Game::run()
{
	//centrofuga koqto she vurti prez cqloto vr i tam she e vsichko
	while (running)
	{
		update();
		
		SDL_Delay(1000 / 60);
	}
}

void Game::update()
{
	//Wallsize and color 
	
	Uint32 color = makeColor(0, 80, 241);
	
	drawRect(0, 0, width, height, makeColor(0, 0, 0));
	//Drawing map borders
	//top
	drawRect(0, 0, width, wallsize, color);
	//left
	drawRect(0, 0, wallsize, height,color);
	//right
	drawRect(width - wallsize, 0, wallsize, height, color);
	//bottom
	drawRect(0, height - wallsize, width, wallsize, color);
	//Draw snake 
	snake.update();
	snake.draw(this);
	
	//Draw Fruit
	fruit.update();
	fruit.draw(*this);
	//sha q karam da sa dviji

	SDL_Event ev;
	while (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
			/* Look for a keypress */
		case SDL_KEYDOWN:
			/* Check the SDLKey values and move change the coords */
			switch (ev.key.keysym.sym)
			{
			case SDLK_LEFT:
			case SDLK_a:
				snake.changeDir(LEFT);
				break;
			case SDLK_RIGHT:
			case SDLK_d:
				snake.changeDir(RIGHT);
				break;
			case SDLK_UP:
			case SDLK_w:
				snake.changeDir(UP);
				break;
			case SDLK_DOWN:
			case SDLK_s:
				snake.changeDir(DOWN);
				break;

			case SDLK_ESCAPE:
				close();
				break;

			case SDLK_SPACE:
				fruit.x = fruit_randpos();
				fruit.y = fruit_randpos();
				break;
			}
		}
	}
	SDL_UpdateWindowSurface(gWindow);


	if (count > 3600)
	{
		close();
	}
	count++;
	
};

int Game::fruit_randpos()
{
	return rand() % (min(width, height) - 2*wallsize - 20) + wallsize;
}

void Game::close()
{
	running = false;

}

void Game::drawRect(int x, int y, int width, int height, Uint32 color)
{
	SDL_Rect rect;
	rect.h = height;
	rect.w = width;
	rect.x = x;
	rect.y = y;
	SDL_FillRect(gScreenSurface, &rect, color);
	
}

Uint32 Game::makeColor(int r, int g, int b)
{
	
	return SDL_MapRGB(gScreenSurface->format, r, g, b); 
}
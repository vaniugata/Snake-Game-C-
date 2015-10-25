#include "Snake.h"
#include "Game/Game.h"

Snake::Snake(int x, int y)
: x(x), y(y), speed(4)
{
	dir = STOP;
}

Snake::~Snake()
{
}

void Snake::draw(Game * g)
{
	g->drawRect(x, y, 20, 20, g->makeColor(0, 255, 100));
}
//Changes snake position
void Snake::update()
{
	switch (dir)
	{
	case LEFT:
		x -= speed;
		break;
	case RIGHT:
		x += speed;
		break;
	case UP:
		y -= speed;
		break;
	case DOWN:
		y += speed;
		break;
	}
}

bool isOpposite(sDir d1, sDir d2)
{
	return (
		(d1 == LEFT && d2 == RIGHT) ||
		(d1 == RIGHT && d2 == LEFT) ||
		(d1 == UP && d2 == DOWN) ||
		(d1 == DOWN && d2 == UP));
}

void Snake::changeDir(sDir dir)
{
	// dir   - which button is pressed
	// this->dir   - current direction
	if (isOpposite(dir, this->dir))
	{
		return;
	}
	else
	{
		this->dir = dir;
	}
	
}

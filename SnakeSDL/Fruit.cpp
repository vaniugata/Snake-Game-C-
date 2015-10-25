#include "Fruit.h"
#include "Game\Game.h"

Fruit::Fruit(int x, int y)
: x(x), y(y)
{
	
}


Fruit::~Fruit()
{
}

void Fruit::draw(Game & g)
{
	g.drawRect(x, y, 20, 20, g.makeColor(0, 255, 0));
}

void Fruit::update()
{

}
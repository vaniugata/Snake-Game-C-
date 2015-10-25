#pragma once

class Game;

class Fruit 
{
public:
	Fruit(int x, int y);
	~Fruit();

	void update();
	void draw(Game & g);

	int x, y;
};



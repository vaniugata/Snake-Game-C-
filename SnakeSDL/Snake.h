#pragma once

class Game;
enum sDir{STOP = 0,LEFT, RIGHT, UP, DOWN};

class Snake
{
public:
	Snake(int x, int y);
	~Snake();

	void update();
	void draw(Game * g); // reference
	void changeDir(sDir dir);// v tozi sluchai obekta e maluk i e po-burzo da go copy insted of take


private:
	// x i y na zmiqta
	int x, y;
	bool LoshoMiE = false;
	sDir dir;
	int speed;
	

};


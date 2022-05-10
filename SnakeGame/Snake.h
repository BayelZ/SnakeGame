#pragma once

#include <iostream>
#include <vector>
#include "Apple.h"
#include "framework.h"
#include "SnakePart.h"

using namespace std;

class Snake
{

public:
	Snake(int, int, int, int, Apple);

	void playerMovement(char input);
	void setControls(char, char, char, char);
	void checkFront(int dir);

	//Get & Set Functions
	int getRowLoc();
	int getColLoc();
	int getDirection();

	bool isAlive();

	void setRowLoc(int nRow);
	void setColLoc(int nCol);
	void setDirection(int nDirection);

	void setAlive(bool nBool);

	void updateApple(Apple);
	void updateBody(int, int, int, bool);
private:
	int rowLocation;
	int colLocation;
	int direction;
	int addLength;
	int appleCount;

	Apple apple;

	const int NORTH = 0, SOUTH = 1, EAST = 3, WEST = 4;

	char UP, DOWN, LEFT, RIGHT;

	bool alive;

	vector<SnakePart> body;
};


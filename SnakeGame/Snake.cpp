#include "Snake.h"

Snake::Snake(int startRow, int startCol, int startLength, int startDirection, Apple apple) {
	appleCount = 0;
	rowLocation = startRow;
	colLocation = startCol;
	direction = startDirection;
	addLength = (appleCount + 1) * 3 / 2;
	alive = true;

	UP = 'w';
	DOWN = 's';
	LEFT = 'a';
	RIGHT = 'd';

	this->apple = apple;

	//Creating the starting body
	for (int i = 0; i < startLength; i++) {
		switch (startDirection) {
		case 0:
			body.push_back(*new SnakePart(startRow + i, startCol, startDirection));
			break;
		case 1:
			body.push_back(*new SnakePart(startRow - i, startCol, startDirection));
			break;
		case 2:
			body.push_back(*new SnakePart(startRow, startCol - i, startDirection));
			break;
		case 3:
			body.push_back(*new SnakePart(startRow, startCol + i, startDirection));
			break;
		}
	}
}

//Get and Set Functions
int Snake::getRowLoc()
{
	return rowLocation;
}
int Snake::getColLoc()
{
	return colLocation;
}
int Snake::getDirection()
{
	return direction;
}
bool Snake::isAlive() {
	return alive;
}
void Snake::setRowLoc(int nRow)
{
	rowLocation = nRow;
}
void Snake::setColLoc(int nCol)
{
	colLocation = nCol;
}
void Snake::setDirection(int nDirection)
{
	direction = nDirection;
}
void Snake::setAlive(bool nBool) {
	alive = nBool;
}

void Snake::updateApple(Apple nApple)
{
	apple = nApple;
}

//Recieves keypress char and changes direction based on the char
void Snake::playerMovement(char input) {
	switch (input) {
	case 0:
		if (direction != NORTH || direction != SOUTH) {
			direction = NORTH;
			checkFront(direction);
		}
		break;
	case 1:
		if (direction != NORTH || direction != SOUTH) {
			direction = SOUTH;
			checkFront(direction);
		}
		break;
	case 2:
		if (direction != WEST || direction != EAST) {
			direction = WEST;
			checkFront(direction);
		}
		break;
	case 3:
		if (direction != WEST || direction != EAST) {
			direction = EAST;
			checkFront(direction);
		}
		break;
	}
}

void Snake::checkFront(int dir) {

}

void Snake::setControls(char nUP, char nDOWN, char nRIGHT, char nLEFT) {
	UP = nUP;
	DOWN = nDOWN;
	LEFT = nLEFT;
	RIGHT = nRIGHT;
}

void Snake::updateBody(int row, int col, int dir, bool eaten) {
	SnakePart pastPart = *new SnakePart(row, col, dir);
	int hRow, hCol, hDir;
	for (SnakePart part: body)
	{
		hRow = part.getRow();
		hCol = part.getCol();
		hDir = part.getDirection();
		part.setPostion(pastPart.getRow(), pastPart.getCol(), pastPart.getDirection());
		pastPart.setPostion(hRow, hCol, hDir);
	}

	if (eaten) {
		int nDir = body[body.size() - 1].getDirection();
		int nRow = body[body.size() - 1].getRow();
		int nCol = body[body.size() - 1].getCol();
			for (int i = 0; i < addLength; i++) {
				switch (nDir) {
				case 1:
					body.push_back(*new SnakePart(nRow + i, nCol, nDir));
					break;
				case 2:
					body.push_back(*new SnakePart(nRow - i, nCol, nDir));
					break;
				case 3:
					body.push_back(*new SnakePart(nRow, nCol - i, nDir));
					break;
				case 4:
					body.push_back(*new SnakePart(nRow, nCol + i, nDir));
					break;
				}
			}
	}
}
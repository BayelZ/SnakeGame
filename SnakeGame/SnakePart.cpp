#include "SnakePart.h"

SnakePart::SnakePart(int row, int col, int direction) {
	rowLoc = row;
	colLoc = col;
	this->direction = direction;
}

void SnakePart::setPostion(int nRow, int nCol, int direction) {
	rowLoc = nRow;
	colLoc = nCol;
	this->direction = direction;
}

int SnakePart::getRow()
{
	return rowLoc;
}

int SnakePart::getCol()
{
	return colLoc;
}

int SnakePart::getDirection()
{
	return direction;
}

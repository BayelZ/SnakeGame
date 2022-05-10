#pragma once

class SnakePart
{
public:
	SnakePart(int, int, int);
	void setPostion(int, int, int);

	int getRow();
	int getCol();
	int getDirection();
private:
	int rowLoc, colLoc, direction;
};
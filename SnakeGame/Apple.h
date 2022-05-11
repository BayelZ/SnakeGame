#pragma once
class Apple
{
	int aX, aY;
	Apple();
	~Apple();
	int getX();
	int getY();
	int score;
	void generate(int width, int height);

};

Apple::~Apple()
{
	cout << "Apple destructor is executed" << endl;
}

int Apple::getX() {
	return aX;
}

int Apple::getY() {
	return aY;
}
// generate apple at a random location on map
void Apple::generate(int width, int height)
{
	aX = rand() % (width - 2) + 1;
	aY = rand() % (height - 2) + 1;
};
cout << "Apple" << endl;

// snake hits apple
if (x == aX && y == aY) {
	score += 10;
	aX = rand() % (width - 2) + 1;
	aY = rand() % (height - 2) + 1;
}

cout << "Score:" << score << endl;
};

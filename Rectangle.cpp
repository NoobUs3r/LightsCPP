#include "Rectangle.h"
#include<SFML/Graphics.hpp>
#include<stdint.h>
#include <time.h>  

using namespace std;

void Rectangle::SetAngle(float x, float y, int width, int height) {
	angle = atan2(y - height / 2, x - width / 2);
	angleCos = cos(angle);
	angleSin = sin(angle);
}

Rectangle::Rectangle() {
	x = 1;
	y = 1;
	angle = 1;
	angleCos = 1;
	angleSin = 1;
	size = 1;
}

void Rectangle::MoveFromCenter(int width, int height) {
	y += angleSin;
	x += angleCos;
}

void Rectangle::SetRandomCoordinatesInCenter(int width, int height) {
	int widthOneThird = width / 3;
	int widthTwoThird = width - widthOneThird;
	int heightOneThird = height / 3;
	int heightTwoThird = height - heightOneThird;

	x = rand() % (widthTwoThird - widthOneThird + 1) + widthOneThird;
	y = rand() % (heightTwoThird - heightOneThird + 1) + heightOneThird;
	SetAngle(x, y, width, height);
}

void Rectangle::SetRandomCoordinates(int width, int height) {
	x = rand() % (width - 1);
	y = rand() % (height - 1);
	SetAngle(x, y, width, height);
}

void Rectangle::SetRandomSize() {
	int min = 1;
	int max = 10;
	size = rand() % (max - min + 1) + min;
}


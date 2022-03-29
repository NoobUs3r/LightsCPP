#pragma once
#include<SFML/Graphics.hpp>
#include<stdint.h>
#include <time.h>  

using namespace std;

class Rectangle
{
	private:
		float x, y, angle, angleCos, angleSin;
		int size;

		void SetAngle(float x, float y, int width, int height);

	public:
		Rectangle();

		float GetX() { return x; }
		float GetY() { return y; }
		int GetSize() { return size; }

		void MoveFromCenter(int width, int height);
		void SetRandomCoordinatesInCenter(int width, int height);
		void SetRandomCoordinates(int width, int height);
		void SetRandomSize();
};


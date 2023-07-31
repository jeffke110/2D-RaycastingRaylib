#pragma once
#ifndef BOUNDARY_H
#define BOUNDARY_H

#define LEFT true
#define RIGHT false


#include "raylib.h"
#include "raymath.h"
#include "Random.h"
#include <ctime>   
#include <cmath>
#include <algorithm>

class Boundary {

public:
	Boundary(float x1, float y1, float x2, float y2, bool direction);
	Boundary();
	~Boundary();
	void draw();

	Vector2 start;
	Vector2 end;
private:
	bool direction;

};

class Car {
public:
	Car(bool direction, Texture2D& carTexture);
	~Car();
	void draw();
	bool isOffScreen();
	bool isMiddle();
	bool getDirection();
	std::vector<Boundary> getBoundaries();
private:
	std::vector<Boundary> boundaries;
	bool direction;
	Texture2D carTexture;
	Vector2 position;
	int height;
	int width;
};


class Cars {
public:
	Cars();
	~Cars();
	void drawCars();
	void removeCars();
	std::vector<Car> getCarsList();
private:
	std::vector<Car> carsList;
	Texture2D carTexture;


};








#endif // !BOUNDARY_H


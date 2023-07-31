#pragma once
#ifndef RAY_H
#define RAY_H


#include "boundary.h"
#include <vector>


class RayCast {

public:
	RayCast(Vector2 &position, float angle);
	Vector2 cast(Boundary wall);
	~RayCast();

private:
	Vector2 position;
	Vector2 direction;


};

#endif // !RAY_H

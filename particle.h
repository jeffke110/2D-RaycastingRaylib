#pragma once
#ifndef PARTICLE
#define PARTICLE

#include "ray.h"

class Particle {

public:
	Particle(Vector2 position, bool direction);
	~Particle();
	void draw();
	void detection(Cars cars);
	float distanceBetweenVectors(const Vector2& v1, const Vector2& v2);

private:
	std::vector<RayCast> rays;
	Vector2 position;
	bool direction;
	Texture2D car;
	Color color;
};

#endif // !PARTICLE


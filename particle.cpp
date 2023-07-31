#include "particle.h"




Particle::Particle(Vector2 position, bool direction) {
	this->position = position;
	this->direction = direction;
	car = LoadTexture("resources/blueCar.png");
	//creata circle of arrays pointing outwards
	for (int angle = 0; angle < 360; angle += 1) {
		rays.push_back(RayCast(position, (float)angle));
	}
	//change color based on the direction the car is facing
	color.a = 150;
	if (direction) {
		color.g = 100;
	}
	else {
		color.g = 100;
		color.r = 100;
	}
}
Particle::~Particle() {

}

//go through each ray and draw min distance from the array of boundaries
void Particle::detection(Cars carsObject) {
	for (auto& ray : rays) {
		Vector2 closestPoint = Vector2{ NULL, NULL };
		float minDistance = INFINITY;
		for (auto& car : carsObject.getCarsList()) {
			for (auto& boundary : car.getBoundaries()) {
				Vector2 point = ray.cast(boundary);
				if (point.x != NULL && point.y != NULL) {
					float distance = distanceBetweenVectors(position, point);
					if (distance < minDistance) {
						minDistance = distance;
						closestPoint = point;
					}
				}
			}
		}
		if (closestPoint.x != NULL && closestPoint.y != NULL) {
			if (direction) {
				DrawLine(position.x, position.y + 50, closestPoint.x, closestPoint.y, color);
			}
			else {
				DrawLine(position.x, position.y - 50, closestPoint.x, closestPoint.y, color);
			}
			
		}
	}

}

//calculate the distance between two vectors
float Particle::distanceBetweenVectors(const Vector2& v1, const Vector2& v2) {
	float dx = v2.x - v1.x;
	float dy = v2.y - v1.y;
	return sqrt(dx * dx + dy * dy);
}

void Particle::draw() {
	if (direction) {
		position = { (float)GetScreenWidth() - 300, 300.0f };
		DrawTextureEx(car, position, 0.0f, 1.0f, WHITE);
	}
	else {
		position = { 300.0f, (float)GetScreenHeight() - 300 };
		DrawTextureEx(car, position, 180.0f, 1.0f, WHITE);
	}

}
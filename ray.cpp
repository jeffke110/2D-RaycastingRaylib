#include "ray.h"

Vector2 angleToVector(float angle) {

	float x = cos(angle);
	float y = sin(angle);
	return Vector2{ x, y };
}


RayCast::RayCast(Vector2 &position, float angle) {
	this->position = position;
	this->direction = angleToVector(angle);
}

RayCast::~RayCast() {


}

//function to calculate intersection between ray and the boundary
Vector2 RayCast::cast(Boundary wall) {
	float x1 = wall.start.x;
	float y1 = wall.start.y;
	float x2 = wall.end.x;
	float y2 = wall.end.y;

	float x3 = position.x;
	float y3 = position.y;
	float x4 = position.x + direction.x;
	float y4 = position.y + direction.y;


	float denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	//ray is parallel to wall
	if (denominator == 0) {
		return Vector2{ NULL, NULL };
	}
	float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
	float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;
	//ray intersects wall and returns point
	if (t > 0 && t < 1 && u > 0) {
		Vector2 point = { 0.0f, 0.0f };
		point.x = x1 + t * (x2 - x1);
		point.y = y1 + t * (y2 - y1);
		return point;
	}
	//ray does not intersect wall
	else {
		return Vector2{ NULL, NULL };
	}

}
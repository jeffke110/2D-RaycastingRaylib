#include "boundary.h"

Boundary::Boundary() {
	// Initialize members to default values
	start.x = 0.0f;
	start.y = 0.0f;
	end.x = 0.0f;
	end.y = 0.0f;
	this->direction = LEFT;
}


//create a boundary representing a line
Boundary::Boundary(float x1, float y1, float x2, float y2, bool direction) {

	start.x = x1;
	start.y = y1;
	end.x = x2;
	end.y = y2;
	this->direction = direction;

}
Boundary::~Boundary() {

}

void Boundary::draw() {
	DrawLine(start.x, start.y, end.x, end.y, RED);
	//left to right
	if (direction) {
		start.x -= 2;
		end.x -= 2;
	}
	//right to left
	else {
		start.x += 2;
		end.x += 2;
	}
}


Car::Car(bool direction, Texture2D& carTexture) {
	height = 50;
	width = 200;
	this->direction = direction;
	this->carTexture = carTexture;
	//left to right
	if (direction) {
		//boundaries of the car (4 boundaries)
		boundaries.push_back(Boundary(GetScreenWidth() + 100.0f, GetScreenHeight() / 4 - height, GetScreenWidth() + width + 100.0f, GetScreenHeight() / 4 - height, true)); //top
		boundaries.push_back(Boundary(GetScreenWidth() + 100.0f, GetScreenHeight() / 4 + height, GetScreenWidth() + width + 100.0f, GetScreenHeight() / 4 + height, true)); //bottom
		boundaries.push_back(Boundary(GetScreenWidth() + width + 100.0f, GetScreenHeight() / 4 - height, GetScreenWidth() + width + 100.0f, GetScreenHeight() / 4 + height, true)); //right
		boundaries.push_back(Boundary(GetScreenWidth() + 100.0f, GetScreenHeight() / 4 - height, GetScreenWidth() + 100.0f, GetScreenHeight() / 4 + height, true)); //left
		position.x = GetScreenWidth() + width + 100.0f;
		position.y = (float)GetScreenHeight() / 4 + height;
	}
	//right to left
	else {
		//boundaries of the car (4 boundaries)
		boundaries.push_back(Boundary(-width - 100.0f, GetScreenHeight() * 3 / 4 - height, -100.0f, GetScreenHeight() * 3 / 4 - height, false)); //top
		boundaries.push_back(Boundary(-width - 100.0f, GetScreenHeight() * 3 / 4 + height, - 100.0f, GetScreenHeight() * 3 / 4 + height, false)); //bottom
		boundaries.push_back(Boundary(0.0f - 100.0f, GetScreenHeight() * 3 / 4 - height, -100.0f, GetScreenHeight() * 3 / 4 + height, false));   //right
		boundaries.push_back(Boundary(-width - 100.0f, GetScreenHeight() * 3 / 4 - height, -width - 100.0f, GetScreenHeight() * 3 / 4 + height, false)); //left
		position.x = -width - 100.0f;
		position.y = (float)GetScreenHeight() * 3 / 4 - height;
	}

}
Car::~Car() {

}

void Car::draw() {
	for (auto& boundary : boundaries) {
		boundary.draw();
	}
	//right to left
	if(direction){
		DrawTextureEx(carTexture, position, 180.0, 1.0, WHITE);
		position.x -= 2;
	}
	//left to right
	else {
		DrawTextureEx(carTexture, position, 0.0, 1.0, WHITE);
		position.x += 2;
	}
}
bool Car::isOffScreen() {
	if (position.x  + 100.0 < 0.0 && direction) {
		return true;
	}
	else if (position.x - 100.0 > GetScreenWidth() && !direction) {
		return true;
	}
	else {
		return false;
	}
}
bool Car::isMiddle() {
	if (direction) {
		return position.x == (float)GetScreenWidth() / 2;
	}
	return position.x + 200 == (float)GetScreenWidth() / 2;
}

bool Car::getDirection() {
	return direction;
}

std::vector<Boundary> Car::getBoundaries() {
	return boundaries;
}


Cars::Cars() {
	carTexture = LoadTexture("resources/car.png");
	carsList.push_back(Car(LEFT, carTexture));
	carsList.push_back(Car(RIGHT, carTexture));
}
Cars::~Cars() {

}
void Cars::drawCars() {
	for (auto& car : carsList) {
		car.draw();
	}
}

void Cars::removeCars() {
	for (auto& car : carsList) {
		if (car.isMiddle() && car.getDirection()) {
			carsList.push_back(Car(LEFT, carTexture));
		}
		if (car.isMiddle() && !car.getDirection()) {
			carsList.push_back(Car(RIGHT, carTexture));
		}
	}
	auto it = std::remove_if(carsList.begin(), carsList.end(), [](Car& b) { return b.isOffScreen();  });
	carsList.erase(it, carsList.end());
}

std::vector<Car> Cars::getCarsList() {
	return carsList;
}


/*******************************************************************************************
*
*   2D Raycasting - Jeffrey Kedda
*   
*   2D Raycasting example involving simple rays casting onto moving cars based on the closest boundary's intersection
*
********************************************************************************************/

#include "particle.h"

int main(void)
{
    // Initialization
    const int screenWidth = 1280;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "2d Raycasting - Jeffrey Kedda");
    SetTargetFPS(60);
    Random::Init();

    Vector2 onePosition = { (float)GetScreenWidth() - 300, 300.0f };
    Vector2 twoPosition = { 300.0f, (float)GetScreenHeight() - 300 };
    Particle policeCarOne = Particle(onePosition, LEFT);
    Particle policeCarTwo = Particle(twoPosition, RIGHT);
    Cars cars = Cars();
    
    while (!WindowShouldClose())    
    {
      
        BeginDrawing();
        ClearBackground(BLACK);
        policeCarOne.detection(cars);
        policeCarTwo.detection(cars);
        

        cars.drawCars();
        policeCarOne.draw();
        policeCarTwo.draw();
        DrawLine(0, GetScreenHeight() /2 , GetScreenWidth(), GetScreenHeight() / 2, WHITE);

        cars.removeCars();
        EndDrawing();

    }


    CloseWindow();

    return 0;
}
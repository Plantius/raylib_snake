#include "/home/niels/projects/game_projects/raylib/src/raylib.h"

#define FPS 60

int main()
{
    const int windowWidth = 800;
    const int windowHeight = 450;

    int posX = windowWidth/2, posY = windowHeight/2;

    int movementSpeed = 5;

    InitWindow(windowWidth, windowHeight, "Snake -- raylib");
    SetTargetFPS(FPS);

    while(!WindowShouldClose()){
        BeginDrawing();

        if (IsKeyDown(KEY_UP)){
            posY -= movementSpeed;
        }if (IsKeyDown(KEY_DOWN)){
            posY += movementSpeed;
        }if (IsKeyDown(KEY_LEFT)){
            posX -= movementSpeed;
        }if (IsKeyDown(KEY_RIGHT)){
            posX += movementSpeed;
        }

        ClearBackground(RAYWHITE);
        DrawCircle(posX, posY, 30, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

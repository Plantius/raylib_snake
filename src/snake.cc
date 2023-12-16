#include "/home/niels/projects/game_projects/raylib/src/raylib.h"

#define FPS 60

int main()
{
    const int windowWidth = 800;
    const int windowHeight = 450;

    int posX = windowWidth/2, posY = windowHeight/2;

    int movementSpeed = 5;
    int signX = 0, signY = 0;
    InitWindow(windowWidth, windowHeight, "Snake -- raylib");
    SetTargetFPS(FPS);

    while(!WindowShouldClose()){
        BeginDrawing();
        
        if (IsKeyDown(KEY_UP)){
            signY = -1;
            signX = 0;
        }else if (IsKeyDown(KEY_DOWN)){
            signY = 1;
            signX = 0;
        }else if (IsKeyDown(KEY_LEFT)){
            signX = -1;
            signY = 0;
        }else if (IsKeyDown(KEY_RIGHT)){
            signX = 1;
            signY = 0;
        }

        posY += signY*movementSpeed;
        posX += signX*movementSpeed;
        ClearBackground(RAYWHITE);
        DrawCircle(posX, posY, 30, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

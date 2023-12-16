#include "/home/niels/projects/game_projects/raylib/src/raylib.h"
#include "snake.h"
#include <iostream>

#define FPS 60

#define MOVEMENT_SPEED 100.0f

void updatePlayer(snake* player, float delta, int &signX, int &signY){
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
    player->setPosition({signX*MOVEMENT_SPEED*delta, signY*MOVEMENT_SPEED*delta});
}

int main()
{
    const int windowWidth = 800;
    const int windowHeight = 450;
    Vector2 startPos = {windowWidth/2, windowHeight/2};
    snake player(startPos, 0);
    float deltaTime = 0;
    int signX = 0, signY = 0;

    InitWindow(windowWidth, windowHeight, "Snake -- raylib");
    SetTargetFPS(FPS);

    while(!WindowShouldClose()){
        // UPDATE PLAYER
        deltaTime = GetFrameTime();
        updatePlayer(&player, deltaTime, signX, signY);
        std::cout << player.getPosition().x << ","<<player.getPosition().y << std::endl;
        // DRAW PLAYER
        BeginDrawing();
        
        ClearBackground(RAYWHITE);

        Rectangle playerRec = {player.getPosition().x, player.getPosition().y, 40, 40};
        DrawRectangleRec(playerRec, PINK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

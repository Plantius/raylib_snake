#include "raylib.h"
#include "snake.h"
#include "object.h"
#include <iostream>
#include <vector>

#define FPS 60

#define MOVEMENT_SPEED 200.0f

#define BORDER 20

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
    snake player({windowWidth/2, windowHeight/2}, 0);

    // Define Objects
    Rectangle playerRec = {player.getPosition().x, player.getPosition().y, 40, 40};
    std::vector<coin> coins;
    srand(time(0));
    for(int i = 0; i < 20; i++){
        Vector2 pos = {(float)(rand()%(windowWidth-BORDER) + BORDER), 
                       (float)(rand()%(windowHeight-BORDER) + BORDER)};
        coins.push_back(coin(pos));
        // std::cout << c.getPosition().x << "," << c.getPosition().y << std::endl;
    }
    
    float deltaTime = 0;
    int signX = 0, signY = 0;

    InitWindow(windowWidth, windowHeight, "Snake -- raylib");
    SetTargetFPS(FPS);

    while(!WindowShouldClose()){
        // UPDATE PLAYER
        deltaTime = GetFrameTime();
        updatePlayer(&player, deltaTime, signX, signY);

        // DRAW PLAYER
        BeginDrawing();
        
        ClearBackground(RAYWHITE);

        for (auto c : coins){
            DrawCircle(c.getPosition().x, c.getPosition().y, 10, RED);
        }
        playerRec.x = player.getPosition().x, playerRec.y = player.getPosition().y;
        DrawRectangleRec(playerRec, PINK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

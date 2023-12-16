#include "/home/niels/projects/game_projects/raylib/src/raylib.h"
#include "/home/niels/projects/game_projects/raylib_snake/include/snake.h"

#define FPS 60

#define MOVEMENT_SPEED 5.0f

void updatePlayer(snake &player, const float delta){
    int signX = 0, signY = 0;
    if (IsKeyDown(KEY_UP)){
        signY = -1;
    }else if (IsKeyDown(KEY_DOWN)){
        signY = 1;
    }else if (IsKeyDown(KEY_LEFT)){
        signX = -1;
    }else if (IsKeyDown(KEY_RIGHT)){
        signX = 1;
    }
    player.setPostition({signX*MOVEMENT_SPEED*delta, signY*MOVEMENT_SPEED*delta});
}

int main()
{
    const int windowWidth = 800;
    const int windowHeight = 450;
    snake player;
    player.setPostition({windowWidth/2, windowHeight/2});

    float deltaTime = 0;

    InitWindow(windowWidth, windowHeight, "Snake -- raylib");
    SetTargetFPS(FPS);

    while(!WindowShouldClose()){
        // UPDATE PLAYER
        deltaTime = GetFrameTime();
        updatePlayer(player, deltaTime);

        // DRAW PLAYER
        BeginDrawing();
        
        ClearBackground(RAYWHITE);

        Rectangle playerRec = {player.getPosition().x, player.getPosition().y, 40, 40};
        DrawRectangleRec(playerRec, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

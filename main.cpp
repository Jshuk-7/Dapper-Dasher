#include "raylib.h"
#include <iostream>

namespace Raylib::DapperDasher
{
    int Run()
    {
        // Viewport settings
        const int WIDTH{512}, HEIGHT{380}, FPS{60};
        const char *TITLE{"DapperDasher"};

        // Rectangle transform
        const int RECT_WIDTH{50}, RECT_HEIGHT{80};
        int posX{WIDTH - RECT_WIDTH}, posY{HEIGHT - RECT_HEIGHT};
        int velocity{0};
        const int JUMP_VELOCITY{-22};

        // Game settings
        const int gravity{1};
        bool isInAir{};

        const char *SCARFY_PATH{"textures/scarfy.png"};
        Texture2D scarfy = LoadTexture(SCARFY_PATH);
        Rectangle scarfyRect;
        Vector2 scarfyPos;

        // Instance window
        InitWindow(WIDTH, HEIGHT, TITLE);
        SetTargetFPS(FPS);

        // Mainloop
        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(WHITE);

            // Ground check
            if (posY >= HEIGHT - RECT_HEIGHT)
            {
                velocity = 0;
                isInAir = false;
            }
            else
            {
                velocity += gravity;
                isInAir = true;
            }

            // Jump check
            if (IsKeyDown(KEY_SPACE) && !isInAir)
            {
                velocity += JUMP_VELOCITY;
            }

            posY += velocity;

            DrawRectangle(HEIGHT / 2, posY, RECT_WIDTH, RECT_HEIGHT, GREEN);

            EndDrawing();
        }

        return 0;
    }
}

int main()
{
    return Raylib::DapperDasher::Run();
}
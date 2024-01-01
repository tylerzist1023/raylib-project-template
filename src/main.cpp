#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "raylib.h"
#include "rlgl.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#pragma comment(lib, "libraylib.a")
#elif defined(PLATFORM_WIN32)
#pragma comment(lib, "opengl32")
#pragma comment(lib, "Gdi32")
#pragma comment(lib, "WinMM")
#pragma comment(lib, "User32")
#pragma comment(lib, "shell32")
#pragma comment(lib, "raylib")
#endif

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

struct GameState {
    int _;
};

void update(void *v) {
    GameState *s = (GameState *)v;

    // render
    BeginDrawing();
    {
        ClearBackground(SKYBLUE);

        DrawText("Hello world", 16, 16, 20, BLACK);

        GuiButton({16,48,100,30}, "Hello button");
    }
    EndDrawing();
}

int main(int argc, char* argv[]) {
    srand(time(0));

    GameState s;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "");

#ifdef PLATFORM_WEB
    emscripten_set_main_loop_arg(update,(void *)(&s),0,1);
#else
    SetTargetFPS(60);
    while(!WindowShouldClose()) {
        update(&s);
    }
#endif
    
    //CloseWindow();
    return 0;
}

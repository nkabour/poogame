/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "game.c"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 1000;
    const int fps = 60;
    // Main game loop
    Game game{screenWidth, screenHeight, fps, "The PooGame"};

    while (!game.GameShouldClose()) // Detect window close button or ESC key
    {
      game.Tick();
    }

    return 0;
}



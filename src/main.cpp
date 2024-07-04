// File: `main.cpp`
// Date: `2024-07-02 | 2024-07-03`

#include "framework.hpp"

int main(int argc, char const *argv[])
{
    framework *window = new framework(800, 600, "SDL Window", SDL_WINDOW_SHOWN);

    while(window->getRunning())
    {
        window->render();
        window->update();
    }

    window->~framework();
    return 0;
}

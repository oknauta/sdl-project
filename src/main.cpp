// File: `main.cpp`
// Date: `2024-07-02`


#include "framework.hpp"

int main(int argc, char const *argv[])
{
    Framework *framework = new Framework
    (800, 600, SDL_WINDOW_SHOWN);

    while(framework->GetRunning())
    {
        framework->Handle();
        framework->Render();
    }

    framework->~Framework();
    return 0;
}

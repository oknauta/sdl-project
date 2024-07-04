// File: `framework.cpp`
// Date: `2024-07-02 | 2024-07-03`

#include "framework.hpp"

framework::framework(int width, int height, const char *windowName, Uint32 windowFlags)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        running = true;
    }
    else
    {
        std::cerr << "Error trying to initializate app.\n";
        running = false;
    }


    if(SDL_CreateWindowAndRenderer(width, height, windowFlags, &window, &renderer) == 0)
    {
        running = true;
    }
    else
    {
        std::cerr << "Error trying to create window.\n";
        running = false;
    }

    SDL_SetWindowTitle(window, windowName);
}

void framework::render()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    // SDL_RenderDrawLine(renderer, 0, 0, 800, 600);

    SDL_RenderPresent(renderer);
}

void framework::update()
{
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            running = false;
        }
    }
}

framework::~framework()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
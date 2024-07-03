// File: `framework.cpp`
// Date: `2024-07-02`

#include "framework.hpp"

Framework::Framework(int width, int height, Uint32 windowFlags)
{
    SDL_Log("Starting SDL...");
    SDL_Init(SDL_INIT_EVERYTHING);
    running = true;

    SDL_Log("Creating window and renderer...");
    SDL_CreateWindowAndRenderer(width, height, windowFlags, &window, &renderer);
    SDL_Log("Finished.");
}

void Framework::Update()
{
    SDL_Log("Initializing loop...");
    while(running)
    {
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                SDL_Log("Pressed X button.");
                running = false;
            }
        }
        SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
    SDL_Log("Loop breaked.");
}

Framework::~Framework()
{
    SDL_Log("Destroying window and renderer...");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Log("Quitting...");
    SDL_Quit();
}
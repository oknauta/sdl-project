// File: `framework.cpp`
// Date: `2024-07-02`

#include "framework.hpp"

Framework::Framework(int width, int height, Uint32 windowFlags)
{
    SDL_Log("Starting SDL...");
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0 )
    {
        running = true;    
    }
    else
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error when starting the window.", NULL);
        running = false;
    }
    

    SDL_Log("Creating window and renderer...");
    SDL_CreateWindowAndRenderer(width, height, windowFlags, &window, &renderer);
    SDL_Log("Finished.");

    SDL_Surface *surface = IMG_Load("dog.jpg");
    shipTex = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

void Framework::Handle()
{
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            running = false;
        }
    }
}

void Framework::Render()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, shipTex, NULL, NULL);
    SDL_RenderPresent(renderer);
}

Framework::~Framework()
{
    SDL_Log("Destroying window and renderer...");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Log("Quitting...");
    SDL_Quit();
}
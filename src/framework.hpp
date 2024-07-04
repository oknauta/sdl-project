// File: `framework.hpp`
// Date: `2024-07-02 | 2024-07-03`

#include <SDL2/SDL.h>
#include <iostream>

class framework
{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event e;
        bool running;
    public:
        framework(int width, int height, const char *name, Uint32 windowFlags);

        void update();
        void render();

        bool getRunning() { return running; }

        ~framework();
};
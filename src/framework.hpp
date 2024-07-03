// File: `framework.hpp`
// Date: `2024-07-02`

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Framework
{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *dog;
        SDL_Event e;
        bool running;
    public:
        Framework(int width, int height, Uint32 windowFlags);
        void Handle();
        void Render();
        ~Framework();
        
        bool GetRunning() { return running; }
};
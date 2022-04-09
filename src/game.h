#pragma once
#include <SDL.h>
#include <string>

class SDL_Window;
class SDL_Renderer;
class SDL_Surface;
class SDL_Texture;

class Game
{
public:
    Game();
    ~Game();

    void update();
    void render();
    void handleEvents();
    void clean();
    void start();

    SDL_Surface *loadSurface(std::string path);

    static bool isRunning;

    const static int SCREEN_WIDTH = 640;
    const static int SCREEN_HEIGHT = 480;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Rect sourceRect;
    SDL_Rect destRect;
};

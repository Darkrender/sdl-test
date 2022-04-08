#pragma once

class SDL_Window;
class SDL_Renderer;

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

    static bool isRunning;

    const static int SCREEN_WIDTH = 640;
    const static int SCREEN_HEIGHT = 480;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#include "game.h"
#include <SDL.h>
#include <assert.h>

bool Game::isRunning;

Game::Game()
{
    assert(!SDL_Init(SDL_INIT_EVERYTHING));
    assert(window = SDL_CreateWindow("Chapter 1: Setting up SDL",
                                     SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                     SCREEN_WIDTH, SCREEN_HEIGHT,
                                     SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE));
    assert(renderer = SDL_CreateRenderer(window, -1, 0));
    isRunning = true;
}

void Game::update()
{
}

void Game::render()
{
    // set to black // This function expects Red, Green, Blue and
    //  Alpha as color values
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // clear the window to black
    SDL_RenderClear(renderer);

    // show the window
    SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            Game::isRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::start()
{
    while (Game::isRunning)
    {
        handleEvents();
        update();
        render();
    }
}

void Game::clean()
{
    // Cleanup code goes here
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

Game::~Game()
{
    clean();
}

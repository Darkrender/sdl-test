#include "game.h"
#include <SDL_image.h>
#include <assert.h>

bool Game::isRunning;

SDL_Surface* Game::loadSurface(std::string path)
{
    //The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, SDL_GetWindowSurface(window)->format, 0 );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}

Game::Game()
{
    assert(!SDL_Init(SDL_INIT_EVERYTHING));
    assert(window = SDL_CreateWindow("Chapter 1: Setting up SDL",
                                     SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                     SCREEN_WIDTH, SCREEN_HEIGHT,
                                     SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE));
    assert(renderer = SDL_CreateRenderer(window, -1, 0));

    int imgFlags = IMG_INIT_PNG;
    assert(IMG_Init(imgFlags) & imgFlags);

    auto tempSurface = loadSurface("../assets/loaded.png");
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    SDL_QueryTexture(texture, NULL, NULL, &sourceRect.w, &sourceRect.h);
    destRect.x = sourceRect.x = 0;
    destRect.y = sourceRect.y = 0;
    destRect.w = sourceRect.w;
    destRect.h = sourceRect.h;

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

    /** Our Code Here */
    SDL_RenderCopy(renderer, texture, &sourceRect, &destRect);

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

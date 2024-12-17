#include <stdio.h>
#include <windows.h>
#include "SDL2/include/SDL2/SDL.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


#ifndef true
typedef int bool;
#define true 0xFF
#define false 0x0
#endif

#define white 0xFFFFFFFF

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{

	bool quit = false;

	SDL_Event e;

	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("could not initialize sdl2: %s\n", SDL_GetError());
		return 1;
	}
	window = SDL_CreateWindow(
			    "hello_sdl2",
			    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			    SCREEN_WIDTH, SCREEN_HEIGHT,
			    SDL_WINDOW_SHOWN
			    );
	if (window == NULL) {
		printf("could not create window: %s\n", SDL_GetError());
		return 1;
	}
	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, NULL, white);
	SDL_UpdateWindowSurface(window);
	
	while(quit != true){

		while(SDL_PollEvent(&e))
		if (e.type == SDL_QUIT)
		{
	      quit = true;
		}

	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
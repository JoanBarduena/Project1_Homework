#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstdbool>
using namespace std;
#include "SDL/include/SDL.h"

#pragma comment (lib, "SDL/libx86/SDL2.lib")
#pragma comment (lib, "SDL/libx86/SDL2main.lib")

int WINDOW_WIDTH = 1200;
int WINDOW_HEIGHT = 800;
int RECT_LENGTH = 150;

int main(int argc, char* argv[]){
	
	SDL_Window *window;     
	SDL_Renderer * renderer; 

	SDL_Init(SDL_INIT_VIDEO);            

	window = SDL_CreateWindow("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	//Renderer
	renderer = SDL_CreateRenderer(window, -1, 0); 

	//Square 

	SDL_Rect rect; 

	rect.w = RECT_LENGTH; 
	rect.h = RECT_LENGTH; 
	rect.x = 525; 
	rect.y = 325;

	//Bullet 

	SDL_Rect bullet; 

	bullet.w = 50; 
	bullet.h = 30;


	bool isRunning = true; 
	SDL_Event event; 

	int num1 = 2, num2 = 2; 

	while (isRunning) {

		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				isRunning = false;
			}

			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					rect.x -= 30;
					break;
				case SDLK_RIGHT:
					rect.x += 30;
					break;
				case SDLK_UP:
					rect.y -= 30;
					break; 
				case SDLK_DOWN:
					rect.y += 30;
					break; 
				case SDLK_DOWN && SDLK_RIGHT:
					rect.y += 30; 
					rect.x += 30; 
					break; 
				case SDLK_SPACE:		
					bullet.x = rect.x + 150; 
					bullet.y = rect.y + (rect.h /2 - bullet.h / 2) ; 
					break; 
				}
			}
		}
		if (rect.x < 0) {
			rect.x = 0; 
		}
		else if (rect.x > 1050) {
			rect.x = 1050; 
		}
		else if (rect.y < 0) {
			rect.y = 0; 
		} 
		else if (rect.y > 650) {
			rect.y = 650; 
		}
		
		if (bullet.y < 1200) {
			bullet.x += 5;
			SDL_Delay(3);
		}

		SDL_SetRenderDrawColor(renderer, 16, 62, 166, 0);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 203, 32, 39, 0);
		SDL_RenderFillRect(renderer, &rect);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
		SDL_RenderFillRect(renderer, &bullet);

		SDL_RenderPresent(renderer); 
	}

	return 0; 
}
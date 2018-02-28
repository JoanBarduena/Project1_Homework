#include <iostream>
#include <cstdlib>
#include <cstdio>
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

	window = SDL_CreateWindow("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	//Renderer
	renderer = SDL_CreateRenderer(window, -1, 0); 
	SDL_SetRenderDrawColor(renderer, 16, 62, 166, 0); 
	SDL_RenderClear(renderer);

	//Square 

	SDL_Rect rect; 

	rect.w = RECT_LENGTH; 
	rect.h = RECT_LENGTH; 
	rect.x = 200; 
	rect.y = 200;

	int num1 = 1, num2 = 1;  

	while (1) {

		SDL_SetRenderDrawColor(renderer, 16, 62, 166, 0);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 203, 32, 39, 0);
		SDL_RenderFillRect(renderer, &rect);
		
		if (rect.x <= 0) {
			num1 = 1;
		}
		else if (rect.x >= 1050) {
			num1 = -1;
		}
		else if (rect.y <= 0) {
			num2 = 1;
		}
		else if (rect.y >= 650) {
			num2 = -1;
		}
		rect.x += num1;
		rect.y += num2;
		
		SDL_RenderPresent(renderer); 
		SDL_Delay(2); 

	}

	return 0; 
}
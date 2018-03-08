using namespace std;
#include "SDL/include/SDL.h"
#include "SDL_Image/include/SDL_image.h"

#pragma comment (lib, "SDL/libx86/SDL2.lib")
#pragma comment (lib, "SDL/libx86/SDL2main.lib")
#pragma comment (lib, "SDL_Image/libx86/SDL2_image.lib")

int WINDOW_WIDTH = 1200;
int WINDOW_HEIGHT = 800;
int RECT_LENGTH = 100;

int main(int argc, char* argv[]){
	
	SDL_Window *window;     
	SDL_Renderer * renderer; 
	SDL_Surface * surface; 
	SDL_Texture * texture; 

	SDL_Init(SDL_INIT_VIDEO);            
	
	window = SDL_CreateWindow("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	//Renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//Square 
	SDL_Rect rect;

	rect.w = RECT_LENGTH;
	rect.h = RECT_LENGTH;
	rect.x = 525;
	rect.y = 325;

	//Bullet 
	SDL_Rect bullet;

	bullet.w = 20;
	bullet.h = 10;

	//PNG
	SDL_Rect destination;
	destination.x = rect.x;
	destination.y = rect.y;
	destination.w = rect.w;
	destination.h = rect.h;

	surface = IMG_Load("RocketSDL.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	//SDL_FreeSurface(surface);

	bool isRunning = true; 
	bool up = false; 
	bool down = false; 
	bool left = false; 
	bool right = false;
	bool space = false; 

	SDL_Event event; 

	while (isRunning) {

		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				isRunning = false;
			}

			else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					left = true;
					break;
				case SDLK_RIGHT:
					right = true;
					break;
				case SDLK_UP:
					up = true;
					break;
				case SDLK_DOWN:
					down = true;
					break;
				case SDLK_SPACE:
					space = true; 
					break;
				}
			}
			else if (event.type == SDL_KEYUP) {
				switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					left = false; 
					break;
				case SDLK_RIGHT:
					right = false;
					break;
				case SDLK_UP:
					up = false;
					break;
				case SDLK_DOWN:
					down = false;
					break;
				case SDLK_SPACE:
					space = false; 
					break;
				}
			}
		}
		if (up == true) {
			rect.y -= 1;
		}
		if (down == true) {
			rect.y += 1;
		}
		if (right == true) {
			rect.x += 1;
		}
		if (left == true) {
			rect.x -= 1;
		}
		if (space == true) {
			bullet.x = rect.x + 100;
			bullet.y = rect.y + (rect.h / 2 - bullet.h / 2);
		}

		if (rect.x < 0) {
			rect.x = 0; 
		}
		else if (rect.x > 1100) {
			rect.x = 1100; 
		}
		else if (rect.y < 0) {
			rect.y = 0; 
		} 
		else if (rect.y > 700) {
			rect.y = 700; 
		}
		
		if (bullet.y < 1200) {
			bullet.x += 1; 
		}

		SDL_SetRenderDrawColor(renderer, 16, 62, 166, 0);
		SDL_RenderClear(renderer);

		//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		//SDL_RenderFillRect(renderer, &rect);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
		SDL_RenderFillRect(renderer, &bullet);

		SDL_RenderCopy(renderer, texture, &rect, &destination);
		SDL_RenderPresent(renderer);
		
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window); 
	SDL_Quit();

	return 0; 
}
#include "Crtanje.hpp"
#include<iostream>
void Crtaj(int* arr, SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_Event event;
	for (int i = 0; i < 100; i++)
	{
		//temporary
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawLine(renderer, i, 99, i, arr[i]);
	}
	SDL_RenderPresent(renderer);
	//SDL_Delay(5);
}

void Crtaj(int* arr, SDL_Renderer* renderer, int red, int blue) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_Event event;

	for (int i = 0; i < 100; i++)
	{
		//temporary
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		if (i == red)
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		if (i == blue)
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

		SDL_RenderDrawLine(renderer, i, 99, i, arr[i]);
	}
	SDL_RenderPresent(renderer);
	//SDL_Delay(5);
}


void ProveriTacne(int* arr, SDL_Renderer* renderer, Mix_Chunk* sound,unsigned int delay) {
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] < arr[i + 1]) {
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			SDL_RenderDrawLine(renderer, i, 99, i, arr[i]);
			SDL_RenderPresent(renderer);
			Mix_Volume(-1, i);
			int channel = Mix_PlayChannel(-1, sound, 0);
			SDL_Delay(delay);
			std::cout << arr[i]<<std::endl;
		}

	}
}

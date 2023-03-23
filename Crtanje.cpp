#include "Crtanje.hpp"
#include<iostream>
#include <Windows.h>

void Crtaj(int* arr, SDL_Renderer* renderer,int brojelemenata) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_Event event;
	for (int i = 0; i < brojelemenata; i++)
	{
		//temporary
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawLine(renderer, i, brojelemenata, i, arr[i]);
	}
	SDL_RenderPresent(renderer);
	//SDL_Delay(5);
}

void Crtaj(int* arr, SDL_Renderer* renderer, int red, int blue,int brojelemenata) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_Event event;
	for (int i = 0; i < brojelemenata; i++)
	{
		//temporary
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		if (i == red) {
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			Beep(100 + 10 * arr[i], 100);

		}
			

		if (i == blue) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		}

		SDL_RenderDrawLine(renderer, i, brojelemenata, i, arr[i]);
	}
	SDL_RenderPresent(renderer);
	//SDL_Delay(5);
}


void ProveriTacne(int* arr, SDL_Renderer* renderer, Mix_Chunk* sound,unsigned int delay,int brojelemenata) {
	for (int i = 0; i < brojelemenata; i++)
	{
		if (arr[i] < arr[i + 1]) {
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			SDL_RenderDrawLine(renderer, i, brojelemenata, i, arr[i]);
			SDL_RenderPresent(renderer);
			//SDL_Delay(1);
			//std::cout << arr[i]<<std::endl;
		} 
		
	}
}

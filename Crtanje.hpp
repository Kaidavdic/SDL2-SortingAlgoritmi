#pragma once
#include<SDL.h>
#include <SDL_mixer.h>

void Crtaj(int* arr, SDL_Renderer* renderer, int red, int blue);
void Crtaj(int* arr, SDL_Renderer* renderer);
void ProveriTacne(int* arr, SDL_Renderer* renderer,Mix_Chunk* sound,unsigned int delay);

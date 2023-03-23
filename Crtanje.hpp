#pragma once
#include<SDL.h>
#include <SDL_mixer.h>

void Crtaj(int* arr, SDL_Renderer* renderer, int brojelemenata);
void Crtaj(int* arr, SDL_Renderer* renderer, int red, int blue, int brojelemenata);
void ProveriTacne(int* arr, SDL_Renderer* renderer, Mix_Chunk* sound, unsigned int delay, int brojelemenata);

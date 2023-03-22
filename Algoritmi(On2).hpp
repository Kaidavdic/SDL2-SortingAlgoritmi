#pragma once
#include "Crtanje.hpp"
#include "SDL.h"
#include <algorithm>
#include <random>


void bubbleSort(int arr[], int n, SDL_Renderer* renderer);
void insertionSort(int arr[], int n, SDL_Renderer* renderer);
void selectionSort(int arr[], int n, SDL_Renderer* renderer);
void bogosort(int a[], int n, SDL_Renderer* renderer);
void CocktailSort(int a[], int n, SDL_Renderer* renderer);

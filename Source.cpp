#include <SDL.h>
#undef main
#include<iostream>
#include<random>
#include<ranges>
#include<algorithm>

using namespace std;

void Crtaj(int* arr, SDL_Renderer* renderer, int red, int blue) {
	for (int i = 0; i < 100; i++)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		if (i == red)
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		if (i == blue)
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderDrawLine(renderer, i, 99, i, arr[i]);

	}
}
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void selectionSort(int arr[], int n,SDL_Renderer* renderer)
{
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);
			Crtaj(arr, renderer, i, j);
			SDL_RenderPresent(renderer);
			SDL_Delay(5);
		}
		if (min_idx != i)
			swap(&arr[min_idx], &arr[i]);
	}
}
bool isSorted(int a[], int n)
{
	while (--n > 0)
		if (a[n] < a[n - 1])
			return false;
	return true;
}

void shuffle(int a[], int n)
{
	for (int i = 0; i < n; i++)
		swap(a[i], a[rand() % n]);
}

void bogosort(int a[], int n, SDL_Renderer* renderer)
{
	while (!isSorted(a, n)) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		Crtaj(a, renderer, -1, -1);
		SDL_RenderPresent(renderer);
		SDL_Delay(5);
		shuffle(a, n);
	}
		
}

void bubbleSort(int arr[], int n,SDL_Renderer*renderer)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);
			Crtaj(arr, renderer, i, j);
			SDL_RenderPresent(renderer);
			SDL_Delay(5);
		}
	}
}
int main()
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_CreateWindowAndRenderer(500, 500,0,&window,&renderer);
	SDL_RenderSetScale(renderer, 5, 5);
	random_device rd;
	uniform_int_distribution<> d(1, 99);
	int arr[100];
	for (int i = 0; i < 100; i++)
	{
		arr[i] = d(rd);
	}
	//bubbleSort(arr, 100, renderer);
	//bogosort(arr, 100, renderer);
	selectionSort(arr, 100, renderer);
	return 0;
}
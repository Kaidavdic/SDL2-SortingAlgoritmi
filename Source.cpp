#include <SDL.h>
#undef main
#include <SDL_mixer.h>

#include <iostream>
#include <random>
#include <algorithm>

#include "Crtanje.hpp"
#include "Algoritmi(On2).hpp"
#include "AlgoritmiO_nlogn_.hpp"

using namespace std;

int main()
{
	random_device rd;
	
	int n;
	//mod sortiranja
	int x;
	cout << "unesite broj elemenata:\n";
	cin >> n;
	int* arr = new int[n];
	cout << "\nUnesite kojim algoritmom zelite da sortirate: \n" <<
		"1.Bubble sort \n" <<
		"2.Selection sort,\n" <<
		"3.Bogo sort,\n" <<
		"4.Insertion sort\n" <<
		"5.Merge Sort\n" <<
		"6.Cocktail Sort\n";
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
	std::shuffle(arr, arr+n,rd);

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_CreateWindowAndRenderer(800, 800, 0, &window, &renderer);
	SDL_RenderSetScale(renderer,(float) 800/n,(float) 800/n);

	

	int result = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 512);
	Mix_Chunk* sound = Mix_LoadWAV("sound.wav");

	
	switch (x)
	{
	case 1:
		bubbleSort(arr, n, renderer);
		break;
	case 2:
		selectionSort(arr, n, renderer);
		break;
	case 3:
		bogosort(arr, n, renderer);
		break;
	case 4:
		insertionSort(arr, n, renderer);
		break;
	case 5:
		mergeSort(arr, 0, n, renderer,0,n);
		break;
	case 6:
		CocktailSort(arr, n, renderer);
		break;
	default:
		break;
	}

	ProveriTacne(arr, renderer, sound,0,n);
	char a;
	cin >> a;
	return 0;
}
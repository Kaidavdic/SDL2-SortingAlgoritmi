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
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_CreateWindowAndRenderer(500, 500,0,&window,&renderer);
	SDL_RenderSetScale(renderer, 5, 5);
	
	int result = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	Mix_Chunk* sound = Mix_LoadWAV("sound.wav");
	
	random_device rd;
	uniform_int_distribution<> d(1, 99);

	int arr[100];
	//mod sortiranja
	int x;
	for (int i = 0; i < 100; i++)
	{
		arr[i] = i;
	}
	std::shuffle(arr, arr+100,rd);

	cout << "Unesite kojim algoritmom zelite da sortirate: \n"<<
		"1.Bubble sort \n"<<
		"2.Selection sort,\n"<<
		"3.Bogo sort,\n"<<
		"4.Insertion sort\n"<<
		"5.Merge Sort\n";
	cin >> x;
	switch (x)
	{
	case 1:
		bubbleSort(arr, 100, renderer);
		break;
	case 2:
		selectionSort(arr, 100, renderer);
		break;
	case 3:
		bogosort(arr, 100, renderer);
		break;
	case 4:
		insertionSort(arr, 100, renderer);
		break;
	case 5:
		mergeSort(arr, 0, 100, renderer,20);
		break;
	case 6:
		bitonicSort(arr, 0, 100, 1, renderer);
		break;
	default:
		break;
	}
	ProveriTacne(arr, renderer, sound,10);
	
	char a;
	cin >> a;
	return 0;
}
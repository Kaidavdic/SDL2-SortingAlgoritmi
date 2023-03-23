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


#pragma region TEST

const int sampleRate = 44100; // The audio sample rate
const int duration = 1; // The duration of the sine wave in milliseconds
const double frequency = 440.0; // The base frequency of the sine wave
const double amplitude = 0.5 * 32767; // The amplitude of the sine wave

#pragma endregion



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

	
	Mix_OpenAudio(sampleRate, AUDIO_S16SYS, 1, 2048);

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

	//ProveriTacne(arr, renderer, sound,0,n);


#pragma region TEST
	if (Mix_OpenAudio(sampleRate, AUDIO_S16SYS, 1, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return 1;
	}

	// Generate and play the sine wave with pitch factor in each iteration of the for loop
	double pitchFactor = 1.0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < arr[i + 1]) {
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			SDL_RenderDrawLine(renderer, i, n, i, arr[i]);
			SDL_RenderPresent(renderer);
			Mix_Volume(-1, i);
			SDL_Delay(0);
			//std::cout << arr[i]<<std::endl;

		// Generate the sine wave
			int numSamples = duration * sampleRate / 1000;
			Uint8* rawAudio = new Uint8[numSamples * 2];
			for (int j = 0; j < numSamples; j++)
			{
				double currentSample = sin(j * frequency * 2 * M_PI / sampleRate * pitchFactor);
				Sint16 sampleValue = (Sint16)(amplitude * currentSample);
				rawAudio[j * 2] = (Uint8)(sampleValue & 0xFF);
				rawAudio[j * 2 + 1] = (Uint8)((sampleValue >> 8) & 0xFF);
			}

			// Load the sine wave as a Mix_Chunk object and play it
			Mix_Chunk* sineWave = Mix_QuickLoad_RAW(rawAudio, numSamples * 2);
			Mix_PlayChannel(-1, sineWave, 0);
			while (Mix_Playing(-1))
			{
				//SDL_Delay(1);
			}

			// Cleanup
			delete[] rawAudio;
			Mix_FreeChunk(sineWave);
			pitchFactor += 1; // Increase the pitch factor by 0.1 in each iteration
		}
	}

	// Cleanup
	Mix_CloseAudio();
#pragma endregion
			//std::cout << arr[i]<<std::endl;	
	char a;
	cin >> a;
	return 0;
}
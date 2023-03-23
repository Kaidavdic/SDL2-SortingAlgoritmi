#include "Algoritmi(On2).hpp"

void insertionSort(int arr[], int n, SDL_Renderer* renderer)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
			Crtaj(arr, renderer, i, j,n);
		}
		arr[j + 1] = key;
	}
}

void bubbleSort(int arr[], int n, SDL_Renderer* renderer)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
			Crtaj(arr, renderer, i, j,n);
		}
	}
}

void swapptr(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n, SDL_Renderer* renderer)
{
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			//Crtaj(arr, renderer, i, j,n);
		}
		if (min_idx != i)
			swapptr(&arr[min_idx], &arr[i]);
	}
}

void bogosort(int a[], int n, SDL_Renderer* renderer)
{
	while (!std::is_sorted(a, a+n)) {
		Crtaj(a, renderer,n);
		std::random_device rd;
		std::shuffle(a, a + n, rd);
	}

}
void CocktailSort(int a[], int n,SDL_Renderer* renderer)
{
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped) {
		swapped = false;

		for (int i = start; i < end; ++i) {
			if (a[i] > a[i + 1]) {
				std::swap(a[i], a[i + 1]);
				swapped = true;
			}
			Crtaj(a, renderer, i, -1,n);

		}

		if (!swapped)
			break;

		swapped = false;

		--end;

		for (int i = end - 1; i >= start; --i) {
			if (a[i] > a[i + 1]) {
				std::swap(a[i], a[i + 1]);
				swapped = true;
			}
			Crtaj(a, renderer, i, -1,n);

		}

		
		++start;
	}
}

#include "AlgoritmiO_nlogn_.hpp"

void merge(int array[], int const left, int const mid,
	int const right, SDL_Renderer* renderer,unsigned int delay)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne
		= 0, // Initial index of first sub-array
		indexOfSubArrayTwo
		= 0; // Initial index of second sub-array
	int indexOfMergedArray
		= left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
		Crtaj(array, renderer, indexOfMergedArray,-1);
		SDL_Delay(delay);
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;

	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}

	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end, SDL_Renderer* renderer,unsigned int delay)
{
	if (begin >= end) {
		return;
	}

	// Returns recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid, renderer,delay);
	mergeSort(array, mid + 1, end, renderer,delay);
	merge(array, begin, mid, end, renderer, delay);
}
void compAndSwap(int a[], int i, int j, int dir,SDL_Renderer*renderer)
{
	if (dir == (a[i] > a[j]))
		std::swap(a[i], a[j]);
	Crtaj(a, renderer, -1, -1);
	SDL_Delay(0);
}

/*It recursively sorts a bitonic sequence in ascending order,
  if dir = 1, and in descending order otherwise (means dir=0).
  The sequence to be sorted starts at index position low,
  the parameter cnt is the number of elements to be sorted.*/
void bitonicMerge(int a[], int low, int cnt, int dir, SDL_Renderer* renderer)
{
	if (cnt > 1)
	{
		int k = cnt / 2;
		for (int i = low; i < low + k; i++)
			compAndSwap(a, i, i + k, dir,renderer);
		bitonicMerge(a, low, k, dir,renderer);
		bitonicMerge(a, low + k, k, dir, renderer);
	}
	
}

/* This function first produces a bitonic sequence by recursively
	sorting its two halves in opposite sorting orders, and then
	calls bitonicMerge to make them in the same order */
void bitonicSort(int a[], int low, int cnt, int dir,SDL_Renderer* renderer)
{

	if (cnt > 1)
	{
		int k = cnt / 2;

		// sort in ascending order since dir here is 1
		bitonicSort(a, low, k, 1, renderer);

		// sort in descending order since dir here is 0
		bitonicSort(a, low + k, k, 0, renderer);

		// Will merge whole sequence in ascending order
		// since dir=1.
		bitonicMerge(a, low, cnt, dir, renderer);
		

	}
}
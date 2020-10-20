#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int& a, int& b);
void quickSort(int arr[], int left, int right);
void partition(int* arr, int& local_left, int& local_right);

int main()
{
	int n, left, right;
	cout << "n: "; cin >> n;
	int* arr = new int[n];
	srand(time(0));

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % n + 0;
	}

	left = 0;
	right = n - 1;

	quickSort(arr, left, right);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << '\n';

	delete[] arr;
	return 0;
}

void quickSort(int arr[], int left, int right) {
    int local_left = left, local_right = right;
	partition(arr, local_left, local_right);

    if (left < local_right)
        quickSort(arr, left, local_right);
    if (local_left < right)
        quickSort(arr, local_left, right);
}

void partition(int* arr, int& local_left, int& local_right)
{
	int pivot = arr[rand() % (local_right - local_left) + local_left];

	while (local_left <= local_right) {
		while (arr[local_left] < pivot)
			local_left++;
		while (arr[local_right] > pivot)
			local_right--;
		if (local_left <= local_right) {
			if(local_left != local_right)
				swap(arr[local_left], arr[local_right]);
			local_left++;
			local_right--;
		}
	}
}

void swap(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
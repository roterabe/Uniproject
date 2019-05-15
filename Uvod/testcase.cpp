#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;

int main()
{
	int j = 0;
	int k = 0;
	bool InvCount;
	int ind = 0;
	int ind2 = 0;
	int mid = 0;
	int buff = 0;
	int check = 2;
	int tmp = 0;
	int x = 0;
	int end = 0;
	const int N = 10000;
	int arr[N];

	for (int h = 0; h < mid; h++) {
		arr[h] = h;
		x++;
	}
	for (int k = N; k > mid; k--) {
		arr[x] = k;
		x++;
	}

	end = N - ind;

	clock_t startTime = clock();

	for (int i = 0; i < end; i++) {
		InvCount = false;

		while (j < N - 1) {
			if (arr[j] > arr[j + 1]) {
				k = arr[j + 1];
				InvCount = true;
				ind = j;
				end = N - ind;
				break;
			}
			j++;
		}
		if (InvCount == false) {
			break;
		}

		if (ind % 2 == 0) {
			mid = ind / 2;
		}
		else mid = (ind / 2) + 1;

		for (int h = 0; h < ind; h++) {
			if (k > arr[mid] && k < arr[mid + 1]) {
				ind2 = mid + 1;
				break;
			}
			if (k < arr[mid]) {
				check += 2;
				mid = ind / check;
			}
			else if (k > arr[mid]) {
				check += 2;
				tmp = ind / check;
				mid = mid + tmp;
			}
		}
		check = 2;
		buff = arr[ind + 1];

		for (int g = ind + 1; g > ind2; g--) {
			arr[g] = arr[g - 1];
		}

		arr[ind2] = buff;
	}

	clock_t endTime = clock();

	cout << (double)(endTime - startTime) / CLOCKS_PER_SEC << endl;

	return 0;
}
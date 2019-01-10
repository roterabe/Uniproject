
#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int* resheto;
	int num;
	int size;
	cin >> num;
	size = num + 1;
	resheto=new int[size];
	
	for (int i = 0; i < size; i++) {
		resheto[i] = 0;
	}

	for (int i = 2; i < size; i++) {
		if (resheto[i] == 0) {
			resheto[i] = i;
			for (int j = i * 2; j < size; j += i) {
				resheto[j] = -1;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		cout << resheto[i] << " ";
	}

	int count_primes = 0;
	for (int i = 0; i < size; i++) {
		if (resheto[i] > 0) {
			count_primes++;
		}
	}

	int* primes = new int[count_primes];
	int* powers = new int[count_primes];

	int pos = 0;
	for (int i = 0; i < size; i++) {
		if (resheto[i] > 0) {
			primes[pos] = resheto[i];
			pos++;
		}
	}
	int x;
	int pow;
	for (int i = 0; i < count_primes; i++) {
		x = num;
		pow = 0;

		while (x % primes[i] == 0) {
			pow++;
			x = x / primes[i];
		}
		powers[i] = pow;
	}
	cout << endl;
	for (int i = 0; i < count_primes; i++) {
		cout << primes[i] << "^" << powers[i] << endl;
	}
    


	return 0;
}


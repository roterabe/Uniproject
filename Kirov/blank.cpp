#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename T>
T maxA(T *arr, int s = 2)
{
  T maxVal = arr[0];
  for (int i = 1; i < s; i++)
    if (arr[i] > maxVal)
      maxVal = arr[i];
  return maxVal;
}

int main()
{
  long *a = new long[2];
  cout << maxA(a);
  vector<int> k[4, 7, 2];
  cout << k.erase(2);

  return 0;
}
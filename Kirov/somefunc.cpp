#include <iostream>
using namespace std;

void rec(int i)
{
  cout << i%100 -1;
  if (i/10 != 0) rec(i/10);
}
int main()
{
  rec(122);
  return 0;
}

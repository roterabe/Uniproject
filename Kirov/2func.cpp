#include <iostream>
#include <iomanip>
using namespace std;

int s(int);
int m(int);
int s(int n)
{ 
    if (n != 0) return n + m(n - 1);
    else return 1;
 }
int m(int n)
{ 
    if (n != 0) return n * s(n - 1);
    else return 0;
}

int main() {
    int k;
    cin >> k;
    cout << "s: " << s(k) << " : m: " << m(k);
    

    return 0;
}
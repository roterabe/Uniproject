#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";
    int my;
    double own;
    string nums;
    cin >> my;
    cin >> own;
    getline(cin, nums);
    cout << i + my << endl;
    double j = d + own;
    cout << std::fixed;
    cout << std::setprecision(1) << j << endl;
    cout << std::scientific << s + nums << endl;


    return 0;
}
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int> & v) {
for(auto e : v) {
cout << e << endl;
}
}

int main() {

vector<int> vi;
vector<string> vs;
vs.push_back("Hello");
vi.push_back(20);
vi.push_back(10);
cout << vi.size() << endl;
print(vi);
sort(vi.begin(), vi.end());
print(vi);

return 0;
}

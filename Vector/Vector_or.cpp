#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> &v) {
    for(auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
vector <int> v;
v.push_back(10);
v.push_back(20);
v.push_back(30);
cout << v.size() << endl;
cout << v.capacity() << endl;
cout << v.at(1) << endl;

print(v);

v.erase(v.begin()+1);
print(v);

v.insert(v.begin()+1, 21);
print(v);


    return 0;
}
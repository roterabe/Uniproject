#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool simple(int num){
        for(int i = 2; i<=num/2; i++){
            if(num % i == 0){
                return false;
        }
    }
    return true;
}

void print(vector<int> s){
    for (auto i:s){
        cout << i << " ";
    }
}

void insert(vector<int> s, vector<int>& mod){
    int cnt = 1;
    for (auto i:s){
        if (cnt % 2 == 0){
            mod.push_back(i);
        }
        cnt++;
    }
}

void calc(vector<int>& mod, int& sum){
    for (auto i:mod){
        sum += i;
    }
}

int main(){
    vector<int> s;
    vector<int> mod;
    int num = 1;
    int sz;
    int sum = 0;
    cout << "Enter size of vector: ";
    cin >> sz;

    //Iterates and inserts prime in vec on account of the simple function.
    for (int i = 0; i < sz; i++){
        if(simple(num)){
            s.push_back(num);
        }
    num++;
    }

//Erase 1 since it's not a part or Erathostenes
s.erase(s.begin());
insert(s, mod);
calc(mod, sum);
print(mod);
cout << endl;
cout << "The sum is: " << sum << endl;
    return 0;
}
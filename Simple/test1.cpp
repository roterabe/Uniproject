#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Checks if simple(prime)
bool simple(int num){
        for(int i = 2; i<=num/2; i++){
            if(num % i == 0){
                return false;
        }
    }
    return true;
}
//Prints vector
void print(vector<int> s){
    for (auto i:s){
        cout << i << " ";
    }
}
//Stores num needed to check in multi
void multip(vector<int>& s, int& multi, int first){
            multi = 1;
            for (int k = 0; k < first; k++){
            multi = multi * s[k];
        }
}

int main(){
    int multi;
    vector<int> s;
    vector<int> mod;
    int whole;
    int num = 1;
    int num1 = 1;
    cin >> whole;
    int sz = whole/2;
    int first = whole/4;
    int sum = 0;
    //Iterates and inserts prime in vec on account of the simple function.
    for (int i = 0; i < sz; i++){
        if(simple(num)){
            s.push_back(num);
        }
    num++;
    }
    for (int i = 0; i < whole*whole; i++){
        mod.push_back(num1);
        num1++;
    }
    s.erase(s.begin());
    multip(s, multi, first);
for(int i = 0; i < first-1; i++){
    for (int j = 0; j < whole*whole; j++){

    if (mod[j] % multi == 0){
        cout << mod[j] << " ";
        //cout << endl << s[i]*s[i+1];
        //cout << endl << s[i] << " ";
    }
}
}
//Erase 1 since it's not a part or Erathostenes

//insert(s, mod);
//calc(mod, sum);
//print(s);
cout << endl;
//print(mod);
//cout << endl;
//cout << "The sum is: " <<  << endl;
    return 0;
}
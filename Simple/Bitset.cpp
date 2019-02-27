#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Prints values in given vector
void print(vector<int> pr){
    for (auto i:pr){
        cout << i << " ";
    }
}
//Fills univesrum vector with 1s
void load1(vector<int>& univ, int sz){
    for (int i = 0; i < sz; i++){
        univ.push_back(1);
    }
}
//Fills subset vec with 0s
void fill2(vector<int>& subs, int sz){
    for (int i = 0; i < sz; i++){
        subs.push_back(0);
    }
}
//Fills bits where matching values depending on which vector is biggest
void load2(vector<int> uni, vector<int> univ, vector<int> sub, vector<int>& subs, int sz, int sz1){
    if(sz < sz1){
    for (int i = 0; i < sz1; i++){
        vector<int>::iterator it;
        for(it = uni.begin(); it != uni.end(); it++){
            int index = distance(uni.begin(), it);
            if (*it == sub[i]){
                subs[index] = 1;
            }
        }     
    }
    }
    if(sz > sz1){
            for (int i = 0; i < sz; i++){
        vector<int>::iterator it;
        for(it = uni.begin(); it != uni.end(); it++){
            int index = distance(uni.begin(), it);
            if (*it == sub[i]){
                subs[index] = 1;
            }
        }     
    }
    }
    }

//Shows values found in universum and subset
void printC(vector<int> univ, vector<int> subs, vector<int> uni){
    for (int i = 0; i < uni.size(); i++){
        if(univ[i] == subs[i]){
            cout << uni[i] << " ";
        }
    }
}
//Main takes input and returns results with data on the side
int main(){
    vector<int> uni;
    vector<int> sub;
    vector<int> univ;
    vector<int> subs;
    int sz, sz1;
    int input, input1;
    cout << "Enter uni size: ";
    cin >> sz;
    cout << "Enter values:" << endl;
    for (int i = 0; i < sz; i++){
        cin >> input;
        uni.push_back(input);
    }
    cout << "Enter sub size: ";
    cin >> sz1;
    cout << "Enter values:" << endl;
    for (int i = 0; i < sz1; i++){
        cin >> input1;
        sub.push_back(input1);
    }

    load1(univ, sz);
    fill2(subs, sz);
    load2(uni, univ, sub, subs, sz, sz1);
    cout << endl;
    print(uni);
    cout << endl;
    print(sub);
    cout << endl;
    print(univ);
    cout << endl;
    print(subs);
    cout << endl << "The common values are: ";
    printC(univ, subs, uni);

    return 0;
}
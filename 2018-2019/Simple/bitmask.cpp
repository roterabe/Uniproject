//Not fully functional but works

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

//Generates Fixed mask
void fill3(vector<int>& gen, int sz){
    int cnt = 1;
    for (int i = 0; i < sz; i++){
        gen.push_back(1);
    }
    gen[1] = 0;
    for(int i = 1; i < sz; i++){
        if(gen[i] == 1){
            gen[i] = 1;
        }
        if(gen[i] == 0)
        gen[i+4] = 0;
        
    }
}
//Shows values found in universum and subset
void printC(vector<int> subs, vector<int> gen, vector<int> sub){
    for (int i = 0; i < sub.size(); i++){
        if(subs[i] == gen[i]){
            cout << sub[i] << " ";
        }
    }
}

//Fills bits where matching values depending on which vector is biggest
// Finds matching value of bits and prints available numbers from Universum
void load2(vector<int> uni, vector<int> univ, vector<int> sub, vector<int>& subs, int sz, int sz1){
for(int i = 0; i < sz; i++){
    vector<int>::iterator it;
    for(it = sub.begin(); it != sub.end(); it++){
        int index = distance(sub.begin(), it);
        if(*it == uni[i]){
            subs[index] = univ[index];
        }
    }

}
}

//Main takes input and returns results with data on the side
int main(){
    vector<int> uni;
    vector<int> sub;
    vector<int> univ;
    vector<int> subs;
    vector<int> gen;
    vector<int> newmask;
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
    //fill2(subs, sz);
    //load2(uni, univ, sub, subs, sz, sz1);
    fill2(subs, sz);
    fill3(gen, sz);
    load2(uni, univ, sub, subs, sz, sz1);
    //cout << endl;
    //cout << endl << "Subs: ";
    //print(subs);
    //cout << endl;
    //print(gen);
    cout << endl << "The answer is: ";
    printC(subs, gen, sub);
    

    return 0;
}
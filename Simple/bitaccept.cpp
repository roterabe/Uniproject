#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//prints vector
void print(vector<int> pr){
    for (auto i:pr){
        std::cout << i << " ";
    }
}
//prints vector
void print1(vector<int> pr){
    for (auto i:pr){
        std::cout << i << " ";
    }
}
//Fills universum with 1s
void load1(vector<int>& univ, int sz){
    for (int i = 0; i < sz; i++){
        univ.push_back(1);
    }
}
//Fills sub with 0s for educational purposes 
void fill2(vector<int>& subs, int sz1){
    for (int i = 0; i < sz1; i++){
        subs.push_back(0);
    }
}
// Finds matching value of bits and prints available numbers from Universum
void load2(vector<int> uni, vector<int> univ, vector<int> sub, vector<int>& subs, int sz, int sz1){
for(int i = 0; i < sz; i++){
    vector<int>::iterator it;
    for(it = sub.begin(); it != sub.end(); it++){
        int index = distance(sub.begin(), it);
        if(*it == univ[i]){
            subs[index] = uni[index];
        }
    }

}
}

/*void printC(vector<int> univ, vector<int> subs, vector<int> uni){
    for (int i = 0; i < uni.size(); i++){
        if(univ[i] == subs[i]){
            std::cout << uni[i] << " ";
        }
    }
}*/


//Main declares variables and asks for input.
int main(){
    vector<int> uni;
    vector<int> sub;
    vector<int> univ;
    vector<int> subs;
    int sz, sz1;
    int input, input1;
    std::cout << "Enter uni size: ";
    cin >> sz;
    std::cout << "Enter values:" << endl;
    for (int i = 0; i < sz; i++){
        cin >> input;
        uni.push_back(input);
    }
    std::cout << "Enter sub size: ";
    cin >> sz1;
    std::cout << "Enter values:" << endl;
    for (int i = 0; i < sz1; i++){
        cin >> input1;
        sub.push_back(input1);
    }

    load1(univ, sz);
    fill2(subs, sz1);
    load2(uni, univ, sub, subs, sz, sz1);
    std::cout << endl;
    print(uni);
    std::cout << endl;
    print(sub);
    std::cout << endl;
    print1(univ);
    std::cout << endl;
    print1(subs);
    //std::cout << endl << "The common values are: ";
    //printC(univ, subs, uni);

    return 0;
}
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void print(vector<float> u){
    for (auto i:u)
    cout << i << " ";
}

void newvec(vector<float> a, vector <float> &b, vector<float> &c, int sz){
    for (int i = 0; i < sz; i++){
        float val = 0;
        float val1 = 0;
        val = b[i] - a[i];
        val1 = c[i] - a[i];
        b.push_back(val);
        c.push_back(val1); 
    }
}


int main(){

    vector<float> a, b, c, newa, newb;
    int sz;
    cout << "Enter vector size: ";
    cin >> sz;
    int ins, ins1, ins2;
    for (int i = 0; i < sz; i++){
        cin >> ins;
        a.push_back(ins);
    }
    for (int i = 0; i < sz; i++){
        cin >> ins1;
        b.push_back(ins1);
    }
    for (int i = 0; i < sz; i++){
        cin >> ins2;
        c.push_back(ins2);
    }
    newvec(a, b, c, sz);
    print(b);
    cout << endl;
    print(c);
    


    return 0;
}
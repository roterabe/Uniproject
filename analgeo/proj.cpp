#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void print(vector<float> u){
    for (auto i:u)
    cout << i << " ";
}
void length(vector<float> &v, float &sum){
    for (auto i:v){
        sum += pow(i, 2.0);
    }
    //cout << "sum: " <<  sum << endl;
}

void calc(vector<float> &u, vector<float> &v, float &calculate){
    for (int i = 0; i < u.size(); i++){
        calculate += u[i]*v[i];
    }
}

void projlength(float calculate, float sum){
    float square = sqrt(sum);
    float ans;
    ans = (calculate / square);
    cout << "Projection length: " << ans << endl;
}

int main(){
    float calculate = 0;
    float sum = 0;
    vector<float> u, v;
    int sz, sz1;
    cout << "Enter first vector size: ";
    cin >> sz;
    cout << "Enter second vector size: ";
    cin >> sz1;
    int ins, ins1;
    for (int i = 0; i < sz; i++){
        cin >> ins;
        u.push_back(ins);
    }
    for (int i = 0; i < sz1; i++){
        cin >> ins1;
        v.push_back(ins1);
    }
    //print(u);
    //cout << endl;
    //print(v);
    length(v, sum);
    //cout << endl;
    calc(u, v, calculate);
    projlength(calculate, sum);
    


    return 0;
}
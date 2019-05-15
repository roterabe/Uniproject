#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void fibon(vector<string> fi, double pos, string &p){
 //static bool initialized;
  fi.push_back(fi[0] + fi[1]);
  for (int k = 2; k < pos / 3; k++) {
    fi.push_back(fi[k - 2] + fi[k]);
    string o = fi[k - 2] + fi[k];
    if (o.length() >= pos && o.length() < pos*2) {
      //if (!initialized) {
        //initialized = true;
        // do the initialization part
        p = fi[k - 2] + fi[k];
        //cout << p << endl;
      }
    }
    }


void print(vector<string> fi){
    for (auto e:fi){
        cout << e << " ";
    }
}




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string a;
    vector<string> fi = vector<string>();
    string b;
    string p;
    double pos;
    int q = 0;
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> a >> b >> pos;
        fi.push_back(a);
        fi.push_back(b);
    
    fibon(fi, pos, p);
    cout << p.at(pos-2);
    //cout << endl << p;
    //cout << endl;
    //print(fi);
    fi = vector<string>();
    }


    return 0;
}


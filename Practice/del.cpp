#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    

    int sz;
    cout << "Enter num elements:" << endl;
    cin >> sz;
   

    bool resheto[sz+1];
    memset(resheto, true, sizeof(resheto));


    for (int p = 2; p*p <= sz; p++){
        if (resheto[p] == true){
            for (int i=p*p; i <= sz; i += p) 
                resheto[i] = false;
        }
    }


    for (int i=2; i <= sz; i++){ 
       if (resheto[i]){ 
          cout << i << " ";} 
    }

    return 0;
}
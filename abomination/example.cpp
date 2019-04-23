#include <iostream>
#include <vector>

using namespace std;

 void printvec(vector<string> die){
     for (auto e:die)
    cout << e << " ";
}

void fill (vector<string> &die){
    string regret;
    while (cin >> regret)
    die.push_back(regret);
}

int main(){
    vector<string> die;
    cout << "Enter your regrets" << endl;
    fill(die); 
    printvec(die);
    return 0;
}
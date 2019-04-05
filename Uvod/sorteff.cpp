#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

void print(vector<int> s){
    for (auto i:s){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void calc(vector<int> &nums, vector<int> &comp){
    //vector<int>::iterator max;
    vector<int>::iterator min;
    min = std::min_element(nums.begin(), nums.end());
    for (auto i:nums){
        i = *min;
        min = *i;
    }

}

int main(){

    vector<int> nums;
    vector<int> comp;
    int sz;
    std::cout << "Enter sz: ";
    std::cin >> sz;
    std::cout << "Enter num: ";
    for (int i = 0; i < sz; i++){
        int k;
        std::cin >> k;
        nums.push_back(k);
    }
    //print(nums);
    calc(nums, comp);
    print(nums);
    print(comp);

    return 0;
}
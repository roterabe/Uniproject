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
    vector<int>::iterator max;
    vector<int>::iterator min;
    max = std::max_element(nums.begin(), nums.end());
    min = std::min_element(nums.begin(), nums.end());
    //int tmp;
    comp.push_back(*min);
    for (int i = 0; i < nums.size(); i++){
        for (int j = 0; j < nums.size(); j++){
            if (nums[j] == *min){
                nums[j] = *max;
            }
        }
        min = std::min_element(nums.begin(), nums.end());
        //tmp = nums[i];
        comp.push_back(*min);
        
    }
    comp.pop_back();

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
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

void print(std::vector<int> a){
    for (auto i:a){
        std::cout << i;
    }
}

int main(){
    std::vector<int> a;
    std::vector<int> b;
    int sz1, sz2;
    std::cout << "Enter num1 size: ";
    std::cin >> sz1;
    std::cout << "Enter num2 size: ";
    std::cin >> sz2;
    for (int i = 0; i < sz1; i++){
        int k;
        std::cin >> k;
        a.push_back(k);
    }
        for (int i = 0; i < sz2; i++){
        int k;
        std::cin >> k;
        b.push_back(k);
    }
    print(a);
    std::cout << std::endl;
    print(b);
    std::cout << std::endl;
    if (sz2 - sz1 == 1){
        for(int i = 0; i < sz2 - sz1; i++){
        a.insert(a.begin(), 0);
        }
    }
    print(a);
        if (sz1 - sz2 == 1){
        for(int i = 0; i < sz1 - sz2; i++){
        b.insert(b.begin(), 0);
        }
    }
    std::cout << std::endl;
    print(b);

    return 0;
}
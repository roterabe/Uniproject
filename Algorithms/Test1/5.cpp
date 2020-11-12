#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = {1,2,3,4,5,6,7,8,9,10};
    for(auto num:numbers){
        num = num * num;
    }

    for(auto i=0;i<numbers.size(); i++){
        std::cout<<numbers[i]<<std::endl;
    }
    return 0;
}
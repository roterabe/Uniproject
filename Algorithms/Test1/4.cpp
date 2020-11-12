#include <iostream>

void Increment(int * val){
    val++;
}

void Increment(int & val){
    val++;
}

int main()
{
    int a = 5;
    Increment(a);
    std::cout<<a<<std::endl;
    Increment(&a);
    std::cout<<a<<std::endl;
    return 0;
}
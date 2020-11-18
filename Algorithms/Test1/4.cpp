#include <iostream>

void Increment(int * val){
    val++;
}

void Increment(int & val){
    val++;
}

int main()
{
    int a = 1;
    int *b = &a;
    Increment(a);
    std::cout<<a<<std::endl;
    Increment(b);
    std::cout<<a<<std::endl;
    Increment(*b);
    std::cout<<a<<std::endl;

    return 0;
}
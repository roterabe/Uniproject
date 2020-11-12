#include <iostream>

bool Foo()
{
    std::cout << "Foo()" << std::endl;
    return true;
}

bool Bar()
{
    std::cout << "Bar()" << std::endl;
    return false;
}

int main()
{
    if (Bar() || Foo())
        std::cout << "It's true" << std::endl;
    return 0;
}
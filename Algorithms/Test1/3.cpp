#include <iostream>

class A
{
public:
    A() : a(0)
    {
        std::cout << "A()" << std::endl;
    }
    ~A()
    {
        std::cout << "~A()" << std::endl;
    }

private:
    int a;
};

class B
{
public:
    B() : b(0)
    {
        std::cout << "B()" << std::endl;
    }
    ~B()
    {
        std::cout << "~B()" << std::endl;
    }

private:
    int b;
};

class C : public B, public A
{
public:
    C() : c(0)
    {
        std::cout << "C()" << std::endl;
    }
    ~C()
    {
        std::cout << "~C()" << std::endl;
    }

private:
    int c;
};

int main()
{
    {
        std::cout << "Enter outer scope" << std::endl;
        C objC;
        {
            std::cout << "Enter inner scope" << std::endl;
            B objB;
            std::cout << "Leave inner scope" << std::endl;
        }
        std::cout << "Leave outer scope" << std::endl;
    }
    return 0;
}
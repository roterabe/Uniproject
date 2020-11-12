#include <iostream>
#include <vector>
using namespace std;

class A{
public:
    A(){
        cout<<"A()"<<endl;
    }
    A(const A& a){
        cout<<"A(const A&)"<<endl;
    }
    A& operator=(const A& a){
        cout<<"A& operator=(const A& a)"<<endl;
        return *this;
    }
    A(A&& a) noexcept{
        cout<<"A(A&& a)"<<endl;
    }
    A& operator=(A&& a) noexcept{
        cout<<"A& operator=(A&& a)"<<endl;
        return *this;
    }

};

int main()
{
    A a1;
    A a2(a1);
    A a3(move(A()));
    a3 = a2;
    a3 = A();
    
    return 0;
}
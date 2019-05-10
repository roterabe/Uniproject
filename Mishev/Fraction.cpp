#include <iostream>
#include <vector>

using namespace std;

class Money{
public:
Money(int lev, int st) : lev(lev), st(st)
{

}
friend Money operator + (const Money& lev, const Money& st);
friend ostream& operator << (ostream&, const Money&);
private:
int lev, st;
};

class Fraction
{
public:
Fraction(int a, int b) : n(a), d(b)
{

}
friend Fraction operator+(const Fraction&, const Fraction&);
friend ostream& operator<<(ostream&, const Fraction&);
friend istream& operator >> (const istream&, Fraction& );
private:
int n, d;
};

/*Fraction operator+=(const Fraction& right){

}*/
Money operator + (const Money& left, const Money& right)
 {
     return Money(left.lev + right.lev + (left.st + right.st)/100, (left.st + right.st)%100);
 }

Fraction operator + (const Fraction& left, const Fraction& right){
    return Fraction(left.n*right.d + right.n*left.d, left.d*right.d);
}

ostream& operator << (ostream& ostr, const Money& k)
{
    ostr << k.lev << ".лв" << " и " << k.st << ".ст" << " ";
    return ostr;
}

ostream& operator << (ostream& ostr, const Fraction& f)
{
    ostr << f.n << "." << f.d << " ";
    return ostr;
}

istream& operator >> (istream& istr, Fraction& f){
    int a, b;
    char c;
    istr >> a >> c >> b;
    f = Fraction(a,b);
    return istr;
}

int main(){

    Fraction a(1,2), b(3,2);
    Fraction c = a + b;
    std::cout << c << b << std::endl;
   // std::cin >> a >> b;
    //std::cout << a << b << std::endl;
    Money kinti(20,50);
    Money kesh = kinti + kinti;
    std::cout << kesh << std::endl;
    


    return 0;
}
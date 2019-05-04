#include <iostream>
#include <vector>
using namespace  std;

class Nucleon {
public:
    virtual int getCharge() {return charge;}
protected:
    int charge = 0;
};

class Proton : public Nucleon{
public:
    Proton() {charge = 1;}
};

class Neutron : public Nucleon {
public:
    Neutron() {charge = 0;}
};

int main (){
    vector <Nucleon*> Pb;

    for(int i=0; i<89; i++){
        Proton* p = new Proton();
        Pb.push_back(p);
    }

    for(int i=0; i<126; i++){
        Neutron* n = new Neutron();
        Pb.push_back(n);
    }

    for(int i=0; i<Pb.size(); i++){
        cout<<Pb[i] -> getCharge()<<" ";
    }

    return 0;
}
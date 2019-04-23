#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


class Person {
public:
    Person();
    std::string getName() {return name;}
    int getAge() {return age;}
    void setName(std::string personName) {name = personName;}
    void setAge(int personAge) {age = personAge;}
private:
    std::string name; 
    int age;
};
Person::Person()
{
    age = 0;
}

class Car{
public:
    std::string getModel() {return model;}
    void setModel(std::string carModel) {model = carModel;}
    void printCar();
private:
    std::string model;
    Person* owner;
    Person* driver;
};
void Car::printCar()
{
    std::cout << "Model:  " << model << std::endl;
    std::cout << "Owner:  " << owner << std::endl;
    std::cout << "Driver:  " << driver << std::endl; 
}


int main(){
    
    std::vector<Person*> someone;
    std::vector<Car*> vehicle;
    std::string name;
    std::string model;
    int age;
    int sz;

    Person *p1;
    std::cin >> sz;

    for (int i = 0; i < sz; i++){
        std::cin >> name;
        std::cin >> age;
    
    p1 = new Person;
    p1->setName(name);
    p1->setAge(age);
    someone.push_back(p1);
    }

    Car *c1;
    std::cin >> sz;




    return 0;
}
#include <iostream>

using namespace std;

class vehicle{
public:
    string color;
    void print(){
    cout<<"Vehicle"<<endl;
    }
};

class car:public vehicle{
public:

    void print(){
    cout<<"Car"<<endl;
    }
};

int main()
{
    vehicle *v1 = new vehicle;
    v1->print();

    vehicle *v2 = new car;     // this is compile time polymorphism i.e. to achieve runtime polymorphism we need to make function virtual
    v2->print();
    return 0;
}

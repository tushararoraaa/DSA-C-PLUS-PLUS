#include <iostream>

using namespace std;

class vehicle{
public:
    string color;
    virtual void print(){
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

    vehicle *v2 = new car;    //this is run time polymorphism as car is being printed now
    v2->print();
    return 0;
}

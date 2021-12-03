#include <iostream>

using namespace std;

class vehicle{
private:
    int maxSpeed;
protected:
    int numTyres;
public:
    string color;
    vehicle(){
    cout<<"Vehicle's default constructor called"<<endl;
    }
    vehicle(int i){
        cout<<"Vehicle's parameterised constructor called"<<endl;
        maxSpeed = i;
    }
    ~vehicle(){
    cout<<"Vehicle's destructor called"<<endl;
    }
    void print(){
    cout<<"Vehicle"<<endl;
    }

};

class car : virtual public vehicle{
public:
    int numGears;

//    void print(){
//        cout<<color<<endl;
//        cout<<numTyres<<endl;
////        cout<<maxSpeed<<endl;
//        cout<<numGears<<endl;
//    }
    void setTyres(int i){
        numTyres = i;
    }

    car(){
    cout<<"Car's default constructor called"<<endl;
    }

    ~car(){
    cout<<"Car's destructor called"<<endl;
    }

};

class truck: virtual public vehicle{
public:
    truck(){
    cout<<"Truck's default constructor called"<<endl;
    }
    ~truck(){
    cout<<"Truck's destructor called"<<endl;
    }
};

class bus:public car, public truck{
public:
    bus(){
    cout<<"Bus's default constructor"<<endl;
    }

    ~bus(){
        cout<<"Bus default destructor"<<endl;
    }
//    void print(){
//        cout<<"Bus Brother"<<endl;
//    }
};


int main()
{
    bus b;
//    b.print();
    return 0;
}

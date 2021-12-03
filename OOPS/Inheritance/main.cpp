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
    ~vehicle(){
    cout<<"Vehicle's destructor called"<<endl;
    }
    void print(){
    cout<<color<<endl;
    }

};

class car : public vehicle{
public:
    int numGears;

    void print(){
        cout<<color<<endl;
        cout<<numTyres<<endl;
//        cout<<maxSpeed<<endl;
        cout<<numGears<<endl;
    }
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

class truck:public car{
public:
    int average;
    truck(){
    cout<<"Truck's default constructor called"<<endl;
    }
    ~truck(){
    cout<<"Truck's destructor called"<<endl;
    }
};

int main()
{
    vehicle v1;
    v1.color = "Black";
    v1.print();

    car c1;
    c1.color = "red";
    c1.setTyres(4);
    c1.numGears = 6;
    c1.print();

    truck t1;
    t1.average = 6;
    t1.color = "blue";
    t1.setTyres(9);
    t1.print();
    return 0;
}

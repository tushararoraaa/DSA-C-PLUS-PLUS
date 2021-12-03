#include <iostream>

using namespace std;        /// using friend function we can access private members outside the class

class vehicle{
private:
    int numTyres;
public:
    vehicle(){
    cout<<"Vehicle"<<endl;
    }
    void print(){
    cout<<numTyres<<endl;
    }
    friend void setTyres(vehicle &v, int x);
    friend class truck;
};

class truck{
private:
    int t;

public:

    void print(vehicle v){
   cout<<"Tyres of truck = "<<v.numTyres<<endl;

    }
};
void setTyres(vehicle &v, int x){
    v.numTyres = x;
}

int main()
{
    vehicle v1;
    setTyres(v1,18);
    v1.print();

    truck t1;
    t1.print(v1);
    return 0;
}

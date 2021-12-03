#include <iostream>

using namespace std;

class Complex{
private:
    int real;
    int imaginary;
public:
    Complex(int real , int imaginary){
        this->real = real;
        this->imaginary = imaginary;
    }

    void display(){
        cout<<this->real<<" + "<<this->imaginary<<"i"<<endl;
    }

    void add(Complex const &c){
        real = real+c.real;
        imaginary = imaginary+c.imaginary;
    }
};

int main()
{
    Complex c1(3,5);
    Complex c2(6,4);
    c1.add(c2);
    c1.display();
    return 0;
}

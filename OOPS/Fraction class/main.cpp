#include <iostream>

using namespace std;

class fraction{
private:
    int numerator;
    int denominator;
public:
    fraction(int numerator, int denominator){
        this-> numerator = numerator;
        this -> denominator = denominator;
    }

    void display(){
        cout<<numerator<<"/"<<denominator<<endl;
    }

    void simplify(){
        int gcd = 1;
        int j = min(this->numerator, this->denominator);
        for(int i = 1; i<=j; i++){
            if(this->numerator%i == 0 && this->denominator%i == 0){
                gcd = i;
            }
        }
        this->numerator = this->numerator/gcd;
        this->denominator = this->denominator/gcd;
    }

    void add(fraction const & f){

        int lcm = denominator * f.denominator;
        int x = (lcm/denominator)*numerator + (lcm/(f.denominator))*f.numerator;

        numerator = x;
        denominator = lcm;

        simplify();
    }

    void multiply(fraction const &f){
        numerator = numerator*(f.numerator);
        denominator = denominator*(f.denominator);
        simplify();
    }

};

int main()
{

    fraction f1(10,2);
    fraction f2(6,3);
    f1.add(f2);
    cout<<"After Addition"<<endl;
    f1.display();
    fraction f3(11,4);
    f2.multiply(f3);
    cout<<"After Multiplication"<<endl;
    f2.display();
    return 0;
}

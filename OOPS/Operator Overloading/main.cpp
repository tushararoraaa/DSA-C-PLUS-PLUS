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

    fraction add(fraction const & f){    //traditional method

        int lcm = denominator * f.denominator;
        int x = (lcm/denominator)*numerator + (lcm/(f.denominator))*f.numerator;
        fraction fNew(x,lcm);
//        numerator = x;
//        denominator = lcm;

        fNew.simplify();
        return fNew;
    }

    fraction operator+(fraction const & f){    //operator overloading

        int lcm = denominator * f.denominator;
        int x = (lcm/denominator)*numerator + (lcm/(f.denominator))*f.numerator;
        fraction fNew(x,lcm);
//        numerator = x;
//        denominator = lcm;

        fNew.simplify();
        return fNew;
    }

    fraction multiply(fraction const &f){

        fraction fNew(numerator*(f.numerator),denominator*(f.denominator));
//        numerator = numerator*(f.numerator);
//        denominator = denominator*(f.denominator);
        fNew.simplify();
        return fNew;
    }

    fraction operator*(fraction const &f){   //operator overloading
        fraction fNew(numerator*(f.numerator),denominator*(f.denominator));
//        numerator = numerator*(f.numerator);
//        denominator = denominator*(f.denominator);
        fNew.simplify();
        return fNew;
    }

    bool operator==(fraction f){
        if(numerator==f.numerator && denominator==f.denominator){
            return true;
        }else{
        return false;
        }
    }

    fraction& operator++(){                       //PRE INCREMENT
        numerator = numerator+denominator;
        simplify();
        return *this;
    }

    fraction& operator++(int){                    //POST INCREMENT
        fraction fNew(numerator,denominator);
        numerator = numerator+denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }

    fraction& operator+=(fraction f){              //+= OPERATOR
        int lcm = denominator * f.denominator;
        int x = (lcm/denominator)*numerator + (lcm/(f.denominator))*f.numerator;
        numerator = x;
        denominator = lcm;
        simplify();
        return *this;
    }

};

int main()
{

    fraction f1(10,2);
    fraction f2(6,3);
    fraction f3 = f1.add(f2);
    cout<<"f1:-"<<endl;
    f1.display();
    cout<<"f2:-"<<endl;
    f2.display();
    cout<<"f3:-"<<endl;
    f3.display();

    fraction f4 = f1+f2;   // operator overloading
    cout<<"f4:-"<<endl;
    f4.display();

    fraction f5(11,4);
    cout<<"f5:-"<<endl;
    f5.display();
    fraction f6 = f2.multiply(f5);
    cout<<"f6:-"<<endl;

    f6.display();

    fraction f7(10,4);
    cout<<"f7:-"<<endl;
    f7.display();
    fraction f8(18,6);
    cout<<"f8:-"<<endl;
    f8.display();
    fraction f9 = f7*f8;
    cout<<"f9:-"<<endl;
    f9.display();

    fraction f10(11,2);
    fraction f11(11,2);
    if(f10==f11){
        cout<<"Equal"<<endl;
    }else{
        cout<<"Not Equal"<<endl;
    }

    fraction f12(5,3);
    fraction f13(6,2);
    f12 +=f13;
    f12.display();
    f13.display();
    f13++;
    f13.display();
    ++f13;
    f13.display();
    fraction f14 = ++f13;
    cout<<"F14"<<endl;
    f14.display();

    return 0;
}

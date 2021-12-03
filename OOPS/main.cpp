#include <iostream>

using namespace std;

class Student{

    private:
        int age;

    public:
        int roll;

        void display(){
            cout<<age<<endl;
            cout<<roll<<endl;
        }
        void setAge(int a){
            age = a;
        }
        int getAge(){
            return age;
        }
        Student(){ //default constructor
        cout<<"This value = "<<this<<endl;  // this holds address of the object
        cout<<"Constructor called"<<endl;
        }

        Student(int x, int y){  // Parameterised Constructor
            cout<<"This value = "<<this<<endl;  //this holds the address of the object
            age = x;
            roll = y;
            cout<<"Parameterised Constructor called"<<endl;
        }
};

int main()
{
    Student s1;
    cout<<"Address of s1 = "<<&s1<<endl;
    s1.display();

    Student * s2 = new Student;
    cout<<"Address of s2 = "<<s2<<endl;
    s2 ->setAge(21);
    s2->roll = 218;

   s2->display();

   Student s3(24,116);
   cout<<"Address of s3 = "<<&s3<<endl;
   s3.display();

   Student s4(s3);  //copy constructor
   s4.display();

   Student s5(116,117);
   Student s6(1160,1170);
   s6=s5;  // copy assignment operator
   s6.display();

    return 0;
}

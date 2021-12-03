#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Queue{
    stack<int> s1;
public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int x = s1.top();
        s1.pop();
        if(s1.empty()){
            return x;
        }
        int item = pop();
        s1.push(x);
        return item;
        }

    bool isEmpty(){
        if(s1.empty()){
            return true;
        }else{
        return false;
        }
    }
};

int main()
{
    Queue q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();


    return 0;
}

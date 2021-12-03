#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty() && s2.empty()){
            return -1;
        }else if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int top = s2.top();
            s2.pop();
            return top;
        }
    }

    bool isEmpty(){
        if(s1.empty() && s2.empty()){
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


    return 0;
}

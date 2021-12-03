#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Stack{
    queue<int> q1;
    queue <int> q2;
    int size;
public:
    Stack(){
        size = 0;
    }
    void push(int element){
        q2.push(element);
        while(!q1.empty()){
            int x = q1.front();
            q2.push(x);
            q1.pop();
        }
        swap(q1,q2);
        size++;
    }
    void pop(){
        q1.pop();
        size--;

    }
    int top(){
        return q1.front();
    }
    void size_of(){
        cout<<size<<endl;
    }
};

int main()
{
    Stack s1;
    s1.push(11);
    s1.push(13);
    s1.push(15);
    s1.push(17);
    s1.push(19);
    cout<<s1.top()<<endl;
    s1.size_of();
    s1.pop();
    s1.size_of();
    cout<<s1.top()<<endl;

    return 0;
}

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Stack{
private:
    int *data;
    int nextIndex;
    int capacity;
public:
    Stack(int totalSize){
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    int size_of(){
        return nextIndex;
    }

    bool isEmpty(){
        if(nextIndex==0){
            return true;
        }else{
            return false;
        }
    }

    void push(int element){
        if(capacity>nextIndex){
            data[nextIndex] = element;
            nextIndex++;
        }else{
            cout<<"OOPS! Stack is full"<<endl;
        }
    }

    int pop(){
        if(isEmpty()){
            cout<<"OOPS! Stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top(){
        if(isEmpty()){
            cout<<"OOPS! Stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }

    void print(){
        while(!isEmpty()){
            cout<<this->top()<<endl;
            this->pop();
        }
    }
};

int main()
{
    Stack s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    int result = s1.top();
    cout<<result<<endl;
    int size = s1.size_of();
    cout<<size<<endl;
    cout<<s1.isEmpty()<<endl;
    return 0;
}

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Stack{
private:
    int *data;
    int nextIndex;
    int capacity;
public:
    Stack(){
        data = new int[capacity];
        nextIndex = 0;
        capacity = 5;   //we can take any
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
        if(capacity==nextIndex){
            int *newData = new int[2*capacity];
            for(int i = 0; i<capacity; i++){
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
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
    Stack s1;
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

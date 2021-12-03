#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Queue{
private:
    int *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
public:

    Queue(){
        data = new int[capacity];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = 5;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void enqueue(int element){
        if(size==capacity){
            int *newData = new int[2*capacity];
            int j = 0;
            for(int i = firstIndex; i<capacity; i++){
                newData[j] = data[i];
                j++;
            }
            for(int i = 0; i<firstIndex; i++){
                newData[j] = data[i];
                j++;
            }
            delete []data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex+1)%capacity;
        size++;
        if(firstIndex==-1){
            firstIndex = 0;
        }
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue Empty"<<endl;
            return 0;
        }
        int ans = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        size--;
        if(size==0){
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

    int front_ele(){
        if(isEmpty()){
            cout<<"Queue Empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
};

int main()
{
    Queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);
    cout<<q1.front_ele()<<endl;
    q1.dequeue();
    q1.dequeue();
    cout<<q1.front_ele()<<endl;
    return 0;
}

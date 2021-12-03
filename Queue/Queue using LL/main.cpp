#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next =NULL;
    }
};

class Queue{
private:
    Node *head, *tail;
    int size;
public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int size_of(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }

    int front_element(){
        if(isEmpty()){
            return -1;
        }
        return head->data;
    }

    void enqueue(int element){
        Node *n = new Node(element);
        if(head==NULL){
            head = n;
            tail = n;
        }else{
            tail->next = n;
            tail = n;
        }
        size++;
    }
    int dequeue(){
        if(isEmpty()){
            return -1;
        }
        int ans = head->data;
        Node *temp = head;
        head = head->next;
        delete(temp);
        size--;
        return ans;
    }
};

int main()
{
    Queue q1;
    q1.enqueue(10);
    q1.enqueue(11);
    q1.enqueue(12);
    q1.enqueue(13);
    q1.enqueue(14);
    q1.enqueue(15);
    q1.enqueue(16);
    q1.enqueue(17);
    q1.enqueue(18);
    q1.enqueue(19);
    q1.enqueue(20);
    cout<<q1.front_element()<<endl;
    cout<<q1.size_of()<<endl;

    for(int i = 0; i<11; i++){
        q1.dequeue();
    }

    cout<<q1.front_element()<<endl;
    cout<<q1.size_of()<<endl;

    return 0;
}

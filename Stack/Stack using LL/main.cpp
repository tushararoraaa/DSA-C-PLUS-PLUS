#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Stack{
private:
    Node *head;
    int size ;
public:
    Stack(){
        head==NULL;
        size = 0;
    }

    void push(int element){
        Node *n = new Node(element);
        if(head==NULL){
            head = n;
        }else{
            n->next = head;
            head = n;
            size++;
        }


    }

    int pop(){
        int answer = head->data;
        Node *temp = head;
        head = head->next;
        delete(temp);
        size--;
        return answer;
    }

    int size_of_stack(){
        return size;
    }

    int top(){
        return head->data;
    }
    bool isEmpty(){
    if(size ==0){
        return true;
    }else{
        return false;
        }
    }
};

int main()
{
    Stack s1;
    s1.push(10);
    s1.push(11);
    s1.push(12);
    int t = s1.top();
    cout<<"Top = "<<t<<endl;
    int e = s1.pop();
    int t2 = s1.top();
    cout<<"Top = "<<t2<<endl;
    cout<<"Element popped = "<<e<<endl;
    return 0;
}

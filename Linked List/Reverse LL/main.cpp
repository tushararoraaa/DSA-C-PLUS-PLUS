#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
    this->data=data;
    next=NULL;
    }
};

void print(Node *head){
    Node *temp = head;
    while(temp){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

Node* reverseLL(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *smallAns = reverseLL(head->next);

    Node *temp = smallAns;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallAns;
}

Node *takeInput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data!=-1){
        Node *n = new Node(data);
        if(head==NULL){
            head=n;
            tail=n;
        }else{
            tail->next = n;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    cout<<"After reversing"<<endl;
    Node *data = reverseLL(head);
    print(data);
    return 0;
}

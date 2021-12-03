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
   Node *current = head;
   Node *previous = NULL;
   Node *nextt = NULL;

   while(current!=NULL){
    nextt = current->next;
    current->next = previous;
    previous = current;
    current = nextt;

   }
   return previous;
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

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

void print(Node *head){
    Node *temp = head;
    while(temp){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

Node * Insert(Node *head, int i, int data){
    Node *n = new Node(data);
    int count = 0;
    Node *temp = head;

    if(i==0){
        n->next = head;
        head = n;
        return head;

    }
    while(count<i-1 && temp!=NULL){
        temp = temp->next;
        count++;
    }
    if(temp!=NULL){
        n->next = temp->next;
    temp->next = n;
    }
    return head;


}

Node* takeInput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data!= -1){
     Node *n = new Node(data);
     if(head==NULL && tail==NULL){
        head = n;
        tail = n;
     }else{
         tail->next = n;
         tail = tail->next;
     }
     cin>>data;
    }
    return head;
}

using namespace std;

int main()
{
    Node *LL = takeInput();
    print(LL);
    int i , data;
    cout<<"Enter Position"<<endl;
    cin>>i;
    cout<<"Enter Value"<<endl;
    cin>>data;
    Node *update = Insert(LL,i,data);
    cout<<"After Inserting"<<endl;
    print(update);

    return 0;
}

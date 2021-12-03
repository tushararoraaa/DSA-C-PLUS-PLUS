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

Node *deletee(Node *head, int i){
    Node *temp = head;
    int count = 0;
    if(i==0){
        head = head->next;
        return head;
    }
    while(count<i-1 &&temp!=NULL){
        temp = temp->next;
        count++;
    }
    if(temp!=NULL){
        Node *a = temp->next;
    Node *b = a->next;
    temp->next = b;
    delete(a);
    }


    return head;

}

void length(Node *head){
    int len = 0;
    Node *temp = head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    cout<<"Length of LL is"<<len<<endl;
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
    Node *head = takeInput();
    print(head);
    length(head);
    int i , data;
    cout<<"Enter Position"<<endl;
    cin>>i;
    cout<<"Enter Value"<<endl;
    cin>>data;
    head = Insert(head,i,data);
    cout<<"After Inserting"<<endl;
    print(head);
    length(head);
    int position;
    cout<<"Enter Position to delete"<<endl;
    cin>>position;
    cout<<"After Deletion"<<endl;
    head = deletee(head,position);
    print(head);
    length(head);

    return 0;
}

#include <iostream>
#include <bits/stdc++.h>

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

Node* takeInput(){
    int data;
    cin>>data;
    Node *head = NULL;
    while(data!= -1){
     Node *n = new Node(data);
     if(head==NULL){
        head = n;
     }else{
         Node *temp = head;
         while(temp->next!=NULL){
            temp = temp->next;
         }
         temp->next = n;
     }
     cin>>data;
    }
    return head;
}

void print(Node *head){
    Node *temp = head;
    while(temp){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

using namespace std;

int main()
{
    Node *ll = takeInput();
    print(ll);
    return 0;
}

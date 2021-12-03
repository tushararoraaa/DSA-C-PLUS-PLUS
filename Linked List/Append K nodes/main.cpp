#include <iostream>

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

Node *takeInput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data!=-1){
            Node *n = new Node(data);
        if(head==NULL){
            head=n;
            tail = n;
        }else{
            tail->next = n;
            tail = n;
        }
        cin>>data;
    }
    return head;
}

int length(Node *head){
    int count = 0;
    Node *temp = head;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}

Node *K_append(Node *head, int K){
    Node *newHead = NULL;
    Node *newTail = NULL;
    Node *tail = head;
    int count = 1;
    int l = length(head);
    K = K%l;

    while(tail->next!=NULL){
        if(count==(l-K)){
            newTail = tail;
        }
        if(count==(l-K+1)){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next=NULL;
    tail->next = head;

    return newHead;
}

int main()
{
    Node *head = takeInput();
    print(head);
    head = K_append(head,4);
    print(head);
    return 0;
}

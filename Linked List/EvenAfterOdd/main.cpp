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

Node * EvenAfterOdd(Node* &head){
    Node *odd = head;
    Node *even = head->next;
    Node *evenStart = even;

    while(odd->next!=NULL && even->next!=NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;
    if(odd->next==NULL){
        even->next = NULL;
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    head = EvenAfterOdd(head);
    print(head);
    return 0;
}

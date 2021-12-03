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

int intersection(Node *h1, Node *h2){
    int l1 = length(h1);
    int l2 = length(h2);
    int d = 0;
    Node *ptr1;
    Node *ptr2;
    if(l1>l2){
        d = l1-l2;
        ptr1 = h1;
        ptr2= h2;
    }else{
        d = l2-l1;
        ptr1 = h2;
        ptr2 = h1;
    }

    while(d){
        ptr1 = ptr1->next;
        if(ptr1 == NULL){
            return -1;
        }
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;

}

int main()
{
    Node *h1 = takeInput();
    Node *h2 = takeInput();
    int i = intersection(h1,h2);
    cout<<"Intersection Point = "<<i<<endl;
    return 0;
}

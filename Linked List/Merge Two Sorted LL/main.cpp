#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node(int data){
    this->data = data;
    next = NULL;
    }
};

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

void print(Node *head){
    Node *temp = head;
    while(temp){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

Node *mergeLL(Node *h1, Node *h2){
    Node *current = NULL;

    if(h1==NULL){
        return h2;
    }else if(h2==NULL){
        return h1;
    }

    if(h1->data<h2->data){
        current = h1;
        current->next = mergeLL(h1->next,h2);
    }else{
        current = h2;
        current->next = mergeLL(h1,h2->next);
    }
    return current;

}

int main()
{
    cout<<"Enter elements for L1 in sorted order:-"<<endl;
    Node *h1 = takeInput();
    print(h1);

    cout<<"Enter elements for L2 in sorted order:-"<<endl;
    Node *h2 = takeInput();
    print(h2);

    Node *head = mergeLL(h1,h2);
    cout<<"After merging"<<endl;
    print(head);

    return 0;
}

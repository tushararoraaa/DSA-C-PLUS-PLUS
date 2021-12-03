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

bool detectCycle(Node *head){
    Node *slow = head;
    Node *fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow){
                cout<<"Loop detected"<<endl;
            return true;
        }
    }
    cout<<"Loop not detected"<<endl;
    return false;
}

void makeCycle(Node *head, int pos){
    Node *temp = head;
    Node *startNode;
    int count = 1;

    while(temp->next!=NULL){
        if(count==pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

void removeCycle(Node *head){
    Node *slow = head;
    Node *fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow!=fast);

    fast = head;
    while(fast->next!=slow->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
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

int main()
{
    Node *head = takeInput();
    print(head);
    makeCycle(head,4);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    return 0;
}

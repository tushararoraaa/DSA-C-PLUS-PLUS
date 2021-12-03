#include <iostream>
#include<bits/stdc++.h>

class Node
{
public:
    int data;
    Node * next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

using namespace std;


void print(Node *head)
{
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }

}

int main()
{
    //Statically

    Node n1(23);
    Node n2(25);
    Node n3(27);
    n1.next = &n2;
    n2.next = &n3;

    Node *head = &n1;
    cout<<"Static LL:-"<<endl;
    print(head);

    //Dynamically

    Node *nd1 = new Node(24);
    Node *nd2 = new Node(28);
    cout<<"Dynamic LL:- "<<endl;
    Node *headd = nd1;
    nd1->next = nd2;
    print(headd);

    return 0;
}

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class BSTNode{
public:
    int data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int data){
        this->data = data;
        left =NULL;
        right = NULL;
    }

    ~BSTNode(){
        delete left;
        delete right;
    }
};

BSTNode* takeInput(){
    int rootData;
    cout<<"Enter Root Data"<<endl;
    cin>>rootData;

    BSTNode *root = new BSTNode(rootData);
    queue<BSTNode*> q1;
    q1.push(root);


    while(q1.size()!=0){

        BSTNode *front = q1.front();
        q1.pop();
        if(front->left == NULL){
            int firstChildData;
        cout<<"Enter data for first child of "<<front->data<<endl;
        cin>>firstChildData;

        if(firstChildData<front->data && firstChildData !=-1){
        BSTNode *leftChild = new BSTNode(firstChildData);
        front->left = leftChild;
        q1.push(leftChild);
    }else if(firstChildData>front->data && firstChildData !=-1){
        BSTNode *rightChild = new BSTNode(firstChildData);
        front->right = rightChild;
        q1.push(rightChild);
    }
        }

    if(front->right ==NULL){
        int secondChildData;
        cout<<"Enter data for second child of "<<front->data<<endl;
        cin>>secondChildData;

        if(secondChildData<front->data && secondChildData !=-1){
        BSTNode *leftChild = new BSTNode(secondChildData);
        front->left = leftChild;
        q1.push(leftChild);
    }else if(secondChildData>front->data && secondChildData !=-1){
        BSTNode *rightChild = new BSTNode(secondChildData);
        front->right = rightChild;
        q1.push(rightChild);
    }
    }

    }
    return root;

}

void print(BSTNode *root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

bool searchNode(BSTNode *root , int x){
    if(root ==NULL){
        return NULL;
    }
    if(x==root->data){
        return true;
    }else if(x>root->data){
        searchNode(root->right, x);
    }else{
        searchNode(root->left, x);
    }
}

int main()
{
    BSTNode *root = takeInput();
    print(root);
    cout<<endl;
    if(searchNode(root,12)){
        cout<<"Element Found"<<endl;
    }else{
        cout<<"OOPS! Not Found"<<endl;
    }
    return 0;
}

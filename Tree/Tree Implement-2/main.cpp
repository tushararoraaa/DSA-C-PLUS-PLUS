#include <iostream>
#include<bits/stdc++.h>

using namespace std;

template <typename T>
class TreeNode{
public:
    T data;
    vector <TreeNode<T>*> children;

    TreeNode(T data){
        this->data = data;

    }
};

TreeNode<int> *takeInput(){
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout<<"Enter number of children of "<<rootData<<endl;
    cin>>n;
    for(int i = 0; i<n; i++){
       TreeNode<int> *child =  takeInput();
       root->children.push_back(child);
    }
    return root;
}

void print(TreeNode<int> *root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<":";

    for(int i = 0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;

    for(int i = 0; i<root->children.size(); i++){
        print(root->children[i]);
    }
}

int main()
{
    TreeNode<int> *root = takeInput();
    print(root);
    return 0;
}

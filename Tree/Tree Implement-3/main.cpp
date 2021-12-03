#include <iostream>
#include<bits/stdc++.h>


//IN THIS WE WILL TAKE INPUT LEVEL WISE

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

TreeNode<int> *takeInput_levelwise(){
    int rootData;
    cout<<"Enter Root Data"<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue <TreeNode<int>*> q1;
    q1.push(root);
    while(q1.size()!= 0){
        TreeNode<int> *front = q1.front();
        q1.pop();
        int n;
        cout<<"Enter number of children of "<<front->data<<endl;
        cin>>n;
        for(int i = 0; i<n; i++){
            int ChildData;
            cout<<"Enter "<<i<<" th child of "<<front->data<<endl;
            cin>>ChildData;
            TreeNode<int> *child = new TreeNode<int>(ChildData);
            front->children.push_back(child);
            q1.push(child);
        }
    }

    return root;
}



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

    queue<TreeNode<int>*> q2;
    q2.push(root);
    while(q2.size()!=0){
        TreeNode<int> *front = q2.front();
        cout<<front->data<<":";
        q2.pop();
        for(int i = 0; i<front->children.size(); i++){
            cout<<front->children[i]->data;
            q2.push(front->children[i]);
        }
        cout<<endl;

    }








//    cout<<root->data<<":";
//
//    for(int i = 0; i<root->children.size(); i++){
//        cout<<root->children[i]->data<<" ";
//    }
//    cout<<endl;
//
//    for(int i = 0; i<root->children.size(); i++){
//        print(root->children[i]);
//    }
}

int main()
{
    TreeNode<int> *root = takeInput_levelwise();
    print(root);
    return 0;
}

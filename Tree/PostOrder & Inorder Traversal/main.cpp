#include <iostream>
#include<bits/stdc++.h>


//IN THIS WE WILL TAKE INPUT LEVEL WISE

using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector <TreeNode<T>*> children;

    TreeNode(T data)
    {
        this->data = data;

    }
};

TreeNode<int> *takeInput_levelwise()
{
    int rootData;
    cout<<"Enter Root Data"<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue <TreeNode<int>*> q1;
    q1.push(root);
    while(q1.size()!= 0)
    {
        TreeNode<int> *front = q1.front();
        q1.pop();
        int n;
        cout<<"Enter number of children of "<<front->data<<endl;
        cin>>n;
        for(int i = 0; i<n; i++)
        {
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



TreeNode<int> *takeInput()
{
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout<<"Enter number of children of "<<rootData<<endl;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        TreeNode<int> *child =  takeInput();
        root->children.push_back(child);
    }
    return root;
}

void PreOrder(TreeNode<int> *root)
{
    cout<<root->data<<" ->";

    for(int i = 0; i<root->children.size(); i++){
        PreOrder(root->children[i]);
    }
}


void InOrder(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return ;
    }

    queue<TreeNode<int>*> q2;
    q2.push(root);
    while(q2.size()!=0)
    {
        TreeNode<int> *front = q2.front();
        cout<<front->data<<" ";
        q2.pop();
        for(int i = 0; i<front->children.size(); i++)
        {
            q2.push(front->children[i]);
        }
        cout<<endl;

    }
}

void PostOrder(TreeNode<int> *root)
{


    for(int i = 0; i<root->children.size(); i++){
        PostOrder(root->children[i]);
    }
    cout<<root->data<<" ->";
}

int numNodes(TreeNode<int> *root)
{
    int ans = 1;
    for(int i = 0; i<root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;

}

int Height(TreeNode<int> *root)
{
    int height = 1;
    for(int i = 0; i<root->children.size(); i++)
    {
        height = max(1+Height(root->children[i]),height);
    }
    return height;

}

void PrintAtLevelK(TreeNode<int> *root, int K)
{
    if(root==NULL){
        return ;
    }

    if(K==0)
    {
        cout<<root->data<<endl;
        return ;
    }

    for(int i = 0; i<root->children.size(); i++)
    {

        PrintAtLevelK(root->children[i],K-1);
    }

}

int leaf_nodes(TreeNode<int> *root){
    int ans = 0;
    if(root == NULL){
        return 0;
    }
    if(root->children.size()==0){
        return 1;
    }
    for(int i = 0; i<root->children.size(); i++){
        ans += leaf_nodes(root->children[i]);
    }
    return ans;

}

int main()
{
    TreeNode<int> *root = takeInput_levelwise();
    cout<<"PreOrder Traversal = ";
    PreOrder(root);
    cout<<endl;
    cout<<"InOrder Traversal = ";
    InOrder(root);
    cout<<endl;
    cout<<"PostOrder Traversal = ";
    PostOrder(root);
    cout<<endl;

    cout<<"Number of nodes = "<<numNodes(root)<<endl;
    cout<<"Height of tree = "<<Height(root)<<endl;
    int level;
    cout<<"Enter the level of which you want nodes"<<endl;
    cin>>level;
    PrintAtLevelK(root,level);
    cout<<"No. of leaf nodes = "<<leaf_nodes(root)<<endl;
    return 0;
}

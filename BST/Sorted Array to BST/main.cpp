#include <iostream>
#include<bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

void LevelOrder(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return ;
    }
    cout<<root->data<<":";
    if(root->left!= NULL)
    {
        cout<<"L:"<<root->left->data<<" ";
    }

    if(root->right!= NULL)
    {
        cout<<"R:"<<root->right->data<<" ";
    }
    cout<<endl;
    LevelOrder(root->left);
    LevelOrder(root->right);
}

BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    if(rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();   // WILL RETURN ROOT OF LEFT SUBTREE
    BinaryTreeNode<int> *rightChild = takeInput();  //WILL RETURN ROOT OF RIGHT SUBTREE
    root->left = leftChild;                         //CONNECTING ROOT WITH LEFT SUBTREE
    root->right = rightChild;                       //CONNECTING ROOT WITH RIGHT SUBTREE
    return root;

}

BinaryTreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter Root Data"<<endl;
    cin>>rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q1;
    q1.push(root);
    while(q1.size()!= 0)
    {
        BinaryTreeNode<int> *front = q1.front();
        q1.pop();

        int leftChildData;
        cout<<"Enter Data for left child of "<<front->data<<endl;
        cin>>leftChildData;

        if(leftChildData!= -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            q1.push(leftChild);
        }

        int rightChildData;
        cout<<"Enter Data for right child of "<<front->data<<endl;
        cin>>rightChildData;

        if(rightChildData!= -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            q1.push(rightChild);
        }
    }
    return root;
}

int numNodes(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+numNodes(root->left)+numNodes(root->right);
}

int height(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ans = max(1+height(root->left),1+height(root->right));
    return ans;
}

int diameter(BinaryTreeNode <int> *root)
{
    if(root == NULL)
    {
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

void InOrder(BinaryTreeNode<int> *root)    //LEFT->ROOT->RIGHT
{
    if(root == NULL)
    {
        return ;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

void PreOrder(BinaryTreeNode<int> *root)    //ROOT->LEFT->RIGHT
{
    if(root == NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    InOrder(root->left);
    InOrder(root->right);
}

void PostOrder(BinaryTreeNode<int> *root)    //LEFT->RIGHT->ROOT
{
    if(root == NULL)
    {
        return ;
    }
    InOrder(root->left);
    InOrder(root->right);
    cout<<root->data<<" ";

}

BinaryTreeNode<int>* arrToBST(int *arr, int indexS, int indexE)
{
    if(indexS>indexE)
    {
        return NULL;
    }
    int midIndex = (indexS + indexE)/2;
    BinaryTreeNode<int> *root2 = new BinaryTreeNode<int>(arr[midIndex]);
    root2->left = arrToBST(arr,indexS,midIndex-1);
    root2->right = arrToBST(arr,midIndex+1, indexE);


    return root2;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
//    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(0);
//    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(1);
//    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(2);
//    root->left = node1;
//    root->right = node2;

    BinaryTreeNode<int> *root = takeInputLevelWise();
    LevelOrder(root);
    cout<<"No. of nodes = ";
    cout<<numNodes(root)<<endl;
    cout<<"Height = ";
    cout<<height(root)<<endl;
    cout<<"Diameter = ";
    cout<<diameter(root)<<endl;
    cout<<"PreOrder :- ";
    PreOrder(root);
    cout<<endl;
    cout<<"InOrder :- ";
    InOrder(root);
    cout<<endl;
    cout<<"PostOrder :- ";
    PostOrder(root);
    cout<<endl;
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    BinaryTreeNode<int> *root2 = arrToBST(arr, 0, n-1);
    PostOrder(root2);
    delete root;
    delete root2;
    return 0;
}

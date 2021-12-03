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

class BST
{
    BinaryTreeNode<int> *root;
public:

    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }
private:
    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if(node == NULL)
        {
            return false;
        }
        if(node->data==data)
        {
            return true;
        }
        else if(data<node->data)
        {
            return hasData(data,node->left);
        }
        else
        {
            return hasData(data, node->right);
        }
    }

    BinaryTreeNode<int>* InsertHelper(int data, BinaryTreeNode<int> *node)
    {
        if(node==NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data<node->data)
        {
            node->left = InsertHelper(data,node->left);
            return node;
        }
        else
        {
            node->right = InsertHelper(data, node->right);
            return node;
        }
        return node;
    }

    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node)
    {
        if(node==NULL)
        {
            return NULL;
        }
        if(data>node->data)
        {
            node->right = deleteData(data,node->right);
            return node;
        }
        else if(data<node->data)
        {
            node->left = deleteData(data,node->left);
            return node;
        }
        else
        {
            if(node->left == NULL && node->right == NULL)
            {
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode <int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if(node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while(minNode->left !=NULL)
                {
                    minNode = minNode->left;
                }
                int minNodeData = minNode->data;
                node->data = minNodeData;
                node->right = deleteData(minNodeData, node->right);
                return node;
            }
        }

    }

    void printTree(BinaryTreeNode<int> *root)
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
        printTree(root->left);
        printTree(root->right);
    }

public:

    bool hasData(int data)
    {
        return hasData(data,root);
    }

    void Insert(int data)
    {
        this->root = InsertHelper(data,this->root);
    }
    void deleteData(int data)
    {
        root = deleteData(data,root);
    }

    void printTree()
    {
        printTree(root);
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
    delete root;
    cout<<"BST:-"<<endl;
    BST b1;
    b1.Insert(10);
    b1.Insert(8);
    b1.Insert(12);
    b1.Insert(7);
    b1.Insert(9);
    b1.Insert(13);
    b1.Insert(14);
    b1.printTree();
    b1.deleteData(10);
    cout<<"After Deletion of root"<<endl;
    b1.printTree();

    return 0;
}

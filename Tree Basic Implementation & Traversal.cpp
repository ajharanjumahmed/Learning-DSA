#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

void inOrder(Node *root_node)
{
    Node *current_node = root_node;
    if(current_node == nullptr)
        return;
    inOrder(current_node->left);
    cout<<current_node->data<<" ";
    inOrder(current_node->right);
}

void preOrder(Node *root_node)
{
    Node *current_node = root_node;
    if(current_node == nullptr)
        return;
    cout<<current_node->data<<" ";
    preOrder(current_node->left);
    preOrder(current_node->right);
}

void postOrder(Node *root_node)
{
    Node *current_node = root_node;
    if(current_node == nullptr)
        return;
    postOrder(current_node->left);
    postOrder(current_node->right);
    cout<<current_node->data<<" ";
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(2);
    root->right->right = new Node(3);
    cout<<"Preorder: ";
    preOrder(root);
    cout<<endl;
    cout<<"Inorder: ";
    inOrder(root);
    cout<<endl;
    cout<<"Postorder: ";
    postOrder(root);
    cout<<endl;
}

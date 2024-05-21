#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *root = nullptr;

void Add_node(int value)
{
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if(root==nullptr)
    {
        root = new_node;
    }
    else
    {
        Node *current_node = root;
        while(current_node->next != nullptr)
        {
            current_node = current_node->next;
        }
        new_node->prev = current_node;
        current_node->next = new_node;
    }
}

void printList()
{
    Node *current_node = root;
    while(current_node != nullptr)
    {
        cout<<current_node->data<<" ";
        current_node = current_node->next;
    }
}

void forward_traversal(Node *head)
{
    Node *current_node = head;
    while(current_node != nullptr)
    {
        cout<<current_node->data<<" ";
        current_node = current_node->next;
    }
}

void backward_traversal(Node *head)
{
    Node *current = head;
    if(current == nullptr)
        return;
    backward_traversal(current->next);
    cout<<current->data<<" ";
}

int sizeOfList(Node *head)
{
    int cnt = 0;
    Node *current_node = head;
    while(current_node != nullptr)
    {
        cnt++;
        current_node = current_node->next;
    }
    return cnt;
}

void delete_node(int data)
{
    if(data == root->data)
    {
        Node *temp = root;
        root = root->next;
        delete(temp);
    }
    else
    {
        Node *current_node = root;
        while(current_node->data != data)
        {
            current_node = current_node->next;
        }
        current_node->prev->next = current_node->next;
        current_node->next->prev = current_node->prev;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5};
    for(auto u:arr)
        Add_node(u);
    printList();
    cout<<endl;
    cout<<"Forward Traversal: ";
    forward_traversal(root);
    cout<<endl;
    cout<<"Backward Traversal: ";
    backward_traversal(root);
    cout<<endl;
    cout<<"Size of list is: ";
    cout<<sizeOfList(root);
    cout<<endl;
    delete_node(3);
    cout<<"List after deleting /"3"/: ";
    printList();
    cout<<endl;
    cout<<"Forward Traversal after deleting: ";
    forward_traversal(root);
    cout<<endl;
    cout<<"Backward Traversal after deleting: ";
    backward_traversal(root);
    cout<<endl;
    cout<<"Size of list is: ";
    cout<<sizeOfList(root);
}

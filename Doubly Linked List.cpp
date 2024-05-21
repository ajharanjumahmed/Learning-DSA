#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
};

Node *root = nullptr;

void add_node(int data)
{
    Node *new_node = new Node();
    new_node ->value = data;
    new_node ->next = nullptr;
    new_node ->prev = nullptr;

    if(root == nullptr)
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

void print_list()
{
    Node *current_node = root;
    while(current_node != nullptr)
    {
        cout<<current_node->value<<" ";
        current_node = current_node->next;
    }
}

int main()
{
    int arr[5] = {1,2,4,6,8};
    for(int u : arr)
    {
        add_node(u);
    }
    print_list();
}

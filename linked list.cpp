#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    struct Node *next;
};

struct Node *root = nullptr; //pointer to point root

void add_node(int data)
{
    Node *new_node = new Node(); //making a new node
    new_node->value = data;
    new_node->next = nullptr;

    Node *current_node = root; //making a pointer to point current node
    if(root==nullptr) //if there is no root
    {
        root = new_node;
    }
    else //adding node other than root
    {
        while(current_node->next != nullptr)
        {
            current_node = current_node->next; //node++
        }
        current_node->next = new_node; // storing the address of new node on last node
    }
}

void print_list()
{
    Node *current_node = root;
    while(current_node != nullptr)
    {
        cout<<current_node->value<<endl;
        current_node = current_node->next;
    }
}

void delete_node(int data)
{
    if(data == root->value) //if we want to delete root
        Node *temp = root;
        root = root->next; //pointing the root to next node
        delete(temp);
    else
    {
        Node *current_node = root;
        Node *previous_node = nullptr;
        while(current_node->value != data)
        {
            previous_node = current_node; //making current node as previous node
            current_node = current_node->next; //node++
        }
        previous_node->next = current_node->next; //storing the address of next node of node that we want to delete to the previous node
        delete(current_node);
    }

}

int main()
{
    add_node(1);
    add_node(2);
    add_node(3);
    add_node(4);
    add_node(5);
    add_node(6);
    delete_node(4);
    print_list();

}

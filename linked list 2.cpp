#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    struct Node *next;
};

struct Node *root= nullptr;

void add_node(int data)
{
    Node *new_node = new Node();
    new_node->value = data;
    new_node->next = nullptr;
    if(root == nullptr)
    {
        root = new_node;
    }
    else
    {
        struct Node *current_node = root;
        while(current_node->next != nullptr)
        {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void Delete(int data)
{
    if(data == root->value)
    {
        struct Node *temp = root;
        root = root->next;
        delete(temp);
    }
    else
    {
        struct Node *current_node = root;
        while(current_node != nullptr)
        {
            struct Node *prev_node;
            if(current_node->value == data)
            {
                prev_node->next = current_node->next;
            }
            prev_node = current_node;
            current_node = current_node->next;
        }
    }
}

void forward_traversal(struct Node *head)
{
    struct Node *current_node = head;
    if(current_node == nullptr)
        return;
    cout<<current_node->value<<" ";
    forward_traversal(current_node->next);
}

void backward_traversal(struct Node *head)
{
    struct Node *current_node = head;
    if(current_node == nullptr)
        return;
    backward_traversal(current_node->next);
    cout<<current_node->value<<" ";
}

int size_of_list(struct Node *head)
{
    Node *current_node = head;
    int cnt =0;
    while(current_node != nullptr)
    {
        cnt++;
        current_node = current_node->next;
    }
    return cnt;
}

void print_list()
{
    struct Node *current_node = root;
    while(current_node != nullptr)
    {
        cout<<current_node->value<<" ";
        current_node = current_node->next;
    }
    cout<<endl;
}

void insert_node(int index, int data)
{
    struct Node *new_node = new Node();
    new_node->value = data;
    new_node->next = nullptr;

    if(index == 0)
    {
        new_node->next = root;
        root = new_node;
    }
    else
    {
        struct Node *current_node = root;
        for(int i=0; i<index-1 && current_node!=nullptr; i++)
        {
            current_node = current_node->next;
        }
        if(current_node == nullptr)
        {
            cout<<"Index is out of bound\n";
            delete new_node;
        }
        else
        {
            new_node->next = current_node->next;
            current_node->next = new_node;
        }
    }


}

int main()
{
    int arr[5] = {1,2,3,4,5};
    for(int u:arr)
        add_node(u);
    cout<<"List is: ";
    print_list();
    Delete(3);
    cout<<"List after deleting 3: ";
    print_list();
    cout<<"Forward traversal: ";
    forward_traversal(root);
    cout<<endl;
    cout<<"Backward traversal: ";
    backward_traversal(root);
    cout<<endl;
    insert_node(2,9);
    cout<<"After inserting 9 at index 2: ";
    print_list();
    cout<<"Forward traversal: ";
    forward_traversal(root);
    cout<<endl;
    cout<<"Backward traversal: ";
    backward_traversal(root);
    cout<<endl;
    cout<<"Number of nodes in the list: "<<size_of_list(root);
}

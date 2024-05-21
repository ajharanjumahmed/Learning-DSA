#include<bits/stdc++.h>
using namespace std;

#define MX_size 10

struct Stack
{
    int top;
    int elements[MX_size];
};

typedef struct Stack st;

void createStack(st *s)
{
    s->top = -1;
}

int isFull(st *s)
{
    if(s->top == MX_size-1)
        return 1;
    else
        return 0;
}

int isEmpty(st *s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}

void push(st *s, int element)
{
    if(isFull(s))
        cout<<"Can't push. The stack is full!"<<endl;
    else
    {
        s->elements[++s->top] = element;
        cout<<element<<" is pushed to the stack!"<<endl;
    }
}

void pop(st *s)
{
    if(isEmpty(s))
        cout<<"Can't pop. The stack is empty!"<<endl;
    else
    {
        cout<<s->elements[s->top--]<<" is popped from the stack!"<<endl;
    }
}

void peek(st *s)
{
    if(isEmpty(s))
        cout<<"The stack is empty!"<<endl;
    else
    cout<<"The top element is "<<s->elements[s->top]<<endl;
}

int main()
{
    st stack;
    createStack(&stack);
    int arr[] = {2,4,7,3,8,2,8,45,7,6};
    for(int i=0; i<10; i++)
        push(&stack, arr[i]);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    peek(&stack);
}

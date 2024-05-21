#include<bits/stdc++.h>
using namespace std;

#define MX_size 5

struct Queue
{
    int front;
    int rear;
    int elements[MX_size];
//    Queue()
//    {
//        front = -1;
//        rear = -1;
//    }
};

typedef struct Queue sq;

void createQueue(sq *q)
{
    q->front = -1;
    q->rear = -1;
}

int isFull(sq *q)
{
    if(q->rear == MX_size-1)
        return 1;
    else
        return 0;
}

int isEmpty(sq *q)
{
    if(q->front==-1)
        return 1;
    else
        return 0;
}

void Enqueue(sq *q, int element)
{
    if(isFull(q))
        cout<<"The queue is full!"<<endl;
    else
    {
        if(q->front==-1)
            q->front = 0;
        q->elements[++q->rear] = element;
        cout<<element<<" is enqueued!"<<endl;
    }
}

void Dequeue(sq *q)
{
    if(isEmpty(q))
        cout<<"The queue is empty!"<<endl;
    else
    {
        cout<<q->elements[q->front++]<<" is dequeued!"<<endl;
        if(q->front > q->rear)
            q->front = q->rear = -1;
    }
}

int main()
{
    sq queue;
    createQueue(&queue);
    int arr[MX_size] = {4,7,2,8,56};
    for(int i=0; i<MX_size; i++)
    {
        Enqueue(&queue, arr[i]);
    }
    Dequeue(&queue);
    Dequeue(&queue);
    Dequeue(&queue);
    Dequeue(&queue);
    Dequeue(&queue);
    Dequeue(&queue);
}

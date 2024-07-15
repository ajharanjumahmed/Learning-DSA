#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n, int root)
{
    int mx = root;
    int left = 2*root+1;
    int right = 2*root+2;

    if(left<n && arr[left]>arr[mx])
    {
        mx = left;
    }
    if(right<n && arr[right]>arr[mx])
    {
        mx = right;
    }

    if(mx != root)
    {
        swap(arr[root],arr[mx]);
        heapify(arr,n,mx);
    }
}

void heapSort(int arr[], int n)
{
    for(int i=n/2-1; i>=0; i--)
    {
        heapify(arr,n,i);
    }

    for(int i=n-1; i>0; i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main()
{
    int n = 6;
    int arr[n] = {10,15,30,40,50,100,60};
    heapSort(arr,n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

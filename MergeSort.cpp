#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid-left+1;
    int n2 = right-mid;
    int l[n1], r[n2];
    for(int i=0; i<n1; i++)
    {
        l[i] = arr[left+i];
    }
    for(int i=0; i<n2; i++)
    {
        r[i] = arr[mid+1+i];
    }
    int i=0, j=0, k=left;
    while(i<n1 && j<n2)
    {
        if(l[i]<=r[j])
        {
            arr[k] = l[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = r[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k] = l[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = r[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if(left<right)
    {
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr,left,mid,right);
    }
}

void printList(int arr[], int size)
{
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    printList(arr,n);
}

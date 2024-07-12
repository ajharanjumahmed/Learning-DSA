#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int k = high;
    for(int i=high; i>low; i--)
    {
        if(arr[i]>=pivot)
        {
            swap(arr[i],arr[k]);
            k--;
        }
    }
    swap(arr[low],arr[k]);
    return k;
}

void QuickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int par = partition(arr,low,high);
        QuickSort(arr,low,par-1);
        QuickSort(arr,par+1,high);
    }

}

int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    QuickSort(arr,0,n-1);
    for(int u:arr)
        cout<<u<<endl;
}

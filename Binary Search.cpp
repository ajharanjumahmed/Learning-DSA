#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int target; cin>>target;
    sort(arr, arr+n);
    int low=0, high=n-1, flag=0;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==target)
        {
            cout<<target<<" is found in index "<<mid<<endl;
            flag = 1;
            break;
        }
        else if(arr[mid]>target)
        {
            high = mid-1;
        }
        else if(arr[mid]<target)
        {
            low = mid+1;
        }
    }
    if(flag==0)
    {
        cout<<"Target not found!"<<endl;
    }
}

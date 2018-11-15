/*
Sort the list of integers using heap tree (Heap sort)
*/

#include <iostream>

using namespace std;

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[],int n,int i)
{
    int small = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[small])
        small = left;

    if(right < n && arr[right] > arr[small])
        small = right;

    if(small != i)
    {
        swap(arr[i],arr[small]);
        sort(arr,n,small);
    }
}

void sorting(int arr[],int n)
{
    for(int i=(n/2)-1 ;i>=0 ; i--)
        sort(arr,n,i);

    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);

        sort(arr,i,0);
    }
}

int main()
{
    cout<<"Enter size";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sorting(arr,n);

    cout<<"Sorted elements";

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}

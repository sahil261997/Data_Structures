/*
Write a program to accept N integers from the user and store them in an array.
Sort the array in ascending order using Bubble sort.
Then accept another number from the user, search whether that number exists in the array using Binary Search.
If it does, display its index and if it doesn’t, then print that the number is not found in the array.
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

void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
           if(arr[j]>arr[j+1])
           swap(arr[j],arr[j+1]);
}

int binary_search(int arr[],int l,int r,int x)
{
    if(r>=l)
    {
        int mid = l + (r-l)/2;

        if(arr[mid] == x)
            return mid;

        if(arr[mid] > x)
            return binary_search(arr,l,mid-1,x);

        return binary_search(arr,mid+1,r,x);
    }

    return -1;
}

int main()
{
    int n;
    cout<<"Enter size";
    cin>>n;
    int arr[n];
    cout<<"Enter array";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    bubble_sort(arr,n);

    cout<<"Sorted array :";

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    int x;
    cout<<"Enter element to be search";
    cin>>x;

    int index = binary_search(arr,0,n-1,x);

    if(index == -1)
        cout<<"Number is Not Found";
    else
        cout<<"Found at :"<<index;

    return 0;
}

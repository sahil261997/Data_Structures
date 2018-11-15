/*
Write a program to accept N numbers from the user and store them in an array.
Then, accept another number from the user and search that using Linear Search.
*/
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter size";
    cin>>n;
    int arr[n];
    cout<<"Enter Array elements";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int num;
    cout<<"Enter number to be search";
    cin>>num;

    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
        {
            flag++;
            cout<<"Element found at index :"<<i;
            break;
        }
    }

    if(flag==0)
        cout<<"No such element";
    return 0;
}

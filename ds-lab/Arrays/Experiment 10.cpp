/*
Write a program to accept N numbers from the user in one array and M numbers in another array.
Then, sort the arrays using Selection Sort and then merge these two arrays using Merge Sort.
*/

#include <iostream>

using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection(int arr[], int n)
{
    int i, j, mi;

    for (i = 0; i < n-1; i++)
    {
        mi = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[mi])
            mi = j;

        swap(&arr[mi], &arr[i]);
    }

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}


void merge(int a[], int m, int b[], int n, int sorted[]) {
  int i, j, k;

  j = k = 0;

  for (i = 0; i < m + n;) {
    if (j < m && k < n) {
      if (a[j] < b[k]) {
        sorted[i] = a[j];
        j++;
      }
      else {
        sorted[i] = b[k];
        k++;
      }
      i++;
    }
    else if (j == m) {
      for (; i < m + n;) {
        sorted[i] = b[k];
        k++;
        i++;
      }
    }
    else {
      for (; i < m + n;) {
        sorted[i] = a[j];
        j++;
        i++;
      }
    }
  }
}

int main()
{
    int n,m;
    cout << "Enter size of I'st array" << endl;
    cin>>n;
    int arr1[n];
    cout<<"Enter Array elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter size of II'nd array"<<endl;
    cin>>m;
    int arr2[m];
    cout<<"Enter Array elements"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }

    cout<<"I'st array sorted :"<<endl;
    selection(arr1,n);
    cout<<endl;
    cout<<"II'nd array sorted :"<<endl;
    selection(arr2,m);
    cout<<endl;

    int arr3[n+m];

    merge(arr1,n,arr2,m,arr3);

    cout<<"Merging two arrays:"<<endl;
    for(int i=0;i<n+m;i++)
    {
        cout<<arr3[i]<<" ";
    }

    return 0;
}

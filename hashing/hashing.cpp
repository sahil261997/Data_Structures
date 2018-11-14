//Hashing -> Open Addressing --> LInear Probing :
#include<iostream>
using namespace std;
//#define num 11;
class hashing 
{
    public:
    static int size;
    int num,h,count;
    int *arr;
    hashing(int s)
    {
        size = s;
        arr = new int[size];
        for(int i=0 ; i<size ; i++)
        {
            arr[i] = 0;
        }
    }
    int hash(int a)
    {
        return a%size;
    }
    bool check(int x)
    {
        if(arr[x]==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insert()
    {
        count = 0;
        cout<<"Enter the NUmber :";
        cin>>num;
        re:
        h = hash(num+count);
        if(check(h))
        {
            arr[h] = num;
            cout<<"Num Added..!!\n";
        }
        else if(count < size)
        {
            count++;
            goto re;
        }
        else
        {
            cout<<"Array Full...!!\n";
        }
    }
    void del()
    {
        count = 0;
        cout<<"Enter The Number To Delete :";
        cin>>num;
        del_re:
        h = hash(num+count);
        if(arr[h] == num)
        {
            arr[h] = 0;
            cout<<"Num Deleted..!!\n";
        }
        else if(count <size)
        {
            count++;
            goto del_re;
        }
    }
    void display()
    {
        for(int i=0 ; i<size ; i++)
        {
            cout<<i<<" -> "<<arr[i]<<endl;
        }
        //cout<<endl;
    }
};
int hashing::size;
int main()
{
    int ch,size;
    cout<<"Enter Size :";
    cin>>size;
    hashing h(size);
    label:
    cout<<"Enter the Choice : 1.insert 2.delete 3.display 4.Exit :";
    cin>>ch;
    switch(ch)
    {
        case 1:h.insert();
        break;
        case 2:h.del();
        break;
        case 3:h.display();
        break;
        case 4: return 0;
        break;
        default: cout<<"Enter The Valid choice \n";
    }
    goto label;
}
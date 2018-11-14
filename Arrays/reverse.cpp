#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    node* next;
}NODE;
class stack
{
    public:
    stack()
    {
        start = NULL;
    }
    void insert(int num)
    {
        node *temp = new node();
        temp->data = num;
        temp->next = NULL;
        if(start == NULL)
        {
            start = temp;
        }
        else
        {
            node* t = start;
            while(t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
        }
    }
    void reverse_arr(int r)
    {
        node* temp = start;
        int j=0,temp1;
        int arr[100];
        while(temp!=NULL)
        {
            arr[j] = temp->data;
            temp = temp->next;
            j++;
        }
        for(int a=0 ; a<r/2 ; a++)
        {
            temp1 = arr[a];
            arr[a] = arr[r-a-1];
            arr[r-a-1] = temp1;
        }
        for(int i=0 ; i<j ;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void reverse_list(int p)
    {
        int count=0;
        node * cur = start;
        node * next = NULL;
        node * pre = NULL;
        while(cur !=NULL && count < p)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            count++;
        }
        start = pre;
        //start->next = next;
        /*while(pre !=NULL)
        {
            cout<<pre->data<<" ";
            pre = pre->next;
        }*/
        while(start !=NULL)
        {
            cout<<start->data<<" ";
            start = start->next;
        }
        start = next;
                while(start !=NULL)
        {
            cout<<start->data<<" ";
            start = start->next;
        }
        //goto label;
        cout<<endl;
    }
    private:
    node* start;
};
int main()
{
    int num,n,r;
    cout<<"Enter the size :";
    cin>>num;
    stack s;
    for(int i=0 ; i<num ; i++)
    {
        cin>>n;
        s.insert(n);
    }
    cout<<"Enter The Position to reverse :";
    cin>>r;
    int ch=0;
    while(ch !=3)
    {
        cout<<"Enter the Choice : 1.arr 2.link_list 3.exit:";
        cin>>ch;
        switch(ch)
        {
            case 1: s.reverse_arr(r);
            break;
            case 2: s.reverse_list(r);
            break;
            case 3: return 0;
            default:cout<<"Enter a valid option\n";
        }
    }
    //s.reverse_list(r);
}
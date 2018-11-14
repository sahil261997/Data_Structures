#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    node *next;
}NODE;
class rev
{
    public:
    rev()
    {
        head = NULL;
    }
    node* insert()
    {
        int num;
        cout<<"Enter Data :";
        cin>>num;
        node *temp = new node();
        temp->data = num;
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            node *temp1 = head;
            while(temp1->next != NULL)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }
        return head;
    }
    void rev_disp(node *temp)
    {
        //node *temp = head;
        if(!temp)
        {
            return;
        }
        rev_disp(temp->next);
        cout<<temp->data<<endl;
    }
    private:
    node *head;
};
int main()
{
    int ch;
    rev r;
    cout<<"Enter Your Choice :1.Insert 2.Reverse_print 3.Exit:";
    cin>>ch;
    node *temp;
    while(ch != 3)
    {
        switch(ch)
        {
            case 1: temp = r.insert();
            break;
            case 2: r.rev_disp(temp);
            break;
            default : cout<<"Enter a valid option \n";
        }
    cout<<"Enter Your Choice :1.Insert 2.Reverse_print 3.Exit:";
    cin>>ch;
    }
}
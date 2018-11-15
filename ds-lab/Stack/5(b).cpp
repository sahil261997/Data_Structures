// USING LINKED LIST

#include<iostream>
using namespace std;
struct stack
{
	int data;
	stack *next;
}*save;
struct 	stack *top=NULL;
void push()
{
	int i;
	cout<<"enter the data : ";
	cin>>i;
	stack *temp=new stack;
	temp->data=i;
	temp->next=NULL;
	if(top==NULL)
	{
		top=temp;
	}
	else
	{
		save=top;
		top=temp;
		temp->next=save;
	}
}
void pop()
{
	stack *temp=new stack;
	 if(top==NULL)
        {
            cout<<"\nStack is Empty:\n";
        }
     else
        {
            temp=top;
	        top=temp->next;
	        delete temp;	
		}	
}
void pip()
		{
			if(top==NULL)
        {
    	    cout<<"\nStack is Empty:\n";
    	     exit(0);
	    }
	    else
	    {
	     cout<<"Stack : ";
	     stack *temp;
	     temp=top;
       	while(temp!=NULL)
	     {
		cout<<temp->data<<"->";
		temp=temp->next;	
		}
	    
     	}
	cout<<endl; 
		}
int main()
{
	int c;
		cout<<"1.Push \n 2.Pop \n 3.Pip \n 4.Exit"<<endl;
	while(1)
	{
		cout<<"enter the choice : ";
		cin>>c;
		switch(c)
		{
			case 1:
				{
				    push();
					break;	
				}
			case 2:
				{
					pop();
					break;	
				}
			case 3:
				{ 
					pip();
					break;
				}
			case 4:
				{
				   exit(0);		
				}
		}
	}
	return 0;
}
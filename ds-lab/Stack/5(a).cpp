/*
Write a menu driven program that implements the following operations on a
Stack(either implement as Linear array and as Linked list) :
•	Push
•	Pop
•	Display Top of the stack
*/


// USING ARRAY

#include <iostream>
using namespace std;
class Stack
{
  int i,size,A[100],top;
  public:
  Stack()
  {
    cout<<"Enter size of stack: ";
    cin>>size;
    top = -1;
  }
  bool isempty()
  {
  if(top==-1)
  return true;
  else
  return false;
  }
  void push(int value)
  {
  if(top==size-1)
  {
    cout<<"Stack Overflow\n";
  }
   else
  {
    top++;
    A[top]=value;
  }
  }
  void pop()
  {
  if(isempty())
    cout<<"Stack Underflow!\n";
  else
    top--;
  }
  void show_top()
  {
  if(isempty())
    cout<<"Stack is empty!\n";
  else
    cout<<"Element at top is: "<<A[top]<<"\n";
  }
  void displayStack()
  {
  if(isempty())
  {
    cout<<"Stack is empty!\n";
  }
  else
  {
  cout<<"Stack is ";
  for(i=top ; i>=0; i--)
    cout<<A[i]<<" ";
  cout<<"\n";
  }
  }
};
int main()
{
  Stack s;
  int choice, flag=1, value;
  while( flag == 1)
  {
  cout<<"\nEnter your choice:\n1.PUSH 2.POP 3.SHOW TOP 4.DISPLAY STACK 5.EXIT\n";
  cin>>choice;
  switch (choice)
  {
  case 1: cout<<"Enter Value: ";
          cin>>value;
          s.push(value);
          break;
  case 2: s.pop();
          break;
  case 3: s.show_top();
          break;
  case 4: s.displayStack();
          break;
  case 5: flag = 0;
          break;
  }
  }
  return 0;
}

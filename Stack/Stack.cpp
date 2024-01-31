#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
struct Node  
{  
   int data;  
   struct Node *next;  
};  
Node* top = NULL;
void push(int data)
{
  Node* node = new Node;
  node->data = data;
  node->next= top;
  top = node;
}
void pop()
{
  if(top==NULL)
   cout<<"Stack Underflow"<<endl;
  else { 
  Node* temp = top;
 cout<<"The popped element is "<< top->data <<endl;
  top = top->next;
  delete temp;}
}
bool isEmpty()
    {
        return top == NULL;
    }
int  topElement()
{
    if (!isEmpty())
      {cout<<"Top element is: "<<top->data;
      return top->data;}
    else
      exit(1);
}
void display() {
   struct Node* ptr;
   if(top==NULL)
   cout<<"stack is empty";
   else {
      ptr = top;
      cout<<"Stack elements are: ";
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
}
int main()
{
  push(1);
  display();
  push(2);
  display();
  pop();
  display();
  push(4);
  push(7);
  push(9);
  display();
  topElement();
}
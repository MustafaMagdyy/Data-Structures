#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
struct Node  
{  
   int data;  
   struct Node *next;  
};  
struct Node* front =NULL;
struct Node* rear =NULL;

bool IsEpmty()
{
  if(front ==NULL && rear==NULL)
  {
    return true;
  }
  else
    return false;
}

void Enqueue(int x)
{
  struct Node* node = new Node;
  node->data = x;
  node->next= NULL;
  if(IsEpmty())
    {
      front=rear=node;
      
    }
  else
  {
    rear->next=node;
    rear=node;
  }   
}

void Dequeue()
{
  struct Node* temp =front;
   if(IsEpmty())
    {
      cout<<"Queue is Empty!"<<endl;
      return;
    }
    if(front == rear) {
		front = rear = NULL;
	}
  else
    {
      front=front->next;
      
    }
    delete temp;
}
int Front() {
	if(front == NULL) {
		printf("Queue is empty\n");
		return 0;
	}
	return front->data;
}

void Print() {
	struct Node* temp = front;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
  IsEpmty();
	Enqueue(2); 
  Print(); 
	Enqueue(4); 
  Print();
	Enqueue(6); 
  Print();
	Dequeue();  
  Print();
	Enqueue(8); 
  Print();
}


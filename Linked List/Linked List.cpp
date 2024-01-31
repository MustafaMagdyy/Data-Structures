#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
struct Node  
{  
   int data;  
   struct Node *next;  
};  
// Create a new Node
void push(Node** head,int data)
{
  struct Node* newNode = new Node();
  newNode->data = data;
  newNode->next = (*head);
  (*head) = newNode;
} 
//Create a new Node at any postion
void insertAny (Node** head, int loc,int data)
{
  Node* ptr = (*head);
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  if(loc==1)
  {
    newNode->next = ptr;
   (*head)=newNode;
    return;
  }
  loc--;
  while(loc>1)
  {
    ptr=ptr->next;
    
    loc--;
  }
  newNode->next = ptr->next;;
  ptr->next=newNode;

}
//Delete any Node
void deleteAt(Node** head,int loc)
{
  Node* ptr= (*head);
  loc--;
  while(loc>1)
  {
    ptr=ptr->next;
    
    loc--;
  }
  struct Node* ptr2 = ptr->next;
  ptr->next=ptr2->next;
  delete ptr2;
}
//Reverse the linked list Ittirative mthod
void reverse(Node** head){
  struct Node *current,*next,*prev;
  current = (*head);
  prev = NULL;
  while(current!=NULL)
  {
    next = current->next;
    current->next = prev;
    prev=current;
    current= next;
  }
  (*head)=prev;

}
//Reverse the linked List recursively 
Node* reverseRec(Node* head)
{
  if(head == nullptr || head->next == nullptr)
  {
    return head;
  }
  Node* newHead=reverseRec(head->next);
  head->next->next=head;
  head->next=NULL;
  return newHead;
}
//Display the linked list recursively
void displyRec(struct Node* head)
{
  if(head==NULL)
  {
    return;
  }
  cout<<head->data<<" ";
  displyRec(head->next);
}
//Display the linked list
void display (Node* node)
{
  while(node!=NULL)
  {
  cout<<node->data<<" ";
  node= node->next;
  }
}

int main()
{
  Node* head = NULL;  
  int x =4;
  int* e=NULL;
  push(&head,6);  
  push(&head,5); 
  push(&head,4);
  push(&head,3);
  push(&head,2);
  push(&head,1);
  insertAny(&head,1,6);
  deleteAt(&head,2);
  display(head);
  reverse(&head);
  head=reverseRec(head);
  display(head); 

  return 0;
}
#include<iostream>
using namespace std;

class node{
    public:

    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void print(node *&head){
 
 node* temp = head;

 while(temp != NULL){
  cout << temp->data << " ";
  temp = temp->next;
 }

}


node *reversinglinklist(node *&head,int K){
  
  node *prev = NULL;
  node *current = head;
  node *forward = NULL;

  int count=0;

  while (count < K and current != NULL)
  {
    forward=current->next;
    current->next=prev;
    prev=current;
    current=forward;
    count++;
  }

  if(forward != NULL){
    head->next = reversinglinklist(forward,K);
  }

  return prev;
}


int main(){

node *node1=new node(5);
node *node2=new node(10);
node *node3=new node(15);
node *node4=new node(20);

node *head=node1;


node1->next=node2;
node2->next=node3;  
node3->next=node4;

cout <<"before reversing" << endl;
print(head);

cout << endl;

node* reversedHead = reversinglinklist(head,2);

cout << "After reversing:" << endl;
print(reversedHead);

}
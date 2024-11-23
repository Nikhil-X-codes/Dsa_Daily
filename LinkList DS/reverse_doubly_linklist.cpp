#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int data){
      this->data=data;
      this->next=NULL;
      this->prev=NULL;
    }
};

node *reversinglinklist(node *&head){
  
  node *prevnode = NULL;
  node *currentnode = head;
  
  while (currentnode != NULL)
  {
    node* temp = currentnode->next;
    currentnode->next=prevnode;
    currentnode->prev=temp;
    prevnode = currentnode;
    currentnode = temp;
  }
  
  return prevnode;
}


void print(node *&head){
 
 node* temp = head;

 while(temp != NULL){
  cout << temp->data << endl;
  temp = temp->next;
 }

}

int main()
{
node *n1=new node(10);
node *n2=new node(20);
node *n3=new node(30);

node *head=n1;

n1->next=n2;
n2->next=n3;

cout <<"before reversing" << endl;
print(head);

cout << endl;

node *reversedHead = reversinglinklist(head);

cout << "After reversing:" << endl;
print(reversedHead);

return 0;
}
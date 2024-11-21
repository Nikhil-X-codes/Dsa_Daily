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

void deleting(int position,node *&head){
  
  if(position == 1){
    node *temp= head;
    head = head->next;

    delete temp;
  }

  else{
   
   node*curr=head;
   node*prev=NULL;
   int count=1;

   while (count < position)
   {
      prev=curr;
      curr=curr->next;
      count++;
   }
    prev->next=curr->next; 
    delete curr;
  }
}

void display(node *&head){

    node* temp = head;
    while (temp != NULL)
    {
       cout << temp->data << endl;
       temp = temp->next;
    }
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

deleting(3,head);
display(head);
}
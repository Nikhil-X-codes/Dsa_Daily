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

void print(node *&head){
 
 node* temp = head;

 while(temp != NULL){
  cout << temp->data << endl;
  temp = temp->next;
 }

}

void deleting(int position,node *&head){
  
  if(position == 1){
    node *temp= head;
    temp->next->prev=NULL;
    head = temp->next;
    temp->next=NULL;
    delete temp;
  }

  else{
   
   node*curr=head;
   node*temp=NULL;
   int count=1;

   while (count < position)
   {
      temp=curr;
      curr=curr->next;
      count++;
   }
    
    curr->prev=NULL;
    temp->next=curr->next;
    curr->next=temp;

    delete curr;
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

deleting(2,head);

print(head);

return 0;
}
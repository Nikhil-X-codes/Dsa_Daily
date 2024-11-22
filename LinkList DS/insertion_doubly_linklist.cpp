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

void insertattop(node *&head,int data){

    node *temp=new node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insertatlast(node *&tail,int data){
   
    node *temp=new node(data);
    temp->prev = tail;
    if (tail != NULL) {
        tail->next = temp;
    }
    tail=temp;
}

void insertatmiddle(node *&head,int position,int data,node *&tail){

    if(position ==1){
        insertattop(head,data);
        return;
    }

    node *temp=head;
    int count=1;

    while(count<position-1 && temp->next!=NULL){
        temp=temp->next;
        count++;
    }

    if(temp->next == NULL){
        insertatlast(tail,data);
    }

    node *nodetoinsert=new node(data);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;

}

int main()
{

node *n1=new node(10);
node *n2=new node(20);

node *head=n1;
node *tail=n2;

n1->next=n2;

// insertattop(head,15);
// insertatlast(tail,15);

insertatmiddle(head,2,30,tail);

print(head);

return 0;
}
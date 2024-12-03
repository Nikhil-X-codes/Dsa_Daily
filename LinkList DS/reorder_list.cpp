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

 node* reversing(node* head){

    if(head == NULL or head->next==NULL){
    return head;
  }

   node *prev=NULL;
   node *current=head;
   node *forward=NULL;

  while (current != NULL)
  {
  forward=current->next;
  current->next=prev;
  prev=current;
  current=forward;
  }
  
  return prev;}
  

    void reorderList(node* head) {
        
      node* fast=head;
      node* slow=head;

       while(fast and fast -> next != NULL){
        slow=slow->next;
        fast =fast->next->next;
       }

       node *rev=reversing(slow);

       node *curr=head;

       while(rev -> next != NULL){

        node * temp_rev=rev->next;
        node * temp=curr->next;

        curr->next=rev;
        rev->next=temp;

        curr = temp;
        rev = temp_rev;
       }
        
    }

    void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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


    cout << "Original list: ";
    printList(head);

    reorderList(head);

    cout << "Reordered list: ";
    printList(head);

    return 0;
}
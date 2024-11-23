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

node *middle(node *&head){ 

    if(head == NULL or head->next==NULL){
        return head;
    }

    node *slow = head;
    node *fast = head;
     
    while(fast != NULL &&  fast->next != NULL){
        slow = slow->next;
        fast=fast->next->next;
    }
  
  return slow;
}

int main(){

node *node1=new node(5);
node *node2=new node(10);
node *node3=new node(15);
node *node4=new node(20);
node *node5=new node(25);

node *head=node1;


node1->next=node2;
node2->next=node3;  
node3->next=node4;
node4->next=node5;

node *middleNode = middle(head);
cout << "The middle of the LinkedList is: " << middleNode->data << endl;

}
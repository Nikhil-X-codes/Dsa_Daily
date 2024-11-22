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

int main()
{
node *n1=new node(10);
node *n2=new node(20);

node *head=n1;

n1->next=n2;

print(head);

return 0;
}
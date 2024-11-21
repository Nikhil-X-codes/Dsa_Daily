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

void insertathead(node *&head,int data){

        node* temp=new node(data);
        temp->next=head;
        head=temp;
    }

void insertattail(node *&tail,int data){
       node* temp=new node(data);
       tail->next=temp;
       tail=temp;
}

void insertatmiddle(int position,node *&head,int data){

    if(position == 1){
     insertathead(head,data);
     return;
    }

     node *temp=head;
     int count=1;

     while (count < position-1)
     {
        temp=temp->next;
        count++;
     }

     node *node_to_insert=new node(data);

     node_to_insert->next=temp->next;
     temp->next=node_to_insert;
     
}

void display(node *&head){
        node* temp=head;

        while(temp != NULL){
            cout << temp->data << endl;
            temp=temp->next;
        }

    }

int main(){

node *node1=new node(5);
node *node2=new node(15);
node *node3=new node(20);

node* head=node1;
node* tail=node1;

node1->next=node2;
node2->next=node3;
tail=node3;


// insertathead(head,10);
// insertathead(head,15);

// insertattail(tail,10);
// insertattail(tail,15);

insertatmiddle(4,head,25);

display(head);

}  
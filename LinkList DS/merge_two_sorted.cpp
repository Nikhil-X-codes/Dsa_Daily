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

void print(node *&head) {
    node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

 void solve(node *&head1,node *&head2){
  
  node* curr1=head1;

  node* curr2=curr1->next;

  node *curr3=head2;
 
 while(curr2 != NULL and curr3 != NULL ){

  if(curr1 -> data <= curr3->data and curr3->data <= curr2 -> data){

     // dono ke beech main dala

    node *curr4=curr3->next;
    curr1->next=curr3;                    
    curr3->next=curr2;

    
    // update pointers 

    curr1=curr3;                           
    curr3=curr4;                             
  } 

  else{
   
   curr1=curr2;
   curr2=curr2->next;
   
   if(curr2 == NULL){
    curr1->next=curr3;
    return;
   }

  }

 }

 }



 node *merge(node *&head1,node *&head2){

    if(head1== NULL) return head2;
    if(head2== NULL) return head1;

    if(head1->data  <= head2->data) {
        solve(head1,head2);
        return head1;
    }

    else{
        solve(head2,head1);
        return head2;
    }

}


int main(){

node *node1=new node(5);
node *node2=new node(10);
node *node3=new node(15);

node *head1=node1;
node1->next=node2;
node2->next=node3;

node *node4=new node(3);
node *node5=new node(6);
node *node6=new node(7);

node *head2=node4;
node4->next=node5;
node5->next=node6;

    cout << "List 1: ";
    print(head1);

    cout << "List 2: ";
    print(head2);

    node* mergedHead = merge(head1, head2);

    cout << "Merged List: ";
    print(mergedHead);
    
return 0;
}

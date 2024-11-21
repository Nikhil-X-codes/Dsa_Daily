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

int main(){

node *node1=new node(5);
cout << node1->data;
cout << node1->next;

}

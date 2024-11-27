#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void remove(node*& head) {

    node* curr = head;

    while (curr != NULL && curr->next != NULL) {
     
     node *temp=curr->next;

     while(temp != NULL && temp->next != NULL){

        if(curr->data != temp->next->data){
            temp = temp->next;
        }

        else{
            node * node_to_delete=temp->next;
            temp->next=node_to_delete->next;
            delete node_to_delete;
        }
     }
    
    curr = curr->next;
    }
}

void print(node*& head) {
    node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* node1 = new node(5);
    node* node2 = new node(10);
    node* node3 = new node(5); 
    node* node4 = new node(3);

    node* head = node1;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    cout << "Original List: ";
    print(head);

    remove(head);

    cout << "List After Removing Duplicates: ";
    print(head);

    return 0;
}

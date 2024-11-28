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

void print(node *&head) {
    node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void sorting(node *&head) {
    int zerocount = 0, onecount = 0, twocount = 0;
    node *temp = head;

    while(temp != NULL) {
        if(temp->data == 0) zerocount++;
        else if(temp->data == 1) onecount++;
        else if(temp->data == 2) twocount++;
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        if(zerocount != 0) {
            temp->data = 0;
            zerocount--; 
        } else if (onecount != 0) {
            temp->data = 1;
            onecount--;
        } else {
            temp->data = 2;
            twocount--;
        }
        temp = temp->next;
    }
}

int main() {
    node *node1 = new node(0);
    node *node2 = new node(1);
    node *node3 = new node(2);
    node *node4 = new node(0);

    node *head = node1;
    node1->next = node2;
    node2->next = node3;  
    node3->next = node4;

    cout << "Original List: ";
    print(head);

    sorting(head);

    cout << "Sorted List: ";
    print(head);

    return 0;
}

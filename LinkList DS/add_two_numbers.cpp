#include <iostream>
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

void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* reverseList(node* head) {
    node* curr = head;
    node* prev = NULL;
    node* forward = NULL;

    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

node* addTwoNumbers(node* head1, node* head2) {

    node* result = NULL;  // Resultant list
    node* tail = NULL;    // Tail for appending nodes
    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry != 0) {
        int sum = carry; 

        if (head1 != NULL) {
            sum += head1->data;
            head1 = head1->next;
        }

        if (head2 != NULL) {
            sum += head2->data;
            head2 = head2->next;
        }

        int digit = sum % 10; // Get the single digit
        carry = sum / 10;     // Calculate the carry

        // Create a new node for the digit
        node* newNode = new node(digit);

        // Append to the result list
        if (result == NULL) {
            result = newNode;
            tail = result;
        } 
        
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return result;
}

int main() {

    node* node1 = new node(5);
    node* node2 = new node(0);
    node* node3 = new node(5);

    node* head1 = node1;
    node1->next = node2;
    node2->next = node3;

    node* node4 = new node(3);
    node* node5 = new node(6);
    node* node6 = new node(7);

    node* head2 = node4;
    node4->next = node5;
    node5->next = node6;

    cout << "List 1: ";
    print(head1);

    cout << "List 2: ";
    print(head2);

    node* h1 = reverseList(head1);
    node* h2 = reverseList(head2);

    node* result = addTwoNumbers(h1, h2);

    node* ans = reverseList(result);

    cout << "Sum: ";
    print(ans);

    return 0;
}

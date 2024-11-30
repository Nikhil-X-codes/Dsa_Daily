#include<iostream>
#include<vector>

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

bool checkpalidrome(vector<int>arr){
   
   int n = arr.size();
   int start = 0;   
   int end = n-1;

   while (start <= end)
   {

     if(arr[start] != arr[end]){
      return false;
     }

     start++;
     end--;
      
   }

   return true;
}


bool isvalidpalidrome(node *&head){

    vector<int>arr;
    node* temp = head;

    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return checkpalidrome(arr);
}


int main(){

node *node1=new node(5);
node *node2=new node(10);
node *node3=new node(10);
node *node4=new node(15);

node *head=node1;


node1->next=node2;
node2->next=node3;  
node3->next=node4;

    cout << "Linked list: ";
    print(head);
    cout << endl;

    if (isvalidpalidrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } 
    
    else {
        cout << "The linked list is not a palindrome." << endl;
    }

return 0;
}
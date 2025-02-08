#include <iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
      this->data=data;
      this->left=NULL;
      this->right=NULL;
    }
};

void levelorder(Node *root){
    
    queue<Node*>q;                     
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
       Node*temp=q.front();
       q.pop();

       if(temp == NULL){
         cout << endl;
         if(!q.empty()) q.push(NULL);
       }


       else{
    cout << temp->data << " ";

    if(temp->left){
        q.push(temp->left);
    }

    if(temp->right){
        q.push(temp->right);
    }

       }
    }
    
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

 cout << "Level order Traversal" << endl;
 levelorder(root);

    return 0;
}
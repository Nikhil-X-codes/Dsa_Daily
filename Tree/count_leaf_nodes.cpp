#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void inorderTraversal(Node* root, int &leafCount) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left, leafCount);
    if (root->left == nullptr && root->right == nullptr)
        leafCount++;
    inorderTraversal(root->right, leafCount);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    int leafCount = 0;
    inorderTraversal(root, leafCount);
    cout << "Number of leaf nodes: " << leafCount << endl;

    return 0;
}
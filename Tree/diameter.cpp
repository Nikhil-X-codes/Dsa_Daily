#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int height(Node* root, int &dia) {
        if (root == NULL) return 0;
        
        int leftHeight = height(root->left, dia);
        int rightHeight = height(root->right, dia);
        
        dia = max(dia, leftHeight + rightHeight);
        
        return max(leftHeight, rightHeight) + 1;
    }
    
    int diameter(Node* root) {
        int dia = 0;
        height(root, dia);
        return dia;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);

    Solution sol;
    cout << sol.diameter(root) << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Node {
public:
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
    int height(Node* node) {
        if (node == NULL) return -1;
        int left = height(node->left);
        int right = height(node->right);
        return max(left, right) + 1;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    cout << sol.height(root) << endl;

    return 0;
}

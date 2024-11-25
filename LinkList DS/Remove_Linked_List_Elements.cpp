#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* current = dummy;

        while (current->next != nullptr) {
            if (current->next->val == val) {
                ListNode* node_to_delete = current->next;
                current->next = node_to_delete->next;
                delete node_to_delete;
            } else {
                current = current->next;
            }
        }

        ListNode* new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    int val = 6;

    Solution solution;
    head = solution.removeElements(head, val);

    printList(head);

    return 0;
}

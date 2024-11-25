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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* node_to_remove = slow->next;
        slow->next = node_to_remove->next;

        delete node_to_remove;

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
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int n = 2;

    Solution solution;
    head = solution.removeNthFromEnd(head, n);

    printList(head);

    return 0;
}

// Time:  O(n)
// Space: O(1)
// Definition for a Node.

class Solution {
public:
    Node* flatten(Node* head) {
        for (auto curr = head; curr; curr = curr->next) {
            if (!curr->child) {
                continue;
            }
            auto curr_next = curr->next;
            curr->child->prev = curr;
            curr->next = curr->child;
            auto last_child = curr;
            while (last_child->next) {
                last_child = last_child->next;
            }
            if (curr_next) {
                last_child->next = curr_next;
                curr_next->prev = last_child;
            }
            curr->child = nullptr;
        }
        return head;
    }
};

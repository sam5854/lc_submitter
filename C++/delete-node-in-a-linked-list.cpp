// Time:  O(1)
// Space: O(1)

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node || !node->next) {
            return;
        }
        auto node_to_delete = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete node_to_delete;
    }
};

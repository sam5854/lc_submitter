// Time:  O(n)
// Space: O(1)

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        auto dummy = new ListNode{0};
        dummy->next = head;

        auto left = dummy, right = head;
        while (right->next) {
            if (right->val != 9) {
                left = right;
            }
            right = right->next;
        }

        if (right->val != 9) {
            ++right->val;
        } else {
            ++left->val;
            right = left->next;
            while (right) {
                right->val = 0;
                right = right->next;
            }
        }

        if (dummy->val == 0) {
            head = dummy->next;
            delete dummy;
            return head;
        }

        return dummy;
    }
};

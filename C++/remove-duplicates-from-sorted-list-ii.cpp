// Time:  O(n)
// Space: O(1)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy{0};
        auto prev = &dummy;
        while (head) {
            if (head->next && head->next->val == head->val) {
                auto val = head->val;
                while (head && head->val == val) {
                    head = head->next;
                }
                prev->next = head;
            } else {
                prev->next = head;
                prev = head;
                head = head->next;
            }
        }
        return dummy.next;
    }
};

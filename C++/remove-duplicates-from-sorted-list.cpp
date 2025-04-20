// Time:  O(n)
// Space: O(1)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto iter = head;
        while (iter) {
            auto runner = iter->next;
            while (runner && runner->val == iter->val) {
                runner = runner->next;
            }
            iter->next = runner;
            iter = runner;
        }
        return head; 
    }
};

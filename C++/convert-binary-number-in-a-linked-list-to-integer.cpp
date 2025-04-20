// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        for (; head; head = head->next) {
            result = result * 2 + head->val;
        }
        return result;
    }
};

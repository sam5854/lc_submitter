// Time:  O(n)
// Space: O(1)

class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode dummy;
        dummy.next = head;
        head = &dummy;
        while (head) {
            for (int i = 0; i < m; ++i) {
                if (!head->next) {
                    return dummy.next;
                }
                head = head->next;
            }
            auto prev = head;
            for (int i = 0; i < n; ++i) {
                if (!head->next) {
                    prev->next = nullptr;
                    return dummy.next;
                }
                head = head->next;
            }
            prev->next = head->next;
        }
        return dummy.next;
    }
};

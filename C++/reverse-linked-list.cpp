// Time:  O(n)
// Space: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        auto dummy = ListNode{0};

        while (head) {
            auto tmp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tmp;
        }

        return dummy.next;
    }
};

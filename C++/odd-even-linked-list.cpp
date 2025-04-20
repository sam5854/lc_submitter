// Time:  O(n)
// Space: O(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head) {
            for (auto odd_tail = head, curr = head->next;
                 curr && curr->next;
                 curr = curr->next) {
                ListNode *even_head = odd_tail->next;
                odd_tail->next = curr->next;
                odd_tail = odd_tail->next;
                curr->next = odd_tail->next;
                odd_tail->next = even_head;
            }
        }
        return head; 
    }
};

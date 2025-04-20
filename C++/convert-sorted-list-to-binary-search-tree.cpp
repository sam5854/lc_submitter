// Time:  O(n)
// Space: O(logn)

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        auto curr = head;
        int n = 0;
        while (curr) {
            curr = curr->next;
            ++n;
        }
        return BuildBSTFromSortedDoublyListHelper(&head, 0, n);
    }

    TreeNode * BuildBSTFromSortedDoublyListHelper(ListNode **head, int s, int e) {
        if (s == e) {
            return nullptr;
        }

        int m = s + ((e - s) / 2);
        auto left = BuildBSTFromSortedDoublyListHelper(head, s, m);
        auto curr = new TreeNode((*head)->val);

        *head = (*head)->next;
        curr->left = left;
        curr->right = BuildBSTFromSortedDoublyListHelper(head, m + 1, e);
        return curr;
    }
};

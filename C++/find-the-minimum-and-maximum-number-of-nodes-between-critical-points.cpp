// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, last = -1, result = numeric_limits<int>::max();
        int prev = head->val;
        head = head->next;
        for (int i = 0; head->next; ++i, prev = head->val, head = head->next) {
            if (!((max(prev, head->next->val) < head->val) || 
                  (min(prev, head->next->val) > head->val))) {
                continue;
            }
            if (first == -1) {
                first = i;
            }
            if (last != -1) {
                result = min(result, i - last);
            }
            last = i;
        }
        if (last == first) {
            return {-1, -1};
        }
        return {result, last - first};
    }
};

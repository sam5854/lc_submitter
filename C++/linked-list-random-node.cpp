// Time:  ctor:      O(1)
//        getRandom: O(n)
// Space: O(1)
// if the length is unknown without using extra space

class Solution {
public:
    Solution(ListNode* head) : head_(head), gen_(random_device()()) {
        
    }
    
    int getRandom() {
        auto reservoir = -1;
        auto n = 0;
        for (auto curr = head_; curr; curr = curr->next) {
            uniform_int_distribution<int> dist(0, n++);
            if (dist(gen_) == 0) {
                reservoir = curr->val;
            }
        }
        return reservoir;
    }

private:
    ListNode *head_;
    default_random_engine gen_;
};

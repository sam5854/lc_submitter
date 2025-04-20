// Time:  ctor: O(n)
//        pick: O(1)
// Space: O(n)

class Solution {
public:
    Solution(vector<int> nums) : gen_(random_device()()) {
        for (int i = 0; i < size(nums); ++i) {
            lookup_[nums[i]].emplace_back(i);
        }
    }
    
    int pick(int target) {
        uniform_int_distribution<int> dist(0, size(lookup_[target]) - 1);
        return lookup_[target][dist(gen_)];
    }

private:
    unordered_map<int, vector<int>> lookup_;
    default_random_engine gen_;
};

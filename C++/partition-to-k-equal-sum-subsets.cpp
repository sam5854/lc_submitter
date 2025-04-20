// Time:  O(n*2^n)
// Space: O(2^n)
// Memoization solution.

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0 || *max_element(nums.begin(), nums.end()) > sum / k) {
            return false;
        }
        unordered_map<int, int> lookup;
        lookup[(1 << nums.size()) - 1] = true;
        return dfs(nums, sum / k, 0, sum, &lookup);
    }

private:
    bool dfs(const vector<int>& nums, const int target,
             const int used, const int todo,
             unordered_map<int, int> *lookup) {
        if (!lookup->count(used)) {
            const auto targ = (todo - 1) % target + 1;
            for (int i = 0; i < nums.size(); ++i) {
                if (((used >> i) & 1) == 0 && nums[i] <= targ) {
                    if (dfs(nums, target, used | (1 << i), todo - nums[i], lookup)) {
                        (*lookup)[used] = true;
                        break;
                    }
                }
            }
        }
        return (*lookup)[used];
    }
};

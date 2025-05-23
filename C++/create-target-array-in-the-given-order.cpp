// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (index[j] >= index[i]) {
                    ++index[j];
                }
            }
        }
        vector<int> result(nums.size(),0);
        for (int i = 0; i < nums.size(); ++i){
            result[index[i]] = nums[i];
        }
        return result;
    }
};

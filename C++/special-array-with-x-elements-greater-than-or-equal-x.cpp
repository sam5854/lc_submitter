// Time:  O(n)
// Space: O(1)
// counting sort solution

class Solution {
public:
    int specialArray(vector<int>& nums) {
        static const int MAX_NUM = 1000;
        vector<int> count(MAX_NUM + 1);
        for (const auto& num : nums) {
            ++count[num];
        }
        for (int n = size(nums), i = 0; i < size(count); n -= count[i++]) {
            if (i == n) {
                return i;
            }
        }
        return -1;
    }
};

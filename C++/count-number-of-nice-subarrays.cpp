// Time:  O(n)
// Space: O(k)

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(const vector<int>& nums, int k) {
        int result = 0, left = 0, count = 0;
        for (int right = 0; right < nums.size(); ++right) {
            count += nums[right] % 2;
            while (count > k) {
                count -= nums[left] % 2;
                ++left;
            }
            result += right - left + 1;
        }
        return result;
    }
};

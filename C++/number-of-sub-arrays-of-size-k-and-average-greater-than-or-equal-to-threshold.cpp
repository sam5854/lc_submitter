// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int result = 0, curr = accumulate(arr.cbegin(), arr.cbegin() + k - 1, 0);
        for (int i = k - 1; i < arr.size(); ++i) {
            curr += arr[i] - ((i - k >= 0) ? arr[i - k]: 0);
            result += int(curr >= k * threshold);
        }
        return result;
    }
};

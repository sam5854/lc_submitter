// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int j;
        for (j = arr.size() - 1; j >= 1; --j) {
            if (arr[j - 1] > arr[j]) {
                break;
            }
        }
        if (j == 0) {
            return 0;
        }
        int result = j;
        for (int i = 0; i < arr.size(); ++i) {
            if (i && arr[i - 1] > arr[i]) {
                break;
            }
            while (j < arr.size() && arr[i] > arr[j]) {
                ++j;
            }
            result = min(result, (j - i + 1) - 2);
        }
        return result;
    }
};

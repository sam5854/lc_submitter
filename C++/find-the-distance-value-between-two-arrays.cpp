// Time:  O((n + m) * logm)
// Space: O(1)

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(begin(arr2), end(arr2));
        int result = 0;
        for (const auto& x : arr1) {
            auto j = distance(cbegin(arr2), lower_bound(cbegin(arr2), cend(arr2), x));
            const auto& left = (j - 1 >= 0) ? arr2[j - 1] : numeric_limits<int>::min();
            const auto& right = (j < arr2.size()) ? arr2[j] : numeric_limits<int>::max();
            result += left + d < x && x < right - d; 
        }
        return result;
    }
};

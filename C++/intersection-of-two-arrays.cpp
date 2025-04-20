// Time:  O(m + n)
// Space: O(min(m, n))
// Hash solution.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersection(nums2, nums1);
        }

        unordered_set<int> lookup{nums1.cbegin(), nums1.cend()};

        vector<int> result;
        for (const auto& i : nums2) {
            if (lookup.count(i)) {
                result.emplace_back(i);
                lookup.erase(i);
            }
        }

        return result;
    }
};

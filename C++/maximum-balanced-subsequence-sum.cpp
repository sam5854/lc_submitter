// Time:  O(nlogn)
// Space: O(n)
// bst, binary search, mono stack

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        static const auto NEG_INF = numeric_limits<int64_t>::min();

        const auto& query = [](const auto& bst, const auto& k) {
            const auto it = bst.lower_bound(pair(k, 0));
            return it != begin(bst) ? prev(it)->second : NEG_INF;
        };

        const auto& update = [](auto& bst, const auto& k, const auto& v) {
            const auto it = bst.lower_bound(pair(k, 0));
            if (it != end(bst) && it->first == k) {
                if (!(it->second < v)) {
                    return;
                }
                bst.erase(it);
            } else if (!(it == begin(bst) || prev(it)->second < v)) {
                return;
            }
            const auto [jt, _] = bst.emplace(k, v);
            while (next(jt) != end(bst) && next(jt)->second <= jt->second) {
                bst.erase(next(jt));
            }
        };

        set<pair<int, int64_t>> bst;
        for (int i = 0; i < size(nums); ++i) {
            const auto val = max(query(bst, (nums[i] - i) + 1), static_cast<int64_t>(0)) + nums[i];
            update(bst, nums[i] - i, val);
        }
        return rbegin(bst)->second;
    }
};

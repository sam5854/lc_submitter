// Time:  O(n * logr * logn)
// Space: O(nlogr)
// sort

class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        const auto& to_binary = [](int x) {
            string result;
            for (; x; x >>= 1) {
                result.push_back(x & 1 ? '1' : '0');
            }
            reverse(begin(result), end(result));
            return result;
        };

        vector<string> bins(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            bins[i] = to_binary(nums[i]);
        }
        sort(begin(bins), end(bins), [](const auto& a, const auto& b) {
            return (a + b) > (b + a);
        });
        string result;
        for (const auto& x : bins) {
            result += x;
        }
        return stoi(result, nullptr, 2);
    }
};

// Time:  O(nlogn)
// Space: O(n)
// BIT solution. (24ms)

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // Get the place (position in the ascending order) of each number.
        vector<int> idx(size(nums));
        iota(begin(idx), end(idx), 0);
        vector<int> lookup(size(nums));
        sort(begin(idx), end(idx),
             [&nums](const auto& a, const auto& b) {
                 return nums[a] == nums[b] ? a < b : nums[a] < nums[b];
             });
        for (int i = 0; i < size(idx); ++i) {
            lookup[idx[i]] = i;
        }
        // Count the smaller elements after the number.
        BIT bit(size(nums));
        vector<int> result(size(nums));
        for (int i = size(nums) - 1; i >= 0; --i) {
            result[i] = bit.query(lookup[i] - 1);
            bit.add(lookup[i], 1);
        }
        return result;
    }

private:
    class BIT {
    public:
        BIT(int n) : bit_(n + 1) {  // 0-indexed
        }
        
        void add(int i, int val) {
            ++i;
            for (; i < size(bit_); i += lower_bit(i)) {
                bit_[i] += val;
            }
        }

        int query(int i) const {
            ++i;
            int total = 0;
            for (; i > 0; i -= lower_bit(i)) {
                total += bit_[i];
            }
            return total;
        }
    
    private:
        int lower_bit(int i) const {
            return i & -i;
        }
        
        vector<int> bit_;
    };
};

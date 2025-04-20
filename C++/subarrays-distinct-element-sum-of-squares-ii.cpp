#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// Time:  O(nlogn)
// Space: O(n)
// bit, fenwick tree, ordered set, math

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
        ordered_set os;
        unordered_map<int, vector<int>> idxs;
        for (int i = size(nums) - 1; i >= 0; --i) {
            idxs[nums[i]].emplace_back(i);
        }
        for (const auto& [_, v] : idxs) {
            os.insert(v.back());
        }
        int result = 0;
        int accu = ((static_cast<int64_t>(size(nums)) * size(os)) % MOD) * size(os) % MOD;
        for (int i = 0; i < size(os); ++i) {
            accu = ((accu - (static_cast<int64_t>(2 * i + 1) * *os.find_by_order(i) % MOD)) % MOD + MOD) % MOD;
        }
        BIT bit(size(nums));
        for (const auto& x : os) {
            bit.add(x, x);
        }

        const auto& update = [&](int x, int accu, int d) {
            const int i = os.order_of_key(idxs[x].back());
            accu = ((accu + d * (static_cast<int64_t>(size(nums)) * (2 * static_cast<int>(size(os)) - 1)
                                 - static_cast<int64_t>(2 * i + 1) * idxs[x].back()
                                 - 2ll * (bit.query(size(nums) - 1) - bit.query(idxs[x].back())))) % MOD + MOD) % MOD;
            bit.add(idxs[x].back(), d * idxs[x].back());
            return accu;
        };

        for (const auto& x : nums) {
            result = (result + accu) % MOD;  // accu = sum(count(i, k) for k in range(i, len(nums)))
            accu = update(x, accu, -1);
            os.erase(idxs[x].back());
            idxs[x].pop_back();
            if (empty(idxs[x])) {
                continue;
            }
            os.insert(idxs[x].back());
            accu = update(x, accu, +1);
        }
        assert(accu == 0);
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
                bit_[i] = (bit_[i] + val) % MOD;
            }
        }

        int query(int i) const {
            ++i;
            int total = 0;
            for (; i > 0; i -= lower_bit(i)) {
                total = (total + bit_[i]) % MOD;
            }
            return total;
        }
    
    private:
        int lower_bit(int i) const {
            return i & -i;
        }
        
        vector<int> bit_;
        static const int MOD = 1e9 + 7;
    };
};

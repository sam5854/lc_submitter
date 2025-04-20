// Time:  O(nlogm)
// Space: O(m)

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        static const int MOD = 1e9 + 7;
        BIT bit(*max_element(cbegin(instructions), cend(instructions)));
        int result = 0;
        for (int i = 0; i < size(instructions); ++i) {
            const auto inst = instructions[i] - 1;
            auto cost = min(bit.query(inst - 1), i - bit.query(inst));
            if (MOD - result <= cost) {
                cost -= MOD;
            }
            result += cost;
            bit.add(inst, 1);
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

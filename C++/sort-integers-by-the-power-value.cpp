// Time:  O(n) on average
// Space: O(n)

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> arr;
        for (int i = lo; i <= hi; ++i) {
            arr.emplace_back(power_value(i), i);
        }
        auto it = begin(arr) + k - 1;
        nth_element(begin(arr), it, end(arr));
        return it->second;
    }

private:
    int power_value(int x) {
        int y = x, result = 0;
        while (x > 1 && !Solution::dp_.count(x)) {
            ++result;
            if (x & 1) {
                x = 3 * x + 1;
            } else {
                x >>= 1;
            }
        }
        Solution::dp_[y] = result + Solution::dp_[x];
        return Solution::dp_[y];
    }
    
    static unordered_map<int, int> dp_;
};

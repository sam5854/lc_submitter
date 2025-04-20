// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res{0};
        for (int i = 1; i <= num; ++i) {
            res.emplace_back((i & 1) + res[i >> 1]);
        }
        return res;
    }
};

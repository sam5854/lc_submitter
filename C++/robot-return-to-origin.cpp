// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> count;
        for (const auto& m : moves) {
            ++count[m];
        }
        return count['L'] == count['R'] && count['U'] == count['D'];
    }
};

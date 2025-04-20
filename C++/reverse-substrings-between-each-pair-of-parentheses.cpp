// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> stk;
        unordered_map<int, int> lookup;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stk.emplace_back(i);
            } else if (s[i] == ')') {
                int j = stk.back(); stk.pop_back();
                lookup[i] = j, lookup[j] = i;
            }
        }
        string result;
        for (int i = 0, d = 1; i < s.length(); i += d) {
            if (lookup.count(i)) {
                i = lookup[i];
                d *= -1;
            } else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};

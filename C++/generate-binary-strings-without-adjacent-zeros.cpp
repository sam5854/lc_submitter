// Time:  O(n * 2^n)
// Space: O(n)
// backtracking

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        string curr;
        const function<void (int)> backtracking = [&](int i) {
            if (i == n) {
                result.push_back(curr);
                return;
            }
            if (empty(curr) || curr.back() == '1') {
                curr.push_back('0');
                backtracking(i + 1);
                curr.pop_back();
            }
            curr.push_back('1');
            backtracking(i + 1);
            curr.pop_back();
        };

        backtracking(0);
        return result;
    }
};

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string sortString(string s) {
        string result;
        auto count = counter(s);
        while(result.length() != s.length()) {
            for (int c = 0; c < count.size(); ++c) {
                if (count[c]) {
                    result += ('a' + c);
                    --count[c];
                }
            }
            for (int c = count.size() - 1; c >= 0; --c) {
                if (count[c]) {
                    result += ('a' + c);
                    --count[c];
                }
            }
        }
        return result;
    }

private:
    vector<int> counter(const string& word) {
        vector<int> count(26);
        for (const auto& c : word) {
            ++count[c - 'a'];
        }
        return count;
    }
};

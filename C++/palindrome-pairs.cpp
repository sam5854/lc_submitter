// Time:  O(n * k^2), n is the number of the words, k is the max length of the words.
// Space: O(n * k)

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<int, unordered_map<string, int>> lookup;
        for (int i = 0; i < words.size(); ++i) {
            lookup[size(words[i])][words[i]] = i;
        }

        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].length(); ++j) {
                if (lookup.count(j) && is_palindrome(words[i], j, words[i].length() - 1)) {
                    string suffix = words[i].substr(0, j); 
                    reverse(suffix.begin(), suffix.end());
                    auto& bucket = lookup[size(suffix)];
                    if (bucket.count(suffix) && i != bucket[suffix]) {
                        res.push_back({i, bucket[suffix]});
                    }
                }
                if (j > 0 && lookup.count(size(words[i]) - j) && is_palindrome(words[i], 0, j - 1)) {
                    string prefix = words[i].substr(j);
                    reverse(prefix.begin(), prefix.end());
                    auto& bucket = lookup[size(prefix)];
                    if (bucket.count(prefix) && bucket[prefix] != i) {
                        res.push_back({bucket[prefix], i});
                    }
                }
            }
        }
        return res;
    }

private:
    bool is_palindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};

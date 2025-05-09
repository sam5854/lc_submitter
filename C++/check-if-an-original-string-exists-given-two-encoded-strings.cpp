// Time:  O(m * n * k), k is the max number of consecutive digits in s1 and s2
// Space: O(m * n * k)
// top-down dp (faster since accessing less states)

class Solution {
public:
    bool possiblyEquals(string s1, string s2) {
        vector<vector<unordered_map<int, bool>>> lookup(size(s1) + 1, vector<unordered_map<int, bool>>(size(s2) + 1));
        return memoization(s1, s2, 0, 0, 0, &lookup);
    }

private:
    int memoization(const string& s1, const string& s2, int i, int j, int k, vector<vector<unordered_map<int, bool>>> *lookup) {
        if (!(*lookup)[i][j].count(k)) {
            if (i == size(s1) && j == size(s2)) {
                (*lookup)[i][j][k] = (k == 0);
            } else if (i != size(s1) && isdigit(s1[i])) {
                (*lookup)[i][j][k] = false;
                int ni = i + 1;
                for (; ni < size(s1); ++ni) {
                    if (!isdigit(s1[ni])) {
                        break;
                    }
                }
                for (const auto& x : optimized_possible_numbers(s1.substr(i, ni - i))) {
                    if (memoization(s1, s2, ni, j, k + x, lookup)) {
                        (*lookup)[i][j][k] = true;
                        break;
                    }
                }
            } else if (j != size(s2) && isdigit(s2[j])) {
                (*lookup)[i][j][k] = false;
                int nj = j + 1;
                for (; nj < size(s2); ++nj) {
                    if (!isdigit(s2[nj])) {
                        break;
                    }
                }
                for (const auto& x : optimized_possible_numbers(s2.substr(j, nj - j))) {
                    if (memoization(s1, s2, i, nj, k - x, lookup)) {
                        (*lookup)[i][j][k] = true;
                        break;
                    }
                }
            } else if (k < 0) {
                (*lookup)[i][j][k] = (i != size(s1)) ? memoization(s1, s2, i + 1, j, k + 1, lookup) : false;
            } else if (k > 0) {
                (*lookup)[i][j][k] = (j != size(s2)) ? memoization(s1, s2, i, j + 1, k - 1, lookup) : false;
            } else {
                (*lookup)[i][j][k] = (i != size(s1) && j != size(s2) && s1[i] == s2[j]) ? memoization(s1, s2, i + 1, j + 1, k, lookup) : false;
            }
        }
        return (*lookup)[i][j][k];
    }

    vector<int> optimized_possible_numbers(const string& s) {
        assert(size(s) <= 3);
        vector<int> result = {stoi(s)};
        if (size(s) >= 2) {
            if (s[1] != '0') {
                result.emplace_back(stoi(s.substr(0, 1 - 0)) + stoi(s.substr(1)));
            }
        }
        if (size(s) >= 3) {
            if (s[2] != '0') {
                result.emplace_back(stoi(s.substr(0, 2 - 0)) + stoi(s.substr(2)));
                if (s[1] != '0') {
                    result.emplace_back(stoi(s.substr(0, 1 - 0)) + stoi(s.substr(1, 2 - 1)) + stoi(s.substr(2)));
                }
            }
        }
        return result;  // vector is much faster than unordered_set even if vector has duplications in this case
    }

    unordered_set<int> general_possible_numbers(const string& s) {  // Time: O(2^l), Space: O(2^l), l is the length of consecutive digits s, and l is at most 3
        vector<unordered_set<int>> dp(size(s));
        for (int i = 0; i < size(s); ++i) {
            for (int j = i, curr = 0, basis = 1; j >= 0; --j, basis *= 10) {
                curr += (s[j] - '0') * basis;
                if (s[j] == '0') {
                    continue;
                }
                if (j == 0) {
                    dp[i].emplace(curr);
                } else {
                    for (const auto& x : dp[j - 1]) {
                        dp[i].emplace(x + curr);
                    }
                }
            }
        }
        return dp.back();
    }
};

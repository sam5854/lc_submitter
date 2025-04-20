// Time:  O(n)
// Space: O(n)

class Solution {
public:
    long long maxProduct(string s) {
        const auto& P = manacher(s);
        queue<pair<int64_t, int64_t>> q;
        vector<int64_t> left = {0};
        for (int i = 0; i < size(s); ++i) {
            while (!empty(q) && q.front().second < i) {
                q.pop();
            }
            left.emplace_back(max(left.back(), empty(q) ? 1 : 1 + 2 * (i - q.front().first)));
            q.emplace(i, i + P[2 * i + 2] / 2);
        }
        q = queue<pair<int64_t, int64_t>>();
        int64_t result = 0, right = 0;
        for (int i = size(s) - 1; i >= 0; --i) {
            while (!empty(q) && q.front().second > i) {
                q.pop();
            }
            right = max(right, empty(q) ? 1 : 1 + 2 * (q.front().first - i));
            q.emplace(i, i - P[2 * i + 2] / 2);
            result = max(result, left[i] * right);
        }
        return result;
    }

private:
    vector<int> manacher(const string& s) {
        string T = preProcess(s);
        const int n = size(T);
        vector<int> P(n);
        int C = 0, R = 0;
        for (int i = 1; i < n - 1; ++i) {
            int i_mirror = 2 * C - i;
            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                ++P[i];
            }
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        return P;
    }

    string preProcess(const string& s) {
        if (empty(s)) {
            return "^$";
        }
        string ret = "^";
        for (int i = 0; i < size(s); ++i) {
            ret += "#" + s.substr(i, 1);
        }
        ret += "#$";
        return ret;
    }
};

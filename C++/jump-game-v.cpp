// Time:  O(n)
// Space: O(n)
// sliding window + top-down dp

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        vector<vector<int>> left(arr.size());
        deque<int> decreasing_dq;
        for (int i = 0; i < arr.size(); ++i) {
            if (!decreasing_dq.empty() && i - decreasing_dq.front() == d + 1) {
                decreasing_dq.pop_front();
            }
            while (!decreasing_dq.empty() && arr[decreasing_dq.back()] < arr[i]) {
                if (!left[i].empty() && arr[left[i].back()] != arr[decreasing_dq.back()]) {
                    left[i].clear();
                }
                left[i].emplace_back(decreasing_dq.back());
                decreasing_dq.pop_back();
            }
            decreasing_dq.emplace_back(i);
        }
        vector<vector<int>> right(arr.size());
        decreasing_dq.clear();
        for (int i = arr.size() - 1; i >= 0; --i) {
            if (!decreasing_dq.empty() && decreasing_dq.front() - i == d + 1) {
                decreasing_dq.pop_front();
            }
            while (!decreasing_dq.empty() && arr[decreasing_dq.back()] < arr[i]) {
                if (!right[i].empty() && arr[right[i].back()] != arr[decreasing_dq.back()]) {
                    right[i].clear();
                }
                right[i].emplace_back(decreasing_dq.back());
                decreasing_dq.pop_back();
            }
            decreasing_dq.emplace_back(i);
        }

        int result = 0;
        vector<int> lookup(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            result = max(result, dp(arr, d, i, left, right, &lookup));
        }
        return result;
    }

private:
    int dp(const vector<int>& arr, int d, int i,
           const vector<vector<int>>& left, const vector<vector<int>>& right,
           vector<int> *lookup) {
        if ((*lookup)[i]) {
            return (*lookup)[i];
        }
        (*lookup)[i] = 1;
        // each dp[j] will be visited at most twice 
        for (const auto& j : left[i]) {
            (*lookup)[i] = max((*lookup)[i], dp(arr, d, j, left, right, lookup) + 1);
        }
        for (const auto& j : right[i]) {
            (*lookup)[i] = max((*lookup)[i], dp(arr, d, j, left, right, lookup) + 1);
        }
        return (*lookup)[i];
    }
};

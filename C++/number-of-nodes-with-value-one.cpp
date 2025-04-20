// Time:  O(q + n)
// Space: O(n)
// bfs

class Solution {
public:
    int numberOfNodes(int n, vector<int>& queries) {
        vector<int> cnt(n);
        const auto& bfs = [&]() {
            int result = 0;
            vector<pair<int, int>> q = {{1, 0}};
            while (!empty(q)) {
                vector<pair<int, int>> new_q;
                for (auto [u, curr] : q) {
                    curr ^= cnt[u - 1] % 2;
                    result += curr;
                    for (int v = 2 * u; v <= min(2 * u + 1, n); ++v) {
                        new_q.emplace_back(v, curr);
                    }
                }
                q = move(new_q);                
            }
            return result;
        };
        
        for (const auto& q : queries) {
            ++cnt[q - 1];
        }
        return bfs();
    }
};

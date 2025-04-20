// Time:  O(n)
// Space: O(n)
// number theory, tree dp, iterative dfs

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        const auto& linear_sieve_of_eratosthenes = [](int n) {  // Time: O(n), Space: O(n)
            vector<int> spf(n + 1, -1);
            vector<int> primes;
            for (int i = 2; i <= n; ++i) {
                if (spf[i] == -1) {
                    spf[i] = i;
                    primes.emplace_back(i);
                }
                for (const auto& p : primes) {
                    if (i * p > n || p > spf[i]) {
                        break;
                    }
                    spf[i * p] = p;
                }
            }
            return spf;
        };

        const auto& spf = linear_sieve_of_eratosthenes(n);
        const auto& is_prime = [&](int x) {
            return spf[x] == x;
        };
    
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            const int u = e[0] - 1, v = e[1] - 1;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        
        const auto& iter_dfs = [&]() {
            int64_t result = 0;
            using RET = vector<int64_t>;
            RET ret(2);
            vector<tuple<int, int, int, int, shared_ptr<RET>, RET *>> stk = {{1, 0, -1, -1, nullptr, &ret}};
            while (!empty(stk)) {
                const auto [step, u, p, i, new_ret, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    (*ret) = {1 - is_prime(u + 1), is_prime(u + 1)};
                    stk.emplace_back(2, u, p, 0, nullptr, ret);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    const auto& v = adj[u][i];
                    stk.emplace_back(2, u, p, i + 1, nullptr, ret);
                    if (v == p) {
                        continue;
                    }
                    const auto& new_ret = make_shared<RET>(2);
                    stk.emplace_back(3, u, p, i, new_ret, ret);
                    stk.emplace_back(1, v, u, -1, nullptr, new_ret.get());
                } else if (step == 3) {
                    result += (*ret)[0] * (*new_ret)[1] + (*ret)[1] * (*new_ret)[0];
                    if (is_prime(u + 1)) {
                        (*ret)[1] += (*new_ret)[0];
                    } else {
                        (*ret)[0] += (*new_ret)[0];
                        (*ret)[1] += (*new_ret)[1];
                    }
                }
            }
            return result;
        };
    
        return iter_dfs();
    }
};

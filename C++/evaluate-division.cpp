// Time:  O((e + q) * α(n)) ~= O(e + q), using either one of "path compression" and "union by rank" results in amortized O(logn)
//                                     , using  both results in α(n) ~= O(1)
// Space: O(n)

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        UnionFind union_find;
        for (int i = 0; i < equations.size(); ++i) {
            union_find.union_set(equations[i][0], equations[i][1], values[i]);
        }
        
        vector<double> result;
        for (const auto& q : queries) {
            result.emplace_back(union_find.query_set(q[0], q[1]));
        }
        return result;
    }

private:
    class UnionFind {
    public:
        UnionFind() {
        }
                
        pair<string, double> find_set(const string& x) {
            if (!set_.count(x)) {
                set_[x] = pair(x, 1.0);
            }
            const auto& [xp, xr] = set_[x];
            if (x != xp) {
                const auto& [pp, pr] = find_set(xp);  // Path compression.
                set_[x] = pair(pp, xr * pr);
            }
            return set_[x];
        }

        bool union_set(const string& x, const string& y, double r) {
            const auto& [xp, xr] = find_set(x);
            const auto& [yp, yr] = find_set(y);
            if (xp == yp) {
                return false;
            }
            if (rank_[xp] < rank_[yp]) {  // Union by rank.
                set_[xp] = pair(yp, r * yr / xr);
            } else if (rank_[xp] > rank_[yp]) {
                set_[yp] = pair(xp, 1.0 / r * xr / yr);
            } else {
                set_[yp] = pair(xp, 1.0 / r * xr / yr);
                ++rank_[xp];
            }
            return true;
        }

        double query_set(const string& x, const string& y) {
            if (!set_.count(x) || !set_.count(y)) {
                return -1.0;
            }
            const auto& [xp, xr] = find_set(x);
            const auto& [yp, yr] = find_set(y);
            return (xp == yp) ? xr / yr : -1.0;
        }

    private:
        unordered_map<string, pair<string, double>> set_;
        unordered_map<string, int> rank_;
    };
    
    class UnionFindPathCompressionOnly {
    public:
        UnionFindPathCompressionOnly() {
        }
                
        pair<string, double> find_set(const string& x) {
            if (!set_.count(x)) {
                set_[x] = pair(x, 1.0);
            }
            const auto& [xp, xr] = set_[x];
            if (x != xp) {
                const auto& [pp, pr] = find_set(xp);  // Path compression.
                set_[x] = pair(pp, xr * pr);
            }
            return set_[x];
        }

        bool union_set(const string& x, const string& y, double r) {
            const auto& [xp, xr] = find_set(x);
            const auto& [yp, yr] = find_set(y);
            if (xp == yp) {
                return false;
            }
            set_[xp] = pair(yp, r * yr / xr); 
            return true;
        }

        double query_set(const string& x, const string& y) {
            if (!set_.count(x) || !set_.count(y)) {
                return -1.0;
            }
            const auto& [xp, xr] = find_set(x);
            const auto& [yp, yr] = find_set(y);
            return (xp == yp) ? xr / yr : -1.0;
        }

    private:
        unordered_map<string, pair<string, double>> set_;
    };
};

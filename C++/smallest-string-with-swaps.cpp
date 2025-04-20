// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) { 
        UnionFind union_find(s.length());
        for (const auto& pair : pairs) {
            union_find.union_set(pair[0], pair[1]);
        }
        unordered_map<int, vector<char>> components;
        for (int i = 0; i < s.length(); ++i) {
            components[union_find.find_set(i)].emplace_back(s[i]);
        }
        for (auto& [i, list] : components) {
            sort(list.begin(), list.end(), greater<char>());
        }
        for (int i = 0; i < s.length(); ++i) {
            const auto& j = union_find.find_set(i);
            s[i] = components[j].back();
            components[j].pop_back();
        }
        return s;
    }

private:
    class UnionFind {
    public:
        UnionFind(const int n) : set_(n) {
            iota(set_.begin(), set_.end(), 0);
        }

        int find_set(const int x) {
           if (set_[x] != x) {
               set_[x] = find_set(set_[x]);  // Path compression.
           }
           return set_[x];
        }

        bool union_set(const int x, const int y) {
            int x_root = find_set(x), y_root = find_set(y);
            if (x_root == y_root) {
                return false;
            }
            set_[min(x_root, y_root)] = max(x_root, y_root);
            return true;
        }

    private:
        vector<int> set_;
    };
};

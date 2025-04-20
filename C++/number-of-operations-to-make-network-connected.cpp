// Time:  O(|E| + |V|)
// Space: O(|V|)

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        UnionFind union_find(n);
        for (const auto& c : connections) {
            union_find.union_set(c[0], c[1]);
        }
        return union_find.size() - 1;
    }

private:
    class UnionFind {
    public:
        UnionFind(const int n) : set_(n), size_(n) {
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
            --size_;
            return true;
        }

        int size() const {
            return size_;
        }

    private:
        vector<int> set_;
        int size_;
    };
};

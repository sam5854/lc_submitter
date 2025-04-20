// Time:  O(nlogn)
// Space: O(n)
// segment tree

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        struct Node {
            Node(char left = 0, char right = 0, int left_len = 0, int right_len = 0, int len = 0, int max_len = 0) 
             : left(left), right(right), left_len(left_len), right_len(right_len), len(len), max_len(max_len) {
            }

            char left;
            char right;
            int left_len;
            int right_len;
            int len;
            int max_len;
        };
        const auto& update = [] (const auto& c) {
            return Node(c, c, 1, 1, 1, 1);
        };
        const auto& build = [&s, &update] (const auto& i) {
            return update(s[i]);
        };
        const auto& query = [] (const auto& x, const auto& y) {
            if (x.len == 0) {
                return y;
            }
            if (y.len == 0) {
                return x;
            }
            return Node(x.left,
                        y.right,
                        x.left_len + ((x.left_len == x.len && x.right == y.left) ? y.left_len : 0),
                        y.right_len + ((y.right_len == y.len && y.left == x.right) ? x.right_len : 0),
                        x.len + y.len,
                        max({x.max_len, y.max_len, (x.right == y.left) ? x.right_len + y.left_len : 0}));
        };
        vector<int> result;
        SegmentTree<Node, char> st(size(s), build, update, query);
        for (int i = 0; i < size(queryCharacters); ++i) {
            st.update(queryIndices[i], queryCharacters[i]);
            result.emplace_back(st.tree[1].max_len);
        }
        return result;
    }
};

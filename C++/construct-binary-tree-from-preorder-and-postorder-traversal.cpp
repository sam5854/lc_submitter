// Time:  O(n)
// Space: O(h)

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        vector<TreeNode*> s;
        s.emplace_back(new TreeNode(pre[0]));
        for (int i = 1, j = 0; i < pre.size(); ++i) {
            auto node = new TreeNode(pre[i]);
            while (s.back()->val == post[j]) {
                s.pop_back(), ++j;
            }
            if (s.back()->left == nullptr) {
                s.back()->left = node;
            } else {
                s.back()->right = node;
            }
            s.emplace_back(node);
        }
        return s[0];
    }
};

// Time:  O(n)
// Space: O(h)

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        vector<TreeNode*> s{root};
        while (!s.empty()) {
            auto node = s.back(); s.pop_back();
            if (!node) {
                continue;
            }
            if (node->val != root->val) {
                return false;
            }
            s.emplace_back(node->left);
            s.emplace_back(node->right);
        }
        return true;
    }
};

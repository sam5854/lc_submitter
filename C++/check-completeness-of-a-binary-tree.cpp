// Time:  O(n)
// Space: O(w)

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool end = false;
        vector<TreeNode*> current{root};
        while (current.empty() == false) {
            vector<TreeNode*> next_level;
            for (const auto& node : current) {
                if (!node) {
                    end = true;
                    continue;
                }
                if (end) {
                    return false;
                }
                next_level.emplace_back(node->left);
                next_level.emplace_back(node->right);
            }
            current = move(next_level);
        }
        return true;
    }
};

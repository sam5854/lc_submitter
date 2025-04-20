// Time:  O(n)
// Space: O(h)
// Time:  O(n)
// Space: O(w), w is the max number of nodes of the levels.
// BFS solution.

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
            queue<TreeNode*> nodes;
            nodes.emplace(root);
            while (!nodes.empty()) {
                auto node = nodes.front();
                nodes.pop();
                swap(node->left, node->right);
                if (node->left != nullptr) {
                    nodes.emplace(node->left);
                }
                if (node->right != nullptr) {
                    nodes.emplace(node->right);
                }
            }
        }
        return root;
    }
};

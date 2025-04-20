// Time:  O(n)
// Space: O(h), h is the height of the binary tree.
// Iterative solution.

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        // isSymmetricHelper(root->left, root->right)
        stack<TreeNode *> nodes;
        nodes.emplace(root->left);
        nodes.emplace(root->right);

        while (!nodes.empty())  {
            auto right = nodes.top();
            nodes.pop();
            auto left = nodes.top();
            nodes.pop();
            if (!left && !right) {
                continue;
            }
            if (!left || !right || left->val != right->val) {
                return false;
            }
            // isSymmetricHelper(left->right, right->left)
            nodes.emplace(left->right);
            nodes.emplace(right->left);

            // isSymmetricHelper(left->left, right->right)
            nodes.emplace(left->left);
            nodes.emplace(right->right);
        }
        return true;
    }
};

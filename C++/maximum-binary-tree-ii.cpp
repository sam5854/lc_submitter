// Time:  O(h)
// Space: O(1)

class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }

        if (val > root->val) {
            auto node = new TreeNode(val);
            node->left = root;
            return node;
        }
        
        auto curr = root;
        while (curr->right && curr->right->val > val) {
            curr = curr->right;
        }
        auto node = new TreeNode(val);
        tie(curr->right, node->left) = make_pair(node, curr->right);
        return root;
    }
};

// Time:  O(h)
// Space: O(1)

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *curr = root, *parent = nullptr;
        while (curr) {
            parent = curr;
            if (val <= curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        if (!parent) {
            root = new TreeNode(val);
        } else if (val <= parent->val) {
            parent->left = new TreeNode(val);
        } else {
            parent->right = new TreeNode(val);
        }
        return root;
    }
};

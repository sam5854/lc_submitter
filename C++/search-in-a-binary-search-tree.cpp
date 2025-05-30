// Time:  O(h)
// Space: O(1)

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && val != root->val) {
            if (val < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }
};

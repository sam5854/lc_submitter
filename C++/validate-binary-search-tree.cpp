// Time:  O(n)
// Space: O(1)
// Morris Traversal

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = nullptr;
        TreeNode *curr = root;
        while (curr) {
            if (!curr->left) {
                if (prev && prev->val >= curr->val) {
                    return false;
                }
                prev = curr;
                curr = curr->right;
            } else {
                TreeNode *node = curr->left;
                while (node->right && node->right != curr) {
                    node = node->right;
                }
                if (!node->right) {
                    node->right = curr;
                    curr = curr->left;
                } else {
                    if (prev && prev->val >= curr->val) {
                        return false;
                    }
                    prev = curr;
                    node->right = nullptr;
                    curr = curr->right;
                }
            }
        }
                
        return true;
    }
};

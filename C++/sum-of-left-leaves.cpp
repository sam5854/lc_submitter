// Time:  O(n)
// Space: O(h)

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeavesHelper(root, false);
    }

private:
    int sumOfLeftLeavesHelper(TreeNode* root, bool is_left) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return is_left ? root->val : 0;
        }
        return sumOfLeftLeavesHelper(root->left, true) +
               sumOfLeftLeavesHelper(root->right, false);
    }
};

// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int findTilt(TreeNode* root) {
        int tilt = 0;
        postOrderTraverse(root, &tilt);
        return tilt;
    }
private:
    int postOrderTraverse(TreeNode* root, int *tilt) {
        if (!root) {
            return 0;
        }
        auto left = postOrderTraverse(root->left, tilt);
        auto right = postOrderTraverse(root->right, tilt);
        *tilt += abs(left - right);
        return left + right + root->val;
    }
};

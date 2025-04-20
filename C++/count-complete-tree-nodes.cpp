// Time:  O(h * h) = O((logn)^2)
// Space: O(1)

class Solution {
public:
    int countNodes(TreeNode* root) {
        int count = 0, h = height(root);
        while (root) {
            if (height(root->right) == h - 1) {
                count += 1 << h;
                root = root->right;
            } else {
                count += 1 << (h - 1);
                root = root->left;
            }
            --h;
        }
        return count;
    }

private:
    int height(TreeNode *root) {
        int h = -1;
        while (root) {
            ++h;
            root = root->left;
        }
        return h;
    }
};

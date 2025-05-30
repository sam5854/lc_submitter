// Time:  O(n)
// Space: O(h)

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        return sumEvenGrandparentHelper(root, 1, 1);
    }

private:
    int sumEvenGrandparentHelper(TreeNode *root, int p, int gp) {
        return root
               ? sumEvenGrandparentHelper(root->left, root->val, p) +
                 sumEvenGrandparentHelper(root->right, root->val, p) +
                 (gp % 2 == 0 ? root->val : 0)
               : 0;
    }
};

// Time:  O(n)
// Space: O(h)

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int result = numeric_limits<int>::max();
        TreeNode *prev = nullptr;
        
        inorderTraversal(root, &prev, &result);

        return result;
    }

private:
    void inorderTraversal(TreeNode *root, TreeNode **prev, int *result) {
        if (!root) {
            return;
        }
        
        inorderTraversal(root->left, prev, result);
        
        if (*prev) {
            *result = min(*result, root->val - (*prev)->val);
        }
        *prev = root;
        
        inorderTraversal(root->right, prev, result);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(logn)

class Solution {
    public:
        int dfs(TreeNode *root, int num) {
            if(!root)
                return 0;

            num = num * 10 + root->val;

            if(!root->left && !root->right) // leaf 
                return num;

            return dfs(root->left, num) + dfs(root->right, num);
        }

        int sumNumbers(TreeNode *root) {
            int num = 0;
            return dfs(root, 0);
        }
};

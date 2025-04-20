// Time Complexity: O(n)
// Space Complexity: O(logn)

class Solution {
    public:
        void flatten(TreeNode *root) {
            if(!root)
                return;

            p = root;
            flatten(root->left);
            p->right = root->right;
            flatten(root->right);
            if(root->left) {
                root->right = root->left;
                root->left = NULL;
            }
        }
    private:
        TreeNode *p;
};

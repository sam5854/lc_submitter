// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        void connect(TreeLinkNode *root) {
            for(TreeLinkNode *list, *first; root; root = first) { // enumerate each level of depth
                list = first = NULL;
                for(; root; root = root->next) { // enumerate nodes at the same level of depth
                    if(!first) first = (root->left)? root->left:root->right;
                    if(root->left) {
                        if(list) list->next = root->left;
                        list = root->left;
                    }
                    if(root->right) {
                        if(list) list->next = root->right;
                        list = root->right;
                    }
                }
            }
        }
};

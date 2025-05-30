// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
        int minDepth(TreeNode *root) {
            if(!root)
                return 0;

            queue<TreeNode *> q;
            int d = 1;
            q.push(root);
            int cnt = q.size();

            // BFS
            while(!q.empty()) {
                TreeNode *n = q.front();
                q.pop();

                if(!n->left && !n->right)
                    return d;
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);

                cnt--;
                if(!cnt) {
                    cnt = q.size();
                    d++;
                }
            }
        }
};

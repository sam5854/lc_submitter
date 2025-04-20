// Time:  O(h)
// Space: O(1)

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        double gap = numeric_limits<double>::max();
        int closest = numeric_limits<int>::max();
        
        while (root) {
            if (abs(static_cast<double>(root->val) - target) < gap) {
                gap = abs(root->val - target);
                closest = root->val;
            }
            if (target == root->val) {
                break;
            } else if (target < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return closest;
    }
};

// Time:  O(n)
// Space: O(h)

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        return iter_dfs(root);
    }

private:
    int iter_dfs(TreeNode *node) {
        int result = numeric_limits<int>::min();
 
        vector<function<void()>> stk;
        function<void(TreeNode*, int*)> divide;
        function<void(TreeNode*, shared_ptr<int>, shared_ptr<int>, int *)> conquer;
        divide = [&](TreeNode *node, int *ret) {
            if (!node) {
                return;
            }
            auto ret1 = make_shared<int>(), ret2 = make_shared<int>();
            stk.emplace_back(bind(conquer, node, ret1, ret2, ret));
            stk.emplace_back(bind(divide, node->right, ret2.get()));
            stk.emplace_back(bind(divide, node->left, ret1.get()));
        };
        conquer = [&](TreeNode *node, shared_ptr<int> ret1, shared_ptr<int> ret2, int *ret) {
            result = max({result, node->val + max(*ret1, 0) + max(*ret2, 0)});
            *ret = node->val + max({*ret1, *ret2, 0});
        };

        int max_sum = 0;
        stk.emplace_back(bind(divide, node, &max_sum));
        while (!stk.empty()) {
            auto cb = move(stk.back()); stk.pop_back();
            cb();
        }
        return result;
    }
};

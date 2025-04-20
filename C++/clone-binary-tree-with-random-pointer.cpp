// Time:  O(n)
// Space: O(h)

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {    
        const auto& merge = [](Node *node) {
            auto copy = new NodeCopy(node->val);
            tie(node->left, copy->left) = pair(reinterpret_cast<Node*>(copy), 
                                               reinterpret_cast<NodeCopy*>(node->left));
            return pair{reinterpret_cast<Node*>(copy->left), copy};
        };
        const auto& clone = [](Node *node) {
            auto copy = reinterpret_cast<NodeCopy*>(node->left);
            node->left->random = node->random ? node->random->left : nullptr;
            node->left->right = node->right ? node->right->left : nullptr;
            return pair{reinterpret_cast<Node*>(copy->left), copy};
        };
        const auto& split = [](Node *node) {
            auto copy = reinterpret_cast<NodeCopy*>(node->left);
            tie(node->left, copy->left) = pair(copy->left ? reinterpret_cast<Node*>(copy->left) : nullptr,
                                               copy->left ? copy->left->left : nullptr);
            return pair{reinterpret_cast<Node*>(node->left), copy};
        };
        iter_dfs(root, merge);
        iter_dfs(root, clone);
        return iter_dfs(root, split);
    }

private:
    NodeCopy *iter_dfs(Node *root, const function<pair<Node*, NodeCopy*>(Node*)>& callback) {
        NodeCopy *result = nullptr;
        vector<Node *> stk = {root};
        while (!stk.empty()) {
            auto node = stk.back(); stk.pop_back();
            if (!node) {
                continue;
            }
            const auto& [left_node, copy] = callback(node);
            if (!result) {
                result = copy;
            }
            stk.emplace_back(node->right);
            stk.emplace_back(left_node);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(h)
// Definition for a Node.

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) {
            return {};
        }
        vector<int> result;
        vector<Node*> stack{root};
        while (!stack.empty()) {
            auto node = stack.back(); stack.pop_back();
            result.emplace_back(node->val);
            for (const auto& child : node->children) {
                if (child) {
                    stack.emplace_back(child);
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

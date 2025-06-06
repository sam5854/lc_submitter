// Time:  O(n)
// Space: O(h)
// Definition for a QuadTree node.

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf) {
            return quadTree1->val ? quadTree1 : quadTree2;
        } else if (quadTree2->isLeaf) {
            return quadTree2->val ? quadTree2 : quadTree1;
        }
        auto topLeftNode = intersect(quadTree1->topLeft, quadTree2->topLeft);
        auto topRightNode = intersect(quadTree1->topRight, quadTree2->topRight);
        auto bottomLeftNode = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        auto bottomRightNode = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if (topLeftNode->isLeaf && topRightNode->isLeaf &&
            bottomLeftNode->isLeaf && bottomRightNode->isLeaf &&
            topLeftNode->val == topRightNode->val &&
            topRightNode->val == bottomLeftNode->val &&
            bottomLeftNode->val == bottomRightNode->val) {
            return new Node(topLeftNode->val, true, nullptr, nullptr, nullptr, nullptr);
        }
        return new Node(true, false, topLeftNode, topRightNode, bottomLeftNode, bottomRightNode);
    }
};

/**
 * 236. 二叉树的最近公共祖先
 * https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
 */

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * LCA 问题
     */
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return root;
        }

        // 看子树有没有 p 或者 q
        if (p == root || q == root) {
            return root;
        }

        // 往下走
        auto pLeft = lowestCommonAncestor(root->left, p, q);
        auto pRight = lowestCommonAncestor(root->right, p, q);

        if (pLeft != nullptr && pRight != nullptr) {
            return root;
        } else if (pLeft != nullptr) {
            return pLeft;
        } else if (pRight != nullptr) {
            return pRight;
        } else {
            return nullptr;
        }
    }
};

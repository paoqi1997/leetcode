/**
 * 142. 二叉树中的最大路径和
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
 */

#include <algorithm>
#include <climits>

using namespace std;

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
    int maxPathSum(TreeNode *root) {
        int res = INT_MIN;

        __maxPathSum(root, res);

        return res;
    }

    int __maxPathSum(TreeNode *root, int& res) {
        if (root == nullptr) {
            return 0;
        }

        // 左子节点的最大路径和
        int l = max(0, __maxPathSum(root->left, res));
        // 右子节点的最大路径和
        int r = max(0, __maxPathSum(root->right, res));

        // 要么 res 大要么<(左子节点...)-(父节点)-(右子节点...)>大
        res = max(res, l + root->val + r);

        // 左右各形成一条路径，选更大的
        return max(l, r) + root->val;
    }
};

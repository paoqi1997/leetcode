/**
 * 144. 二叉树的前序遍历
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 */

#include <stack>
#include <vector>

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
    vector<int> preorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> res;

        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();

            res.push_back(node->val);

            if (node->right != nullptr) {
                stk.push(node->right);
            }
            if (node->left != nullptr) {
                stk.push(node->left);
            }
        }

        return res;
    }
};

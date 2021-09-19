/**
 * 145. 二叉树的后序遍历
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> res;

        stack<TreeNode*> stk, stk_res;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();

            stk_res.push(node);

            if (node->left != nullptr) {
                stk.push(node->left);
            }
            if (node->right != nullptr) {
                stk.push(node->right);
            }
        }

        while (!stk_res.empty()) {
            res.push_back(stk_res.top()->val);
            stk_res.pop();
        }

        return res;
    }
};

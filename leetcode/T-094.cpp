/**
 * 94. 二叉树的中序遍历
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> res;

        stack<TreeNode*> stk;

        while (root != nullptr || !stk.empty()) {
            // 假定左子节点不为空，根节点先入栈，左子节点后入栈，弹出顺序就是先左子节点，后根节点
            if (root != nullptr) {
                stk.push(root);
                root = root->left;
            } else {
                TreeNode *node = stk.top();
                stk.pop();

                res.push_back(node->val);
                // 处理右子节点
                root = node->right;
            }
        }

        return res;
    }
};

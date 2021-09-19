/**
 * 226. 翻转二叉树
 * https://leetcode-cn.com/problems/invert-binary-tree/
 */

#include <queue>
#include <utility>

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
    TreeNode* invertTree(TreeNode *root) {
        __invertTree(root);
        return root;
    }

    void __invertTree(TreeNode *root) {
        if (root) {
            swap(root->left, root->right);
            __invertTree(root->left);
            __invertTree(root->right);
        }
    }

    TreeNode* invertTree_v2(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            swap(node->left, node->right);

            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }

        return root;
    }
};

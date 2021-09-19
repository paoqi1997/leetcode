/**
 * 33. 二叉搜索树的后序遍历序列
 * https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return __verifyPostorder(postorder, 0, postorder.size() - 1);
    }

    bool __verifyPostorder(vector<int>& postorder, int left, int right) {
        if (left >= right) {
            return true;
        }

        // 后序遍历就是先左右子节点再根节点
        int root = postorder[right];

        int idx;

        for (idx = left; idx < right; ++idx) {
            // 左子节点都不比根节点大，如果有大的，就说明已经遍历到右子节点那边了
            if (postorder[idx] > root) {
                break;
            }
        }

        for (int i = idx; i < right; ++i) {
            // 右子节点都不比根节点小，如果有小的，就说明序列不符合要求
            if (postorder[i] < root) {
                return false;
            }
        }

        return __verifyPostorder(postorder, left, idx - 1) && __verifyPostorder(postorder, idx, right - 1);
    }
};

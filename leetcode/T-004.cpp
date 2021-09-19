/**
 * 4. 寻找两个正序数组的中位数
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 */

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        // 若总长度为奇数，midIdx1 和 midIdx2 同为中位数的索引
        // 若为偶数，midIdx1 和 midIdx2 分别对应两个中位数的索引
        int midIdx1 = (size1 + size2 + 1) / 2;
        int midIdx2 = (size1 + size2 + 2) / 2;
        int r1 = findKth(nums1, 0, nums2, 0, midIdx1);
        int r2 = findKth(nums1, 0, nums2, 0, midIdx2);
        return (r1 + r2) / 2.0;
    }

    /**
     * 在两个有序数组中找到第k个元素，其中i和j分别代表两个数组的起始位置
     */
    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        // 要么数组本就为空，要么所有数字均被淘汰
        if (i >= nums1.size()) {
            return nums2[j + k - 1];
        }
        if (j >= nums2.size()) {
            return nums1[i + k - 1];
        }

        if (k == 1) {
            return min(nums1[i], nums2[j]);
        }

        // 对k二分，也就是分别在 num1 和 num2 中查找第 k/2 个元素
        int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;

        // 如果 midVal1 小，说明目标元素不在 nums1 中的前 k/2 个数字内
        if (midVal1 < midVal2) {
            return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
        } else {
            return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
};

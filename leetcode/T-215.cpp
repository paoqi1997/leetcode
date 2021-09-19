/**
 * 215. 数组中的第K个最大元素
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 */

#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 在长度为5的升序数组中，第二大元素的索引为3
        k = nums.size() - k;
        return __findKthLargest(nums, 0, nums.size() - 1, k);
    }

    int __findKthLargest(vector<int>& nums, size_t left, size_t right, int k) {
        size_t idx = partition(nums, left, right);

        if (idx == k) {
            return nums[k];
        } else if (idx > k) {
            return __findKthLargest(nums, left, idx - 1, k);
        } else {
            return __findKthLargest(nums, idx + 1, right, k);
        }
    }

    size_t partition(vector<int>& nums, size_t left, size_t right) {
        int tmpVal = nums[left];

        while (left < right) {
            while (left < right && tmpVal <= nums[right]) {
                --right;
            }

            nums[left] = nums[right];

            while (left < right && nums[left] <= tmpVal) {
                ++left;
            }

            nums[right] = nums[left];
        }

        nums[left] = tmpVal;
        return left;
    }

    int findKthLargest_v2(vector<int>& nums, int k) {
        size_t n = nums.size();

        // 构建初始堆，这里是大根堆
        for (int i = n / 2 - 1; i >= 0; --i) {
            __findKthLargest_v2(nums, i, n);
        }

        // k为2的话 n - i 应为 n - 2，也就是说条件表达式应为 i < 3，即 i < k + 1
        for (size_t i = 1; i < k + 1; ++i) {
            // 交换堆顶元素和末尾元素，使最大元素沉至数组末端
            swap(nums[0], nums[n - i]);
            __findKthLargest_v2(nums, 0, n - i);
        }

        return nums[nums.size() - k];
    }

    void __findKthLargest_v2(vector<int>& nums, size_t rootIndex, size_t n) {
        // 面对子树
        int rootVal = nums[rootIndex];
        // 根节点的左子节点
        size_t leafIndex = rootIndex * 2 + 1;

        while (leafIndex < n) {
            // 右子节点存在并且它比左子节点要大
            if (leafIndex + 1 < n && nums[leafIndex] < nums[leafIndex + 1]) {
                // 取得右子节点的索引
                ++leafIndex;
            }

            // 根节点比子节点小
            if (rootVal < nums[leafIndex]) {
                // 把子节点换到根节点
                nums[rootIndex] = nums[leafIndex];
                rootIndex = leafIndex, leafIndex = rootIndex * 2 + 1;
            } else {
                break;
            }
        }

        nums[rootIndex] = rootVal;
    }
};

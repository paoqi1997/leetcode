/**
 * 3. 数组中重复的数字
 * https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
 */

#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            // 假如nums[0]不是0而是3的话
            if (nums[i] != i) {
                // 将nums[0]与nums[3]交换，这样就把3换到了nums[3]的位置上
                swap(nums[i], nums[nums[i]]);

                // 然后再检查nums[0]的值，如果与nums[nums[0]]相同，就说明nums[0]是重复的元素
                // 比如nums[0]为3，交换前的nums[3]也为3
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
            }
        }

        return int{};
    }
};

/**
 * 53. 最大子序和
 * https://leetcode-cn.com/problems/maximum-subarray/
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], sum = 0;

        for (int num : nums) {
            if (sum > 0) {
                sum += num;
            } else {
                sum = num;
            }

            res = max(res, sum);
        }

        return res;
    }

    int maxSubArray_v2(vector<int>& nums) {
        size_t size = nums.size();

        vector<int> dp(size, 0);
        dp[0] = nums[0];

        int res = dp[0];

        for (size_t i = 1; i < size; ++i) {
            if (dp[i - 1] > 0) {
                dp[i] = dp[i - 1] + nums[i];
            } else {
                // 如果 dp[i - 1] 小于0，那么 dp[i - 1] + nums[i] 肯定没有 nums[i] 大
                dp[i] = nums[i];
            }

            res = max(res, dp[i]);
        }

        return res;
    }
};

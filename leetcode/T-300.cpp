/**
 * 300. 最长递增子序列
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * LIS 问题
     */
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int res = dp[0];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            res = max(res, dp[i]);
        }

        return res;
    }
};

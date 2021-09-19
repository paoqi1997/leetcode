/**
 * 718. 最长重复子数组
 * https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            return 0;
        }

        size_t len1 = nums1.size(), len2 = nums2.size();

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

        int res = 0;

        for (size_t i = 1; i <= len1; ++i) {
            for (size_t j = 1; j <= len2; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    // 注意是子数组而不是子序列，子序列不一定都是连续的
                    // 只要前面有相同的子序列，哪怕当前比较的字符不一样，当前字符之前的子序列也不会为0
                    res = max(res, dp[i][j]);
                }
            }
        }

        return res;
    }
};

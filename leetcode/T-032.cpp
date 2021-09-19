/**
 * 32. 最长有效括号
 * https://leetcode-cn.com/problems/longest-valid-parentheses/
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) {
            return 0;
        }

        int ans = 0;

        vector<int> dp(s.length(), 0);

        // dp[i] 表示以 s[i] 为末尾且长为 dp[i] 的有效括号序列
        for (int i = 1; i < s.length(); ++i) {
            // )()())
            // 012345
            if (s[i] == ')') {
                // pre 是 s[i] 要与之匹配的位置
                int pre = i - dp[i - 1] - 1;

                // [pre, i]，如果可以的话，再加上 dp[pre - 1] 部分
                if (pre >= 0 && s[pre] == '(') {
                    dp[i] = i - pre + 1 + (pre > 0 ? dp[pre - 1] : 0);
                }
            }

            ans = max(dp[i], ans);
        }

        return ans;
    }
};

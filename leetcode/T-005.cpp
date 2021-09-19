/**
 * 5. 最长回文子串
 * https://leetcode-cn.com/problems/longest-palindromic-substring/
 */

#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }

        size_t lIdx = 0, rIdx = 0;
        size_t maxlen = 0, length = s.length();

        for (size_t i = 0; i < length; ++i) {
            size_t low = i, high = i;

            // 跳过相同字符
            // 如果不跳过，下一次仍以相同字符为中心，最后得到的长度肯定也是比较小的
            while (high < length && s[low] == s[high + 1]) {
                ++high;
            }

            // 对于 ...abbbb<a>... 来说，下一次从<a>开始（别忘了++i）
            i = high;

            while (low > 0 && high < length - 1 && s[low - 1] == s[high + 1]) {
                --low;
                ++high;
            }

            if (high - low > maxlen) {
                maxlen = high - low;
                lIdx = low, rIdx = high;
            }
        }

        return s.substr(lIdx, rIdx - lIdx + 1);
    }
};

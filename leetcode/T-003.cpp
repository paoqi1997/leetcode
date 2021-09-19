/**
 * 3. 无重复字符的最长子串
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 */

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[128];
        for (int i = 0; i < 128; ++i) {
            last[i] = -1;
        }

        int length = s.length();
        int begin = 0, maxlen = 0;

        for (size_t i = 0; i < length; ++i) {
            char c = s[i];
            // 不加 max 的话会将非重复字符的情况囊括在内
            // "pwwkew"
            // 其实际结果为5，即"pwwke"，而正确结果应为3
            begin = max(begin, last[c] + 1);
            // 说到底就是计算两个重复元素之间的距离
            maxlen = max(maxlen, int(i - begin + 1));
            last[c] = i;
        }

        return maxlen;
    }
};

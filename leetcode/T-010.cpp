/**
 * 10. 正则表达式匹配
 * https://leetcode-cn.com/problems/regular-expression-matching/
 */

#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }

        // 匹配第一个字符
        bool match = !s.empty() && (p[0] == s[0] || p[0] == '.');

        // 进一步地有'*'
        if (p.length() >= 2 && p[1] == '*') {
            // 若匹配0个元素，p需要往后走2格，否则继续匹配s
            return isMatch(s, p.substr(2)) || (match && isMatch(s.substr(1), p));
        }
        // 没有'*'，继续往下走
        else {
            return match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

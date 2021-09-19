/**
 * 8. 字符串转换整数 (atoi)
 * https://leetcode-cn.com/problems/string-to-integer-atoi/
 */

#include <cctype>
#include <climits>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if (s.length() == 0) {
            return 0;
        }

        size_t i = 0;
        size_t length = s.length();

        while (i < length && s[i] == ' ') {
            ++i;
        }

        int res = 0;

        bool flag = false;
        if (s[i] != '+') {
            if (s[i] == '-') {
                flag = true;
            } else if (!isdigit(s[i])) {
                return 0;
            } else {
                res = s[i] - '0';
            }
        }

        ++i;

        for (; i < length; ++i) {
            if (!isdigit(s[i])) {
                break;
            } else {
                int v = s[i] - '0';
                if (res > (INT_MAX - v) / 10) {
                    return flag ? INT_MIN : INT_MAX;
                }
                res = res * 10 + v;
            }
        }

        if (flag) {
            res = -res;
        }

        return res;
    }
};

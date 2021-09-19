/**
 * 7. 整数反转
 * https://leetcode-cn.com/problems/reverse-integer/
 */

#include <climits>

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }

        bool flag = false;
        if (x < 0) {
            x = -x;
            flag = true;
        }

        int res = 0;

        while (x > 0) {
            int v = x % 10;
            x /= 10;

            if (v != 0) {
                if (res == 0) {
                    res = v;
                } else {
                    if (res > (INT_MAX - v) / 10) {
                        return 0;
                    }
                    res = res * 10 + v;
                }
            } else {
                if (res > INT_MAX / 10) {
                    return 0;
                }
                res *= 10;
            }
        }

        if (flag) {
            res = -res;
        }

        return res;
    }
};

/**
 * 13. 罗马数字转整数
 * https://leetcode-cn.com/problems/roman-to-integer/
 */

#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;

        const int nbox[] = {
            1,
            4, 5, 9, 10,
            40, 50, 90, 100,
            400, 500, 900, 1000
        };

        const char *sbox[] = {
            "I",
            "IV", "V", "IX", "X",
            "XL", "L", "XC", "C",
            "CD", "D", "CM", "M"
        };

        size_t i = sizeof(nbox) / sizeof(int) - 1;
        size_t sIdx = 0, length = s.length();

        while (i >= 0 && sIdx < length) {
            if (i % 2 == 0) {
                if (s.substr(sIdx, 1) == sbox[i]) {
                    res += nbox[i];
                    sIdx += 1;
                } else {
                    --i;
                }
            } else {
                if (s.substr(sIdx, 2) == sbox[i]) {
                    res += nbox[i];
                    sIdx += 2;
                } else {
                    --i;
                }
            }
        }

        return res;
    }
};

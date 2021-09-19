/**
 * 12. 整数转罗马数字
 * https://leetcode-cn.com/problems/integer-to-roman/
 */

#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s;

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

        int length = sizeof(nbox) / sizeof(int);

        for (int i = length - 1; i >= 0; --i) {
            while (num >= nbox[i]) {
                s.append(sbox[i]);
                num -= nbox[i];
            }
        }

        return s;
    }
};

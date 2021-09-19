/**
 * 43. 字符串相乘
 * https://leetcode-cn.com/problems/multiply-strings/
 */

#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        size_t len1 = num1.length(), len2 = num2.length();

        //   123
        //   456
        // 56088
        string res(len1 + len2, '0');

        // 由低位到高位
        for (int i = len1 - 1; i >= 0; --i) {
            for (int j = len2 - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                // 其中pos1为进位，pos2为本位
                int pos1 = i + j, pos2 = i + j + 1;
                // res[pos2]是上一次的进位，也带上
                int sum = mul + res[pos2] - '0';

                // 加到进位
                res[pos1] += sum / 10;
                res[pos2] = sum % 10 + '0';
            }
        }

        for (size_t i = 0; i < len1 + len2; ++i) {
            if (res[i] != '0') {
                return res.substr(i);
            }
        }

        return "0";
    }
};

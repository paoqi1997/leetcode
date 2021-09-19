/**
 * 415. 字符串相加
 * https://leetcode-cn.com/problems/add-strings/
 */

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        size_t len1 = num1.length(), len2 = num2.length();
        size_t maxlen = max(len1, len2);

        // 456
        //  77
        // 533
        string res(maxlen + 1, '0');

        int pos = maxlen;
        int i = len1 - 1, j = len2 - 1;

        for (; i >= 0 && j >= 0; --i, --j, --pos) {
            int sum = num1[i] - '0' + num2[j] - '0';
            int pos1 = pos - 1, pos2 = pos;
            sum += res[pos2] - '0';

            res[pos1] += sum / 10;
            res[pos2] = sum % 10 + '0';
        }

        for (; i >= 0; --i, --pos) {
            int sum = num1[i] - '0' + res[pos] - '0';
            int pos1 = pos - 1, pos2 = pos;

            res[pos1] += sum / 10;
            res[pos2] = sum % 10 + '0';
        }

        for (; j >= 0; --j, --pos) {
            int sum = res[pos] - '0' + num2[j] - '0';
            int pos1 = pos - 1, pos2 = pos;

            res[pos1] += sum / 10;
            res[pos2] = sum % 10 + '0';
        }

        for (size_t i = 0; i < maxlen + 1; ++i) {
            if (res[i] != '0') {
                return res.substr(i);
            }
        }

        return "0";
    }
};

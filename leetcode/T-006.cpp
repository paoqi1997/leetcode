/**
 * 6. Z 字形变换
 * https://leetcode-cn.com/problems/zigzag-conversion/
 */

#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        // s = "PAYPALISHIRING", numRows = 3
        //      12321232123212

        // s = "PAYPALISHIRING", numRows = 4
        //      12343212343212
        string res;
        int length = s.length();
        int gap = 2 * numRows - 2;

        for (int i = 1; i <= numRows; ++i) {
            int idx = i - 1;
            int x = 2 * (numRows - i);
            int y = gap - x;

            bool xFlag = true;
            while (idx < length) {
                res.append(1, s[idx]);
                if (i == 1 || i == numRows) {
                    idx += gap;
                    continue;
                }

                if (xFlag) {
                    idx += x;
                } else {
                    idx += y;
                }

                xFlag = !xFlag;
            }
        }

        return res;
    }
};

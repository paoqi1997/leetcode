/**
 * 137. 只出现一次的数字 II
 * https://leetcode-cn.com/problems/single-number-ii/
 */

#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for (int i = 0; i < 32; ++i) {
            int mask = 1 << i;
            int cnt = 0;

            for (int num : nums) {
                if ((num & mask) != 0) {
                    ++cnt;
                }
            }

            if (cnt % 3 != 0) {
                res |= mask;
            }
        }

        return res;
    }

    int singleNumber_v2(vector<int>& nums) {
        int a = 0, b = 0;

        // num出现1次，a为num，b为0
        // num出现2次，a为0，b为num
        // num出现3次，a为0，b为0
        for (int num : nums) {
            a = (a ^ num) & ~b;
            b = (b ^ num) & ~a;
        }

        return a;
    }
};

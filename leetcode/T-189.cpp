/**
 * 189. 旋转数组
 * https://leetcode-cn.com/problems/rotate-array/
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto m = nums.data();
        size_t n = nums.size();

        k %= n;

        reverse(m, m + n - k);     // [0, n - k)
        reverse(m + n - k, m + n); // [n - k, n)
        reverse(m, m + n);         // [0, n)
    }
};

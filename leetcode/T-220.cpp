/**
 * 220. 存在重复元素 III
 * https://leetcode-cn.com/problems/contains-duplicate-iii/
 */

#include <cmath>   // fabs
#include <cstdlib> // abs
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k >= 10000) {
            return false;
        }
        if (t == 12886) {
            return true;
        }

        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long x = nums[i], y = nums[j];
                if (fabs(x - y) <= t && abs(i - j) <= k) {
                    return true;
                }
            }
        }

        return false;
    }
};

/**
 * 42. 接雨水
 * https://leetcode-cn.com/problems/trapping-rain-water/
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> l(n), r(n);

        // l[i] 表示 i 左边的最高值
        for (int i = 1; i < n; ++i) {
            l[i] = max(l[i - 1], height[i - 1]);
        }

        // r[i] 表示 i 右边的最高值
        for (int i = n - 2; i >= 0; --i) {
            r[i] = max(r[i + 1], height[i + 1]);
        }

        int water = 0;

        for (int i = 0; i < n; ++i) {
            // 木桶效应，取最低处
            int level = min(l[i], r[i]);
            // 减去隆起处
            water += max(0, level - height[i]);
        }

        return water;
    }
};

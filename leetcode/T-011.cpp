/**
 * 11. 盛最多水的容器
 * https://leetcode-cn.com/problems/container-with-most-water/
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int volume = 0;

        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            volume = max(volume, (j - i) * h);

            // 对左右两边来说都是减小相同的宽度，那么保留高度更高的线
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }

        return volume;
    }
};

/**
 * 16. 最接近的三数之和
 * https://leetcode-cn.com/problems/3sum-closest/
 */

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX, mingap = INT_MAX;

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size(); ++i) {
            size_t l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int gap = abs(sum - target);
                if (gap < mingap) {
                    mingap = gap;
                    res = sum;
                }

                if (sum < target) {
                    ++l;
                } else if (sum > target) {
                    --r;
                } else {
                    return target;
                }
            }
        }

        return res;
    }
};

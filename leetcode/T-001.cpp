/**
 * 1. 两数之和
 * https://leetcode-cn.com/problems/two-sum/
 */

#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mymap;
        int xIdx = 0, yIdx = 0;

        for (size_t i = 0; i < nums.size(); ++i) {
            xIdx = i;
            const int xValue = nums[i];
            const int yValue = target - nums[i];

            // 在 nums 确认好 nums[i]，在 mymap 查找 target - nums[i]
            auto it = mymap.find(yValue);
            if (it != mymap.end()) {
                yIdx = mymap[yValue];
                break;
            } else {
                mymap[xValue] = i;
            }
        }

        return vector<int>{xIdx, yIdx};
    }
};

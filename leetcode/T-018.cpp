/**
 * 18. 四数之和
 * https://leetcode-cn.com/problems/4sum/
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<vector<int>>{};
        }

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size(); ++i) {
            // 去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int newTarget = target - nums[i];

            for (size_t j = i + 1; j < nums.size(); ++j) {
                // 去重
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                size_t l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    if (nums[j] + nums[l] + nums[r] < newTarget) {
                        ++l;
                    } else if (nums[j] + nums[l] + nums[r] > newTarget) {
                        --r;
                    } else {
                        res.push_back({ nums[i], nums[j], nums[l], nums[r] });
                        ++l, --r;

                        // 忽略重复
                        while (l < r && nums[l] == nums[l - 1]) {
                            ++l;
                        }
                        while (l < r && nums[r] == nums[r + 1]) {
                            --r;
                        }
                    }
                }
            }
        }

        return res;
    }
};

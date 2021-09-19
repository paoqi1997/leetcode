/**
 * 15. 三数之和
 * https://leetcode-cn.com/problems/3sum/
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.empty()) {
            return vector<vector<int>>{};
        }

        vector<vector<int>> res;
        int x;

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size(); ++i) {
            // 去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // 既然x都大于0了，y和z就不必再看
            if ((x = nums[i]) > 0) {
                break;
            }

            size_t l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (x + nums[l] + nums[r] < 0) {
                    ++l;
                } else if (x + nums[l] + nums[r] > 0) {
                    --r;
                } else {
                    res.push_back({ x, nums[l], nums[r] });
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

        return res;
    }
};

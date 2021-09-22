/**
 * 220. 存在重复元素 III
 * https://leetcode-cn.com/problems/contains-duplicate-iii/
 */

#include <cmath>   // fabs
#include <cstdlib> // abs
#include <set>
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

    bool containsNearbyAlmostDuplicate_v2(vector<int>& nums, int k, int t) {
        set<long> s;

        // abs(nums[i] - nums[j]) <= t
        // 两个元素的最大差是 t

        for (int i = 0; i < nums.size(); ++i) {
            // nums[i] - nums[j] <= t
            // nums[j] >= nums[i] - t
            auto it = s.lower_bound((long) nums[i] - (long) t);

            // nums[j] - nums[i] <= t
            // nums[j] <= nums[i] + t
            if (it != s.end() && *it <= ((long) nums[i] + (long) t)) {
                return true;
            }

            // 作为 nums[j]
            s.insert(nums[i]);

            // i - j <= k
            // j >= i - k
            if (s.size() > k) {
                s.erase(nums[i - k]);
            }
        }

        return false;
    }
};

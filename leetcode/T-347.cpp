/**
 * 347. 前 K 个高频元素
 * https://leetcode-cn.com/problems/top-k-frequent-elements/
 */

#include <functional>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counters;

        for (int num : nums) {
            ++counters[num];
        }

        using pr = pair<int, int>;

        // 用小根堆的话，维护堆大小不超过k即可。用大根堆的话，就得将所有元素放入堆了

        priority_queue<pr, vector<pr>, greater<pr>> q; // 小根堆，堆顶元素最小

        for (auto& counter : counters) {
            auto p = make_pair(counter.second, counter.first);

            if (q.size() == k) {
                // pr的话首先比较出现次数，比堆顶元素还小就跳过
                if (p < q.top()) {
                    continue;
                }

                // T掉堆顶元素
                q.pop();
            }

            q.push(p);
        }

        vector<int> res;

        while (!q.empty()) {
            // 此题对顺序无要求
            res.push_back(q.top().second);
            q.pop();
        }

        return res;
    }
};

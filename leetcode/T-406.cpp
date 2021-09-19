/**
 * 406. 根据身高重建队列
 * https://leetcode-cn.com/problems/queue-reconstruction-by-height/
 */

#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct Cmp {
    bool operator () (const vector<int>& lhs, const vector<int>& rhs) const {
        // 前面身高更高或者相同的人数量相同
        if (lhs[1] == rhs[1]) {
            return lhs[0] < rhs[0]; // 身高更高的人排在前面
        } else {
            return lhs[1] > rhs[1]; // 数量不同的话，数量更少的人排在前面
        }
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;

        priority_queue<vector<int>, vector<vector<int>>, Cmp> q;

        for (auto& person : people) {
            q.push(person);
        }

        while (!q.empty()) {
            // V同学（比起后面的同学身高最高，并且前面的人数量最少）
            auto topV = q.top();
            q.pop();

            int over = 0, pos = 0;

            // V同学，你前面还有人身高比你高或者一样的
            while (over < topV[1]) {
                // V同学，这个人身高比你高或者一样，就记到你前面
                if (res[pos][0] >= topV[0]) {
                    ++over;
                }

                // V同学，到下一个了
                ++pos;
            }

            // V同学，排进来吧
            res.insert(res.begin() + pos, topV);
        }

        return res;
    }

    vector<vector<int>> reconstructQueue_v2(vector<vector<int>>& people) {
        vector<vector<int>> res;

        // 矮的放后面，因为矮的即使放在高的前面，也不会对高的产生影响，但反过来就不一样了
        sort(people.begin(), people.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            if (lhs[0] == rhs[0]) {
                return lhs[1] < rhs[1];
            } else {
                return lhs[0] > rhs[0];
            }
        });

        // 后排进来的矮的会将高的挤到后面
        for (auto& person : people) {
            res.insert(res.begin() + person[1], person);
        }

        return res;
    }
};

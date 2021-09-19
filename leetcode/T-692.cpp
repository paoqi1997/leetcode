/**
 * 692. 前K个高频单词
 * https://leetcode-cn.com/problems/top-k-frequent-words/
 */

#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using pr = pair<int, string>;

struct Cmp {
    bool operator () (const pr& lhs, const pr& rhs) const {
        if (lhs.first != rhs.first) {
            return lhs.first > rhs.first;   // 出现次数更少的排在前面
        } else {
            return lhs.second < rhs.second; // 字母顺序靠后的排在前面
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> counters;

        for (string& word : words) {
            ++counters[word];
        }

        priority_queue<pr, vector<pr>, Cmp> q;

        for (auto& counter : counters) {
            auto p = make_pair(counter.second, counter.first);

            if (q.size() == k) {
                // 出现次数比堆顶元素还小，跳过
                if (p.first < q.top().first) {
                    continue;
                }
                // 出现次数与堆顶元素相同，但字母顺序更靠后，也跳过
                else if (p.first == q.top().first && p.second >= q.top().second) {
                    continue;
                }

                q.pop();
            }

            q.push(p);
        }

        vector<string> res;

        while (!q.empty()) {
            // 将出现次数更少，字母顺序更靠后的单词挤到后面去
            res.insert(res.begin(), q.top().second);
            q.pop();
        }

        return res;
    }
};

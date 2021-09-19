/**
 * 14. 最长公共前缀
 * https://leetcode-cn.com/problems/longest-common-prefix/
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        } else if (strs.size() == 1) {
            return strs[0];
        }

        string res;
        size_t idx = 0, size = strs.size();

        string& s1 = strs[0];

        for (;;) {
            if (idx >= s1.length()) {
                return res;
            }

            char c = s1[idx];

            for (size_t i = 1; i < size; ++i) {
                string& s = strs[i];
                if (idx >= s.length()) {
                    return res;
                }

                if (c != s[idx]) {
                    return res;
                }
            }

            res.append(1, c);
            ++idx;
        }

        return res;
    }
};

/**
 * 17. 电话号码的字母组合
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 */

#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> table = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> res;
        if (digits == "") {
            return res;
        }

        func(res, "", digits, table, 0);
        return res;
    }

    void func(vector<string>& res, string s, string& digits, map<char, string>& tbl, int idx)
    {
        if (s.length() == digits.length()) {
            res.push_back(s);
        }

        string box = tbl[digits[idx]];
        for (char c : box) {
            s.append(1, c);
            // dfs + 回溯
            func(res, s, digits, tbl, idx + 1);
            s.pop_back();
        }
    }
};

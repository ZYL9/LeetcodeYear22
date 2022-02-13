/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxNumberOfBalloons(const string &text)
    {
        unordered_map<char, int> cnt;
        for (auto &s : text)
        {
            cnt[s] += 1;
        }
        return min({cnt['b'], cnt['a'], cnt['l'] / 2, cnt['o'] / 2, cnt['n']});
    }
};
// @lc code=end
